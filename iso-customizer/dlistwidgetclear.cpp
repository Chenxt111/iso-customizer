#include "dlistwidgetclear.h"

DListWidgetClear::DListWidgetClear(QWidget *parent)
    : DListWidget(parent)
{
    this->setMouseTracking(true);
}

void DListWidgetClear::mouseMoveEvent(QMouseEvent *e)
{
    emit indexfoucs(e);
}

void DListWidgetClear::clearData()
{
    int count = this->count();

    for(int i = 0; i < count ; i++) {
        QListWidgetItem *sel = this->item(0);

        if (this->itemWidget(sel)) {
            this->removeItemWidget( sel );
            int r = this->row(sel);
            QListWidgetItem *item = this->takeItem(r);

            delete item;
        } else {
            int r = this->row(sel);
            QListWidgetItem *item = this->takeItem(r);

            delete item;
        }
        sel = nullptr;
        delete sel;
    }
}

void DListWidgetClear::clearButtnCliked(const QPoint &locat)
{
    if ( this->itemAt(locat) ) {
        QListWidgetItem *sel = this->itemAt(locat);
        if ( this->itemWidget( sel ) ) {
            this->removeItemWidget( sel );
            int r = this->row(sel);
            QListWidgetItem *item = this->takeItem(r);
            delete item;
            emit creatWidget();
        }
    }
}
