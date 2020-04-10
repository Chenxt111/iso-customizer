#ifndef DCHOICEISO_H
#define DCHOICEISO_H

#include <DLabel>
#include <DFontSizeManager>
#include <dfilechooseredit.h>
#include <DPushButton>

#include <QLabel>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QDebug>
#include <QString>
#include <QFileInfo>

DWIDGET_USE_NAMESPACE

class DChoiceIso : public QWidget
{
    Q_OBJECT
public:
    explicit DChoiceIso(QWidget *parent = nullptr);

signals:
    void nextBtnCliked();
};

#endif // DCHOICEISO_H
