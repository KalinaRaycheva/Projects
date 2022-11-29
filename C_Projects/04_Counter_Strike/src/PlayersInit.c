#include "PlayerInit.h"
#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>

static Player* getPlayer(int id,int health,int armor)
{
    Player* player=(Player*)malloc(sizeof(Player));//new
    player->playerId=id;
    setArmor(&player->playerData, armor);
    setHealth(&player->playerData, health);
    return player;
}

static void createPistol(Pistol* pistol,enum PistolType type,int damage,int clipSize,int bullets,int ammo)
{
    pistol->pistolType=type;
    pistol->remainingAmmo=ammo;
    pistol->damagePerRound=damage;
    pistol->currClipBullets=bullets;
    pistol->clipSize=clipSize;
}

void initPlayers(BattleField *bf)// Vector* players
{
    int playerHealth = 0;
    int playerArmor = 0;
    Player* currentPlayer;
    vectorInit(&bf->players,PLAYERS_COUNT);//vectorInit(players,PLAYERS_COUNT);

    for (int player = 0; player < PLAYERS_COUNT; player++)
    {
        scanf("%d %d", &playerHealth, &playerArmor);
        currentPlayer=getPlayer(player, playerHealth, playerArmor);
        vectorPush(&bf->players,currentPlayer);
    }
}

void buyPistols(BattleField *bf)
{
    int pistolId = 0;
    int pistolDamagePerRound = 0;
    int pistolClipSize = 0;
    int pistolRemainingAmmo = 0;
    Player* currentPlayer;
    for (int player = 0; player < PLAYERS_COUNT; player++)//vectorGetSize(players)
    {
        scanf("%d %d %d %d", &pistolId, &pistolDamagePerRound, &pistolClipSize, &pistolRemainingAmmo);
        currentPlayer=vectorGet(&bf->players,player);
        createPistol(&currentPlayer->pistol,pistolId,pistolDamagePerRound,pistolClipSize,pistolClipSize,pistolRemainingAmmo);
    }
}

void deinit(BattleField* battleField){
    for (size_t player = 0; player < PLAYERS_COUNT; player++)
    {
        Player *currPlayer = vectorGet(&battleField->players, player);
        free(currPlayer);
        currPlayer = NULL;
    }
    vectorFree(&battleField->players);
}
