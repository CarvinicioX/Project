#include "Vaccine.h"
#include "Digimon.h"
#include "QString"
#include "sstream"

using namespace std;

Vaccine::Vaccine(QString Name, int Hp, int Attack, QString image):Digimon(Name, Hp, Attack, image),Type(1){
}

Vaccine::Vaccine(const Digimon& rhs):Digimon(rhs.getName(), rhs.getHp(), rhs.getAttack(), rhs.getImage()),Type(1) {
}

Vaccine::~Vaccine()
{

}

int Vaccine::Defend(int Type)const {
    if (Type == 1) {
        return Attack/2;
    } else if (Type == 2) {
        return 0;
    } else if (Type == 3) {
        return Attack;
    }
    return 0;
}

int Vaccine::getType()const {
    return 1;
}

string Vaccine::toString()const {
    stringstream ss;
    ss << Digimon::toString() << ", Attribute: Vaccine";
    return ss.str();
}
