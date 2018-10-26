#include <iostream>
#include <thread>
#include <vector>
#include "chars.h"
using namespace std;

void fight(Chars& player,Chars& enemy)
{
    while(player.getAlive() && enemy.getAlive())
    {
        enemy.setAlive(!(attack(player,enemy)));
        if(enemy.getAlive())
            player.setAlive(!(attack(enemy,player)));
    }
}
void game(Chars& player)
{

    while(player.getAlive())
    {
        int enemyHealth=player.getLevel()*40;
        int enemyAttack=player.getLevel()*2;
        int enemyDefense=player.getLevel()*1;
        int enemyDodge=player.getLevel()*1;
        Chars enemy(enemyHealth,enemyAttack,enemyDefense,enemyDodge,true,0);
        fight(player,enemy);
        if(player.getAlive())
        {
            int chanceOfLevelUp = rand()%10;
            if(rand()%100<chanceOfLevelUp)
                player.levelUp();
            player.setLevel(player.getLevel()+1);
        }
        else
        {
            cout << "player has been slain at level "<< player.getLevel()<<endl;
            break;
        }

    }
}

int main()
{
    typedef vector<Chars> Players;
    int nbrPlayer(50);
    Players players(nbrPlayer,Chars(1000,5,2,2,true,1));

    typedef vector<thread> Games;
    Games games;

    for(int i=0;i<players.size();i++)
    {
        games.emplace_back(thread(game,std::ref(players[i])));
    }
    for(int i=0;i<players.size();i++)
    {
        games[i].join();
    }

    return 0;

}
