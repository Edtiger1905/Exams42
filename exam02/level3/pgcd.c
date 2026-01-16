/* sub: scrivi un programma che prende 2 
stringhe con dentro numeri che entrano nella
dimensione degli int,e stampa il loro 
MCD(massimo comune divisore). 
Se il numero dei parametri non e' 2, stampa una newline. */

#include <stdlib.h>
#include <stdio.h>

/* 1. funzione principale: fa tutti calcoli del caso e stampa
l'MCD. */

int main(int ac, char const *av[])
{
    int n1;
    int n2;

    /* 2. conversione input: converte gli argomenti
    da stringa a intero */
    n1 = atoi(av[1]);
    n2 = atoi(av[2]);
    /* 3. controllo argomenti: il programma 
    funziona solo con due numeri positivi passati 
    come argomenti */
    if(ac == 3)
    {
        if(n1 > 0 && n2 > 0)
        {
            /* 4. algoritmo di  Euclide(per sottrazione): 
            riduce i due numeri finche' diventano uguali. */
            while(n1 != n2)
            {
                if(n1 > n2)
                    n1 -= n2;
                else
                    n2 -= n1;
            }
            /* 5. stampa del risultato: quando i numeri
            coincidono, il valore e' l'MCD. */
            printf("%d", n1);
        }
    }
    printf("\n");
    return (0);
}