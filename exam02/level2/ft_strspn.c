
#include <string.h>

/* (1) SCOPO
   Replica il comportamento di strspn: conta quanti caratteri
   iniziali di una stringa appartengono a un insieme dato. */


/* (2) FUNZIONE DI SUPPORTO
   ft_strchr cerca un carattere in una stringa e restituisce
   un puntatore alla sua prima occorrenza oppure NULL. */
char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return ((char *)s);
        ++s;
    }
    return (0);
}


/* (3) FUNZIONE PRINCIPALE
   Scorre la stringa dall'inizio e si ferma
   al primo carattere non presente in accept. */
size_t ft_strspn(const char *s, const char *accept)
{
    size_t i;

    /* (4) INIZIALIZZAZIONE E SCANSIONE
       i conta i caratteri validi finché sono presenti in accept. */
    i = 0;
    while (s[i] != '\0' && ft_strchr(accept, s[i]) != 0)
        ++i;

    /* (5) RISULTATO */
    return (i);
}
