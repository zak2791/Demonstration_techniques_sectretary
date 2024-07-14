#include "itemsportsmen.h"
#include "database.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QPainterPath>

ItemSportsmen::ItemSportsmen(sportsman s, int n, QWidget *parent) : QWidget{parent} {
    athlete = s;

    QHBoxLayout* layout = new QHBoxLayout(this);
    QLabel* num = new QLabel(QString::number(n));
    num->setAlignment(Qt::AlignCenter);
    QLabel* name = new QLabel(s.name);


    QLabel* region = new QLabel(s.region);

    QLabel* range = new QLabel(s.range);
    range->setAlignment(Qt::AlignCenter);

    QLabel* rate = new QLabel("");
    rate->setAlignment(Qt::AlignCenter);

    QLabel* secondRate = new QLabel("");
    secondRate->setAlignment(Qt::AlignCenter);

    QLabel* place = new QLabel("");
    place->setAlignment(Qt::AlignCenter);

    layout->addWidget(num);
    layout->addWidget(name);
    layout->addWidget(region);
    layout->addWidget(range);
    layout->addWidget(rate);
    layout->addWidget(secondRate);
    layout->addWidget(place);

    num->setFixedWidth(40);

    range->setFixedWidth(60);
    rate->setFixedWidth(60);
    secondRate->setFixedWidth(60);
    place->setFixedWidth(60);
    //show();
    idSportsman = s.id;

}

void ItemSportsmen::paintEvent(QPaintEvent *)
{

    QPainter p(this);

    QPainterPath path;
    path.addRoundedRect(1, 1, width() - 2, height() - 2, 5, 5);
    QPen pen(Qt::black);
    p.setPen(pen);
    if(athlete.status == 1)
        p.fillPath(path, Qt::lightGray);
    else
        p.fillPath(path, Qt::white);

    p.drawPath(path);

}

void ItemSportsmen::mousePressEvent(QMouseEvent * e)
{
    qDebug()<<athlete.status;
    if(athlete.status == 0){
        emit sendOnMat(idSportsman, athlete);
        athlete.status = 1;
    }
    qDebug()<<athlete.status;
    update();
}

//////////////////////////////////////////////////
/// Обновление данных по сигналу с базы данных ///
//////////////////////////////////////////////////
void ItemSportsmen::updateData(int id, QVector<float>, float total, int second_rate)
{
        if(id != idSportsman)
        return;

}

// void ItemSportsmen::setMat(int index)
// {
//     mat = index;
// }
























