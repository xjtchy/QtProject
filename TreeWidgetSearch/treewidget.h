#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QTreeWidget>
#include <QBrush>
#include <QDebug>

namespace Ui {
class CTreeWidget;
}

class CTreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CTreeWidget(QWidget *parent = 0);
    ~CTreeWidget();
    void searchChild(QTreeWidgetItem *cItem, const QString &txt);
    void parentExpand(QTreeWidgetItem *item);

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::CTreeWidget *ui;
    QBrush m_itemBrush;
};

#endif // TREEWIDGET_H
