#include "Ganador.h"
#include "ui_Ganador.h"

Ganador::Ganador(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ganador)
{
    ui->setupUi(this);
}

Ganador::~Ganador()
{
    delete ui;
}

int Ganador::getNumber()const {
    return 0;
}

void Ganador::on_buttonBox_rejected()
{
    this->close();
    exit(0);
}
