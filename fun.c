#include <stdio.h>
#include <stdlib.h>

int main() {
    char character;
    char knightstat[] = "HP 30, Mana 5, Stamina 15";
    char magestat[] = "HP 20, Mana 30, Stamina 10";
    char archerstat[] = "HP 15, Mana 15, Stamina 30";
    printf("Choose Your Character: \n Knight:\t %s \n Mage:\t %s \n Archer: \t %s\n", knightstat, magestat, archerstat);
    scanf("%s", &character);
    printf("%s\n", character);
    return 0;
}
