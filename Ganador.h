#ifndef GANADOR_H
#define GANADOR_H

#include <QDialog>

namespace Ui {
class Ganador;
}

class Ganador : public QDialog
{
    Q_OBJECT

public:
    explicit Ganador(QWidget *parent = 0);
    ~Ganador();
    int getNumber()const;

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

private:
    Ui::Ganador *ui;
};

#endif // GANADOR_H
