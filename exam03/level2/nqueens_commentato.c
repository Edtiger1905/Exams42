/* sub: soluzione al problema delle N regine (n-queens problem). 
Il problema chiede di posizionare N regine su una scacchiera NxN
in modo che nessuna regina possa attaccare un'altra. Il programma
trova e stampa tutte le soluzioni possibili.
*/

/* Blocco 0: Librerie
- unistd.h -> fornisce funzioni POSIX (non usata direttamente qui)
- stdio.h -> fornisce fprintf per la stampa
- string.h -> fornisce funzioni per le stringhe (non usata direttamente qua)
- stdlib.h -> fornisce atoi
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Blocco 1: check_diag -> Controlla se posizionare una regina in posizione
(row, column) creerebbe un conflitto diagonale con le regine gia' piazzate
Come funziona:
- board[i] contiene la riga in cui e' posizionata la regina nella colonna i.
- Per ogni colonna i gia' riempita (da 0 a column - 1), controlla se la regina
in quella colonna e' sulla stessa diagonale della nuova posizione.
La formula delle diagonali:
- Diagonale discendente (in basso a destra): due caselle sono sulla stessa diagonale se
riga1 - colonna1 == riga2 - colonna2
- Diagonale ascendente (in alto a desta): due casselle sono sula stessa diagonale se
riga1 + colonna1 == riga2 + colonna2, che e' equivalente a riga1 - riga2 == colonna2 - colonna1
Nel codice: 
- board[i] - row == i - column -> controlla la diagonale discendente
- board[i] - row == column - i -> controlla la diagonale ascendente
Valori di ritorno:
- 0 se c'e' un conflitto (posizione non valida)
- 1 se non ci sono conflitti (postazione valida)
*/

int check_diag(int board[], int row, int column)
{
    int i;

    i = 0;
    while(i < column)
    {
        if(board[i] - row == i - column || board[i] - row == column - i)
            return (0);
        i++;
    }
    return (1);
}

/* Blocco 2: check_ori -> Controlla se posizionare una regina nella riga row
creerebbe un conflitto orizzontale con le regine gia' piazzate.
Come funziona: 
- Scorre tutte le colonne gia' riempite (da 0 a column - 1).
- Per ogni colonna i,controlla se board[i] == row, cioe' se c'e' gia' una regina
in quella riga.
- Se trova una regina nella stessa riga, ritorna 0 (conflitto).
- Se non trova conflitti,ritorna 1 (posizione valida).
*/

int check_ori(int board[], int row, int column)
{
    int i;

    i = 0;
    while(i < column)
    {
        if(board[i] == row)
            return (0);
        i++;
    }
    return (1);
}

/* Blocco 3: fill_square -> Cuore dell'algoritmo. Risolve il
problema delle N regine usando backtracking ricorsivo.
Variabili:
- board[] -> array che rappresenta la scacchiera. board[i] contiene la riga
in cui e' posizionata la regina nella colonna i.
- n -> dimensione della scacchiera (NxN)
- column -> colonna corrente che stiamo cercando di riempire
Flusso:
I. Caso base -> tutte le colonne sono riempite:
- Se column == n significa che abbiamo piazzato con successo N regine (una per ogni colonna).
- Stampa la soluzione trovata: scorre l'array board e stampa la riga di ogni regina, 
separata da spazi.
- Ritorna per permettere al backtracking di continuare a trovare altre soluzioni.
II. Caso ricorsivo -> prova tutte le righe possibili:
"for (int row = 0; row < n; row++)"
- Prova a piazzare una regina in ogni riga della colonna corrente.
- Per ogni riga row:
1. Controlla se la posizione e' valida chiamando check_ori e check_diag.
2. Se entrambe ritornano 1 (nessun conflitto):
- Piazza la regina: board[column] = row
- Chiama ricorsivamente fill_square per la colonna successiva:
fill_square(board, n, column + 1)
3. Quando la ricorsione ritorna (backtracking), prova la prossima riga.
extra: Il backtracking implicito -> quando fill_square ritorna dalla ricorsione,board[column]
viene automaticamente sovrascritto dalla prossima iterazione del for,quindi non serve 
"ripulire" esplicitamente la posizione.
*/

void fill_square(int board[], int n, int column)
{
    if(column == n)
    {
        int j;

        j = 0;
        while(j < n)
        {
            fprintf(stdout, "%i", board[j]);
            if(j < n - 1)
                fprintf(stdout, " ");
            j++;
        }
        fprintf(stdout, "\n");
        return;
    }
    for(int row = 0; row < n; row++)
    {
        if(check_ori(board, row, column) && check_diag(board, row, column))
        {
            board[column] = row;
            fill_square(board, n, column + 1);
        }
    }
}
/* Blocco 4: main -> Punto di ingresso del programma. Gestisce gli argomenti dalla linea di
comando e avvia la risoluzione.
Flusso:
1. Controlla che ci siano esattamente 2 argomenti (nome programma + numero) e che il 
numero sia positivo.
2. Converte l'argomento stringa in intero con atoi(av[1]) e lo salva in n. 
3. Dichiara un array board[n] di dimensione variabile (VLA -> variable length array).
4. Chiama fill_square(board, n, 0) per iniziare la ricerca delle soluzioni partendo 
dalla colonna 0.
5. Stampa una newline finale.
*/

int main(int ac, char **av)
{
    if(ac == 2 & atoi(av[1]) > 0)
    {
        int n = atoi(av[1]);
        int board[n];
        fill_square(board, n, 0);
    }
    fprintf(stdout, "\n");
}