#include "eventscrollbar.h"

EventScrollBar::EventScrollBar(QObject* pobj/*= О*/) : QObject(pobj) {

}

bool EventScrollBar::eventFilter(QObject* pobj, QEvent* pe){
    if (pe->type() == QEvent::Show)
        emit sigShowHide(true);
    if (pe->type() == QEvent::Hide)
        emit sigShowHide(false);
    return false;
}
