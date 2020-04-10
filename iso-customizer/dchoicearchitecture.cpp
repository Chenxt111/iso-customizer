#include "dchoicearchitecture.h"

DChoiceArchitecture::DChoiceArchitecture(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    pMainLayout->setSpacing(10);
    pMainLayout->addStretch(2);

    QHBoxLayout *pDlabelSpace = new QHBoxLayout();
    DLabel *pDlabel = new DLabel(QString(tr("选择架构")));
    QFont fontBold;
    fontBold.setBold(true);
    pDlabel->setFont(fontBold);
    DFontSizeManager::instance()->bind(pDlabel, DFontSizeManager::T3);
    pDlabelSpace->addStretch(1);
    pDlabelSpace->addWidget(pDlabel);
    pDlabelSpace->addStretch(20);
    pMainLayout->addLayout(pDlabelSpace);

    QHBoxLayout *pListBox = new QHBoxLayout();
    DListViewRest *pListView = new DListViewRest();
    QStandardItemModel *pItemModel = new QStandardItemModel(this);

    pItemARM = new QStandardItem("ARM");
    pItemARM->setFlags(Qt::ItemIsEnabled);
    pItemModel->appendRow(pItemARM);

    pItemX86 = new QStandardItem("X86");
    pItemX86->setFlags(Qt::ItemIsEnabled);
//    pItemX86->setCheckState(Qt::Checked);
    pItemModel->appendRow(pItemX86);

    pItemMIPS = new QStandardItem("MIPS");
    pItemMIPS->setFlags(Qt::ItemIsEnabled);
    pItemModel->appendRow(pItemMIPS);

    pListView->setModel(pItemModel);
    pListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    pListBox->addWidget(pListView);
    pMainLayout->addLayout(pListBox);
    pMainLayout->addStretch(15);

    QHBoxLayout *pHboxLayout3 = new QHBoxLayout();
    pNextBtn = new DPushButton();
    pNextBtn->setText(tr("下一步"));
    pNextBtn->setFixedSize(260, 35);
    pNextBtn->setEnabled(false);
    pHboxLayout3->addStretch(1);
    pHboxLayout3->addWidget(pNextBtn);
    pHboxLayout3->addStretch(1);
    pMainLayout->addLayout(pHboxLayout3);
    pMainLayout->addStretch(1);

    connect(pNextBtn, &DPushButton::clicked, this, [=]{
        emit nextBtnCliked();
    });

    connect(pListView, &DListViewRest::currentChange, this, &DChoiceArchitecture::CheckIndexChangedSignal);
    setLayout(pMainLayout);
}

void DChoiceArchitecture::CheckIndexChangedSignal(const QModelIndex &current, const QModelIndex &previous)
{
    pNextBtn->setEnabled(true);

    switch (previous.row()) {
        case 0: pItemARM->setCheckState(Qt::Unchecked);
            break;
        case 1: pItemX86->setCheckState(Qt::Unchecked);
            break;
        case 2: pItemMIPS->setCheckState(Qt::Unchecked);
            break;
        default: break;
    }
    switch (current.row()) {
        case 0: pItemARM->setCheckState(Qt::Checked);
            break;
        case 1: pItemX86->setCheckState(Qt::Checked);
            break;
        case 2: pItemMIPS->setCheckState(Qt::Checked);
            break;
        default: break;
    }
}


DListViewRest::DListViewRest(QWidget *parent)
    :   DListView(parent)
{

}

void DListViewRest::currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    emit currentChange(current, previous);
}






