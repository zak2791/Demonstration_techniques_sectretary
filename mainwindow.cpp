#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>
#include <QClipboard>
#include <QMessageBox>
#include "main.h"
#include <QTableWidget>

#include <QDir>
#include <QActionGroup>
#include "addcompetition.h"
#include "itemsporsmanonmat.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabAllList->removeTab(1);
    ui->tabAllList->removeTab(0);

    add = ui->add;
    addBuffer = ui->addFromBuffer;

    manageBase = new DataBase;

    lastCompetitions = ui->menu->addMenu("Последние");
    lastCompetitions->setEnabled(false);

    lblStatus = new QLabel();
    statusBar()->addWidget(lblStatus);

    //Соревнования
    connect(ui->create,             SIGNAL(triggered(bool)), this, SLOT(createCompetition()));
    connect(ui->change,             SIGNAL(triggered(bool)), this, SLOT(changeCompetition()));

    //Спортсмены
    connect(ui->add,            SIGNAL(triggered(bool)), this, SLOT(addSportsman()));
    connect(ui->addFromBuffer,  SIGNAL(triggered(bool)), this, SLOT(addFromBuffer()));


    fillLastCompetitions();

    connect(manageBase, SIGNAL(changeItems()), this, SLOT(changeItemsOnMat()));
    // ui->layoutMatA->addWidget(new ItemSporsmanOnMat());
    // ui->layoutMatA->addWidget(new ItemSporsmanOnMat);
    // ui->layoutMatA->addWidget(new ItemSporsmanOnMat);
    MatA = ui->layoutMatA;
    ui->layoutMatA->addStretch();

    MatB = ui->layoutMatB;
    ui->layoutMatB->addStretch();

    server = new UdpServer(ui->quickWidget, this);

    tabWgt = ui->tabWidget;
    connect(tabWgt, SIGNAL(currentChanged(int)), manageBase, SLOT(setMat(int)));
    connect(tabWgt, SIGNAL(currentChanged(int)), this, SLOT(setMat(int)));  //????????????????????????!!!!!!!!!!!
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manageBase;
    delete server;
}

void MainWindow::fillLastCompetitions(){
    QDir dir = QDir::current();
    QFileInfoList lFiles = dir.entryInfoList({"*.db"}, QDir::Files, QDir::Time);
    if(lFiles.count() > 0){
        QActionGroup* gr = new QActionGroup(this);
        foreach(QFileInfo inf, lFiles){
            QAction* act = gr->addAction(inf.completeBaseName());
            act->setCheckable(true);
            connect(act, SIGNAL(triggered()), this, SLOT(choiceCompetitions()));
        }
        lastCompetitions->clear();
        lastCompetitions->addActions(gr->actions());
        lastCompetitions->setEnabled(true);
    }
}

void MainWindow::resizeEvent(QResizeEvent* e)
{

}

void MainWindow::createCompetition()
{
    AddCompetition* add = new AddCompetition(true, this, this);
    add->exec();
    // QList<QAction*> allActions = mainwin->findChildren<QAction*>();
    // foreach(QAction* act, allActions){
    //     if(act->text() == currentDataBase.left(currentDataBase.lastIndexOf('.'))){
    //         act->trigger();
    //         break;
    //     }
    // }
}

void MainWindow::changeCompetition()
{
    qDebug()<<"change";
}

void MainWindow::addSportsman()
{
    qDebug()<<"add";
}

///////////////////////////////////////////////
/// Добавление спортсменов из буфера обмена ///
///////////////////////////////////////////////
void MainWindow::addFromBuffer()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    QString originalText = clipboard->text();

    QMessageBox msgBox;
    if(originalText.split("\n").count() < 1){
        msgBox.setText("Неверные данные в буфере обмена!");
        msgBox.exec();
        return;
    }

    if(originalText.split("\n").at(0).split("\t").count() != 6){
        msgBox.setText("Неверные данные в буфере обмена!");
        msgBox.exec();
        return;
    }

    if(!manageBase->addSportsmen(originalText))
        return;

    fillWindowSportsmen();
}

//////////////////////////////////////
/// Открыть последние соревнования ///
//////////////////////////////////////
void MainWindow::choiceCompetitions()
{
    if(static_cast<QAction*>(sender())->text() != currentActionLast){
        currentActionLast = static_cast<QAction*>(sender())->text();
        if(manageBase->openDataBase(currentActionLast + ".db")){
            lblStatus->setText(currentActionLast);
            fillWindowSportsmen();
        }
    }
    add->setEnabled(true);
    addBuffer->setEnabled(true);
}

///////////////////////////////////////////////
/// Заполнение окна вкладок со спортсменами ///
///////////////////////////////////////////////
void MainWindow::fillWindowSportsmen()
{
    QList<MainListSportsmen*> listTable = ui->tabAllList->findChildren<MainListSportsmen*>();
    QList<QTabWidget*> listTab = ui->tabAllList->findChildren<QTabWidget*>();
    foreach(MainListSportsmen* table, listTable){
        table->deleteLater();
        qDebug()<<"MainListSportsmen";
    }
    foreach(QTabWidget* tab, listTab){
        tab->deleteLater();
        qDebug()<<"QTabWidget";
    }

    QVector<sportsman> listSportsmens;
    listSportsmens = manageBase->readAllSportsmen();
    std::sort(listSportsmens.begin(), listSportsmens.end());
    QString c, a, w;
    QList<QTabWidget*> lTabCategory;
    QList<QTabWidget*> lTabAge;
    QList<MainListSportsmen*> lTable;

    foreach(sportsman s, listSportsmens){
        if(c != s.category){
            c = s.category;
            a = s.age;
            w = s.weight;
            lTabCategory.append(new QTabWidget);
            lTabAge.append(new QTabWidget);
            //QAbstractItemModel* model = manageBase->getModel(c, a, w);
            lTable.append(new MainListSportsmen(c, a, w, manageBase));
            connect(lTable.last(), SIGNAL(changeFont(QFont)), this, SLOT(changeFont(QFont)));
            connect(lTable.last(), SIGNAL(sendOnMat(int, sportsman)), this, SLOT(addItemOnMat(int, sportsman)));
            ui->tabAllList->addTab(lTabCategory[lTabCategory.count() - 1], c);
            lTabCategory[lTabCategory.count() - 1]->addTab(lTabAge[lTabAge.count() - 1], a);
            lTabAge[lTabAge.count() - 1]->addTab(lTable[lTable.count() - 1], w);
            qDebug()<<c;
            qDebug()<<"______"<<a;
            qDebug()<<"____________"<<w;
            qDebug()<<"__________________"<<s.name;
        }else{
            if(a != s.age){
                a = s.age;
                w = s.weight;
                lTabAge.append(new QTabWidget);
                //QAbstractItemModel* model = manageBase->getModel(c, a, w);
                lTable.append(new MainListSportsmen(c, a, w, manageBase));
                connect(lTable.last(), SIGNAL(changeFont(QFont)), this, SLOT(changeFont(QFont)));
                connect(lTable.last(), SIGNAL(sendOnMat(int, sportsman)), this, SLOT(addItemOnMat(int, sportsman)));
                lTabCategory[lTabCategory.count() - 1]->addTab(lTabAge[lTabAge.count() - 1], a);
                lTabAge[lTabAge.count() - 1]->addTab(lTable[lTable.count() - 1], w);
                qDebug()<<"______"<<a;
                qDebug()<<"____________"<<w;
                qDebug()<<"__________________"<<s.name;
            }else{
                if(w != s.weight){
                    w = s.weight;
                    //QAbstractItemModel* model = manageBase->getModel(c, a, w);
                    lTable.append(new MainListSportsmen(c, a, w, manageBase));
                    connect(lTable.last(), SIGNAL(changeFont(QFont)), this, SLOT(changeFont(QFont)));
                    connect(lTable.last(), SIGNAL(sendOnMat(int, sportsman)), this, SLOT(addItemOnMat(int, sportsman)));
                    lTabAge[lTabAge.count() - 1]->addTab(lTable[lTable.count() - 1], w);

                    qDebug()<<"____________"<<w;
                }
                qDebug()<<"__________________"<<s.name<<s.region;
            }
        }
    }
}

void MainWindow::changeFont(QFont f)
{
    //font = f;
    foreach(MainListSportsmen* l, lTable){
        l->setFont(f);
    }
}

void MainWindow::changeItemsOnMat()
{
    qDebug()<<"changeItemsOnMat";
    //MatA->addWidget(new ItemSporsmanOnMat());
}

void MainWindow::addItemOnMat(int index, sportsman s)
{
    qDebug()<<"MainWindow "<<index<<mat;
    if(tabWgt->currentIndex() == 0){
        MatA->insertWidget(MatA->count() - 1, new ItemSporsmanOnMat(s));
        //MatA->update();
    }
    else{
        MatB->insertWidget(MatA->count() - 1, new ItemSporsmanOnMat(s));
        //MatB->update();
    }

}

void MainWindow::setMat(int index)
{
    mat = index;
    qDebug()<<"setMat "<<mat;
}
