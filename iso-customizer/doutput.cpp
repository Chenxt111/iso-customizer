#include "doutput.h"

DOutPut::DOutPut(QWidget *parent)
    : QWidget(parent)
{
    m_ptimer = new QTimer();
    m_ptimer->setInterval(100);
    connect(m_ptimer, &QTimer::timeout, this, &DOutPut::slotTimerOut);

    QVBoxLayout *pMainLayout = new QVBoxLayout () ;

    QHBoxLayout *HBoxLayoutLabel = new QHBoxLayout () ;
    DLabel *pDlabel = new DLabel (QString(tr("准备输出"))) ;
    QFont fontBold;
    fontBold.setBold(true);
    pDlabel->setFont(fontBold);
    DFontSizeManager::instance()->bind(pDlabel, DFontSizeManager::T3);
    HBoxLayoutLabel->addStretch(1);
    HBoxLayoutLabel->addWidget(pDlabel);
    HBoxLayoutLabel->addStretch(1);
    pMainLayout->addStretch(1);
    pMainLayout->addLayout(HBoxLayoutLabel);

    QHBoxLayout *HBoxLayoutWater = new QHBoxLayout () ;
    m_pDWaterProgress = new DWaterProgress();
    m_pDWaterProgress->setTextVisible(false);
    m_pDWaterProgress->setValue(m_valus);
    HBoxLayoutWater->addStretch(1);
    HBoxLayoutWater->addWidget(m_pDWaterProgress);
    HBoxLayoutWater->addStretch(1);
    pMainLayout->addStretch(3);
    pMainLayout->addLayout(HBoxLayoutWater);
    pMainLayout->addStretch(2);

    QHBoxLayout *pHboxLayout3 = new QHBoxLayout();
    DPushButton *pNextBtn = new DPushButton();
    pNextBtn->setText(tr("下一步"));
    pNextBtn->setFixedSize(260, 35);
    pHboxLayout3->addStretch(1);
    pHboxLayout3->addWidget(pNextBtn);
    pHboxLayout3->addStretch(1);
    pMainLayout->addLayout(pHboxLayout3);
    pMainLayout->addStretch(1);

    connect(pNextBtn, &DPushButton::clicked, this, [=]{
        emit nextBtnCliked();
    });

    setLayout(pMainLayout);
}

void DOutPut::slotDPuBtnClicked()
{
    ;
}

void DOutPut::slotTimerOut()
{
    m_valus += 1;
    if(m_valus == 100)
    {
        m_valus = 0;
    }
    m_pDWaterProgress->setValue(m_valus);
    update();
}
