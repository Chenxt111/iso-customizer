#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dchoiceiso.h"
#include "dprogramconf.h"
#include "dchoicearchitecture.h"
#include "dpreparation.h"
#include "dchoicekernel.h"
#include "doutput.h"
#include "dmidterminstallation.h"
#include "dpostcleaning.h"

#include <DMainWindow>
#include <DWidget>
#include <DStandardPaths>
#include <DSettingsDialog>
#include <DTabBar>
#include <DTitlebar>
#include <DListView>
#include <DGroupBox>
#include <DListWidget>
#include <DPushButton>
#include <DFontSizeManager>

#include <QModelIndex>
#include <QMainWindow>
#include <QString>
#include <QDir>
#include <QDebug>
#include <QIcon>
#include <QStandardPaths>
#include <QStackedWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QHash>
#include <QListWidgetItem>
#include <QAbstractItemModel>

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    MainWindow(DMainWindow *parent = 0);
    ~MainWindow();

private:
    QHBoxLayout *m_pHBoxLayout;
    QWidget *m_pCentralWidget;
    QWidget *m_pViewWidget;
    QVBoxLayout *m_pListVBoxLayout;
    QStackedWidget *m_pStackWidget;
    DListView *m_pDListView;
    QStandardItemModel *pItemModel;
    QHash<QString, QWidget*> m_hash_ItemName_ItemWidget;

    DChoiceIso *m_pChoiceIso;
    DProgramConf *m_pProgarmConf;
    DChoiceArchitecture *m_pChoiceArchitecture;
    DPreparation *m_pPreparation;
    DMidTermInstallation *m_pMidTermInstallation;
    DPostCleaning *m_pPostCleaning;
    DChoiceKernel *m_pChoiceKernel;
    DOutPut *m_pOutPut;

    QString m_strConfDir;
    QString m_srConfPath;

    bool pItemchoiceArchitectureflag;
    bool pItemProgramConfflag;
    bool pItemPreparationflag;
    bool pItemMidTermInstallationflag;
    bool pItemPostCleaningflag;
    bool pItemChoiceKernelflag;
    bool pItemOutPutflag;

private:
    void initUI();
    void initConnections(QStandardItem *pItem);
    void settingsInit();

private slots:
    void slotListViewItemClicked(const QModelIndex &index);
    void slotListViewItemChange();

};

 #endif // MAINWINDOW_H
