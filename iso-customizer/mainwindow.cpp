#include "mainwindow.h"

MainWindow::MainWindow(DMainWindow *parent)
    : DMainWindow(parent)
    , m_pCentralWidget(new QWidget())
    , m_pStackWidget(new QStackedWidget())
    , m_pChoiceIso(new DChoiceIso)
    , m_pDGroupBox(new DGroupBox)
    , m_pDListView(new DListView)
{
    initUI();
    settingsInit();

    //titlebar 设置标题栏
    titlebar()->setIcon(QIcon::fromTheme("iso定制工具-32px"));
    const QString str = "ISO定制工具";
    titlebar()->setTitle(str);

    QStandardItemModel *pItemMode = new QStandardItemModel(this);
//    QAbstractItemModel *pItemMode = new QAbstractItemModel();

    QVBoxLayout *pVBoxLayout = new QVBoxLayout();
    pVBoxLayout->setSpacing(20);

    DListWidget *pDListWidget = new DListWidget();

    QListWidgetItem *QListWidgetItem1 = new QListWidgetItem();
    pDListWidget->addItem(QListWidgetItem1);
//    QWidget *pWidget1 = new QWidget();
    QHBoxLayout *pHBLayout1 = new QHBoxLayout();
    pHBLayout1->setSpacing(10);
    DPushButton *pItemChoiceISOBtn1 = new DPushButton();
    pItemChoiceISOBtn1->setMinimumHeight(40);
    pItemChoiceISOBtn1->setChecked(true);
    pItemChoiceISOBtn1->setText("选择ISO");
    pItemChoiceISOBtn1->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive1.svg"));
    pItemChoiceISOBtn1->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

//    QStandardItem *pItemChoiceISO = new QStandardItem("选择ISO");
//    DPushButton *pItemChoiceISOBtn1 = new DPushButton();
//    pItemChoiceISOBtn1->setMinimumHeight(40);
//    pItemChoiceISOBtn1->setChecked(true);
//    pItemChoiceISOBtn1->setText("选择ISO");
//    pItemChoiceISOBtn1->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive1.svg"));
//    pItemChoiceISOBtn1->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
//    m_pStackWidget->addWidget(m_pChoiceIso);
//    m_hash_ItemName_ItemWidget.insert("选择ISO", m_pChoiceIso);
//    pItemMode->appendRow(pItemChoiceISO);
//    pHBLayout1->addWidget(pItemChoiceISOBtn1);
//    pWidget1->setLayout(pHBLayout1);
//    pWidget1->setMinimumHeight(20);
//    pDListWidget->setItemWidget(QListWidgetItem1, pWidget1);


    QStandardItem *pItemChoiceArchitecture = new QStandardItem("选择架构");
    DPushButton *pItemChoiceArchitectureBtn = new DPushButton();
    pItemChoiceArchitectureBtn->setChecked(true);
    pItemChoiceArchitectureBtn->setText("选择架构");
    pItemChoiceArchitectureBtn->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive2.svg"));
    pItemChoiceArchitectureBtn->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
    m_pStackWidget->addWidget(m_pChoiceIso);
    m_hash_ItemName_ItemWidget.insert("选择架构", m_pChoiceIso);
    pItemMode->appendRow(pItemChoiceArchitecture);
//    pVBoxLayout->addWidget(pItemChoiceArchitectureBtn);

//    m_pDGroupBox->setLayout(pVBoxLayout);
    m_pDListView->setModel(pItemMode);
    pVBoxLayout->addWidget(pDListWidget);
    m_pDGroupBox->setLayout(pVBoxLayout);

    m_pStackWidget->setCurrentWidget(m_pChoiceIso);
    m_pCentralWidget->setLayout(m_pHBoxLayout);
    setCentralWidget(m_pCentralWidget);

}

MainWindow::~MainWindow()
{

}

void MainWindow::initUI()
{
    this->setWindowFlags(0);
    // 设置禁止最大化
    this->setFixedSize(807, 607);

    m_pHBoxLayout = new QHBoxLayout();
    m_pHBoxLayout->setSpacing(10);
    m_pDListView->setSpacing(15);
    m_pHBoxLayout->addWidget(m_pDGroupBox, 3);
    m_pHBoxLayout->addWidget(m_pStackWidget, 8);

    DPushButton *btn1 = new DPushButton();
    btn1->setText("选择iso");
    btn1->setCheckable(true);
    btn1->setFixedSize(200, 40);
    DPushButton *btn2 = new DPushButton();
    btn2->setText("选择架构");
    btn2->setCheckable(true);
    btn2->setFixedSize(200, 40);

    QVBoxLayout *vlayout = new QVBoxLayout();
    vlayout->addWidget(btn1);
    vlayout->addWidget(btn2);

    m_pDGroupBox->setLayout(vlayout);
//    m_pDGroupBox->setStyleSheet("QWidget{background-color:white;border-radius:8px;}"); // setStyleSheet(“QWidget{background-color:gray;border-top-left-radius:15px;border-top-right-radius:5px;}”));
//    m_pStackWidget->setStyleSheet("QWidget{background-color:white;border-radius:8px;}"); // setStyleSheet(“QWidget{background-color:gray;border-top-left-radius:15px;border-top-right-radius:5px;}”));
}

void MainWindow::settingsInit()
{
    //设置存储后端，保存设置界面的设置信息
    m_strConfDir = DStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    qDebug() << "m_strConfDir:" << m_strConfDir;
    QString m_srConfPath = m_strConfDir + QDir::separator() + "dtkdemo.conf";
    m_srConfPath = m_strConfDir + QDir::separator() + "dtkdemo.conf";
    qDebug() << "m_strConfDir:" << m_srConfPath;
}




