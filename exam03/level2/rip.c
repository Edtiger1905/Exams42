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

Fl

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