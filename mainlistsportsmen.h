#ifndef MAINLISTSPORTSMEN_H
#define MAINLISTSPORTSMEN_H

#include <QWidget>
#include "database.h"
#include <QPainter>
#include <QScrollBar>
#include <QSpacerItem>
#include <QHBoxLayout>

namespace Ui {
class MainListSportsmen;
}

class MainListSportsmen : public QWidget
{
    Q_OBJECT

public:
    explicit MainListSportsmen(QString, QString, QString, DataBase*, QWidget *parent = nullptr);
    ~MainListSportsmen();
    void setFont(QFont);

public slots:
    //void setMat(int);

private:
    Ui::MainListSportsmen *ui;
    QPainter* painter;
    int X0;
    int Y0;
    int scaleFactor;
    void drawHLine(int, int, int);
    void drawVLine(int, int, int);
    void drawName(int, int, QString);
    void drawRegion(int, int, QString);
    void drawPlace(int, int, int);
    void drawRate(int, int, QString);
    QFont font;
    void addItemsSportsmen(void);
    DataBase* base;
    QString category;
    QString age;
    QString weight;
    QScrollBar* bar;
    QSpacerItem* spacer;
    QHBoxLayout* layout;

    //int mat = 0;

private slots:
    void toggleView(bool);
    void printToPdf(void);
    void slotFont(void);
    void eventScrollBar(bool);

signals:
    void changeFont(QFont);
    //void sigMat(int);
    int sendOnMat(int, sportsman);

};

#endif // MAINLISTSPORTSMEN_H
