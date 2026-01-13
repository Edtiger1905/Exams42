/* sub: scrivere una stringa con gli
spazi esatti,senza tabs o altro*/

#include <unistd.h>

int main(int ac,char const **av)
{
    /* 1. dichiarazioni di funzioni e check iniziali */
    int i;
    int flg;

    if(ac == 2)
    {
        i = 0;
        /* 2. check della stringa: se trova uno spazio o un
        tab all'inzio della stringa salta quel carattere,
        fino a quando non trova un carattere */
        while(av[1][i] == ' ' || av[1][i] == '\t')
            i += 1;
        /* 3. cuore della funzione: fino a quando la stringa non
        arriva al null terminator,scorre la stringa. Se trova un
        carattere di quelli proibiti imposta flg a 1 come reminder
        per lo spazio. Se non trova lo spazio,controlla se flg esiste
        e mette lo spazio dove serve,azzerando poi flg.
        Stampa il carattere comunque,anche se salta la condizione. */
        while(av[1][i])
        {
            if(av[1][i] == ' ' || av[1][i] == '\t')
                flg = 1;
            if(!(av[1][i] == ' ' || av[1][i] == '\t'))
            {
                if(flg)
                    write(1, " ", 1);
                flg = 0;
                write(1, &av[1][i], 1);
            }
            /* 4. Check finali e chiusura programma: incrementa la i,
            questa scrittura equivale a: "i = i + 1;",mette la newline
            come da sub e mette il return. */
            i += 1;
        }
    }
    write(1, "\n", 1);
    return (0);
}