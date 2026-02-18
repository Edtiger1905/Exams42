/* sub: Scrivi una funzione chiamata ft_scanf che simula il 
comportamento della vera funzione scanf con le seguenti restrizioni:
- Gestisce solo i formati %d, %s e %c
- Non gestisce le opzioni m e '
- Non gestisce i campi di larghezza
- Non gestisce i caratteri modificatori di tipo (h, hh, l, ecc...)
- Non gestisce le conversioni che iniziano con %n$
*/

/* Blocco 0: librerie
stdarg.h -> fornisce gli strumenti per gestire le funzioni 
con argomenti variabili: va_list, va_start, va_arg e va_end
stdio.h -> fornisce FILe, fgetc, ungetc, ferror e stdin
ctype.h -> fornisce isspace e isdigit
*/
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

/* Blocco 1: skip_space
Consuma tutti i caratteri (spazi, tabulazioni, ecc...) dal file 
finche' non trova qualcosa di non-spazio. Quel carattere non-spazio
viene rimesso indietro nel buffer con ungetcp perche' appartiene al
token successivo e non va perso.
Va chiamata prima di leggere un intero %d o una stringa %s, perche'
scanf standard ignora gli spazi iniziali per questi due tipi.
*/
static void skip_space(FILE *f)
{
    int c;
    while((c = fgetc(f)) != EOF && isspace(c))
    {
        if(c != EOF)
            ungetc(c, f);

    }
}
/* Blocco 2: scan_char
- Legge esattamente un carattere dal file e lo scrive nel puntatore
passato tramite va_list
- Se c'e' EOF si entra nell'if e si controlla ferror per capire il
motivo: se c'e' stato un errore di I/O ritorna -1, se invece e' solo
finito il file ritorna 0.
- va_arg(ap, char *) -> estrae il prossimo argomento dalla lista 
variadica e lo salva in dest, che e' il puntatore al char passato da
chi ha chiamato ft_scanf.
- *dest = (char)c -> deferenzia il puntatore e ci scrive dentro il 
carattere letto, convertendolo da int a char.
- %c non salta gli spazi, quindi non chiama skip_space. Questo e' un 
comportamento fedele a scanf
- Ritorna 1 se la lettura ha avuto successo.
*/
static int scan_char(FILE *f, va_list ap)
{
    int c;
    char *dest;

    c = fgetc(f);
    if(c == EOF)
    {
        if(ferror(f))
            return -1;
        else
            return 0;
    }
    dest = va_arg(ap, char *);
    *dest = (char)c;
    return 1;
}
/* Blocco 3: scan_int

*/
static int scan_int(FILE *f, va_list ap)
{
    int c;
    int sign;
    int value;
    int digits;
    int *dest;

    sign = 1;
    value = 0;
    digits = 0;
    c = fgetc(f);
}