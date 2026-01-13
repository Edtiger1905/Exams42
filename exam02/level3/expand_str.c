/* sub: prendere una stringa e in mezzo
alle parole mettere essatamente 3 spazi,
senza spazi o tabs tra di loro.  */

#include <unistd.h>
int main(int ac,char const *av[])
{
    /* 1. dichiarazione delle variabili e check iniziali:
    dichiara i e flag e fa check sugli argomenti. */
    int i;
    int flag;
    if(ac == 2)
    {
        i = 0;
        /* 2. Salta spazi fino alla prima parola */
        while(av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        /* 3. Cuore della funzione: scorre la stringa fino al null terminator,controlla se ci sono spazi o tabs.
        Se ci sono imposta flag a 1. Il secondo ciclo effettivamente e' il cuore della funzione, quando non ci sono spazi
        o tabs e flag = 1, mette 3 spazi,stampando il carattere comunque.*/
        while(av[1][i])
        {
            if(av[1][i] == ' ' || av[1][i] == '\t')
                flag = 1;
            if(!(av[1][i] == ' ' || av[1][i] == '\t' ))
            {
                if(flag)
                    write(1, "   ", 3);
                    flag = 0;
                    write(1, &av[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}