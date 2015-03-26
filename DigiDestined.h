#ifndef DIGIDESTINED_H
#define DIGIDESTINED_H

#include "Digimon.h"
#include "Vaccine.h"
#include "Data.h"
#include "Virus.h"
#include <QString>
#include <vector>

using namespace std;

class DigiDestined {
    QString Name;
    int Winns;
    QString Image;
public:
    DigiDestined(QString, QString);
    ~DigiDestined();
    void setWinns();
    QString getImage()const;
    QString getName()const;
    int getWinns()const;
    string toString()const;
};

#endif // DIGIDESTINED_H
