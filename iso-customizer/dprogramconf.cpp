#include "dprogramconf.h"

DProgramConf::DProgramConf(QWidget *parent)
    : QWidget(parent)
    , pFileNameList(new QStringList())
    , pCenterBox(new DGroupBox())
    , groupVBox(new QVBoxLayout())
    , pListVBox(new DListView())
    , pDListWidgetClear(new DListWidgetClear())
    , pWidget(new QWidget())
    , pHBLayout(new QHBoxLayout())
    , pMainLayout(new QVBoxLayout())
    , pCenterLabel(new DLabel(QString(tr("请选择程序"))))
    , pDCommandLinkButtonClear(new DCommandLinkButton(tr("全部清除")))
{
    pMainLayout->setSpacing(20);
    pMainLayout->addStretch(8);

    QHBoxLayout *pDlabelSpace = new QHBoxLayout();
    DLabel *pDlabel = new DLabel(QString(tr("程序配置")));
//    DCommandLinkButton *pDCommandLinkButtonClear = new DCommandLinkButton(tr("全部清除"));
    pDCommandLinkButtonClear->setHidden(true);
    connect(pDCommandLinkButtonClear, &DCommandLinkButton::clicked, this, &DProgramConf::ClearbuttonClicked);
    QFont fontBold;
    fontBold.setBold(true);
    pDlabel->setFont(fontBold);
    DFontSizeManager::instance()->bind(pDlabel, DFontSizeManager::T3);
    pDlabelSpace->addStretch(1);
    pDlabelSpace->addWidget(pDlabel);
    pDlabelSpace->addStretch(18);
    pDlabelSpace->addWidget(pDCommandLinkButtonClear);
    pDlabelSpace->addStretch(1);
    pMainLayout->addLayout(pDlabelSpace);

//    pListVBox->setFixedHeight(350);
    pDListWidgetClear->setFixedHeight(350);
//    pMainLayout->addWidget(pListVBox);

    DFontSizeManager::instance()->bind(pCenterLabel, DFontSizeManager::T2);
    DPalette pa = DApplicationHelper::instance()->palette(pCenterLabel);
    QColor color(Qt::gray);
    pa.setColor(DPalette::WindowText, color);
    pCenterLabel->setPalette(pa);
    pCenterLabel->setAlignment(Qt::AlignCenter);
    pCenterLabel->setFixedHeight(350);
//    pCenterLabel->setHidden(true);
    pMainLayout->addWidget(pCenterLabel);

    pWidget->setMouseTracking(true);
    pHBLayout = new QHBoxLayout();
    pHBLayout->setSpacing(10);
    pDIconButtonClear = new DIconButton(nullptr);
    pDIconButtonClear->setIcon(QIcon(":/icons/deepin/builtin/清除.svg"));
    pDIconButtonClear->setFlat(true);
    pDIconButtonClear->setIconSize(QSize(30, 30));
    pDIconButtonClear->setHidden(false);
    pHBLayout->addStretch(2);
    pHBLayout->addWidget(pDIconButtonClear);

    pWidget->setLayout(pHBLayout);

    QHBoxLayout *pHboxLayoutChoice = new QHBoxLayout();
    DCommandLinkButton *pDCommandLinkButtonChoice = new DCommandLinkButton(tr("选择程序deb包"));
    pDCommandLinkButtonChoice->setHidden(false);
    connect(pDCommandLinkButtonChoice, &DCommandLinkButton::clicked, this, &DProgramConf::LinkbuttonClicked);

    pHboxLayoutChoice->addStretch(1);
    pHboxLayoutChoice->addWidget(pDCommandLinkButtonChoice);
    pHboxLayoutChoice->addStretch(1);
    pMainLayout->addLayout(pHboxLayoutChoice);


    QHBoxLayout *pHboxLayout3 = new QHBoxLayout();
    DPushButton *pNextBtn = new DPushButton();
    pNextBtn->setText(tr("下一步"));
    pNextBtn->setFixedSize(260, 35);
    pHboxLayout3->addStretch(1);
    pHboxLayout3->addWidget(pNextBtn);
    pHboxLayout3->addStretch(1);
    pMainLayout->addLayout(pHboxLayout3);
    pMainLayout->addStretch(1);

    connect(pDListWidgetClear, &DListWidgetClear::indexfoucs, this, &DProgramConf::itemFoucs);
    connect(pDIconButtonClear, &DIconButton::clicked, this, [=]{
        QPoint local = pDIconButtonClear->mapTo(pWidget, pWidget->pos());
        qDebug() << "locat = " << local;

        emit iconBtnCliked(local);
    });
    connect(this, &DProgramConf::iconBtnCliked, pDListWidgetClear, &DListWidgetClear::clearButtnCliked);
    connect(pDListWidgetClear, &DListWidgetClear::creatWidget, this, [=]{
        pWidget = new QWidget () ;
        pWidget->setMouseTracking(true);
        pWidget->setLayout(pHBLayout);

        if (pDListWidgetClear->count() == 0) {
            pDListWidgetClear->setHidden(true);
            pCenterLabel->setHidden(false);
            pDCommandLinkButtonClear->setHidden(true);
//            delete  pDListWidgetClear;
//            pDListWidgetClear = new DListWidgetClear();
        }
    });

    setLayout(pMainLayout);
}

void DProgramConf::LinkbuttonClicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);

    //设置默认文件路径
    fileDialog->setDirectory("/home/cxt");
    //设置文件过滤器
    fileDialog->setNameFilter(tr("*.deb"));
    //设置可以选择多个文件,默认为只能选择一个文件QFileDialog::ExistingFiles
    fileDialog->setFileMode(QFileDialog::ExistingFiles);
    //设置视图模式
    fileDialog->setViewMode(QFileDialog::Detail);
    //打印所有选择的文件的路径
    QStringList fileNames;
    if ( fileDialog->exec() ) {
       fileNames = fileDialog->selectedFiles();
    }
    if (!pFileNameList->isEmpty()) {
        pFileNameList->clear();
    }
    for ( auto tmp : fileNames ) {
       qDebug() << tmp << endl;
       pFileNameList->push_front(tmp);
    }

    if ( !pFileNameList->isEmpty() ) {
        pCenterLabel->setHidden(true);
        pDListWidgetClear->setHidden(false);
        pMainLayout->insertWidget(2, pDListWidgetClear);
//        QStandardItemModel *pItemModel = new QStandardItemModel(this);
        for ( auto tmp : *pFileNameList ) {
            QListWidgetItem *pItemtmp= new QListWidgetItem(tmp);
            QFileIconProvider icon;
            pItemtmp->setIcon(icon.icon(tmp));
            pItemtmp->setSizeHint(QSize(540, 50));
            pDListWidgetClear->addItem(pItemtmp);
            qDebug() << "ok" << endl;
        }
        pDCommandLinkButtonClear->setHidden(false);
    } else {
        pDListWidgetClear->setHidden(true);
        pCenterLabel->setHidden(false);
        pDCommandLinkButtonClear->setHidden(true);
    }
}

void DProgramConf::ClearbuttonClicked()
{
    pFileNameList->clear();
    pDListWidgetClear->clearData();

    pDListWidgetClear->setHidden(true);
    pCenterLabel->setHidden(false);
    pDCommandLinkButtonClear->setHidden(true);
}

void DProgramConf::itemFoucs(QMouseEvent *e)
{
    for(int i = 0; i < pDListWidgetClear->count() ; i++) {
        QListWidgetItem *sel = pDListWidgetClear->item(i);

        if (pDListWidgetClear->itemWidget(sel)) {
            pDListWidgetClear->removeItemWidget(sel);
            pWidget = new QWidget () ;
            pWidget->setMouseTracking(true);
            pWidget->setLayout(pHBLayout);
        }
        sel = nullptr;
        delete sel;
    }
    if ( pDListWidgetClear->itemAt(e->pos()) ) {
            pDListWidgetClear->setItemWidget(pDListWidgetClear->itemAt(e->pos()), pWidget);
    }
}
