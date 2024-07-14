#include "itemsporsmanonmat.h"

#include <QBoxLayout>
#include <QPainterPath>
#include <QPen>
#include <QPainter>

ItemSporsmanOnMat::ItemSporsmanOnMat (sportsman s, QWidget* parent) : QWidget {parent} {
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QVBoxLayout* nameLayout = new QVBoxLayout(this);
    QVBoxLayout* rate1Layout = new QVBoxLayout(this);
    QVBoxLayout* rate2Layout = new QVBoxLayout(this);
    QVBoxLayout* rate3Layout = new QVBoxLayout(this);
    QVBoxLayout* rate4Layout = new QVBoxLayout(this);
    QVBoxLayout* rate5Layout = new QVBoxLayout(this);
    QHBoxLayout* nameRegionLayout = new QHBoxLayout(this);
    QHBoxLayout* rateLayout = new QHBoxLayout(this);

    int style = 2 | 0x20;

    name->setMinimumWidth(150);
    name->setFrameStyle(style);
    name->setText(s.name);

    region->setMinimumWidth(150);
    region->setFrameStyle(style);
    region->setText(s.region);

    range->setFixedWidth(40);
    range->setFrameStyle(style);
    range->setAlignment(Qt::AlignCenter);
    range->setText(s.range);

    categoryInfo->setFrameStyle(style);
    categoryInfo->setText(s.category + ", " + s.age + ", " + s.weight);

    rate_1_1->setFixedWidth(30);
    rate_1_1->setFrameStyle(style);
    rate_1_1->setAlignment(Qt::AlignCenter);
    rate_1_2->setFixedWidth(30);
    rate_1_2->setFrameStyle(style);
    rate_1_2->setAlignment(Qt::AlignCenter);
    rate_1_3->setFixedWidth(30);
    rate_1_3->setFrameStyle(style);
    rate_1_3->setAlignment(Qt::AlignCenter);
    rate_2_1->setFixedWidth(30);
    rate_2_1->setFrameStyle(style);
    rate_2_1->setAlignment(Qt::AlignCenter);
    rate_2_2->setFixedWidth(30);
    rate_2_2->setFrameStyle(style);
    rate_2_2->setAlignment(Qt::AlignCenter);
    rate_2_3->setFixedWidth(30);
    rate_2_3->setFrameStyle(style);
    rate_2_3->setAlignment(Qt::AlignCenter);
    rate_3_1->setFixedWidth(30);
    rate_3_1->setFrameStyle(style);
    rate_3_1->setAlignment(Qt::AlignCenter);
    rate_3_2->setFixedWidth(30);
    rate_3_2->setFrameStyle(style);
    rate_3_2->setAlignment(Qt::AlignCenter);
    rate_3_3->setFixedWidth(30);
    rate_3_3->setFrameStyle(style);
    range->setAlignment(Qt::AlignCenter);
    rate_4_1->setFixedWidth(30);
    rate_4_1->setFrameStyle(style);
    range->setAlignment(Qt::AlignCenter);
    rate_4_2->setFixedWidth(30);
    rate_4_2->setFrameStyle(style);
    rate_4_2->setAlignment(Qt::AlignCenter);
    rate_4_3->setFixedWidth(30);
    rate_4_3->setFrameStyle(style);
    rate_4_3->setAlignment(Qt::AlignCenter);
    rate_5_1->setFixedWidth(30);
    rate_5_1->setFrameStyle(style);
    rate_5_1->setAlignment(Qt::AlignCenter);
    rate_5_2->setFixedWidth(30);
    rate_5_2->setFrameStyle(style);
    rate_5_2->setAlignment(Qt::AlignCenter);
    rate_5_3->setFixedWidth(30);
    rate_5_3->setFrameStyle(style);
    rate_5_3->setAlignment(Qt::AlignCenter);

    totalRate->setFixedWidth(50);
    totalRate->setFrameStyle(style);
    totalRate->setAlignment(Qt::AlignCenter);
    additionalRate->setFixedWidth(50);
    additionalRate->setFrameStyle(style);
    additionalRate->setAlignment(Qt::AlignCenter);

    nameRegionLayout->addWidget(name);
    nameRegionLayout->addWidget(region);
    nameRegionLayout->addWidget(range);

    nameLayout->addWidget(categoryInfo);
    nameLayout->addLayout(nameRegionLayout);

    rate1Layout->addWidget(rate_1_1);
    rate1Layout->addWidget(rate_1_2);
    rate1Layout->addWidget(rate_1_3);

    rate2Layout->addWidget(rate_2_1);
    rate2Layout->addWidget(rate_2_2);
    rate2Layout->addWidget(rate_2_3);

    rate3Layout->addWidget(rate_3_1);
    rate3Layout->addWidget(rate_3_2);
    rate3Layout->addWidget(rate_3_3);

    rate4Layout->addWidget(rate_4_1);
    rate4Layout->addWidget(rate_4_2);
    rate4Layout->addWidget(rate_4_3);

    rate5Layout->addWidget(rate_5_1);
    rate5Layout->addWidget(rate_5_2);
    rate5Layout->addWidget(rate_5_3);

    rateLayout->addLayout(rate1Layout);
    rateLayout->addLayout(rate2Layout);
    rateLayout->addLayout(rate3Layout);
    rateLayout->addLayout(rate4Layout);
    rateLayout->addLayout(rate5Layout);

    mainLayout->addLayout(nameLayout);
    // mainLayout->addLayout(rate1Layout);
    // mainLayout->addLayout(rate2Layout);
    // mainLayout->addLayout(rate3Layout);
    // mainLayout->addLayout(rate4Layout);
    // mainLayout->addLayout(rate5Layout);
    mainLayout->addLayout(rateLayout);
    mainLayout->addWidget(totalRate);
    mainLayout->addWidget(additionalRate);

    // rate1Layout->setSpacing(0);
    // rate2Layout->setSpacing(0);
    // rate3Layout->setSpacing(0);
    // rate4Layout->setSpacing(0);
    // rate5Layout->setSpacing(0);
    // rateLayout->setSpacing(0);

    // nameRegionLayout->setSpacing(0);
    //mainLayout->setSpacing(0);

}

void ItemSporsmanOnMat::paintEvent(QPaintEvent *)
{
    QPainter p(this);

    QPainterPath path;
    path.addRoundedRect(1, 1, width() - 2, height() - 2, 5, 5);
    QPen pen(Qt::black);
    p.setPen(pen);
    //if(flagChoice)
        //p.fillPath(path, Qt::lightGray);
    //else
    //    p.fillPath(path, Qt::white);

    p.drawPath(path);
}
