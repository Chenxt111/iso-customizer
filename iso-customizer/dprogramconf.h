#ifndef DPROGRAMCONF_H
#define DPROGRAMCONF_H

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

class DProgramConf : public QWidget
{
    Q_OBJECT
public:
    explicit DProgramConf(QWidget *parent = nullptr);

private:
    QStringList *pFileNameList;
    DGroupBox *pCenterBox;
    QVBoxLayout *groupVBox;
    DListView *pListVBox;
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

private slots:
    void LinkbuttonClicked();
    void ClearbuttonClicked();
    void itemFoucs(QMouseEvent *e);
};

#endif // DPROGRAMCONF_H
