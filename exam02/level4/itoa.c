/* sub: scrivi una funzione che converte un int in una
stringa terminata da null termianator. */

#include <stdlib.h>

char *ft_itoa(int nbr)
{
    /* 1. dichiara n come long per evitare overflow */
    char    *str;
    long    n;
    int     len;

    n = nbr;
    len = 0;
    /* 2. calcolo della lunghezza della stringa:
    gestisce il caso negativo incrementando la
    lunghezza per il segno meno */
    if(n <= 0)
    {
        len++;
        n = -n;
    }
    /* - divide n per 10 finché è maggiore di 0 per trovare
    il numero delle cifre. */
    while(n > 0)
    {
        n /= 10;
        len++;
    }
    /* 3. allocazione della stringa: aggiunge
    spazio per il null terminator */
    str = (char *)malloc(sizeof(char) * (len + 1));
    if(!str)
        return (NULL);
    str[len] = '\0';
    n = nbr;
    if(n < 0)
    {
        str[0] = '-';
        n = -n;
    }
    /* 4. costruzione della stringa: riempie la
    stringa dalla fine all'inizio con le cifre */
    if(n == 0)
        str[0] = '0';
    while(n > 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}