#ifndef DOUTPUT_H
#define DOUTPUT_H

#include <DWidget>
#include <DLabel>
#include <DPushButton>
#include <DFontSizeManager>
#include <DWaterProgress>
#include <DIconButton>
#include <DApplicationHelper>

#include <QWidget>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QTimer>
#include <QPalette>

DWIDGET_USE_NAMESPACE

class DOutPut : public QWidget
{
    Q_OBJECT
public:
    explicit DOutPut(QWidget *parent = nullptr);

signals:
    void nextBtnCliked();

public slots:
    void slotDPuBtnClicked();
    void slotTimerOut();
    void manufactureComplete();

private:
    QTimer *m_ptimer;
    DWaterProgress *m_pDWaterProgress;
    int m_valus = 0;
    DPushButton *m_pDPushButton;
    QVBoxLayout *pMainLayout;
    DLabel *pDlabel;
    QHBoxLayout *HBoxLayoutSuccess;
    QHBoxLayout *HBoxSuccessLabel;
    QHBoxLayout *pHboxBtnSuccess;
    DIconButton *pDSuccessBtn;
    DPushButton *pNextBtn;
    DLabel *pDSuccessLabel;
    QHBoxLayout *HBoxLayoutWater;

    bool successFlag;
};

#endif // DOUTPUT_H
