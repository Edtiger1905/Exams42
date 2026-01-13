#include "ft_list.h"
/* sub: conta il numero degli elementi
in una lista concatenata*/

/* 1. Funzione principale: calcola
il numero di elementi in una 
lista concatenata*/

int ft_list_size(t_list *begin_list)
{
    /* 2. Caso base: lista vuota */
    if(begin_list == 0)
        return (0);
    else
    /* 3. Caso ricorsivo: conta il nodo corrente
    e continua con il resto della lista. */
        return (1 + ft_list_size(begin_list->next));
}