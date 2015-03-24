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
    vector<Digimon*> Vpet;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_Player1Attack_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
