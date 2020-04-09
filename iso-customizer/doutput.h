#ifndef DOUTPUT_H
#define DOUTPUT_H

#include <DWidget>
#include <DLabel>
#include <DPushButton>
#include <DFontSizeManager>
#include <DWaterProgress>

#include <QWidget>
#include <QHBoxLayout>
#include <QBoxLayout>
#include <QTimer>

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

private:
    QTimer *m_ptimer;
    DWaterProgress *m_pDWaterProgress;
    int m_valus = 0;
    DPushButton *m_pDPushButton;
};

#endif // DOUTPUT_H
