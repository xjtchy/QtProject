#include "treewidget.h"
#include "ui_treewidget.h"

CTreeWidget::CTreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CTreeWidget)
{
    ui->setupUi(this);
    m_itemBrush =  ui->treeWidget->topLevelItem(0)->background(0);
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(on_lineEdit_editingFinished()));
}

CTreeWidget::~CTreeWidget()
{
    delete ui;
}

void CTreeWidget::searchChild(QTreeWidgetItem *cItem, const QString &txt)
{
    int childCount = cItem->childCount();
    for  (int i = 0; i < childCount; ++i) {
        QTreeWidgetItem *item = cItem->child(i);
        if (-1 != item->text(0).indexOf(txt)) {
            item->setExpanded(true);
            item->setBackground(0,Qt::green);
            parentExpand(item);
        } else {
            item->setBackground(0, m_itemBrush);
        }
        searchChild(item, txt);
    }
}

void CTreeWidget::parentExpand(QTreeWidgetItem *item)
{
    if (item->parent() != NULL) {
        QTreeWidgetItem *pItem = item->parent();
        if (! pItem->isExpanded()) {
            pItem->setExpanded(true);
        }
        parentExpand(pItem);
    }
}

void CTreeWidget::on_pushButton_clicked()
{
    ui->treeWidget->collapseAll();
    QString txt = ui->lineEdit->text();
    bool isEmptyTxt = txt.isEmpty();
    bool isEmptyTree = ui->treeWidget->topLevelItemCount(); //·ÇÁã¸öÎªtrue
    if (isEmptyTxt) {
        QTreeWidgetItemIterator it(ui->treeWidget);
        while(*it) {
            (*it)->setBackground(0, m_itemBrush);
            it++;
        }
        return;
    }
    if ( ! isEmptyTree) { return; }


#if 0
    int count = ui->treeWidget->topLevelItemCount();
    for (int i =0; i < count; ++i) {
        QTreeWidgetItem *cItem = ui->treeWidget->topLevelItem(i);
        if (-1 != cItem->text(0).indexOf(txt)) {
            cItem->setBackground(0,Qt::green);
        } else {
            cItem->setBackground(0, m_itemBrush);
        }
        searchChild(cItem, txt);
    }
#else

    QTreeWidgetItemIterator it(ui->treeWidget);
    while(*it) {
        QString str = (*it)->text(0);
        if (-1 != str.indexOf(txt)) {
            QTreeWidgetItem *pItem = (*it)->parent();
            if (pItem !=  NULL) {
                bool isExpanded = pItem->isExpanded();
                if (! isExpanded){
                    ui->treeWidget->expandItem(pItem);
                }
            }
            (*it)->setBackground(0,Qt::green);
            parentExpand(*it);
        } else{
            (*it)->setBackground(0, m_itemBrush);
        }
        it++;
    }
#endif
}

void CTreeWidget::on_lineEdit_editingFinished()
{
    on_pushButton_clicked();
}
