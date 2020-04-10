#include "mainwindow.h"

MainWindow::MainWindow(DMainWindow *parent)
    : DMainWindow(parent)
    , m_pViewWidget(new QWidget())
    , m_pListVBoxLayout(new QVBoxLayout())
    , m_pCentralWidget(new QWidget())
    , m_pStackWidget(new QStackedWidget())
    , m_pChoiceIso(new DChoiceIso)
    , m_pDListView(new DListView)
    , m_pChoiceArchitecture(new DChoiceArchitecture)
    , m_pProgarmConf(new DProgramConf)
    , m_pPreparation(new DPreparation)
    , m_pMidTermInstallation(new DMidTermInstallation)
    , m_pPostCleaning(new DPostCleaning)
    , m_pChoiceKernel(new DChoiceKernel)
    , m_pOutPut(new DOutPut)
    , pItemchoiceArchitectureflag(false)
    , pItemProgramConfflag(false)
    , pItemPreparationflag(false)
    , pItemMidTermInstallationflag(false)
    , pItemPostCleaningflag(false)
    , pItemChoiceKernelflag(false)
    , pItemOutPutflag(false)
{
    initUI();
    settingsInit();

    //titlebar 设置标题栏
    titlebar()->setIcon(QIcon::fromTheme("iso定制工具-32px"));
    const QString str = "ISO定制工具";
    titlebar()->setTitle(str);

    QVBoxLayout *pVBoxLayout = new QVBoxLayout();
    pVBoxLayout->setSpacing(40);

    pItemModel = new QStandardItemModel(this);
//    DListWidget *pDListWidget = new DListWidget();

    QStandardItem *pItemchoiceISO = new QStandardItem("选择ISO");
    pItemchoiceISO->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive1.svg"));
    pItemchoiceISO->setText(tr("选择ISO"));
    m_pStackWidget->addWidget(m_pChoiceIso);
    m_hash_ItemName_ItemWidget.insert("选择ISO", m_pChoiceIso);
    pItemModel->appendRow(pItemchoiceISO);

    QStandardItem *pItemchoiceArchitecture = new QStandardItem("选择架构");
    pItemchoiceArchitecture->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive2.svg"));
    pItemchoiceArchitecture->setText(tr("选择架构"));
    pItemchoiceArchitecture->setEnabled(false);
//    pItemchoiceArchitecture->setToolTip("1111");
    m_pStackWidget->addWidget(m_pChoiceArchitecture);
    m_hash_ItemName_ItemWidget.insert("选择架构", m_pChoiceArchitecture);
    pItemModel->appendRow(pItemchoiceArchitecture);

    QStandardItem *pItemProgramConf = new QStandardItem("程序配置");
    pItemProgramConf->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive3.svg"));
    pItemProgramConf->setText(tr("程序配置"));
    pItemProgramConf->setEnabled(false);
    m_pStackWidget->addWidget(m_pProgarmConf);
    m_hash_ItemName_ItemWidget.insert("程序配置", m_pProgarmConf);
    pItemModel->appendRow(pItemProgramConf);

    QStandardItem *pItemPreparation = new QStandardItem("前期准备");
    pItemPreparation->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive4.svg"));
    pItemPreparation->setText(tr("前期准备"));
    pItemPreparation->setEnabled(false);
    m_pStackWidget->addWidget(m_pPreparation);
    m_hash_ItemName_ItemWidget.insert("前期准备", m_pPreparation);
    pItemModel->appendRow(pItemPreparation);

    QStandardItem *pItemMidTermInstallation = new QStandardItem("中期安装");
    pItemMidTermInstallation->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive5.svg"));
    pItemMidTermInstallation->setText(tr("中期安装"));
    pItemMidTermInstallation->setEnabled(false);
    m_pStackWidget->addWidget(m_pMidTermInstallation);
    m_hash_ItemName_ItemWidget.insert("中期安装", m_pMidTermInstallation);
    pItemModel->appendRow(pItemMidTermInstallation);

    QStandardItem *pItemPostCleaning = new QStandardItem("后期清理");
    pItemPostCleaning->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive6.svg"));
    pItemPostCleaning->setText(tr("后期清理"));
    pItemPostCleaning->setEnabled(false);
    m_pStackWidget->addWidget(m_pPostCleaning);
    m_hash_ItemName_ItemWidget.insert("后期清理", m_pPostCleaning);
    pItemModel->appendRow(pItemPostCleaning);

    QStandardItem *pItemChoiceKernel = new QStandardItem("选择Kernel");
    pItemChoiceKernel->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive7.svg"));
    pItemChoiceKernel->setText(tr("选择Kernel"));
    pItemChoiceKernel->setEnabled(false);
    m_pStackWidget->addWidget(m_pChoiceKernel);
    m_hash_ItemName_ItemWidget.insert("选择Kernel", m_pChoiceKernel);
    pItemModel->appendRow(pItemChoiceKernel);

    QStandardItem *pItemOutPut = new QStandardItem("输出");
    pItemOutPut->setIcon(QIcon(":/icons/deepin/builtin/NO_inactive8.svg"));
    pItemOutPut->setText(tr("输出"));
    pItemOutPut->setEnabled(false);
    m_pStackWidget->addWidget(m_pOutPut);
    m_hash_ItemName_ItemWidget.insert("输出", m_pOutPut);
    pItemModel->appendRow(pItemOutPut);

    m_pDListView->setModel(pItemModel);
    m_pDListView->setCurrentIndex(m_pDListView->model()->index(0, 0));
    m_pDListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_pStackWidget->setCurrentWidget(m_pChoiceIso);
    connect(m_pDListView, &DListView::clicked, this, &MainWindow::slotListViewItemClicked);
    m_pDListView->setShortcutEnabled(2, false);


    connect(m_pChoiceIso, &DChoiceIso::nextBtnCliked, this, &MainWindow::slotListViewItemChange);
    connect(m_pChoiceArchitecture, &DChoiceArchitecture::nextBtnCliked, this, &MainWindow::slotListViewItemChange);
    connect(m_pProgarmConf, &DProgramConf::nextBtnCliked, this, &MainWindow::slotListViewItemChange);
    connect(m_pPreparation, &DPreparation::nextBtnCliked, this, &MainWindow::slotListViewItemChange);
    connect(m_pMidTermInstallation, &DMidTermInstallation::nextBtnCliked, this, &MainWindow::slotListViewItemChange);
    connect(m_pPostCleaning, &DPostCleaning::nextBtnCliked, this, &MainWindow::slotListViewItemChange);
    connect(m_pChoiceKernel, &DChoiceKernel::nextBtnCliked, this, &MainWindow::slotListViewItemChange);
    connect(m_pOutPut, &DOutPut::nextBtnCliked, this, [=]{
        pItemOutPut->setCheckState(Qt::Checked);
    });

    m_pCentralWidget->setLayout(m_pHBoxLayout);
    setCentralWidget(m_pCentralWidget);
}

MainWindow::~MainWindow()
{
    ;
}

void MainWindow::initUI()
{
    this->setWindowFlags(0);
    // 设置禁止最大化
    this->setFixedSize(807, 607);

    m_pListVBoxLayout->addSpacing(10);
    m_pListVBoxLayout->addWidget(m_pDListView);
    m_pViewWidget->setLayout(m_pListVBoxLayout);

    m_pHBoxLayout = new QHBoxLayout();
    m_pHBoxLayout->setSpacing(10);
    m_pHBoxLayout->addWidget(m_pViewWidget, 3);
    m_pHBoxLayout->addWidget(m_pStackWidget, 8);

    DFontSizeManager::instance()->bind(m_pDListView, DFontSizeManager::T7);
    m_pViewWidget->setStyleSheet("QWidget{background-color:White;border-top-left-radius:10px;border-top-right-radius:10px;border-bottom-left-radius:10px;border-bottom-right-radius:10px;}");
    m_pStackWidget->setStyleSheet("QStackedWidget{background-color:White;border-top-left-radius:10px;border-top-right-radius:10px;border-bottom-left-radius:10px;border-bottom-right-radius:10px;}");

}

void MainWindow::initConnections(QStandardItem *pItem)
{
    ;
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

    QModelIndex tempModel = index;
    QStandardItem *tempItem = pItemModel->itemFromIndex(tempModel);

//    m_pStackWidget->setCurrentWidget(m_hash_ItemName_ItemWidget.value(strItemName));
    if(tempItem->isEnabled())
    {
        m_pStackWidget->setCurrentWidget(m_hash_ItemName_ItemWidget.value(strItemName));
    }
}

void MainWindow::slotListViewItemChange()
{
    int row = m_pDListView->currentIndex().row();

    QModelIndex tempModel = m_pDListView->model()->index(row, 0);
    QStandardItem *tempItem = pItemModel->itemFromIndex(tempModel);
    if( !tempItem->checkState() ) {
        tempItem->setCheckState(Qt::Checked);
    }

    row++;

    QModelIndex tempModel1 = m_pDListView->model()->index(row, 0);
    QStandardItem *tempItem1 = pItemModel->itemFromIndex(tempModel1);
    tempItem1->setEnabled(true);
    m_pDListView->setCurrentIndex(tempModel1);
    m_pDListView->clicked(tempItem1->index());

    m_pStackWidget->setCurrentWidget(m_hash_ItemName_ItemWidget.value(tempItem1->text()));
}



