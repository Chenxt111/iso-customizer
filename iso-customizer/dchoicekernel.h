#ifndef DCHOICEKERNEL_H
#define DCHOICEKERNEL_H

#include <DLabel>
#include <DFontSizeManager>
#include <dfilechooseredit.h>
#include <DPushButton>

#include <QWidget>
#include <QStringList>
#include <QDebug>

DWIDGET_USE_NAMESPACE

class DChoiceKernel : public QWidget
{
    Q_OBJECT
public:
    explicit DChoiceKernel(QWidget *parent = nullptr);

signals:
    void nextBtnCliked();

public slots:
};

#endif // DCHOICEKERNEL_H
