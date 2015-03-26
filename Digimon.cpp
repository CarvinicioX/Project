#include "Digimon.h"
#include <QString>
#include <sstream>

using namespace std;

Digimon::Digimon(QString Name, int Hp, int Attack, QString image) {
    this->Name = Name;
    this->Hp = Hp;
    this->Attack = Attack;
    this->image = image;
}

Digimon::Digimon(const Digimon& rhs):Name(rhs.Name),Hp(rhs.Hp),Attack(rhs.Attack),image(rhs.image) {

}

Digimon::~Digimon() {
}

int Digimon::getHp()const {
    return Hp;
}

QString Digimon::getName()const {
    return Name;
}

int Digimon::getAttack()const {
    return Attack;
}

QString Digimon::getImage()const {
    return image;
}

string Digimon::toString()const {
    stringstream ss;
    ss << "Name: " << Name.toStdString() << ", Hp: " << Hp << ", Attack: " << Attack;
    return ss.str();
}
