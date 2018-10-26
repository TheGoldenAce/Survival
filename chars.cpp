#include "chars.h"

Chars::Chars()
{
   health = 100;
   attack=12;
   defense= 0;
   dodge=0;
   alive=true;
   levels=0;

}

Chars::Chars(int baseHealth = 100, int baseAtack =12, int baseDefense =0, int baseDodge = 0, bool baseAlive=true, int baseLevel=0) :
               health(baseHealth)
             , attack(baseAtack)
             , defense(baseDefense)
             , dodge(baseDodge)
             , alive(baseAlive)
             , levels(baseLevel){}

void Chars::levelUp()
{
 health*= (((rand()%100)/100)+1);
 attack+= rand()%5;
 defense+= 1;
 dodge+= 1;
}

bool attack(Chars& attacker,Chars& victim)
{
    int TryToDodge = rand()% victim.getDodge();

    if(rand()%100<TryToDodge)
        return false;
    else
    {
        victim.setHealth(victim.getHealth()-(attacker.getAtack()*(victim.getDefense()*(1-0.01))));
        if(victim.getHealth()<=0)
            return true;
        return false;
    }
}
