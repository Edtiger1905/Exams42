
#include <stdio.h>
#include <string.h>

/* 1. scopo

replica strpbrk: trova il primo carattere di s1 
che appartiene all'insieme di caratteri s2
*/

/* 2. Funione principale

scorre s1 dall'inizio e,per ogni carattere,
controlla se e' presente in s2
*/
char *ft_strpbrk(const char *s1,const char *s2)
{
    int i;

    /* 3. controllo input:
    se una delle stringhe e' NULL, non si puo' procedere
    */
   if(!s1 || !s2)
        return (0);

    /* 4. Scansione delle stringhe 
    per ogni carattere di s1,si confronta con tutti i 
    caratteri di s2 finche' non trova una corrispondenza
    */

    while (*s1)
    {
        i = 0;
        while (s2[i])
        {
            if(*s1 == s2[i])
                return((char *)s1);
            i++;
        }
        s1++;
    }
    /* 5. nessuna corrispondenza
    nessun carattere di s1 e' presente in s2
    */
    return(0);
}