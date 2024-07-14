#include "addcompetition.h"
#include "ui_addcompetition.h"
#include <QDebug>

#include <QMessageBox>
#include <QFileInfo>
//#include <QSqlDatabase>
//#include <QSqlError>
//#include <QSqlQuery>
#include <QStatusBar>

AddCompetition::AddCompetition(bool b, MainWindow* mv, QWidget *parent) :
    QDialog(nullptr),
    ui(new Ui::AddCompetition)
{
    ui->setupUi(this);

    //formmain = (FormMain*)parent;
    mainwin = mv;

    state = b;
    if(b)
        setWindowTitle("Новое соревнование");
    else
        setWindowTitle("Правка соревнования");
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(reject()));
    connect(ui->btnCreate, SIGNAL(clicked()), this, SLOT(createCompetitions()));
}

AddCompetition::~AddCompetition()
{
    delete ui;

}

void AddCompetition::createCompetitions(){
    QString name = ui->leName->text();
    QString city = ui->leCity->text();
    QString start = ui->deStart->text();
    QString finish = ui->deFinish->text();
    QMessageBox msgBox;
    if(name.trimmed() == "" || city.trimmed() == ""){
        msgBox.setText("Все поля должны быть заполнены!");
        msgBox.exec();
        return;
    }
    QString baza_name = name + "_" + city + "_" + start + "_" + finish + ".db";
    if(QFileInfo::exists(baza_name)){
        msgBox.setText("Соревнование уже существует!");
        msgBox.exec();
        return;
    }
    if(!mainwin->manageBase->addDataBase(baza_name)){
        msgBox.setText("Ошибка создания базы данных!");
        msgBox.exec();
        return;
    }

       // QList<QLabel*> lL = mainwin->statusBar()->findChildren<QLabel*>();
       // foreach(QLabel* lbl, lL){
       //     mainwin->statusBar()->removeWidget(lbl);
       //     delete lbl;
       // }
    //QLabel* lblStatus = new QLabel(name);

    mainwin->lblStatus->setText(baza_name.left(baza_name.lastIndexOf(".")));

    //formmain->btnEnterName->setEnabled(false);

    //formmain->currentDataBase = baza_name;
    mainwin->fillLastCompetitions();
    QList<QAction*> lAction = mainwin->findChildren<QAction*>();
    foreach(QAction* act, lAction){
        if(act->text() == baza_name.left(baza_name.lastIndexOf(".")))
            act->setChecked(true);
        else
            act->setChecked(false);
    }
    mainwin->add->setEnabled(true);
    mainwin->addBuffer->setEnabled(true);

    reject();
}
