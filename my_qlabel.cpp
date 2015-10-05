#include "my_qlabel.h"

my_qlabel::my_qlabel(QWidget *parent) :
    QLabel(parent)
{
}

void my_qlabel::mouseMoveEvent(QMouseEvent *ev)
{
    emit mouseHover();
}

void my_qlabel::leaveEvent(QEvent *)
{
    emit mouseNotHover();
}

void my_qlabel::mouseReleaseEvent(QMouseEvent *ev)
{
    emit mouseClick();
}
