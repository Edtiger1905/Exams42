/* sub: scrivi un programma che prende 2 stringhe e stampa 1
seguito da un newline se la prima stringa e' nascosta nella 
seconda, senno' stampa 0 seguito da un newline.
*/
#include <unistd.h>

/* 1. funzione principale: verifica se la prima stringa
e' una sottosequenza della seconda come da subject */
int main(int ac,char **av)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    /* 2. controllo argomenti: il programma funziona solo con
    due argomenti */
    if(ac == 3)
    {
        /* 3. scansione delle stringhe: scorre la seconda 
        stringa cercando,in ordine,i caratteri della prima */
        while(av[2][j] && av[1][i])
        {
            if(av[2][j] == av[1][i])
                i++;
            j++;
        }
        /* 4. risultato: se tutti i caratteri della prima
        stringa sono stati trovati,stampa 1, altrimenti 0. */
        if(av[1][i] == '\0')
            write(1,"1",1);
        else
            write(1,"0",1);
    }
    write(1,"\n",1);
    return (0);
}