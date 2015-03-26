#ifndef CHOOSEDIGIDESTINED_H
#define CHOOSEDIGIDESTINED_H

#include <QDialog>
#include "DigiDestined.h"
#include "Digimon.h"

namespace Ui {
class ChooseDigiDestined;
}

class ChooseDigiDestined : public QDialog
{
    Q_OBJECT
    vector<DigiDestined> DigiDestinados;
    int Player1, Player2;
protected:
public:
    Ui::ChooseDigiDestined *ui;
    explicit ChooseDigiDestined(vector<DigiDestined>, QWidget *parent = 0);
    ~ChooseDigiDestined();
    int retornaIndicePlayer1()const;
    int retornaIndicePlayer2()const;
private slots:
    void on_Player1SelectionComboBox_currentIndexChanged(int index);

    void on_Player2SelectionComboBox_currentIndexChanged(int index);

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

};

#endif // CHOOSEDIGIDESTINED_H
