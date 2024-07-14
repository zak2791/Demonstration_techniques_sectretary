#include "database.h"
#include <QMessageBox>
#include <QLabel>

DataBase::DataBase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
}

DataBase::~DataBase(){
    if(db.open())
        db.close();
}

bool DataBase::openDataBase(QString name)
{
    if (db.open())
        db.close();
    db.setDatabaseName(name);
    if (!db.open())
        return false;






    return true;
}

bool DataBase::addDataBase(QString name)
{
    db.setDatabaseName(name);
    if (!db.open())
        return false;

    QSqlQuery query;

    QMessageBox msgBox;

    QString str =   "CREATE TABLE sportsmen "
                    "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "name  TEXT, region TEXT, range TEXT, status INTEGER DEFAULT 0, category TEXT, "
                    "age  TEXT, weight TEXT, "
                    "UNIQUE (name, region, age, weight))";

    if(!query.exec(str)){
        msgBox.setText("Ошибка создания таблицы sportsmen " + db.lastError().text());
        msgBox.exec();
        db.close();
        return false;
    }

    str = "CREATE TABLE first_round "
          "(id INTEGER PRIMARY KEY AUTOINCREMENT, "
          "id_sportsmam INTEGER, "
          "rate1_1 REAL, rate1_2 REAL, rate1_3 REAL, "
          "rate2_1 REAL, rate2_2 REAL, rate2_3 REAL, "
          "rate3_1 REAL, rate3_2 REAL, rate3_3 REAL, "
          "rate4_1 REAL, rate4_2 REAL, rate4_3 REAL, "
          "rate5_1 REAL, rate5_2 REAL, rate5_3 REAL, "
          "total  REAL, secondrate INTEGER, status INTEGER DEFAULT 0, mat)";

    if(!query.exec(str)){
        msgBox.setText("Ошибка создания таблицы first_round " + db.lastError().text());
        msgBox.exec();
        db.close();
        return false;
    }

    return true;
}

bool DataBase::addSportsmen(QString str)
{
    // QString sql = "INSERT INTO sportsmen (name, region, category, age, weight) "
    //               "VALUES ('%1', '%2', '%3', '%4', '%5')";
    // QSqlQuery query;
    // int count = 1;
    // foreach(QString str, str.removeLast().split("\n")){
    //     QStringList sList = str.split("\t");
    //     query.exec(sql.arg(sList.at(0), sList.at(1), sList.at(4), sList.at(2), sList.at(3)));
    //     qDebug()<<count++;
    // }
    QSqlQuery query;
    QVariantList names;
    QVariantList regions;
    QVariantList categories;
    QVariantList ages;
    QVariantList weights;
    QVariantList range;
    query.prepare("INSERT INTO sportsmen (name, region, category, age, weight, range ) "
                  "VALUES (?, ?, ?, ?, ?, ?)");
    foreach(QString str, str.removeLast().split("\n")){
        QStringList sList = str.split("\t");
        names.append(sList.at(0));
        regions.append(sList.at(1));
        categories.append(sList.at(5));
        ages.append(sList.at(2));
        weights.append(sList.at(3));
        range.append(sList.at(4));
    }
    query.addBindValue(names);
    query.addBindValue(regions);
    query.addBindValue(categories);
    query.addBindValue(ages);
    query.addBindValue(weights);
    query.addBindValue(range);
    if (!query.execBatch())
        qDebug() << query.lastError();

    // foreach(QString str, str.removeLast().split("\n")){
    //     QStringList sList = str.split("\t");
    //     query.bindValue(0, sList.at(0));
    //     query.bindValue(1, sList.at(1));
    //     query.bindValue(2, sList.at(4));
    //     query.bindValue(3, sList.at(2));
    //     query.bindValue(4, sList.at(3));
    //     query.exec();
    // }
    // qDebug()<<"end transaction:"<<QSqlDatabase::database().commit();

    return true;
}

QList<sportsman> DataBase::readAllSportsmen()
{
    QVector<sportsman> listSportsmens;
    QSqlQuery query;
    query.exec("SELECT * FROM sportsmen");
    while(query.next()){
        sportsman sMan;
        sMan.name = query.value("name").toString();
        sMan.region = query.value("region").toString();
        sMan.weight = query.value("weight").toString();
        sMan.age = query.value("age").toString();
        sMan.category = query.value("category").toString();
        sMan.range = query.value("range").toString();
        listSportsmens.append(sMan);
    }
    return listSportsmens;
}

QList<sportsman> DataBase::selectlSportsmen(QString c, QString a, QString w)
{
    QVector<sportsman> listSportsmens;
    QSqlQuery query;
    QString sql("SELECT * FROM sportsmen WHERE category = '%1' and age = '%2' and weight = '%3'");
    query.exec(sql.arg(c, a, w));
    while(query.next()){
        sportsman sMan;
        sMan.name = query.value("name").toString();
        sMan.region = query.value("region").toString();
        sMan.weight = query.value("weight").toString();
        sMan.age = query.value("age").toString();
        sMan.category = query.value("category").toString();
        sMan.range = query.value("range").toString();
        sMan.status = query.value("status").toInt();
        listSportsmens.append(sMan);
    }
    return listSportsmens;
}

QList<sportsman> DataBase::selectAndSortlSportsmen(QString c, QString a, QString w)
{
    QVector<sportsman> listSportsmens;
    QSqlQuery query;
    QString sql("SELECT * FROM sportsmen WHERE category = '%1' and age = '%2' and weight = '%3'");
    query.exec(sql.arg(c, a, w));
    while(query.next()){
        sportsman sMan;
        sMan.id = query.value("id").toInt();
        sMan.name = query.value("name").toString();
        sMan.region = query.value("region").toString();
        sMan.weight = query.value("weight").toString();
        sMan.age = query.value("age").toString();
        sMan.category = query.value("category").toString();
        sMan.range = query.value("range").toString();
        sMan.status = query.value("status").toInt();
        listSportsmens.append(sMan);
    }
    return listSportsmens;
}

QSqlTableModel* DataBase::getModel(QString c, QString a, QString w)
{
    QSqlTableModel* model = new QSqlTableModel;
    model->setTable("sportsmen");

    QString filter = "category = '%1' and age = '%2' and weight = '%3'";
    filter = filter.arg(c).arg(a).arg(w);
    model->setFilter (filter);

    model->select();




    return model;
}

void DataBase::addItemOnMat(int id, sportsman)
{
    QSqlQuery query;
    query.prepare("INSERT INTO first_round (id_sportsman, status, mat) VALUES (?, ?, ?)");
    query.addBindValue(id);
    query.addBindValue(0);
    query.addBindValue(mat);
    query.exec();
    query.prepare("UPDATE sportsmen SET status = ? WHERE id = ?;");
    query.addBindValue(1);
    query.addBindValue(id);
    query.exec();
}

void DataBase::addData(int id, QVector<float> rates, float total)
{
    QSqlQuery query;
    QString sql("SELECT * FROM first_round WHERE id_sportsmam = '%1'");
    query.exec(sql.arg(id));
    if(query.next()){       //

    }
    else{

    }

    emit sigFirst(id, rates, total, 0);
}

void DataBase::setMat(int m)
{
    mat = m;
}
