/* sub: scrivi un programma che prende una stringa e la
stampa dopo aver rigirato la prima parola alla fine. */

#include <unistd.h>

int main(int ac, char **av)
{
    /* 1. dichiarazione variabili e inizalizzazione flag */
    int i;
    int start;
    int end;
    int flag;

    flag = 0;

    /* 2. check sugli argomenti e controlla se av comincia
    dal primo argomento. Inizializza anche i. */
    if(ac > 1 && av[1][0])
    {
        i = 0;
        /* 3. se ci sono degli spazi all'inizio li salta e
        inizializza start come il punto iniziale della parola. */
        while(av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        start = i;
        /* 4. se ci sono delle lettere della parola passa al
        prossimo carattere,una volta finito segna la fine in
        end */
        while(av[1][i] != '\0' && av[1][i] != ' ' && av[1][i] != '\t')
            i++;
        end = i;
        /* 5. salta i spazi dopo la prima parola */
        while(av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        /* 6. stampa il resto della stringa,evitando spazi
        e tabs duplicati */
        while(av[1][i])
        {
            while((av[1][i] == ' ' && av[1][i + 1] == ' ') 
            || (av[1][i] == '\t' && av[1][i + 1] == '\t'))
                i++;
            /* 7. scrive l'ultimo spazio prima dell'ultima
            parola,quella presa dall'inizio */
            if(av[1][i] == ' ' || av[1][i] == '\t')
                flag = 1;
            /* 8. scrive il resto della parola prima 
            dell'ultima */
            write(1, &av[1][i], 1);
            i++;
        }
        /* 9. scrive la prima parola alla fine mettendo prima
        lo spazio se c'e' */
        if(flag)
            write(1, " ", 1);
        while(start < end)
        {
            write(1, &av[1][start], 1);
            start ++;
        }
    }
    write(1, "\n", 1);
    return (0);
}