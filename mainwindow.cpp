#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ChooseDigiDestined.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    int Player111;
    int Player222;
    DigiDestinados.push_back(DigiDestined("Cody", ":/new/DigiElegidos/Digimon/D.png"));
    DigiDestinados.push_back(DigiDestined("Davis", ":/new/DigiElegidos/Digimon/Davis.png"));
    DigiDestinados.push_back(DigiDestined("Kari", ":/new/DigiElegidos/Digimon/Kari.png"));
    DigiDestinados.push_back(DigiDestined("Ken", ":/new/DigiElegidos/Digimon/Ken.png"));
    DigiDestinados.push_back(DigiDestined("T.K.", ":/new/DigiElegidos/Digimon/TdotKdot.png"));
    DigiDestinados.push_back(DigiDestined("Yolei", ":/new/DigiElegidos/Digimon/Yolei.png"));
    ui->setupUi(this);
    ChooseDigiDestined Choose(Player111, Player222, DigiDestinados);
    Choose.exec();
    QString ss;
    ss.setNum(Player111);
    ui->Player1Name->setText(ss);
    ss.setNum(Player222);
    ui->Player2Name->setText(ss);
    Digimon* NewDigi1 = new Vaccine("Armadillomon", 650, 190, ":/new/Digimons/Digimon/Armadillomon.png");
    Digimon* NewDigi2 = new Vaccine("Gatomon", 750, 210, ":/new/Digimons/Digimon/Gatomon.png");
    Digimon* NewDigi3 = new Data("Hawkmon", 600, 220, ":/new/Digimons/Digimon/Hawkmon.png");
    Digimon* NewDigi4 = new Data("Patamon", 630, 170, ":/new/Digimons/Digimon/Patamon.png");
    Digimon* NewDigi5 = new Virus("Veemon", 550, 200, ":/new/Digimons/Digimon/Veemon.png");
    Digimon* NewDigi6 = new Virus("Wormmon", 550, 170, ":/new/Digimons/Digimon/Wormmon.png");
    Vpet.push_back(NewDigi1);
    Vpet.push_back(NewDigi2);
    Vpet.push_back(NewDigi3);
    Vpet.push_back(NewDigi4);
    Vpet.push_back(NewDigi5);
    Vpet.push_back(NewDigi6);
    Vpet.swap(Vpet);
    QString str = QString::fromStdString(Vpet[0]->getName());
    ui->Player1Hp->setMaximum(Vpet[0]->getHp());
    ui->Player1Hp->setValue(Vpet[0]->getHp());
//    ui->Player1Name->setText(str);
    str = QString::fromStdString(Vpet[1]->getName());
    ui->Player2Hp->setMaximum(Vpet[1]->getHp());
    ui->Player2Hp->setValue(Vpet[1]->getHp());
//    ui->Player2Name->setText(str);
    QPixmap* mipi = new QPixmap(":/new/Sprites/Digimon/Background.png");
    ui->Background->setPixmap(*mipi);
    delete mipi;
    ui->Background->lower();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Player1Attack_clicked()
{

}
