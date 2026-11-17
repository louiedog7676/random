#include <stdio.h>
#include <time.h>

int loader(){
    int i,j,n = 0;
    for(; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("\r                      ");
            fflush(stdout);
            printf("\rLoading Character");
            printf("%.*s", j, "...");
            fflush(stdout);
            struct timespec req, rem;
            req.tv_sec = 0;
            req.tv_nsec = 300000000;

            nanosleep(&req, &rem);
        }
    }
    return 0;
}

int main() 
{
    int character;
    char knightstat[] = "HP 30, Mana 10, Stamina 15";
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
    printf("Choose Your Character: \n 1 Knight:\t %s \n 2 Mage:\t %s \n 3 Archer: \t %s\n", knightstat, magestat, archerstat);
    scanf("%d", &character);
    int hp;
    int mana;
    int stamina;
    loader();
    switch(character)
    {
    case 1:
        hp = 30;
        mana = 10;
        stamina = 15;
        break;
    case 2:
        hp = 20;
        mana = 30;
        stamina = 10;
        break;
    case 3:
        hp = 15;
        mana = 15;
        stamina = 30;
        break;
    default:
        printf("[ERROR] '%s' is not a valid command.\n", character);
        break;
    }
    printf("\n Your Stats are:\n HP %d\n Mana %d\n Stamina %d\n", hp, mana, stamina);
    return 0;
}
