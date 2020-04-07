#include "dchoiceiso.h"

DChoiceIso::DChoiceIso(QWidget *parent)
    : QWidget(parent)
{
//    this->setStyleSheet("QWidget{background-color:white;border-radius:8px;}");

    QVBoxLayout *pMainLayout = new QVBoxLayout();
    pMainLayout->setSpacing(30);
    pMainLayout->addStretch();

    QHBoxLayout *pHboxLayout5 = new QHBoxLayout();
    pHboxLayout5->addStretch();
    pMainLayout->addLayout(pHboxLayout5, 1);
    DLabel *pDlabel = new DLabel(QString(tr("选择ISO:")));
    QFont fontBold;
    fontBold.setBold(true);
    pDlabel->setFont(fontBold);
    DFontSizeManager::instance()->bind(pDlabel, DFontSizeManager::T3);
    pMainLayout->addWidget(pDlabel, 1);

    QHBoxLayout *pHboxLayout1 = new QHBoxLayout();
    pHboxLayout1->addStretch();
    QHBoxLayout *pHBoxLayout3 = new QHBoxLayout();
    pHBoxLayout3->addStretch();
    pHBoxLayout3->setSpacing(20);
    DFileChooserEdit *pDFileChooserEdit = new DFileChooserEdit();
    pDFileChooserEdit->setFixedSize(500, 35);
    pMainLayout->addWidget(pDFileChooserEdit, 2);
    pMainLayout->addLayout(pHboxLayout1, 9);

    QHBoxLayout *pHboxLayout2 = new QHBoxLayout();
    pHboxLayout1->addStretch();
    DPushButton *pNextBtn = new DPushButton();
    pNextBtn->setText(tr("下一步"));
    pNextBtn->setFixedSize(260, 35);
    pHboxLayout2->addWidget(pNextBtn);
    pMainLayout->addLayout(pHboxLayout2, 1);
    QHBoxLayout *pHboxLayout4 = new QHBoxLayout();
    pHboxLayout1->addStretch();
    pMainLayout->addLayout(pHboxLayout4, 1);
//    pDFileChooserEdit->setText(QString(tr("选择ISO")));

//    pMainLayout->addStretch();

//    QGridLayout *pMainLayout = new QGridLayout();

//    DLabel *pDlabel = new DLabel(QString(tr("选择ISO:")));
//    pDlabel->setFixedSize(100, 50);
//    DFontSizeManager::instance()->bind(pDlabel, DFontSizeManager::T3);

//    DFileChooserEdit *pDFileChooserEdit = new DFileChooserEdit();
//    pDFileChooserEdit->setFixedSize(500, 35);

//    DPushButton *pNextBtn = new DPushButton();
//    pNextBtn->setText(tr("下一步"));
//    pNextBtn->setFixedSize(260, 35);

//    pMainLayout->addWidget(pDlabel, 1, 1);
//    pMainLayout->addWidget(pDFileChooserEdit, 2, 1);
//    pMainLayout->addWidget(pNextBtn, 8, 4);

    this->setLayout(pMainLayout);
}
