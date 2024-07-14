#ifndef EVENTSCROLLBAR_H
#define EVENTSCROLLBAR_H

#include "qobject.h"
#include <QEvent>

class EventScrollBar : public QObject {
    Q_OBJECT
protected:
    virtual bool eventFilter(QObject*, QEvent*);
public:
    EventScrollBar(QObject* pobj = 0);
signals:
    void sigShowHide(bool);
};

#endif // EVENTSCROLLBAR_H
