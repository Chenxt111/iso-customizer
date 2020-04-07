#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dchoiceiso.h"

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
    QStackedWidget *m_pStackWidget;
    DListView *m_pDListView;
    DGroupBox *m_pDGroupBox;
    QHash<QString, QWidget*> m_hash_ItemName_ItemWidget;

    DChoiceIso *m_pChoiceIso;

    QString m_strConfDir;
    QString m_srConfPath;

private:
    void initUI();
    void initConnections();
    void settingsInit();

};

 #endif // MAINWINDOW_H
