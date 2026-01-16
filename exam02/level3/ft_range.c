/* sub: dobbiamo allocare un array di int con il malloc e
riempirlo con i valori da start a end compresi,e ritornare
un pointer al primo valore dell'array
es:
(1, 3) -> ritorna 1,2,3
(-1, 2) -> ritorna -1,0,1,2 */
#include <stdlib.h>

/* 1. funzione principale: alloca e restituisce un array di
interi,come da subject */
int *ft_range(int start, int end)
{
    int i;
    int len;
    int *res;
    /* 2. calcolo della dimensione: la lunghezza e'
    la distanza tra start ed end piu' 1 per includere
    entrambi */
    i = 0;
    res = (int *)malloc(sizeof(int) * len);
    /* 3. check sul malloc e calcolo lunghezza senza
    funzioni esterne */
    if(!res)
        return (NULL);

    if(start < end)
        len = end - start + 1;
    else
        len = start - end + 1;
    /* 4. riempimento dell'array: inserisce i valori partendo
    da start fino ad arrivare a end. */
    while(i < len)
    {
        if(start < end)
        {
            res[i] = start;
            start++;
            i++;
        }
        else
        {
            res[i] = start;
            start--;
            i++;
        }
    }
    return (res);
}
