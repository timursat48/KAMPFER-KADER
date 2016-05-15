#include<stdio.h>

void usdintorub(float one_usd_in_rub);
void eurintorub(float one_eur_in_rub);
int main()
{

    const float one_usd_in_rub = 66.44;
    const float one_eur_in_rub = 74.96;
    int what;
    printf("\tExchange Rates for ~March 2016\n\n1) USD-RUB\n2) EUR-RUB\nInput number : ");
    scanf("%d",&what);
    switch (what)
    {
    case 1:
        usdintorub(one_usd_in_rub);
        break;
    case 2:
        eurintorub(one_eur_in_rub);
        break;
    default:
        main();
        break;
    }
    getchar();
    return 0;
}

