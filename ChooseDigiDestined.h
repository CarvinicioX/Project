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
    int Player1;
    int Player2;
    vector<DigiDestined> DigiDestinados;
public:
    explicit ChooseDigiDestined(int&, int&, vector<DigiDestined>, QWidget *parent = 0);
    ~ChooseDigiDestined();

private slots:
    void on_Player1SelectionComboBox_currentIndexChanged(int index);

    void on_Player2SelectionComboBox_currentIndexChanged(int index);

    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::ChooseDigiDestined *ui;
};

#endif // CHOOSEDIGIDESTINED_H
