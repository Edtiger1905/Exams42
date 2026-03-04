/* sub: crea un programma che genera tutte le permutazioni di una stringa data. 
Una permutazione e' un riordinamento dei caratteri: per esempio, le permutazioni di "abc"
sono: "abc", "acb", "bac", "bca", "cab", "cba".
Il programma ordina prima i caratteri in ordine alfabetico, poi genera tutte le permutazioni
in ordine lessicografico.
*/

/*  Blocco 0: Librerie 
stdio.h -> fornisce puts per stampare stringhe
stdlib.h -> fornisce calloc per allocare memoria inizializzata a zero e free per liberarla
*/

#include <stdio.h>
#include <stdlib.h>

/* Blocco 1: ft_strlen -> Calcola la lunghezza di una stringa.
Flusso:
1. Dichiara len per contare i caratteri.
2. Se s e' NULL (puntatore nullo), ritorna 0 per evitare errori.
3. Usa un for che incrementa len finche' non trova il carattere \0 (termianatore di stringa).
4. Ritorna la lunghezza calcolata.
*/

int ft_strlen(char *s)
{
    int len;
    if(!s)
        return (0);
    for(len = 0; s[len]; len++);
    return (len);
}

/* Blocco 2: ft_swap -> Scambia il contenuto di due caratteri.
Flusso: 
1. Dichiara t come variabile temporanea.
2. Salva il valore puntato da a in t.
3. Copia il valore puntato da b in a.
4. Copia il valore salvato in t in b.
*/

void ft_swap(char *a, char *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

/* Blocco 3: ft_sort_string -> Ordina una stringa in ordina alfabetico usando l'algoritmo
selection sort.

Funzionamento di selection sort:
1. Divide idealmente l'array in due parti: quella ordinata (a sinistra) e quella non ordinata
(a destra).
2. Per ogni posizione i,cerca il carattere piu' piccolo nella parte non ordinata.
3. Scambia il carattere piu' piccolo trovato con quello in posizione i.
4. Ripete finche' tutta la stringa e' ordinata.

Flusso:
1. Dichiara min_idx per tenere traccia del minimo.
2. Loop esterno (i da 0 a len - 2): Rappresenta la posizione corrente da riempire.
3. Inizializza min_idx = i, assumendo che il minimo sia all'inizio della parte non ordinata.
4. Loop interno (j da i + 1 a len - 1): cerca il carattere piu' piccolo nella parte non
ordinata.
5. Se trova un carattere piu' piccolo (str[j] < str[min_idx]), aggiorna min_idx.
6. Dopo il loop interno, scambia il minimo trovato con il carattere in posizione i.
7. Ripete per tutte le posizioni.

Esempio:
- Iterazione 1: trova 'a' (indice 2), scambia con 'c' (indice 0) -> "abc"
- Iterazione 2: trova 'b' (indice 1), gia' al posto giusto -> "abc"
*/

void ft_sort_string(char *str, int len)
{
    int min_idx;
    for(int i = 0; i < len - 1; i++)
    {
        min_idx = i;
        for(int j = i + i; j < len; j++)
        {
            if(str[j] < str[min_idx])
                min_idx = j;
        }
        ft_swap(&str[min_idx], &str[i]);
    }
}

/* Blocco 4: typedef long long t_mask -> crea un alias t_mask per il tipo long long.
Viene usato come maschera di bit per tracciare quali caratteri sono gia' stati usati. 
Un long long ha 64 bit,quindi supporta stringhe fino a 64 caratteri.
*/

typedef long long t_mask;

/* Blocco 5: permutations -> Genera ricorsivamente tutte le permutazioni dei 
caratteri usando backtacking.

Parametri:
- set[] -> array di caratteri ordinati da permutare.
- buff[] -> buffer temporaneo dove si costruisce la permutazione corrente
- mask -> maschera di bit che traccia quali caratteri sono gia' stati usati
- depth -> profondita' corrente (quanti caratteri abbiamo gia' piazzato)
- n_elem -> numero totale di elementi

Come funziona la maschera di bit:
- Ogni bit della maschera rappresenta un carattere: il bit i e' 1 se il carattere set[i] e'
gia' stato usato.
- (1 << i) crea una maschera con solo il bit i impostato a 1.
- mask & (1 << i) controlla se il bit i e' gia' impostato nella maschera.
- mask + (1 << i) aggiunge il bit i alla maschera (equivalente a mask | (1 << i)).

Flusso dettagliato:
I. Caso base -> permutazione completa:

if(depth == n_elem)
{
    puts(buff);
    return ;
}

- Se depth == n_elem significa che abbiamo piazzato tutti i caratteri.
- Stampa la permutazione completa con puts(buff).
- Ritorna per permettere al backtracking di continuare.

II. Caso ricorsivo -> prova ogni carattere disponibile:

for (int i = 0; i < n_elem; i++)
{
    if (!(mask & (1 << i)))
    {
        buff[depth] = set[i];
        permutations(set, buff, mask + (1 << i), depth + 1, n_elem);
    }
}

- Scorre tutti i caratterii dell'insieme set.
- Per ogni carattere i :
1. Controlla se l bit i e' a 0 nella maschera (carattere non ancora usato): !(mask & (1 << i))
2. Se disponibile:
    - Piazza il carattere nella posizione corrente: buff[depth] = set[i]
    - Chiama ricorsivamente permutation con:
        - Maschera aggiornata: mask + (1 << i) (marca il carattere come usato)
        - Profondita' incrementata: depth + 1
3. Quando la ricorsione ritorna, il backtracking e' implicito: il prossimo i sovrascrivera'
buff[depth].
*/

void permutations(char set[], char buff[], t_mask mask, int depth, int n_elem)
{
	if (depth == n_elem)
	{
		puts(buff);
		return ;
	}
	for (int i = 0; i < n_elem; i++)
	{
		if (!(mask & (1 << i)))
		{
			buff[depth] = set[i];
			permutations(set, buff, mask + (1 << i), depth + 1, n_elem);
		}
	}
}

/* Blocco 6: main -> e' il punto di ingresso del programma. Gestisce gli argomenti, prepara
i dati e avvia la generazione delle permutazioni.

Flusso:
1. Controlla che ci siano esattamente 2 argomenti e che la stringa non sia vuota (av[1][0] 
verifica che il primo carattere non sia '\0').
2. Calcola la lunghezza della stringa con "ft_strlen(av[1]) e la salva in n_elem".
3. Assegna set per puntare alla stringa di input av[1].
4. Alloca memoria per il buffer temporaneo buff usando calloc,che inizializza automaticamente
tutti i byte a zero (importante per avere il terminatore "\0").
5. Ordina la stringa in ordine alfabetico con ft_sort_string.
6. Chiama permutations con:
    - set -> la stringa ordinata
    - buff -> il buffer vuoto
    - mask = 0 -> nessun carattere usato all'inizio
    - depth = 0 -> inizia dalla posizione 0
    - n_elem -> numero totale di caratteri
7. Libera la memoria allocata per buff con free.
Extra: Calloc alloca byte inizalizzati a zero,cosa che garantisce che la stringa abbia sempre
il null terminator alla fine.
*/
int main(int ac, char **av)
{
    if(ac != 2 || !av[1][0])
        return (1);
    int n_elem = ft_strlen(av[1]);
    char *set = av[1];
    char *buff = calloc(n_elem, sizeof(char));
    ft_sort_string(set, n_elem);
    permutations(set, buff, 0, 0, n_elem);
    free(buff);
}