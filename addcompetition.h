#ifndef ADDCOMPETITION_H
#define ADDCOMPETITION_H

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class AddCompetition;
}

class AddCompetition : public QDialog
{
    Q_OBJECT

public:
    explicit AddCompetition(bool, MainWindow* mv = nullptr, QWidget *parent = nullptr);
    ~AddCompetition();

public slots:
    void createCompetitions(void);

private:
    Ui::AddCompetition *ui;
    bool state; //true - создать, false - редактировать
    MainWindow* mainwin;
    //FormMain* formmain;

};

#endif // ADDCOMPETITION_H
