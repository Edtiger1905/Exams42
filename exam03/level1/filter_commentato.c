/* Sub: scrivi un programma che legge dallo standard input e sostituisce tutte le occorrenze
di una stringa data (passata come argomento) con asterischi ('*'), poi scrive il risultato
sullo standard output. Se il numero di argomenti non è 1, ritorna. */

/* Blocco 0: Librerie
- unistd.h -> fornisce read e write
- string.h -> fornisce strlen
- stdlib.h -> fornisce malloc e free
*/
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* Blocco 1: ft_strjoin -> Concatena la stringa s1 con il primo carattere di s2, libera s1
e ritorna la nuova stringa allocata.

Flusso:
1. Dichiara i e lo inizializza a 0.
2. Alloca memoria per una nuova stringa: strlen(s1) + 2 byte (lunghezza di s1 +
1 carattere da s2 + terminatore \0).
3. Controlla se malloc e' riuscita. Se fallisce,ritorna NULL immediatamente.
4. Copia tutti i caratteri di s1 nella nuova stringa usando un while:
    - Copia s1[i] in str[i].
    - Incrementa i.
5. Aggiunge il primo carattere di s2 alla fine: str[i] = s2[0].
6. Aggiunge il terminatore: str[i + 1] = '\0'.
7. Libera la memoria di s1 con free(s1) perche' non serve piu' (viene sostituita 
dalla nuova stringa).
8. Ritorna il puntatore alla nuova stringa.
*/
char *ft_strjoin(char *s1,char *s2)
{
    int i = 0;
    char *str = malloc(strlen(s1) + 2);

    if(!str)
        return (NULL);
    while(s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = s2[0];
    str[i + 1] = '\0';
    free(s1);
    return (str);
}

/* Blocco 2: main -> Punto di ingresso del programma. Legge l'input, cerca il pattern e lo 
sostituisce con asterischi.
Flusso:
1. 
*/
int main(int ac, char **av)
{
    int i = 0, j, len;
    char *str, buf[1];

    if(ac != 2)
        return (1);
    str = malloc(1);
    str[0] = '\0';
    len = strlen(av[1]);
    while(read(0, buf, 1))
        str = ft_strjoin(str, buf);
    while(str[i])
    {
        j = 0;
        while(str[i + j] && av[1][j] && str[i + j] == av[1][j])
            j++;
        if(j == len)
        {
            while(j-- > 0)
                str[i++] = '*';
        }
        else
            i++;
    }
    write(1, str, strlen(str));
    free(str);
    return (0);
}