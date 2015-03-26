#include "DigiDestined.h"
#include "Digimon.h"
#include "Vaccine.h"
#include "Data.h"
#include "Virus.h"
#include <sstream>
#include <QString>
#include <iostream>

using namespace std;

DigiDestined::DigiDestined(QString Name, QString Image) {
    this->Name = Name;
    this->Image = Image;
    this->setWinns();
}

DigiDestined::~DigiDestined()
{

}

void DigiDestined::setWinns() {
    Winns = 0;
}

QString DigiDestined::getImage()const {
    return Image;
}

QString DigiDestined::getName()const {
    return Name;
}

int DigiDestined::getWinns()const {
    return Winns;
}

string DigiDestined::toString()const {
    stringstream ss;
    ss << "DigiDestines: " << Name.toStdString() << ", Winns: " << Winns << ", ";
    return ss.str();
}
