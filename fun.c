#include <stdio.h>
#include <time.h>
#include <unistd.h>
struct player {
    int hp;
    int mana;
    int stm;
};
struct attack {
    int dmg;
    int stm;
    int dfs;
};
struct boss{
    int hp;
    int dmg;
};
int loader(char word[]){
    int i,j = 0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("\r                         ");
            fflush(stdout);
            printf("\rLoading %s", word);
            printf("%.*s", j, "...");
            fflush(stdout);
            struct timespec req, rem;
            req.tv_sec = 0;
            req.tv_nsec = 100000000;

            nanosleep(&req, &rem);
        }
    }
    printf("Done!");
    return 0;
}
int menu(int opt, int arr[]){
    struct attack choice;
    switch(opt) {
        case 1:
            printf("1. God. 100 DMG 0 STM \n2. Dagger 10 DMG 2 STM \n3. Shield 0 DMG 20 DFS \n");
            scanf("%d", &opt);
            switch(opt) {
                case 1:
                    choice.dmg = 100;
                    choice.stm = 0;
                    choice.dfs = 0;
                    break;
                case 2:
                    choice.dmg = 10;
                    choice.stm = 2;
                    choice.dfs = 0;
                    break;
                case 3:
                    choice.dmg = 0;
                    choice.stm = 3;
                    choice.dfs = 20;
                    break;
            }
    }
    arr[0] = choice.dmg;
    arr[1] = choice.stm;
    arr[2] = choice.dfs;
    return 0;
}

int main() 
{
    int character;
    char knightstat[] = "HP 30, Mana 0, Stamina 15";
    char magestat[] = "HP 20, Mana 30, Stamina 10";
    char archerstat[] = "HP 15, Mana 15, Stamina 30";

    FILE *file = fopen("models", "r");
    if(file == NULL){
        return 1;
    }
    char ch;
    while((ch = fgetc(file)) != EOF){
        putchar(ch);
    }
    fclose(file);

    printf("\n");
    printf("Choose Your Character: \n 1 Knight:\t Attacks with High Damage | %s \n 2 Mage:\t Attacks with Short Range and Damage | %s \n 3 Archer: \t Attacks with Long Range | %s\n", knightstat, magestat, archerstat);
    scanf("%d", &character);

    int hp;
    int mana;
    int energy;

    loader("Character");

    struct player stats;

    switch(character)
    {
    case 1:
        stats.hp = 30;
        stats.mana = 10;
        stats.stm = 15;
        break;
    case 2:
        stats.hp = 20;
        stats.mana = 30;
        stats.stm = 10;
        break;
    case 3:
        stats. hp = 15;
        stats.mana = 15;
        stats.stm = 30;
        break;
    default:
        printf("[ERROR] '%s' is not a valid command.\n", character);
        break;
    }

    printf("\n-----------\nYour Stats are:\nHP %d\nMana %d\nStamina %d\n", stats.hp, stats.mana, stats.stm);
    sleep(5); 

    struct boss spider;
    loader("First Enemy");
    spider.hp = 100;
    spider.dmg = 2;
    int attack[3];
    hp = stats.hp;
    mana = stats.mana;
    energy = stats.stm;
    // make a badass spider image
    printf("\n----------------\nAHHHH a SPIDER appears out of the shadows! What will you do!? \n \nHP %d DMG %d\n", spider.hp, spider.dmg);
    do{
        menu(character, attack);
        spider.hp -= attack[0];
        energy -= attack[1];
        hp -= (spider.dmg - attack[2]);
        printf("Spider: %dHP \nYou: %dHP, %d Energy, %d Mana\n", spider.hp, hp, energy, mana);
    } while(spider.hp > 0 & hp > 0);
    if(spider.hp <= 0){
        printf("You killed the Spider!!\n");
    }
    if(hp <= 0){
        printf("You died :<\n");
    }
    return 0;
}
