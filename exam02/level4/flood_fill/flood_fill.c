/* sub: scrivi una funzione che prendere una matrice
bidimensionale di char, un t_point della dimensione dell'array
e un t_point iniziale.
Partendo dal dato 'begin' t_point, questa funzione riempie
un intera zona rimpiazzando tutti i caratteri dentro con
il carattere 'F'. Una zona e' un gruppo di stessi caratteri
delimitati orizzontalmente e verticalmente da altri 
caratteri o dal limite dell'array. */

#include "flood_fill.h"
void fill(char **tab, t_point size,t_point cur,char to_fill)
{
    /* 1. condizioni di arresto: ferma la ricorsione se:
    - si esce dalla griglia
    - la cella non contiene il carattere da riempire */
    if(cur.y < 0 || cur.y >= size.y 
        || cur.x < 0 || cur.x >= size.x 
        || tab[cur.y][cur.x] != to_fill)
        return ;
    /* 2. riempimento della cella corrente: marca
    la posizione come già visitata */
    tab[cur.y][cur.x] = 'F';
    /* 3. espansione ricorsiva: propaga il riempimento
    nelle 4 direzioni.
    - cur.x - 1,cur.y -> serve per la chiamata dopo,
    aumentando o diminuendo in base alla direzione.
    In sinistra o destra viene incrementato il primo valore,
    quello delle x. In su o giù viene incrementato il 
    secondo valore, quello delle y. */
    fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill); // sinistra
    fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill); // destra
    fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill); // sopra
    fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill); // sotto
}

void flood_fill(char **tab, t_point size, t_point begin)
{
    char to_fill;
    /* 4. avvio del flood fill: salva il carattere
    di partenza e avvia la funzione ricorsiva */
    fill(tab, size, begin, tab[begin.y][begin.x]);
}

/* appunti per capire meglio: 
1. char **tab: matrice bidimensionale di char,ha 2 indici.
2. t_point : struttura usata per le cordinate(x,y).
3. t_ponit size: dimensione della matrice.
4. t_point cur: posizione corrente nella matrice.
5. char to_fill: carattere da sostituire con 'F'.
- tab[cur.y][cur.x]: prende la cella corrente nella matrice.
- condizioni di arresto: evitano di uscire dai limiti. 
controllo verticale(cur.y < 0 || cur.y >= size.y) 
e orizzontale(cur.x < 0 || cur.x >= size.x).
- tab[cur.y][cur.x] != to_fill: ferma se la cella non
contiene il carattere da riempire.
- tab[cur.y][cur.x] = 'F': riempie la cella corrente con 'F'.


*/