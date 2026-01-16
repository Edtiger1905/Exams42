/* sub: scrivi un programma che prende un numero da linea
di comando e stampa la tabelline dall'1 al 9 di quel numero */
#include <unistd.h>

/* 1. funzione di supporto: questo ft_atoi gestisce spazi,
segno e cifre numeriche.*/
int ft_atoi(char *str)
{
    int res;
    int sign;

    res = 0;
    sign = 1;
    /* 2. salta spazi iniziali */
    while(*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    /* 3. gestione del segno */
    if(*str == '-')
        sign = -1;
    if(*str == '+' || *str == '-')
        str++;
    /* 4. costruzione del numero */
    while(*str >= '0' && *str <= '9')
    {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);
}
/* 5. funzione di supporto: stampa un carattere */
void ft_putchar(char c)
{
    write(1, &c, 1);
}
/* 6. funzione di supporto: stampa un numero intero e 
gestisce i numeri negativi e il caso limite INT_MIN */
void ft_putnbr(int nb)
{
    /* 7. per non incorrere in overflow,dichiarazione
    di una variabile long */
    long n;

    n = nb;
    /* 8. gestione del segno */
    if(n < 0)
    {
        ft_putchar('-');
        n *= -1;
    }
    /* 9. ricorsione per stampa cifra per cifra */
    if(n / 10 > 0)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}
/* 10 funzione principale: stampa le tabelline da 1 a 9 
di un numero preso da linea di comando */
int main(int ac, char *av[])
{
    /* 11. dichiarazione variabili,check argomenti e
    inizializzazione.*/
    int i;
    int nbr;

    if(ac == 2)
    {
        i = 1;
        nbr = ft_atoi(av[1]);
        /* 12. stampa le tabelline da 1 a 9.
        i x nbr = risultato */
        while(i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(nbr);
            write(1, " = ", 3);
            ft_putnbr(i * nbr);
            write(1, "\n", 1);
            i += 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}
