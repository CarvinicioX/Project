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
    ui->Player2Defend->setEnabled(false);
    ui->Player2Cambiar->setEnabled(false);
    ui->Player2Skip->setEnabled(false);
    ui->Player2Withdraw->setEnabled(false);
    //Crea los DigiDestinesd(Player's)
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
    Digimon* NewDigi2 = new Vaccine("Gatomon", 750, 210, ":/new/Digimons/Digimon/Gatomon.png");
    Digimon* NewDigi3 = new Data("Hawkmon", 600, 220, ":/new/Digimons/Digimon/Hawkmon.png");
    Digimon* NewDigi4 = new Data("Patamon", 630, 170, ":/new/Digimons/Digimon/Patamon.png");
    Digimon* NewDigi5 = new Virus("Veemon", 550, 200, ":/new/Digimons/Digimon/Veemon.png");
    Digimon* NewDigi6 = new Virus("Wormmon", 550, 170, ":/new/Digimons/Digimon/Wormmon.png");
    //Se ingresan al vector
    Vpet.push_back(NewDigi1);
    Vpet.push_back(NewDigi2);
    Vpet.push_back(NewDigi3);
    Vpet.push_back(NewDigi4);
    Vpet.push_back(NewDigi5);
    Vpet.push_back(NewDigi6);
    //Se reparten entre los jugadores aleatoriamente
    for (int i = 0; i < Vpet.size(); i++) {
        if (Player1->getName() == "Cody" && Vpet[i]->getName() == "Armadillomon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer1.push_back(Vpet[i]);
        } else if (Player1->getName() == "Davis" && Vpet[i]->getName() == "Veemon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer1.push_back(Vpet[i]);
        }else if (Player1->getName() == "Kari" && Vpet[i]->getName() == "Gatomon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer1.push_back(Vpet[i]);
        }else if (Player1->getName() == "Ken" && Vpet[i]->getName() == "Wormmon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer1.push_back(Vpet[i]);
        }else if (Player1->getName() == "T.K." && Vpet[i]->getName() == "Patamon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer1.push_back(Vpet[i]);
        }else if (Player1->getName() == "Yolei" && Vpet[i]->getName() == "Hawkmon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer1.push_back(Vpet[i]);
        }
    }
    for (int i = 0; i < Vpet.size(); i++) {
        if (Player2->getName() == "Cody" && Vpet[i]->getName() == "Armadillomon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer2.push_back(Vpet[i]);
        } else if (Player2->getName() == "Davis" && Vpet[i]->getName() == "Veemon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer2.push_back(Vpet[i]);
        }else if (Player2->getName() == "Kari" && Vpet[i]->getName() == "Gatomon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer2.push_back(Vpet[i]);
        }else if (Player2->getName() == "Ken" && Vpet[i]->getName() == "Wormmon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer2.push_back(Vpet[i]);
        }else if (Player2->getName() == "T.K." && Vpet[i]->getName() == "Patamon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer2.push_back(Vpet[i]);
        }else if (Player2->getName() == "Yolei" && Vpet[i]->getName() == "Hawkmon") {
            Vpet.erase(Vpet.begin() + i);
            VpetPlayer2.push_back(Vpet[i]);
        }
    }
    for (int i = 0; i < 4; i++) {
        if (rand() % 2 && VpetPlayer1.size() < 4) {
            VpetPlayer1.push_back(Vpet[i]);
        } else if (VpetPlayer2.size() < 4) {
            VpetPlayer2.push_back(Vpet[i]);
        }
    }
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
        ui->Player1Defend->setEnabled(false);
        ui->Player1Cambiar->setEnabled(false);
        ui->Player1Skip->setEnabled(false);
        ui->Player1Withdraw->setEnabled(false);
        ui->Player2Attack->setEnabled(true);
        ui->Player2Defend->setEnabled(true);
        ui->Player2Cambiar->setEnabled(true);
        ui->Player2Skip->setEnabled(true);
        ui->Player2Withdraw->setEnabled(true);
    } else if (!ui->Player1Attack->isEnabled() && ui->Player2Attack->isEnabled()) {
        ui->Player1Attack->setEnabled(true);
        ui->Player1Defend->setEnabled(true);
        ui->Player1Cambiar->setEnabled(true);
        ui->Player1Skip->setEnabled(true);
        ui->Player1Withdraw->setEnabled(true);
        ui->Player2Attack->setEnabled(false);
        ui->Player2Defend->setEnabled(false);
        ui->Player2Cambiar->setEnabled(false);
        ui->Player2Skip->setEnabled(false);
        ui->Player2Withdraw->setEnabled(false);
    }
}

void MainWindow::on_Player1Attack_clicked()
{
    if (ui->Player2Hp->value() < VpetPlayer1[DigiActivoPlayer1]->getAttack()) {
        MainWindow::on_Player2Cambiar_clicked();
    } else {
        ui->Player2Hp->setValue(ui->Player2Hp->value() - VpetPlayer1[DigiActivoPlayer1]->getAttack());
        this->CambiarTurno();
    }
}

void MainWindow::on_Player2Cambiar_clicked()
{
    this->CambiarTurno();
    if (DigiActivoPlayer2 == 0) {
        DigiActivoPlayer2 = 1;
        ui->Player1Wins->setValue(1);
    } else if (DigiActivoPlayer2 == 1) {
        DigiActivoPlayer2 = 2;
        ui->Player1Wins->setValue(2);
    } else if (DigiActivoPlayer2 == 2) {
        DigiActivoPlayer2 = 3;
        ui->Player1Wins->setValue(3);
    }
    if (ui->Player2Hp->value() <= VpetPlayer1[DigiActivoPlayer1]->getAttack()) {
        if (DigiActivoPlayer2 == 3) {
            Ganador Gano;
            DigiActivoPlayer1 = 0;
            DigiActivoPlayer2 = 0;//Agregar metodo para actualizar gui automaticamente
            Gano.exec();
        }
    }
    cout << VpetPlayer2[DigiActivoPlayer2]->toString() << endl;
    QPixmap* pixi = new QPixmap(VpetPlayer2[DigiActivoPlayer2]->getImage());
    ui->Player2Hp->setMaximum(VpetPlayer2[DigiActivoPlayer2]->getHp());
    ui->Player2Hp->setValue(VpetPlayer2[DigiActivoPlayer2]->getHp());
    ui->Player2NombreDigimon->setText(VpetPlayer2[DigiActivoPlayer2]->getName());
    pixi = new QPixmap(VpetPlayer2[DigiActivoPlayer2]->getImage());
    ui->Player2Digimon->setPixmap(*pixi);
    delete pixi;
}

void MainWindow::on_Player2Attack_clicked()
{
    if (ui->Player1Hp->value() <= VpetPlayer2[DigiActivoPlayer2]->getAttack()) {
        MainWindow::on_Player1Cambiar_clicked();
    } else {
        ui->Player1Hp->setValue(ui->Player1Hp->value() - VpetPlayer2[DigiActivoPlayer2]->getAttack());
        this->CambiarTurno();
    }
}

void MainWindow::on_Player1Cambiar_clicked()
{
    this->CambiarTurno();
    if (DigiActivoPlayer1 == 0) {
        DigiActivoPlayer1 = 1;
        ui->Player2Wins->setValue(1);
    } else if (DigiActivoPlayer1 == 1) {
        DigiActivoPlayer1 = 2;
        ui->Player2Wins->setValue(2);
    } else if (DigiActivoPlayer1 == 2) {
        DigiActivoPlayer1 = 3;
        ui->Player2Wins->setValue(3);
    }
    if (ui->Player1Hp->value() <= VpetPlayer2[DigiActivoPlayer2]->getAttack()) {
        if (DigiActivoPlayer1 == 3) {
            Ganador Gano;
            Gano.exec();
            DigiActivoPlayer1 = Gano.getNumber();
            DigiActivoPlayer2 = Gano.getNumber();
        }
    }
    cout << VpetPlayer1[DigiActivoPlayer1]->toString() << endl;
    QPixmap* pixi = new QPixmap(VpetPlayer1[DigiActivoPlayer1]->getImage());
    ui->Player1Hp->setMaximum(VpetPlayer1[DigiActivoPlayer1]->getHp());
    ui->Player1Hp->setValue(VpetPlayer1[DigiActivoPlayer1]->getHp());
    ui->Player1NombreDigimon->setText(VpetPlayer1[DigiActivoPlayer1]->getName());
    pixi = new QPixmap(VpetPlayer1[DigiActivoPlayer1]->getImage());
    ui->Player1Digimon->setPixmap(*pixi);
    delete pixi;
}
