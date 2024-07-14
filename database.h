#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include "main.h"
#include <QSqlTableModel>

class DataBase : public QObject
{
    Q_OBJECT
public:
    DataBase();
    ~DataBase();
    bool openDataBase(QString);
    bool addDataBase(QString);
    bool addSportsmen(QString);
    QList<sportsman> readAllSportsmen(void);
    QList<sportsman> selectlSportsmen(QString, QString, QString);
    QList<sportsman> selectAndSortlSportsmen(QString, QString, QString);
    QSqlTableModel* getModel(QString, QString, QString);

private:
    QSqlDatabase db;
    int mat = 0;    // ковёр: 0 - А, 1 - Б

public slots:

    ///////////////////////////////////////////////////////////////////////////////
    /// вставка строки в таблицу "first_round" при отправке спортсмена на ковёр ///
    ///////////////////////////////////////////////////////////////////////////////
    void addItemOnMat(int   // id спортсмена
                      , sportsman
                      //int   // ковёр: 0 - А, 1 - Б
                      );

    //////////////////////////////////////////////////
    /// вставка данных из сокета для первого круга ///
    //////////////////////////////////////////////////
    void addData(int,               // id спортсмена
                 QVector<float>,    // 15 оценок
                 float              // сумма баллов
                 );

    void setMat(int);

signals:
    //void setStatus(QString);
    void changeItems(void);

    ////////////////////////////////
    /// изменения в первом круге ///
    ////////////////////////////////
    void sigFirst(int,              // id спортсмена
                  QVector<float>,   // оценки (3х5=15)
                  float,            // сумма баллов
                  int               // дополнительная оценка
                  );

    void update_half(int);      // изменения в полуфинале
    void update_final(int);     // изменения в финале
    void update_third(int);     // изменения в розыгрыше за третья место

};

#endif // DATABASE_H
