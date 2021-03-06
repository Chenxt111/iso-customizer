#include "dchoiceiso.h"

DChoiceIso::DChoiceIso(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    pMainLayout->setSpacing(10);
    pMainLayout->addStretch(2);

    QHBoxLayout *pDlabelSpace = new QHBoxLayout();
    DLabel *pDlabel = new DLabel(QString(tr("选择ISO")));
    QFont fontBold;
    fontBold.setBold(true);
    pDlabel->setFont(fontBold);
    DFontSizeManager::instance()->bind(pDlabel, DFontSizeManager::T3);
    pDlabelSpace->addStretch(1);
    pDlabelSpace->addWidget(pDlabel);
    pDlabelSpace->addStretch(20);
    pMainLayout->addLayout(pDlabelSpace);

    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();
    DFileChooserEdit *pDFileChooserEdit = new DFileChooserEdit();
    QStringList nameFilter;
    nameFilter.push_back(tr("*.iso"));
    pDFileChooserEdit->setNameFilters(nameFilter);
    pDFileChooserEdit->setFixedSize(500, 35);
    pHBoxLayout2->addStretch(1);
    pHBoxLayout2->addWidget(pDFileChooserEdit);
    pHBoxLayout2->addStretch(1);
    pMainLayout->addLayout(pHBoxLayout2);

    pMainLayout->addStretch(15);

    QHBoxLayout *pHboxLayout3 = new QHBoxLayout();
    DPushButton *pNextBtn = new DPushButton();
    pNextBtn->setEnabled(false);
    pNextBtn->setText(tr("下一步"));
    pNextBtn->setFixedSize(260, 35);
    pHboxLayout3->addStretch(1);
    pHboxLayout3->addWidget(pNextBtn);
    pHboxLayout3->addStretch(1);
    pMainLayout->addLayout(pHboxLayout3);
    pMainLayout->addStretch(1);

    connect(pDFileChooserEdit, &DFileChooserEdit::textChanged, this, [=] {
        QFileInfo fileinfo(pDFileChooserEdit->text());
        if( (!pDFileChooserEdit->text().isEmpty()) && (fileinfo.isFile()) ) {
            pNextBtn->setEnabled(true);
            pDFileChooserEdit->setAlert(false);
        } else {
            pNextBtn->setEnabled(false);
            pDFileChooserEdit->setAlert(true);
        }
    });
    connect(pNextBtn, &DPushButton::clicked, this, [=]{
        emit nextBtnCliked();
    });

    this->setLayout(pMainLayout);
}
