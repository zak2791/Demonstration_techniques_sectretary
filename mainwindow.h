#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "database.h"
#include "udpserver.h"
#include <mainlistsportsmen.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString currentDataBase;   //текущая база данных
    DataBase* manageBase;
    QLabel* lblStatus;
    void fillLastCompetitions(void);
    QAction* add;
    QAction* addBuffer;

private:
    Ui::MainWindow *ui;
    virtual void resizeEvent(QResizeEvent*);

    QMenu* lastCompetitions;
    QString currentActionLast = "";
    UdpServer* server;
    //QFont font;
    QVBoxLayout* MatA;
    QVBoxLayout* MatB;

    QList<MainListSportsmen*> lTable;

    QTabWidget* tabWgt;

    int mat = 0;

private slots:
    void createCompetition(void);
    void changeCompetition(void);
    void addSportsman(void);
    void addFromBuffer(void);
    void choiceCompetitions(void);
    void fillWindowSportsmen(void); //заполнение окна вкладок со спортсменами
    void changeFont(QFont);
    void changeItemsOnMat(void);
    void addItemOnMat(int, sportsman);
    void setMat(int);

};



#endif // MAINWINDOW_H
