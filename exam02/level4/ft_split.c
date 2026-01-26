#include <stdlib.h>
/* sub: converte una stringa in diverse substringhe. */
char        **ft_split(char *str)
{
    /* 1. dichiara variabili e inizializza variabili.
    i -> righe
    j -> colonne
    k -> parole
    **split -> array di stringhe ritornato
    */
    int        i;
    int        j;
    int        k;
    char    **split;

    i = 0;
    k = 0;
    /* 2. allocazione di memoria e check sull'allocazione di memoria
    per risparmiare spazio,
    se fallisce ritorna NULL */
    if (!(split = (char **)malloc(sizeof(char *) * 256)))
        return (NULL);
    /* 3. skip spazi bianchi iniziali */
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i += 1;
    /* 4. ciclo principale per dividere la stringa
    in parole */
    while (str[i])
    {
        /* 5. inizializzazione delle colonne,allocazione di
        memoria per le parole e check sull'allocazione di memoria */
        j = 0;
        if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
            return (NULL);
        /* 6. quando non ci sono spazi bianchi,
        copia i caratteri di str aumentandoli ogni
        volta di 1 nella matrice split aumentata nelle righe
        ogni volta di 1 creata appositamente per mettere le
        sottostringhe. */
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
            split[k][j++] = str[i++];
        /* 7. skip spazi bianchi tra le parole */
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i += 1;
        /* 8. terminazione della stringa corrente e
        incremento dell'indice delle parole */
        split[k][j] = '\0';
        k += 1;
    }
    /* 9. terminazione dell'array di stringhe e return
    della stringa */
    split[k] = NULL;
    return (split);
}