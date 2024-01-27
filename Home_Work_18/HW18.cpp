#include <iostream>
#include "PlayerClass.h"
#include "Weapon.h"
#include "Player.h"


int main()
{
    
    Player* firstPlayer = new Player(new SniperRifle, new Attacker, "Firstone");

    Player* secondPlayer = new Player(new Sword, new Attacker, "Secondone");

    for (int i = 0; i < 100; i++)
    {
        firstPlayer->attack(secondPlayer, 700);
    }
   

}
