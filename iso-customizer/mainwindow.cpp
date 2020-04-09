#include "mainwindow.h"

MainWindow::MainWindow(DMainWindow *parent)
    : DMainWindow(parent)
    , m_pCentralWidget(new QWidget())
    , m_pStackWidget(new QStackedWidget())
    , m_pChoiceIso(new DChoiceIso)
    , m_pDListView(new DListView)
    , m_pChoiceArchitecture(new DChoiceArchitecture)
    , m_pProgarmConf(new DProgramConf)
{
    initUI();
    settingsInit();

    //titlebar 设置标题栏
    titlebar()->setIcon(QIcon::fromTheme("iso定制工具-32px"));
    const QString str = "ISO定制工具";
    titlebar()->setTitle(str);

    QVBoxLayout *pVBoxLayout = new QVBoxLayout();
    pVBoxLayout->setSpacing(40);

    QStandardItemModel *pItemModel = new QStandardItemModel(this);
//    DListWidget *pDListWidget = new DListWidget();

    QStandardItem *pItemchoiceISO = new QStandardItem("选择ISO");
    pItemchoiceISO->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive1.svg"));
    pItemchoiceISO->setText(tr("选择ISO"));
//    pItemchoiceISO->setTristate(false);
//    pItemchoiceISO->setFlags(Qt::ItemIsEnabled|Qt::ItemIsDropEnabled);
    m_pStackWidget->addWidget(m_pChoiceIso);
    m_hash_ItemName_ItemWidget.insert("选择ISO", m_pChoiceIso);
    pItemModel->appendRow(pItemchoiceISO);

    QStandardItem *pItemchoiceArchitecture = new QStandardItem("选择架构");
    pItemchoiceArchitecture->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive2.svg"));
    pItemchoiceArchitecture->setText(tr("选择架构"));
    m_pStackWidget->addWidget(m_pChoiceArchitecture);
    m_hash_ItemName_ItemWidget.insert("选择架构", m_pChoiceArchitecture);
    pItemModel->appendRow(pItemchoiceArchitecture);

    QStandardItem *pItemProgramConf = new QStandardItem("程序配置");
    pItemProgramConf->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive3.svg"));
    pItemProgramConf->setText(tr("程序配置"));
    m_pStackWidget->addWidget(m_pProgarmConf);
    m_hash_ItemName_ItemWidget.insert("程序配置", m_pProgarmConf);
    pItemModel->appendRow(pItemProgramConf);

    QStandardItem *pItemPreparation = new QStandardItem("前期准备");
    pItemPreparation->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive4.svg"));
    pItemPreparation->setText(tr("前期准备"));
    m_pStackWidget->addWidget(m_pProgarmConf);
    m_hash_ItemName_ItemWidget.insert("前期准备", m_pProgarmConf);
    pItemModel->appendRow(pItemPreparation);

    m_pDListView->setModel(pItemModel);
    m_pDListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pStackWidget->setCurrentWidget(m_pChoiceIso);
    connect(m_pDListView, &DListView::clicked, this, &MainWindow::slotListViewItemClicked);
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
    m_pHBoxLayout->addWidget(m_pDListView, 3);
    m_pHBoxLayout->addWidget(m_pStackWidget, 8);

    DFontSizeManager::instance()->bind(m_pDListView, DFontSizeManager::T7);

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

void MainWindow::slotListViewItemClicked(const QModelIndex &index)
{
    QString strItemName = index.data().toString();
    qDebug() << "strItemName:" << strItemName;

    m_pStackWidget->setCurrentWidget(m_hash_ItemName_ItemWidget.value(strItemName));
}


