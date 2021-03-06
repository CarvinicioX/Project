#include "ChooseDigiDestined.h"
#include "ui_ChooseDigiDestined.h"
#include <QStringList>
#include <iostream>

using namespace std;

ChooseDigiDestined::ChooseDigiDestined(vector<DigiDestined> DigiDestinados, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChooseDigiDestined)
{
    ui->setupUi(this);
    this->DigiDestinados = DigiDestinados;
    QString Tamer1, Tamer2, Tamer3, Tamer4, Tamer5, Tamer6;
    Tamer1 = "Cody";
    Tamer2 = "Davis";
    Tamer3 = "Kari";
    Tamer4 = "Ken";
    Tamer5 = "T.K.";
    Tamer6 = "Yolei";
    QStringList Combo;
    Combo << Tamer1 << Tamer2 << Tamer3 << Tamer4 << Tamer5 << Tamer6;
    ui->Player1SelectionComboBox->addItems(Combo);
    ui->Player2SelectionComboBox->addItems(Combo);
    ui->Player2SelectionComboBox->setCurrentIndex(1);
}

ChooseDigiDestined::~ChooseDigiDestined()
{
    delete ui;
}

int ChooseDigiDestined::retornaIndicePlayer1()const {
    return Player1;
}

int ChooseDigiDestined::retornaIndicePlayer2()const {
    return Player2;
}

void ChooseDigiDestined::on_Player1SelectionComboBox_currentIndexChanged(int index)
{
    cout << index << endl;
    if (ui->Player1SelectionComboBox->currentIndex() == ui->Player2SelectionComboBox->currentIndex()) {
        if (ui->Player1SelectionComboBox->currentIndex() == DigiDestinados.size() - 1) {
            ui->Player2SelectionComboBox->setCurrentIndex(ui->Player1SelectionComboBox->currentIndex() - 1);
        } else {
            ui->Player2SelectionComboBox->setCurrentIndex(ui->Player1SelectionComboBox->currentIndex() + 1);
        }
    }
    QPixmap* mypix;
    if (ui->Player1SelectionComboBox->currentIndex() == 0) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Cody.png");
        ui->Player1Name->setText("Cody");
    } else if (ui->Player1SelectionComboBox->currentIndex() == 1) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Davis.png");
        ui->Player1Name->setText("Davis");
    } else if (ui->Player1SelectionComboBox->currentIndex() == 2) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Kari.png");
        ui->Player1Name->setText("Kari");
    } else if (ui->Player1SelectionComboBox->currentIndex() == 3) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Ken.png");
        ui->Player1Name->setText("Ken");
    } else if (ui->Player1SelectionComboBox->currentIndex() == 4) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/TdotKdot.png");
        ui->Player1Name->setText("T.K.");
    } else {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Yolei.png");
        ui->Player1Name->setText("Yolei");
    }
    ui->Player1Mugshot->setPixmap(*mypix);
    delete mypix;
}

void ChooseDigiDestined::on_Player2SelectionComboBox_currentIndexChanged(int index)
{
    cout << index << endl;
    if (ui->Player2SelectionComboBox->currentIndex() == ui->Player1SelectionComboBox->currentIndex()) {
        if (ui->Player2SelectionComboBox->currentIndex() == DigiDestinados.size() - 1) {
            ui->Player1SelectionComboBox->setCurrentIndex(ui->Player2SelectionComboBox->currentIndex() - 1);
        } else {
            ui->Player1SelectionComboBox->setCurrentIndex(ui->Player2SelectionComboBox->currentIndex() + 1);
        }
    }
    QPixmap* mypix;
    if (ui->Player2SelectionComboBox->currentIndex() == 0) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Cody.png");
        ui->Player2Name->setText("Cody");
    } else if (ui->Player2SelectionComboBox->currentIndex() == 1) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Davis.png");
        ui->Player2Name->setText("Davis");
    } else if (ui->Player2SelectionComboBox->currentIndex() == 2) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Kari.png");
        ui->Player2Name->setText("Kari");
    } else if (ui->Player2SelectionComboBox->currentIndex() == 3) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Ken.png");
        ui->Player2Name->setText("Ken");
    } else if (ui->Player2SelectionComboBox->currentIndex() == 4) {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/TdotKdot.png");
        ui->Player2Name->setText("T.K.");
    } else {
        mypix = new QPixmap(":/new/DigiElegidos/Digimon/Yolei.png");
        ui->Player2Name->setText("Yolei");
    }
    ui->Player2Mugshot->setPixmap(*mypix);
    delete mypix;
}

void ChooseDigiDestined::on_buttonBox_rejected()
{
    exit(0);
}

void ChooseDigiDestined::on_buttonBox_accepted()
{
    Player1 = ui->Player1SelectionComboBox->currentIndex();
    Player2 = ui->Player2SelectionComboBox->currentIndex();
    cout << "Exito" << endl;
    this->close();
}
