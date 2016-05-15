#include<stdio.h>
int main();
void usdintorub(float one_usd_in_rub)
{
    int change;
    float rub;
    float usd;
    printf("=============\n    USD-RUB\n=============\n");
    printf("USD : ");
    scanf("%f", &usd);
    rub = one_usd_in_rub*usd;
    printf("%.2f USD ~ %.2f RUB\n\n", usd, rub);
    getchar();
    printf("Continue or in main menu?\n1)Continue\n2)Main menu\n");
    scanf("%d",&change);
    switch(change)
    {
    case 1:
        usdintorub(one_usd_in_rub);
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

