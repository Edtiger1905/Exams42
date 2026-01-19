/* sub: scrivi un programma che prende un int positivo e
stampa i suoi fattoriali primi sul stdout,seguito da un newline.
i fattoriali devono essere sistemati in ordine ascendente e
separati da un '*'. */

#include <stdio.h>
#include <stdlib.h>

/* 1. funzione principale: serve a trovare i fattoriali primi */
int main(int ac, char *av[])
{
    /* 2. dichiarazione delle variabili,check argomenti
    e inizializzazione delle variabili. */
    int i;
    int num;

    if(ac == 2)
    {
        i = 1;
        num = atoi(av[1]);
        /* 3. se il numero e' uguale a 1,stampa 1 */
        if(num == 1)
            printf("1");
        /* 4. ciclo per trovare i fattoriali primi:
        parte da 2 e se num e' divisibile per i, stampa
        i. Se num e' uguale a i, rompe il ciclo. Senno'
        stampa il '*' e divide num per i. Reimposta i a 1 e
        ricomincia il ciclo fino a quando num e' maggiore 
        o uguale a i. */
        while(num >= ++i)
        {
            if(num % i == 0)
            {
                printf("%d", i);
                if(num == i)
                    break;
                printf("*");
                num /= i;
                i = 1;
            }
        }
    }
    printf("\n");
    return (0);
}