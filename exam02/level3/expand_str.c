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
        /* 2. salta spazi  */
        while(av[1][i] == ' ' || av[1][i] == '\t')
            i++;
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