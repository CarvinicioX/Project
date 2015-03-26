#include "Virus.h"
#include "Digimon.h"
#include "QString"
#include "sstream"

using namespace std;

Virus::Virus(QString Name, int Hp, int Attack, QString image):Digimon(Name, Hp, Attack, image), Type(3){
}

Virus::Virus(const Digimon& rhs):Digimon(rhs.getName(), rhs.getHp(), rhs.getAttack(), rhs.getImage()),Type(3) {
}

Virus::~Virus()
{

}

int Virus::Defend(int Type)const {
    if (Type == 1) {
        return 0;
    } else if (Type == 2) {
        return Attack;
    } else if (Type == 3) {
        return Attack/2;
    }
    return 0;
}

int Virus::getType()const {
    return Type;
}

string Virus::toString()const {
    stringstream ss;
    ss << Digimon::toString() << ", Attribute: Vaccine";
    return ss.str();
}
