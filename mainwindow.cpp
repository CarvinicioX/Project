#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ChooseDigiDestined.h"
#include "Ganador.h"
#include "Digimon.h"
#include "Vaccine.h"
#include "Data.h"
#include "Virus.h"
#include <QString>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(0));
    DigiActivoPlayer1 = 0;
    DigiActivoPlayer2 = 0;
    ui->setupUi(this);
    ui->Player2Attack->setEnabled(false);
    ui->Player2Cambiar->setEnabled(false);
    ui->Player2Skip->setEnabled(false);
    ui->Player2Withdraw->setEnabled(false);
    //Crea los DigiDestineds(Player's)
    DigiDestinados.push_back(DigiDestined("Cody", ":/new/DigiElegidos/Digimon/Cody.png"));
    DigiDestinados.push_back(DigiDestined("Davis", ":/new/DigiElegidos/Digimon/Davis.png"));
    DigiDestinados.push_back(DigiDestined("Kari", ":/new/DigiElegidos/Digimon/Kari.png"));
    DigiDestinados.push_back(DigiDestined("Ken", ":/new/DigiElegidos/Digimon/Ken.png"));
    DigiDestinados.push_back(DigiDestined("T.K.", ":/new/DigiElegidos/Digimon/TdotKdot.png"));
    DigiDestinados.push_back(DigiDestined("Yolei", ":/new/DigiElegidos/Digimon/Yolei.png"));
    //Elige los personajes el Usuario
    ChooseDigiDestined Choose(DigiDestinados);
    Choose.exec();
    //Ya elegidos se Crean los Player's Elegidos(Valga la redundancia)
    Player1 = new DigiDestined(DigiDestinados[Choose.retornaIndicePlayer1()].getName(), DigiDestinados[Choose.retornaIndicePlayer1()].getImage());
    Player2 = new DigiDestined(DigiDestinados[Choose.retornaIndicePlayer2()].getName(), DigiDestinados[Choose.retornaIndicePlayer2()].getImage());
    cout << Player1->toString() << endl;
    cout << Player2->toString() << endl;
    //Se vacia el vector con los demas players no utilizados
    for (int i = 0; i < DigiDestinados.size(); i++) {
        DigiDestinados.pop_back();
    }
    //Se Crean los Digimons
    Digimon* NewDigi1 = new Vaccine("Armadillomon", 650, 190, ":/new/Digimons/Digimon/Armadillomon.png");
    Digimon* NewDigi2 = new Vaccine("Gatomon", 750, 190, ":/new/Digimons/Digimon/Gatomon.png");
    Digimon* NewDigi3 = new Data("Hawkmon", 600, 180, ":/new/Digimons/Digimon/Hawkmon.png");
    Digimon* NewDigi4 = new Data("Patamon", 630, 170, ":/new/Digimons/Digimon/Patamon.png");
    Digimon* NewDigi5 = new Virus("Veemon", 550, 160, ":/new/Digimons/Digimon/Veemon.png");
    Digimon* NewDigi6 = new Virus("Wormmon", 550, 200, ":/new/Digimons/Digimon/Wormmon.png");
    //Se ingresan al vector
    VpetPlayer1.push_back(NewDigi1);
    VpetPlayer2.push_back(NewDigi2);
    VpetPlayer1.push_back(NewDigi3);
    VpetPlayer2.push_back(NewDigi4);
    VpetPlayer1.push_back(NewDigi5);
    VpetPlayer2.push_back(NewDigi6);
    //Se reparten entre los jugadores
    //Carga los jugadores al GUI
    ui->Player1Name->setText(Player1->getName());
    ui->Player2Name->setText(Player2->getName());
    QPixmap* pixi = new QPixmap(Player1->getImage());
    ui->Player1Mugshot->setPixmap(*pixi);
    delete pixi;
    pixi = new QPixmap(Player2->getImage());
    ui->Player2Mugshot->setPixmap(*pixi);
    cout << Player1->toString() << endl;
    cout << Player2->toString() << endl;
    //Carga los digimon al GUI
    ui->Player1Hp->setMaximum(VpetPlayer1[DigiActivoPlayer1]->getHp());
    ui->Player1Hp->setValue(VpetPlayer1[DigiActivoPlayer1]->getHp());
    ui->Player1NombreDigimon->setText(VpetPlayer1[DigiActivoPlayer1]->getName());
    pixi = new QPixmap(VpetPlayer1[DigiActivoPlayer1]->getImage());
    ui->Player1Digimon->setPixmap(*pixi);
    ui->Player2Hp->setMaximum(VpetPlayer2[DigiActivoPlayer2]->getHp());
    ui->Player2Hp->setValue(VpetPlayer2[DigiActivoPlayer2]->getHp());
    ui->Player2NombreDigimon->setText(VpetPlayer2[DigiActivoPlayer2]->getName());
    pixi = new QPixmap(VpetPlayer2[DigiActivoPlayer2]->getImage());
    ui->Player2Digimon->setPixmap(*pixi);
    QPixmap* mipi = new QPixmap(":/new/Sprites/Digimon/Background.png");
    ui->Background->setPixmap(*mipi);
    delete mipi;
    ui->Background->lower();
    ui->History->appendPlainText("Bienvenido.");
    ui->History->appendPlainText("Empieza Atacando el Jugador 1.");
}

MainWindow::~MainWindow()
{
    for (int i = 0; i < Vpet.size(); i++) {
        delete Vpet[i];
    }
    delete Player1;
    delete Player2;
    delete ui;
}

void MainWindow::CambiarTurno()const {
    if (ui->Player1Attack->isEnabled() && !ui->Player2Attack->isEnabled()) {
        ui->Player1Attack->setEnabled(false);
        ui->Player1Cambiar->setEnabled(false);
        ui->Player1Skip->setEnabled(false);
        ui->Player1Withdraw->setEnabled(false);
        ui->Player2Attack->setEnabled(true);
        if (DigiActivoPlayer2 < 2) {
            ui->Player2Cambiar->setEnabled(true);
        } else {
            ui->Player2Cambiar->setEnabled(false);
        }
        ui->Player2Skip->setEnabled(true);
        ui->Player2Withdraw->setEnabled(true);
    } else if (!ui->Player1Attack->isEnabled() && ui->Player2Attack->isEnabled()) {
        ui->Player1Attack->setEnabled(true);
        if (DigiActivoPlayer1 < 2) {
            ui->Player1Cambiar->setEnabled(true);
        } else {
            ui->Player1Cambiar->setEnabled(false);
        }
        ui->Player1Skip->setEnabled(true);
        ui->Player1Withdraw->setEnabled(true);
        ui->Player2Attack->setEnabled(false);
        ui->Player2Cambiar->setEnabled(false);
        ui->Player2Skip->setEnabled(false);
        ui->Player2Withdraw->setEnabled(false);
    }
}

void MainWindow::on_Player1Attack_clicked()
{
    stringstream ss;
    ss << VpetPlayer2[DigiActivoPlayer2]->getName().toStdString() << " ha Atacado por " << VpetPlayer2[DigiActivoPlayer2]->getAttack() << " Puntos de Vida.";
    QString Append = QString::fromStdString(ss.str());
    ui->History->appendPlainText(Append);
    if (ui->Player2Hp->value() < VpetPlayer1[DigiActivoPlayer1]->getAttack()) {
        MainWindow::on_Player2Cambiar_clicked();
    } else {
        this->CambiarTurno();
        ui->Player2Hp->setValue(ui->Player2Hp->value() - VpetPlayer1[DigiActivoPlayer1]->getAttack());
    }
}

void MainWindow::on_Player2Cambiar_clicked()
{
    this->CambiarTurno();
    if (DigiActivoPlayer2 < 3) {
        if (DigiActivoPlayer2 == 0) {
            DigiActivoPlayer2 = 1;
            ui->Player1Wins->setValue(1);
            stringstream ss;
            ss << VpetPlayer2[DigiActivoPlayer2 - 1]->getName().toStdString() << " ha Cambiado por " << VpetPlayer2[DigiActivoPlayer2]->getName().toStdString() << ".";
            QString Append = QString::fromStdString(ss.str());
            ui->History->appendPlainText(Append);
        } else if (DigiActivoPlayer2 == 1) {
            DigiActivoPlayer2 = 2;
            ui->Player1Wins->setValue(2);
            stringstream ss;
            ss << VpetPlayer2[DigiActivoPlayer2 - 1]->getName().toStdString() << " ha Cambiado por " << VpetPlayer2[DigiActivoPlayer2]->getName().toStdString() << ".";
            QString Append = QString::fromStdString(ss.str());
            ui->History->appendPlainText(Append);
        } else if (DigiActivoPlayer2 == 2) {
            DigiActivoPlayer2 = 3;
            ui->Player1Wins->setValue(3);
            stringstream ss;
            ss << VpetPlayer2[DigiActivoPlayer2 - 1]->getName().toStdString() << " no hay mas Digimons.";
            QString Append = QString::fromStdString(ss.str());
            ui->History->appendPlainText(Append);
        }
    }
    if (ui->Player2Hp->value() <= VpetPlayer1[DigiActivoPlayer1]->getAttack()) {
        if (DigiActivoPlayer2 == 3) {
            Ganador Gano;
            Gano.exec();
        } else {
            QPixmap* pixi = new QPixmap(VpetPlayer2[DigiActivoPlayer2]->getImage());
            ui->Player2Hp->setMaximum(VpetPlayer2[DigiActivoPlayer2]->getHp());
            ui->Player2Hp->setValue(VpetPlayer2[DigiActivoPlayer2]->getHp());
            ui->Player2NombreDigimon->setText(VpetPlayer2[DigiActivoPlayer2]->getName());
            pixi = new QPixmap(VpetPlayer2[DigiActivoPlayer2]->getImage());
            ui->Player2Digimon->setPixmap(*pixi);
            delete pixi;
        }
    } else {
        QPixmap* pixi = new QPixmap(VpetPlayer2[DigiActivoPlayer2]->getImage());
        ui->Player2Hp->setMaximum(VpetPlayer2[DigiActivoPlayer2]->getHp());
        ui->Player2Hp->setValue(VpetPlayer2[DigiActivoPlayer2]->getHp());
        ui->Player2NombreDigimon->setText(VpetPlayer2[DigiActivoPlayer2]->getName());
        pixi = new QPixmap(VpetPlayer2[DigiActivoPlayer2]->getImage());
        ui->Player2Digimon->setPixmap(*pixi);
        delete pixi;
    }
}

void MainWindow::on_Player2Attack_clicked()
{
    stringstream ss;
    ss << VpetPlayer1[DigiActivoPlayer1]->getName().toStdString() << " ha Atacado por " << VpetPlayer1[DigiActivoPlayer1]->getAttack() << " Puntos de Vida.";
    QString Append = QString::fromStdString(ss.str());
    ui->History->appendPlainText(Append);
    if (ui->Player1Hp->value() <= VpetPlayer2[DigiActivoPlayer2]->getAttack()) {
        MainWindow::on_Player1Cambiar_clicked();
    } else {
        this->CambiarTurno();
        ui->Player1Hp->setValue(ui->Player1Hp->value() - VpetPlayer2[DigiActivoPlayer2]->getAttack());
    }
}

void MainWindow::on_Player1Cambiar_clicked()
{
    this->CambiarTurno();
    if (DigiActivoPlayer1 < 3) {
        if (DigiActivoPlayer1 == 0) {
            DigiActivoPlayer1 = 1;
            ui->Player2Wins->setValue(1);
            stringstream ss;
            ss << VpetPlayer1[DigiActivoPlayer1 - 1]->getName().toStdString() << " ha Cambiado por " << VpetPlayer1[DigiActivoPlayer1]->getName().toStdString() << ".";
            QString Append = QString::fromStdString(ss.str());
            ui->History->appendPlainText(Append);
        } else if (DigiActivoPlayer1 == 1) {
            DigiActivoPlayer1 = 2;
            ui->Player2Wins->setValue(2);
            stringstream ss;
            ss << VpetPlayer1[DigiActivoPlayer1 - 1]->getName().toStdString() << " ha Cambiado por " << VpetPlayer1[DigiActivoPlayer1]->getName().toStdString() << ".";
            QString Append = QString::fromStdString(ss.str());
            ui->History->appendPlainText(Append);
        } else if (DigiActivoPlayer1 == 2) {
            DigiActivoPlayer1 = 3;
            ui->Player2Wins->setValue(3);
            stringstream ss;
            ss << VpetPlayer1[DigiActivoPlayer1 - 1]->getName().toStdString() << " no hay mas Digimons.";
            QString Append = QString::fromStdString(ss.str());
            ui->History->appendPlainText(Append);
        }
    }
    if (ui->Player1Hp->value() <= VpetPlayer2[DigiActivoPlayer2]->getAttack()) {
        if (DigiActivoPlayer1 == 3) {
            Ganador Gano;
            Gano.exec();
        } else {
            QPixmap* pixi = new QPixmap(VpetPlayer1[DigiActivoPlayer1]->getImage());
            ui->Player1Hp->setMaximum(VpetPlayer1[DigiActivoPlayer1]->getHp());
            ui->Player1Hp->setValue(VpetPlayer1[DigiActivoPlayer1]->getHp());
            ui->Player1NombreDigimon->setText(VpetPlayer1[DigiActivoPlayer1]->getName());
            pixi = new QPixmap(VpetPlayer1[DigiActivoPlayer1]->getImage());
            ui->Player1Digimon->setPixmap(*pixi);
            delete pixi;
        }
    } else {
        QPixmap* pixi = new QPixmap(VpetPlayer1[DigiActivoPlayer1]->getImage());
        ui->Player1Hp->setMaximum(VpetPlayer1[DigiActivoPlayer1]->getHp());
        ui->Player1Hp->setValue(VpetPlayer1[DigiActivoPlayer1]->getHp());
        ui->Player1NombreDigimon->setText(VpetPlayer1[DigiActivoPlayer1]->getName());
        pixi = new QPixmap(VpetPlayer1[DigiActivoPlayer1]->getImage());
        ui->Player1Digimon->setPixmap(*pixi);
        delete pixi;
    }
}

void MainWindow::on_Player1Skip_clicked()
{
    this->CambiarTurno();
    stringstream ss;
    ss << VpetPlayer1[DigiActivoPlayer1]->getName().toStdString() << " ha Skipeado Turno.";
    QString Append = QString::fromStdString(ss.str());
    ui->History->appendPlainText(Append);
}

void MainWindow::on_Player2Skip_clicked()
{
    this->CambiarTurno();
    stringstream ss;
    ss << VpetPlayer2[DigiActivoPlayer2]->getName().toStdString() << " ha Skipeado Turno.";
    QString Append = QString::fromStdString(ss.str());
    ui->History->appendPlainText(Append);
}

void MainWindow::on_Player1Withdraw_clicked()
{
    stringstream ss;
    ss << DigiDestinados[0].getName().toStdString() << " se ha Rendido.";
    QString Append = QString::fromStdString(ss.str());
    ui->History->appendPlainText(Append);
    Ganador Gano;
    Gano.exec();
}

void MainWindow::on_Player2Withdraw_clicked()
{
    stringstream ss;
    ss << DigiDestinados[1].getName().toStdString() << " se ha Rendido.";
    QString Append = QString::fromStdString(ss.str());
    ui->History->appendPlainText(Append);
    Ganador Gano;
    Gano.exec();
}
