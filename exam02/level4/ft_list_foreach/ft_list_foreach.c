
/* sub: scrivi una funzione che prende una lista e un pointer
a funzione e lo applica a qualsiasi elemento della lista.*/

#include <stdlib.h>
#include "ft_list.h"

/* 1. funzione principale: prende la lista 
e la funzione da applicare */
void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    /* 2. dichiara una variabile come parte della lista e 
    la inizializza facendola diventare l'inizio della lista.*/
    t_list *list_ptr;

    list_ptr = begin_list;
    /* 3. fino a quando non finisce la lista,passa al prossimo elemento quando converte 
     */
    while (list_ptr)
    {
        (*f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}