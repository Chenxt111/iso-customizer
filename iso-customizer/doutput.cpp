#include "doutput.h"

DOutPut::DOutPut(QWidget *parent)
    : QWidget(parent)
    , successFlag(false)
{
    m_ptimer = new QTimer();
    m_ptimer->setInterval(100);
    connect(m_ptimer, &QTimer::timeout, this, &DOutPut::slotTimerOut);

    pMainLayout = new QVBoxLayout () ;

    QHBoxLayout *HBoxLayoutLabel = new QHBoxLayout () ;
    pDlabel = new DLabel (QString(tr("准备输出"))) ;
    QFont fontBold;
    fontBold.setBold(true);
    pDlabel->setFont(fontBold);
    DFontSizeManager::instance()->bind(pDlabel, DFontSizeManager::T3);
    HBoxLayoutLabel->addStretch(1);
    HBoxLayoutLabel->addWidget(pDlabel);
    HBoxLayoutLabel->addStretch(1);
    pMainLayout->addStretch(1);
    pMainLayout->addLayout(HBoxLayoutLabel);

    HBoxLayoutWater = new QHBoxLayout () ;
    m_pDWaterProgress = new DWaterProgress();
    m_pDWaterProgress->setTextVisible(false);
    m_pDWaterProgress->setValue(m_valus);
    HBoxLayoutWater->addStretch(1);
    HBoxLayoutWater->addWidget(m_pDWaterProgress);
    HBoxLayoutWater->addStretch(1);

    HBoxLayoutSuccess = new QHBoxLayout () ;
    pDSuccessBtn = new DIconButton (nullptr);
//    pDSuccessBtn->setFlat(true);
    DPalette pa = DApplicationHelper::instance()->palette(pDSuccessBtn);
    pa.setColor(DPalette::Button, Qt::white);
    pDSuccessBtn->setPalette(pa);
    pDSuccessBtn->setAutoFillBackground(true);
    pDSuccessBtn->setFlat(true);
    pDSuccessBtn->setIcon(QIcon(":/icons/deepin/builtin/progress.svg"));
    pDSuccessBtn->setIconSize(QSize(100, 100));
    HBoxLayoutSuccess->addStretch(1);
    HBoxLayoutSuccess->addWidget(pDSuccessBtn);
    HBoxLayoutSuccess->addStretch(1);
//    pDSuccessBtn->setHidden(true);
    pDSuccessLabel = new DLabel(tr("制作成功"));
    DFontSizeManager::instance()->bind(pDSuccessLabel, DFontSizeManager::T9);
    HBoxSuccessLabel = new QHBoxLayout () ;
    HBoxSuccessLabel->addStretch(1);
    HBoxSuccessLabel->addWidget(pDSuccessLabel);
    HBoxSuccessLabel->addStretch(1);

    pMainLayout->addStretch(5);
    pMainLayout->addLayout(HBoxLayoutWater);
    pMainLayout->addStretch(4);

    QHBoxLayout *pHboxLayout3 = new QHBoxLayout();
    pNextBtn = new DPushButton();
    pNextBtn->setText(tr("下一步"));
    pNextBtn->setFixedSize(260, 35);
    pHboxLayout3->addStretch(1);
    pHboxLayout3->addWidget(pNextBtn);
    pHboxLayout3->addStretch(1);
    pMainLayout->addLayout(pHboxLayout3);
    pMainLayout->addStretch(2);

    pHboxBtnSuccess = new QHBoxLayout();
    DPushButton *pOkBtn = new DPushButton();
    pOkBtn->setText(tr("完成"));
    pOkBtn->setFixedSize(260, 35);

    DPushButton *pViewBtn = new DPushButton();
    pViewBtn->setText(tr("查看文件"));

    pViewBtn->setFixedSize(260, 35);
    pHboxBtnSuccess->addStretch(1);
    pHboxBtnSuccess->addWidget(pOkBtn);
    pHboxBtnSuccess->addStretch(1);
    pHboxBtnSuccess->addWidget(pViewBtn);
    pHboxBtnSuccess->addStretch(1);

    connect(pNextBtn, &DPushButton::clicked, this, [=]{
        m_ptimer->start();
        m_pDWaterProgress->setTextVisible(true);
        pDlabel->setText(tr("正在输出"));

        emit nextBtnCliked();
    });
    connect(m_pDWaterProgress, &DWaterProgress::valueChanged, this, &DOutPut::manufactureComplete);

    setLayout(pMainLayout);
}

void DOutPut::slotDPuBtnClicked()
{
    ;
}

void DOutPut::slotTimerOut()
{
    m_valus += 1;
    if(m_valus >= 100)
    {
        m_valus = 100;
    }
    m_pDWaterProgress->setValue(m_valus);
    update();
}

void DOutPut::manufactureComplete()
{
    if( m_pDWaterProgress->value() == 100 ) {
        m_ptimer->stop();
    }

    if ( (m_pDWaterProgress->value() == 100) && (successFlag == true) ) {
        pDlabel->setText(tr("输出成功"));
        pMainLayout->takeAt(3);
        m_pDWaterProgress->setHidden(true);
        pNextBtn->setHidden(true);
        pMainLayout->insertLayout(3, HBoxLayoutSuccess);
        pMainLayout->insertLayout(4, HBoxSuccessLabel);
        pMainLayout->insertStretch(5, 1);
        pMainLayout->takeAt(7);
        pMainLayout->insertLayout(7, pHboxBtnSuccess);
    } else if  ( (m_pDWaterProgress->value() == 100) && (successFlag == false) ){
        pDlabel->setText("输出失败");
        pDSuccessBtn->setIcon(QIcon(":/icons/deepin/builtin/fail.svg"));
        pNextBtn->setText(tr("关闭"));
        QHBoxLayout *HBoxFailLabel = new QHBoxLayout() ;
        pDSuccessLabel->setText("制作失败");
        DFontSizeManager::instance()->bind(pDSuccessLabel, DFontSizeManager::T6);
        DLabel *pDFailLabel = new DLabel(tr("失败原因 ：未知的错误"));
        DFontSizeManager::instance()->bind(pDFailLabel, DFontSizeManager::T9);
        QVBoxLayout *VBoxFailLabel = new QVBoxLayout() ;
        VBoxFailLabel->addLayout(HBoxSuccessLabel);
        VBoxFailLabel->setSpacing(1);
        VBoxFailLabel->addWidget(pDFailLabel);

        HBoxFailLabel->addStretch(1);
        HBoxFailLabel->addLayout(VBoxFailLabel);
        HBoxFailLabel->addStretch(1);

        pMainLayout->takeAt(3);
        m_pDWaterProgress->setHidden(true);
        pMainLayout->insertLayout(3, HBoxLayoutSuccess);
        pMainLayout->insertLayout(4, HBoxFailLabel);
        pMainLayout->insertStretch(5, 1);
    }
}
