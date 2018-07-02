#include "enterchoosecardinterface.h"
#include "ui_enterchoosecardinterface.h"

EnterChooseCardInterface::EnterChooseCardInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EnterChooseCardInterface)
{
    ui->setupUi(this);
}

EnterChooseCardInterface::~EnterChooseCardInterface()
{
    delete ui;
}
