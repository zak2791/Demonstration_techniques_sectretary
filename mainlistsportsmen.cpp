#include "mainlistsportsmen.h"
#include "itemsportsmen.h"
#include "ui_mainlistsportsmen.h"
#include <QPrinter>

#include <QFile>
#include <QPdfWriter>
#include <QFontDialog>
#include <QSqlTableModel>

#include "eventscrollbar.h"

MainListSportsmen::MainListSportsmen(QString c, QString a, QString w, DataBase* b, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainListSportsmen)
{
    ui->setupUi(this);

    base = b;
    category = c;
    age = a;
    weight = w;

    connect(ui->r1, SIGNAL(toggled(bool)), this, SLOT(toggleView(bool)));
    emit ui->r1->toggled(true);
    connect(ui->btnPrint, SIGNAL(clicked()), this, SLOT(printToPdf()));
    connect(ui->btnFont, SIGNAL(clicked()), this, SLOT(slotFont()));
    X0 = 10;
    Y0 = 50;

    bar = ui->scrollArea->verticalScrollBar();
    EventScrollBar* filter = new EventScrollBar(bar);
    bar->installEventFilter(filter);
    connect(filter, SIGNAL(sigShowHide(bool)), this, SLOT(eventScrollBar(bool)));

    spacer = ui->hSpacer;

    layout = ui->horizontalLayout;

    ui->vLayout->addStretch();
    addItemsSportsmen();
}

MainListSportsmen::~MainListSportsmen()
{
    delete ui;
}

void MainListSportsmen::setFont(QFont f)
{
    font = f;
}

// void MainListSportsmen::setMat(int index)
// {
//     mat = index;
//     emit sigMat(index);
// }

void MainListSportsmen::toggleView(bool view)
{
    if(view)
        ui->stackedWidget->setCurrentIndex(0);
    else
        ui->stackedWidget->setCurrentIndex(1);
}

void MainListSportsmen::printToPdf(void)
{
    // QImage windowImage = ui->quickWidget->grabFramebuffer();
    QPrinter pdfPrinter(QPrinter::HighResolution);
    pdfPrinter.setPageSize(QPageSize::A4);
    //pdfPrinter.setOutputFormat(QPrinter::PdfFormat);
    pdfPrinter.setOutputFormat(QPrinter::NativeFormat);
    pdfPrinter.setOutputFileName("test.pdf");



    painter = new QPainter;
    //QRect r(painter.viewport());
    painter->begin(&pdfPrinter);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(10);
    painter->setPen(pen);
    // QFont f("Verdana", 10, true);
    // f.setBold(true);
    // f.setItalic(true);
    // f.setFamily("Times New Roman");
    painter->setFont(font);



    scaleFactor = painter->viewport().width() / 210;

    drawName(10, 0, "Жингалов\nАлександр");
    drawName(60, 0, "Брянская\nобласть");
    drawPlace(170, 30, 1);
    drawPlace(170, 70, 2);
    drawPlace(170, 100, 3);
    drawRate(110, 0, "142.5");

    drawHLine(0, 0, 130);
    drawHLine(0, 10, 160);
    drawHLine(0, 20, 160);
    drawHLine(0, 30, 130);
    drawHLine(160, 30, 10);
    drawHLine(160, 40, 10);
    drawHLine(0, 40, 130);
    drawHLine(0, 50, 160);
    drawHLine(0, 60, 160);
    drawHLine(0, 70, 130);

    drawHLine(160, 70, 10);
    drawHLine(160, 80, 10);
    drawHLine(130, 90, 30);
    drawHLine(130, 100, 40);
    drawHLine(130, 110, 40);
    drawHLine(130, 120, 30);

    for(int i = 0; i < 80; i += 20){
        drawVLine(0, i, 10);
        drawVLine(10, i, 10);
        drawVLine(60, i, 10);
        drawVLine(100, i, 10);
        drawVLine(110, i, 10);
        drawVLine(130, i, 10);
    }

    drawVLine(130, 10, 10);
    drawVLine(140, 10, 10);
    drawVLine(160, 10, 50);

    drawVLine(130, 50, 10);
    drawVLine(140, 50, 10);
    //drawVLine(160, 50, 10);

    drawVLine(130, 90, 10);
    drawVLine(140, 90, 10);
    drawVLine(160, 90, 30);

    drawVLine(130, 110, 10);
    drawVLine(140, 110, 10);

    drawVLine(170, 30, 10);
    drawVLine(170, 70, 10);
    drawVLine(170, 100, 10);

    drawVLine(160, 70, 10);

    pen.setColor(Qt::lightGray);
    //pen.setWidth(10);
    painter->setPen(pen);

    drawVLine(120, 1, 8);
    drawVLine(120, 21, 8);
    drawVLine(120, 41, 8);
    drawVLine(120, 61, 8);

    drawVLine(150, 11, 8);
    drawVLine(150, 51, 8);

    drawVLine(150, 91, 8);
    drawVLine(150, 111, 8);


    painter->end();
    delete painter;

}

void MainListSportsmen::slotFont()
{
    bool ok;
    font = QFontDialog::getFont(&ok, font, this);
    if (ok) {
        // the user clicked OK and font is set to the font the user selected
        emit changeFont(font);
    } else {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Helvetica [Cronyx], 10
    }
}

void MainListSportsmen::eventScrollBar(bool b)
{
    if(b)
        spacer->changeSize(bar->width() + 9, 40, QSizePolicy::Fixed, QSizePolicy::Fixed);
    else
        spacer->changeSize(9, 40, QSizePolicy::Fixed, QSizePolicy::Fixed);
    layout->update();
}



void MainListSportsmen::drawHLine(int x, int y, int w)
{
    painter->drawLine((x + X0) * scaleFactor, (y + Y0) * scaleFactor, (x + X0 + w) * scaleFactor, (y + Y0) * scaleFactor);
}

void MainListSportsmen::drawVLine(int x, int y, int h)
{
    painter->drawLine((x + X0) * scaleFactor, (y + Y0) * scaleFactor, (x + X0) * scaleFactor, (y + Y0 + h) * scaleFactor);
}

void MainListSportsmen::drawName(int x, int y, QString s)
{
    painter->drawText(QRect((x + X0 + 1) * scaleFactor, (y + Y0) * scaleFactor, 49 * scaleFactor, 10 * scaleFactor), Qt::AlignVCenter , s);
}

void MainListSportsmen::drawRegion(int x, int y, QString s)
{
    painter->drawText(QRect((x + X0 + 1) * scaleFactor, (y + Y0) * scaleFactor, 39 * scaleFactor, 10 * scaleFactor), Qt::AlignVCenter , s);
}

void MainListSportsmen::drawPlace(int x, int y, int place)
{
    painter->drawText(QRect((x + X0 + 1) * scaleFactor, (y + Y0) * scaleFactor, 19 * scaleFactor, 10 * scaleFactor), Qt::AlignVCenter , QString::number(place) + " место");
}

void MainListSportsmen::drawRate(int x, int y, QString rate)
{
    QFont f = painter->font();
    int size = f.pointSize();
    qDebug()<<size;
    f.setPointSize(size - 2);
    painter->setFont(f);
    painter->drawText(QRect((x + X0 + 1) * scaleFactor, (y + Y0) * scaleFactor, 9 * scaleFactor, 10 * scaleFactor), Qt::AlignVCenter | Qt::AlignHCenter, rate);
    painter->setFont(font);
}

void MainListSportsmen::addItemsSportsmen()
{
    QList<sportsman> list = base->selectAndSortlSportsmen(category, age, weight);
    int count = 1;
    QList<ItemSportsmen*> listItems = ui->vLayout->findChildren<ItemSportsmen*>();
    foreach(ItemSportsmen* item, listItems)
        delete item;
    foreach(sportsman s, list){
        auto item = new ItemSportsmen(s, count++);
        ui->vLayout->insertWidget(ui->vLayout->count() - 1, item);
        connect(item, SIGNAL(sendOnMat(int, sportsman)), static_cast<QObject*>(base), SLOT(addItemOnMat(int, sportsman)));
        connect(item, SIGNAL(sendOnMat(int, sportsman)), this, SIGNAL(sendOnMat(int, sportsman)));
        connect(static_cast<QObject*>(base), SIGNAL(sigFirst(int,QVector<float>,float,int)),
                                       item, SLOT(updateData(int,QVector<float>,float,int)));
    }
}
