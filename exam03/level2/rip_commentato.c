/* sub: Scrivi un programma che dato un argomento stringa con solo parentesi,se non sono
bilanciate rimuovi il minimo numero di parentesi (sostituendole con spazi) per bilanciarle.
Stampa tutte le soluzione possibili.*/

/* Blocco 0: Librerie
- unistd.h -> fornisce write per scrivere su file descriptor (stdout)
*/

#include <unistd.h>

/* Blocco 1: check_par -> verifica se una stringa di parentesi e' bilanciata. 
Flusso:
1. Dichiara i come indice per scorrere la stringa e n come contatore del bilancio.
2. Inizializza i = 0 e n = 0.
3. Scorre la stringa carattere per carattere:
    - Se trova (, incrementa n (apre una parentesi).
    - Se trova ):
        - Controlla se n <= 0,cioe' se ci sono abbastanza ( aperte. Se no, ritorna 1
        (non bilanciata).
        - Altrimenti decrementa n (chiude una parentesi).
4. Alla fine del ciclo, ritorna n:
    - Se n == 0 -> bilanciata (ritorna 0)
    - Se n > 0 -> ci sono ( non chiuse (ritorna un numero positivo)

Valori di ritorno:
- 0 -> stringa bilanciata
- > 0 -> stringa non bilanciata

Esempio:
- (()) -> ritorna 0 (bilanciata)
- (() -> ritorna 1 (non bilanciata)
- ()) -> ritorna 1 (non bilanciata)
*/

int check_par(char *str)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while(str[i])
    {
        if(str[i] == '(')
            n++;
        if(str[i] == ')')
        {
            if(n <= 0)
                return (1);
            n--;
        }
        i++;
    }
    return (n);
}

/* Blocco 2: replace_spaces -> Genera ricorsivamente tutte le possibili combinazioni di
rimozioni di parentesi usando backtracking con potatura, e stampa solo le soluzioni 
bilanciate con il minimo numero di rimozioni.

Parametri:
- str -> La stringa da processare (modificata durante la ricorsione)
- n -> posizione corrente nella stringa
- len -> lunghezza totale della stringa
- s_min -> puntatore al minimo numero di spazi trovato finora
- spaces -> numero di spazi (rimozioni) nella configurazione corrente

Flusso:

Caso 1 -> stringa bilanciata trovata:
- Se !check_par(str) ritorna 0,la stringa e' bilanciata.
- Controlla spaces != len per evitare di stampare una stringa composta solo da spazi.
- Stampa la stringa con write(1, str, len) (file descriptor 1 e' stdout)
- Stampa un newline \n.
- Aggiorna in minimo: *s_min = spaces. Da questo momento cerchera' solo soluzioni con questo
numero o meno rimozioni.
- Ritorna per permettere al backtracking di continuare.

Caso 2 -> condizioni di terminazione:
- Se n == len, abbiamo processato tutti i caratteri -> ritorna.
- Se spaces > *s_min, abbiamo gia' trovato soluzioni migliori (con meno rimozioni),
ritorna senza esplorare oltre.

Caso ricorsivo -> esplora due possibilita':
Per ogni carattere in posizione n, esplora due rami dall'albero di ricerca:

I. Ramo 1 -> non rimuovere: chiama ricorsivamente senza modificae str[n], avanzando 
semplicemente alla posizione successiva.

II. Ramo 2 -> rimuovere (rimuovere con spazio):
- Salva il carattere originale in tmp.
- Sostituisce str[n] con uno spazio ' '.
- Chiama ricorsivamente incrementando spaces (una rimozione in piu').
- Ripristina il carattere originale con str[n] = tmp (backtracking esplicito).
*/

void replace_spaces(char *str, int n, int len, int *s_min, int spaces)
{
    char tmp;

    if(!check_par(str))
    {
        if(spaces != len)
            write(1, str, len);
        write(1, "\n", 1);
        *s_min = spaces;
        return ; 
    }
    if(n == len || spaces > *s_min)
        return ;
    replace_spaces(str, n + 1, len, s_min, spaces);
    tmp = str[n];
    str[n] = ' ';
    replace_spaces(str, n + 1, len, s_min, spaces + 1);
    str[n] = tmp;
}

/* Blocco 3: main -> Prepara i dati e avvia la ricerca delle soluzioni.
Flusso:
1. Controlla che ci siano esattamente 2 argomenti.
2. Dichiara len e lo inizializza a 0.
3. Calcola la lunghezza della stringa di input utilizzando un for:
    - Inizializza len = 0;
    - Incrementa len finche' av[1][len] non e' \0.
    - Il corpo del loop e' vuoto (;), tutto il lavoro e' fatto nell'espressione di 
    incremento, e' una specie di strlen.
4. Dichiara str[1000] -> un array di dimensione fissa che puo' contenere fino a 1000 
caratteri.
5. Dichiara i e lo inizializza a 0.
6. Copia la stringa di input av[1] nell'array locale str:
    - Usa un while che continua finche' av[1][i] non e' '\0'.
    - Copia carattere per carattere: str[i] = av[1][i].
    - Incrementa i dopo ogni copia.
7. Dichiara s_min e lo inizializza a len, che rappresenta il massimo numero possibile di 
spazi (tutti i caratteri rimossi).
8. Chiama replace_spaces con:
    - str -> la stringa locale copiata
    - 0 -> inizia dalla posizione 0
    - len -> lunghezza effettiva della stringa in input
    - &s_min -> puntatore al minimo (sara' aggiornato durante la ricerca)
    - 0 -> inizialmente nessuna rimozione
*/

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int len = 0;
        for(len = 0; av[1][len] != '\0'; len++)
        {
            ;
        }
        char str[1000];
        int i = 0;
        while(av[1][len])
        {
            str[i] = av[1][i];
            i++;
        }
        int s_min = len;
        replace_spaces(str, 0, len, &s_min, 0);
    }
}