#include "Data.h"
#include "Digimon.h"
#include "QString"
#include "sstream"

using namespace std;

Data::Data(QString Name, int Hp, int Attack, QString image):Digimon(Name, Hp, Attack, image),Type(2){
}

Data::Data(const Digimon& rhs):Digimon(rhs.getName(), rhs.getHp(), rhs.getAttack(), rhs.getImage()),Type(2) {
}

Data::~Data()
{

}

int Data::Defend(int Type)const {
    if (Type == 1) {
        return Attack;
    } else if (Type == 2) {
        return Attack/2;
    } else if (Type == 3) {
        return 0;
    }
    return 0;
}

int Data::getType()const {
    return Type;
}

string Data::toString()const {
    stringstream ss;
    ss << Digimon::toString() << ", Attribute: Data";
    return ss.str();
}
