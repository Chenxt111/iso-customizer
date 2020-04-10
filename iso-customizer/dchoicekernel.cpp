#include "dchoicekernel.h"

DChoiceKernel::DChoiceKernel(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    pMainLayout->setSpacing(10);
    pMainLayout->addStretch(2);

    QVBoxLayout *pVBoxLayoutKernel = new QVBoxLayout();
    QHBoxLayout *pDlabelSpace = new QHBoxLayout();
    DLabel *pDlabel = new DLabel(QString(tr("选择Kernel")));
    QFont fontBold;
    fontBold.setBold(true);
    pDlabel->setFont(fontBold);
    DFontSizeManager::instance()->bind(pDlabel, DFontSizeManager::T3);
//    pDlabelSpace->addStretch(1);
//    pDlabelSpace->addWidget(pDlabel);
//    pDlabelSpace->addStretch(20);
//    pMainLayout->addLayout(pDlabelSpace);

    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();

    pVBoxLayoutKernel->addWidget(pDlabel);
    pVBoxLayoutKernel->addSpacing(5);

    DLabel *pDlabelKernel = new DLabel(QString(tr("Kernel")));
    DFontSizeManager::instance()->bind(pDlabelKernel, DFontSizeManager::T7);
    pVBoxLayoutKernel->setSpacing(1);
    pVBoxLayoutKernel->addWidget(pDlabelKernel);

    DFileChooserEdit *pDKernelChooserEdit = new DFileChooserEdit();
    pDKernelChooserEdit->setFixedSize(520, 35);
    pVBoxLayoutKernel->addWidget(pDKernelChooserEdit);

    DLabel *pDlabelInirtd = new DLabel(QString(tr("inirtd")));
    DFontSizeManager::instance()->bind(pDlabelInirtd, DFontSizeManager::T7);
    pVBoxLayoutKernel->setSpacing(1);
    pVBoxLayoutKernel->addWidget(pDlabelInirtd);

    QStringList nameFilter;
    nameFilter.push_back(tr("*.lz"));
    DFileChooserEdit *pDInirtdChooserEdit = new DFileChooserEdit();
    pDInirtdChooserEdit->setNameFilters(nameFilter);
    pDInirtdChooserEdit->setFixedSize(520, 35);
    pVBoxLayoutKernel->addWidget(pDInirtdChooserEdit);

    pHBoxLayout2->addStretch(1);
    pHBoxLayout2->addLayout(pVBoxLayoutKernel);
    pHBoxLayout2->addStretch(1);
    pMainLayout->addLayout(pHBoxLayout2);

    pMainLayout->addStretch(15);

    QHBoxLayout *pHboxLayout3 = new QHBoxLayout();
    DPushButton *pNextBtn = new DPushButton();
    pNextBtn->setText(tr("下一步"));
    pNextBtn->setEnabled(false);
    pNextBtn->setFixedSize(260, 35);
    pHboxLayout3->addStretch(1);
    pHboxLayout3->addWidget(pNextBtn);
    pHboxLayout3->addStretch(1);
    pMainLayout->addLayout(pHboxLayout3);
    pMainLayout->addStretch(1);

    connect(pNextBtn, &DPushButton::clicked, this, [=]{
        emit nextBtnCliked();
    });
    connect(pDKernelChooserEdit, &DFileChooserEdit::textChanged, this, [=] {
        QFileInfo fileinfo(pDKernelChooserEdit->text());
        if( (!pDKernelChooserEdit->text().isEmpty()) && (fileinfo.isFile()) ) {
            pDKernelChooserEdit->setAlert(false);
            if ( (!pDInirtdChooserEdit->text().isEmpty()) && ( !pDInirtdChooserEdit->isAlert()) ) {
                pNextBtn->setEnabled(true);
            }
        } else {
            pNextBtn->setEnabled(false);
            pDKernelChooserEdit->setAlert(true);
        }
    });
    connect(pDInirtdChooserEdit, &DFileChooserEdit::textChanged, this, [=] {
        QFileInfo fileinfo(pDInirtdChooserEdit->text());
        if( (!pDInirtdChooserEdit->text().isEmpty()) && (fileinfo.isFile()) ) {
            pDInirtdChooserEdit->setAlert(false);
            if ( (!pDKernelChooserEdit->text().isEmpty()) && ( !pDKernelChooserEdit->isAlert()) ) {
                pNextBtn->setEnabled(true);
            }
        } else {
            pNextBtn->setEnabled(false);
            pDInirtdChooserEdit->setAlert(true);
        }
    });

    this->setLayout(pMainLayout);
}
