/* sub: scrivi un programma che stampa il
numero degli argomenti che gli vengono passati,
seguiti da newline. Se non ci sono argomenti,
stampa 0 seguito da una newline. */

#include <unistd.h>

/* 1. funzione di supporto: stampa un intero positivo cifra
per cifra usando la ricorsione */

void ft_putnbr(int n)
{
    char digit;
    /* 2. ricorsione: se il numero ha piu' di una cifra,
    stampa prima tutte le cifre piu'significative */
    if(n >= 10)
        ft_putnbr(n / 10);
    /* 3. stampa della cifra corrente: converte l'ultima 
    cifra in carattere e la scrive su stdout */
    digit = (n % 10) + '0';
    write(1, &digit, 1);
}
/* 4. funzione pricipale: stampa il numero di argomenti 
passati al programma (escluso il nome) */
int main(int argc, char **argv)
{
    (void)argv;
    /* 5. calcolo argomenti: argc include il nome del programma
    quindi si sottrae 1. */
    ft_putnbr(argc - 1);
    write(1, "\n", 1);
    return (0);
}