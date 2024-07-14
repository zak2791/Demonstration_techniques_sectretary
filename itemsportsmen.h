#ifndef ITEMSPORTSMEN_H
#define ITEMSPORTSMEN_H

#include <QWidget>
#include "main.h"
#include <QMouseEvent>

class ItemSportsmen : public QWidget
{
    Q_OBJECT
public:
    explicit ItemSportsmen(sportsman, int, QWidget *parent = nullptr);

private:
    //getSportsman()

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent*);
    int idSportsman;
    sportsman athlete;
    int mat = 0;

public slots:
    void updateData(int,QVector<float>,float,int);
    //void setMat(int);

signals:
    void sendOnMat(int, sportsman);

};

#endif // ITEMSPORTSMEN_H
