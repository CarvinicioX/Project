#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <DigiDestined.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    vector<DigiDestined> DigiDestinados;
    DigiDestined* Player1;
    DigiDestined* Player2;
    int DigiActivoPlayer1, DigiActivoPlayer2;
    vector<Digimon*> Vpet;
    vector<Digimon*> VpetPlayer1;
    vector<Digimon*> VpetPlayer2;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void CambiarTurno()const;

private slots:
    void on_Player1Attack_clicked();

    void on_Player2Cambiar_clicked();

    void on_Player2Attack_clicked();

    void on_Player1Cambiar_clicked();

private:
    Ui::MainWindow *ui;
    string toString()const;
};

#endif // MAINWINDOW_H
