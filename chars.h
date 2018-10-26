#ifndef CHARS_H
#define CHARS_H
#include<iostream>



class Chars
{private:
    int health;
    int attack;
    int defense;
    int dodge;
    bool alive;
    int levels;
public:
    Chars();
    Chars(int, int, int, int, bool,int);
    inline int getHealth(){return health;}
    inline int getAtack(){return attack;}
    inline int getDefense(){return defense;}
    inline int getDodge(){return dodge;}
    inline bool getAlive(){return alive;}
    inline int getLevel(){return levels;}

    inline void setHealth(int newHealth){health = newHealth;}
    inline void setAttack(int newAttack){attack=newAttack;}
    inline void setDefense(int newDefese){defense=newDefese;}
    inline void setDodge(int newDodge){dodge = newDodge;}
    inline void setAlive(bool newAlive){alive=newAlive;}
    inline void setLevel(int newLevel){levels = newLevel;}

    void levelUp();


};
bool attack(Chars& attacker,Chars& victim);


#endif // CHARS_H
