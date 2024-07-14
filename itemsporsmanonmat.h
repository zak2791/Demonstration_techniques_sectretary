#ifndef ITEMSPORSMANONMAT_H
#define ITEMSPORSMANONMAT_H

#include <QWidget>
#include <QLabel>

#include "main.h"

class ItemSporsmanOnMat : public QWidget
{
    Q_OBJECT
public:
    explicit ItemSporsmanOnMat(sportsman, QWidget *parent = nullptr);

private:
    QLabel* categoryInfo = new QLabel("Категория, возраст, вес, разряд");
    QLabel* name = new QLabel("Петров Александр");
    QLabel* region = new QLabel("Брянская область");
    QLabel* range = new QLabel("МС");

    QLabel* rate_1_1 = new QLabel("1");
    QLabel* rate_1_2 = new QLabel("10.5");
    QLabel* rate_1_3 = new QLabel("10.5");
    QLabel* rate_2_1 = new QLabel("10.5");
    QLabel* rate_2_2 = new QLabel("10.5");
    QLabel* rate_2_3 = new QLabel("10.5");
    QLabel* rate_3_1 = new QLabel("10.5");
    QLabel* rate_3_2 = new QLabel("10.5");
    QLabel* rate_3_3 = new QLabel("10.5");
    QLabel* rate_4_1 = new QLabel("10.5");
    QLabel* rate_4_2 = new QLabel("10.5");
    QLabel* rate_4_3 = new QLabel("10.5");
    QLabel* rate_5_1 = new QLabel("10.5");
    QLabel* rate_5_2 = new QLabel("10.5");
    QLabel* rate_5_3 = new QLabel("10.5");

    QLabel* totalRate = new QLabel("140.5");
    QLabel* additionalRate = new QLabel("5");

    int status = 0; //0 - не отправлен
                    //1 - отправлен (жёлтый)
                    //2 - в работе  (красный)
                    //3 - отработан (зелёный)

    void paintEvent(QPaintEvent*);
};

#endif // ITEMSPORSMANONMAT_H
