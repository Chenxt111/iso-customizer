#ifndef DCHOICEARCHITECTURE_H
#define DCHOICEARCHITECTURE_H

#include <DWidget>
#include <DFontSizeManager>
#include <DLabel>
#include <DListView>
#include <DPushButton>

#include <QStandardItemModel>
#include <QStandardItem>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QModelIndex>
#include <QListView>
#include <QLabel>
#include <QDebug>

DWIDGET_USE_NAMESPACE

class DChoiceArchitecture : public QWidget
{
    Q_OBJECT
public:
    explicit DChoiceArchitecture(QWidget *parent = nullptr);

private:
    QStandardItem *pItemARM;
    QStandardItem *pItemX86;
    QStandardItem *pItemMIPS;

signals:
    void nextBtnCliked();

private slots:
    void CheckIndexChangedSignal(const QModelIndex &current, const QModelIndex &previous);
};

class DListViewRest : public DListView
{
    Q_OBJECT
public:
    explicit DListViewRest(QWidget *parent = nullptr);

private:
    virtual void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;

signals:
    void currentChange(const QModelIndex &current, const QModelIndex &previous);
};

#endif // DCHOICEARCHITECTURE_H
