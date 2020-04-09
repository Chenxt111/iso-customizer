#ifndef DPREPARATION_H
#define DPREPARATION_H

#include "dlistwidgetclear.h"

#include <DWidget>
#include <DLabel>
#include <DPalette>
#include <DLineEdit>
#include <DMessageManager>
#include <DFontSizeManager>
#include <DApplicationHelper>
#include <DCommandLinkButton>
#include <DPushButton>
#include <DGroupBox>
#include <DListView>

#include <QDebug>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QWidget>
#include <QColor>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFileDialog>
#include <QFileIconProvider>
#include <QMouseEvent>
#include <qiterator.h>

DWIDGET_USE_NAMESPACE

class DPreparation : public QWidget
{
    Q_OBJECT
public:
    explicit DPreparation(QWidget *parent = nullptr);

private:
    QStringList *pFileNameList;
    DGroupBox *pCenterBox;
    QVBoxLayout *groupVBox;
    QList<DLineEdit> *groupLineEditList;
    QVBoxLayout *pMainLayout;
    DLabel *pCenterLabel;
    DCommandLinkButton *pDCommandLinkButtonClear;

    DListWidgetClear *pDListWidgetClear;
    QWidget *pWidget;
    QHBoxLayout *pHBLayout;
    DIconButton *pDIconButtonClear;

signals:
    void iconBtnCliked(const QPoint &locat);
    void nextBtnCliked();

private slots:
    void LinkbuttonClicked();
    void ClearbuttonClicked();
    void itemFoucs(QMouseEvent *e);
};

#endif // DPREPARATION_H
