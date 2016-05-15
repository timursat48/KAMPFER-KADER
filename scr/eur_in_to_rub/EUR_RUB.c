#include<stdio.h>
int main();
void eurintorub(float one_eur_in_rub)
{
    int change;
    float rub;
    float eur;
    printf("=============\n    EUR-RUB\n=============\n");
    printf("EUR : \n");
    scanf("%f", &eur);
    rub = one_eur_in_rub*eur;
    printf("%.2f EUR ~ %.2f RUB\n\n", eur, rub);
    getchar();
    printf("Continue or in main menu?\n1)Continue\n2)Main menu\n");
    scanf("%d",&change);
    switch(change)
    {
    case 1:
        eurintorub(one_eur_in_rub);
        break;
    case 2:
        main();
        break;
    default:
        main();
        break;
    }
    getchar();
}
