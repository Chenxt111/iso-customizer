#ifndef DLISTWIDGETCLEAR_H
#define DLISTWIDGETCLEAR_H

#include <DListWidget>
#include <DWidget>

#include <QDebug>

DWIDGET_USE_NAMESPACE

class DListWidgetClear : public DListWidget
{
    Q_OBJECT
public:
    explicit DListWidgetClear(QWidget *parent = nullptr);
    void clearData();

private:
    virtual void mouseMoveEvent(QMouseEvent *e) override;

signals:
    void indexfoucs(QMouseEvent *e);
    void creatWidget();

public slots:
    void clearButtnCliked(const QPoint &locat);

};

#endif // DLISTWIDGETCLEAR_H
