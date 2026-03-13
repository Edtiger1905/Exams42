
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
con argomenti variadici: va_list, va_start, va_arg e va_end
stdio.h -> fornisce FILe, fgetc, ungetc, ferror e stdin
ctype.h -> fornisce isspace e isdigit.
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
Flusso:
I. Si dichiarano tute le variabili in cima: c per i caratteri letti,sign per il 
segno (+1 o -1), value per costruire il numero, digits per contare quante cifre sono state 
lette, dest per il puntatore da riempire.
II. Si inizializzano sign = 1, value = 0; digits = 0.
III. Legge il primo carattere per controllare se e' + o -. Se e' -,imposta sign = -1,
altrimenti lascia sign = 1. Se non e' un segno,lo rimette dentro con ungetc.
IV. Entra nel while e legge cifra per cifra,costruendo il valore con la formula classica
value = value * 10 + (c - '0'). Sottrarre '0' converte il carattere ASCII nella cifra 
numerica corrispondente. Ogni cifra letta incrementa digits.
V. Quando trova un carattere che non e' una cifra, esce dal loop. Se quel carattere non e'
EOF, lo rimette indietro perche' appartiene al token successivo.
VI. Controlla se c'e' stato un errore con ferror(f) o se non ha letto nessuna 
cifra (digits == 0). In questi casi ritorna -1 per errore o 0 per matching fallito.
VII. Estrae il puntatore dest dalla va_list e ci scrive il risultato finale value * sign.
VIII. Ritorna 1 per indicare successo.
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
    if(c == EOF)
    {
        if(ferror(f))
            return(-1);
        else
            return(0);
    }
    if(c == '+' || c == '-')
    {
        if(c == '-')
            sign = -1;
    }
    else
        ungetc(c, f);
    while(isdigit(c = fgetc(f)))
    {
        value = value * 10 + (c - '0');
        digits++;
    }
    if(c != EOF)
        ungetc(c, f);
    if(ferror(f) || !digits)
    {
        if(ferror(f))
            return (-1);
        else
            return (0);
    }
    dest = va_arg(ap, int *);
    *dest = value * sign;
    return (1);
}

/* Blocco 4: scan_string 
Flusso:
I. Si dichiarano tutte le variabili in cima: c per il carattere letto,n per contare i
caratteri,s per il puntatore al buffer
II. Si inizializza n = 0.
III. Estrae subito il puntatore destinazione s dalla va_list prima di iniziare la lettura.
IV. Entra nel while e legge carattere per carattere finche' non trova uno spazio o EOF.
Ogni carattee viene scritto nel buffer con *s = (char)c, poi il puntatore avanza con s++
e il contatore n viene incrementato.
V. Lo spazio (o il carattere non-spazio) che ha fermato il loop viene rimesso indietro con
ungetc,come per scan_int,perche' appartiene al token successivo.
VI. Controlla se c'e' stato un errore con ferror(f) o se non ha letto nulla (n == 0). 
In questi casi ritorna -1 per errore o 0 per matching fallito.
VII. Aggiunge il terminatore '\0' alla fine,rendendo il buffer una stringa C valida.
VIII. Ritorna 1 per indicare successo.
*/

static int scan_string(FILE *f, va_list ap)
{
    int c;
    int n;
    char *s;

    n = 0;
    s = va_arg(ap, char *);
    while((c = fgetc(f)) != EOF && !isspace(c))
    {
        *s = (char)c;
        s++;
        n++;
    }
    if(c != EOF)
        ugetc(c, f);
    if(ferror(f) || !n)
    {
        if(ferror(f))
            return (-1);
        else
            return (0);
    }
    *s = '\0';
    return (1);
}
/* Blocco 5: ft_vfscanf 
E' il parser della stringa di formato. Scorre format carattere per carattere e decide
cosa fare. 
Flusso: 
I. Si inizializzano le variabili: nconv per contare le conversioni riuscite,
c per leggere caratteri, ret per salvare i valori di ritorno delle funzioni scan_*.
II. Si inizializza nconv = 0.
III. Legge un carattere dal file per controllare subito se e' EOF. Se lo e',ritorna EOF
immediatamente. Altrimenti lo rimette indietro con ungetc perche' non doveva ancora essere
consumato.
IV. Entra nel while principale e scorre la stringa di formato carattere per carattere.
V. Caso 1 -> Conversione (%): Se trova %, avanza di una posizione con format++ e controlla 
quale tipo di conversione e' richiesto:
- Se e' %d o %s, chiama prima skip_space per saltare gli spazi iniziali dall'input.
- Chiama la funzione scan_* appropriata e salva il risultato in ret.
- Se ret != 1 (matching fallito o errore), esce dal loop con break.
- Se invece ret == 1, incrementa nconv perche' la conversione e' riuscita.
VI. Caso 2 -> Spazio nel formato: se trova uno spazio (o tab,newline,ecc ...) nel formato,
chiama skip_space per consumare tutti gli spazi dall'input.
VII. Caso 3 -> Carattere letterale: se trova qualsiasi altro carattere, lo deve matchare 
esattamente con l'input. Legge un carattere con fgetc, lo confronta con *format, e se
non corrisponde esce dal loop (dopo aver rimesso il carattere con ungetc se non era EOF).
VIII. Alla fine di ogni iterazione, avanza nella stringa di formato con format++.
IX. Quando esce dal loop, controlla ferror(f): se c'e' stato un errore ritorna EOF, 
altrimenti ritorna nconv (il numero di conversoni riuscite).
*/

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
    int nconv;
    int c;
    int ret;

    nconv = 0;
    c = fgetc(f);
    if(c == EOF)
        return (EOF);
    ungetc(c, f);
    while(*format)
    {
        if(format == '%')
        {
            format++;
            if(*format == 'd' || *format == 's')
                skip_space(f);
            if(*format == 'c')
                ret = scan_char(f, ap);
            else if(*format == 'd')
                ret = scan_int(f, ap);
            else if(*format == 's')
                ret = scan_string(f, ap);
            else
                break;
            if(ret != 1)
                break;
            nconv++;
        }
        else if(isspace(*format))
            skip_space(f);
        else
        {
            c = fgetc(f);
            if(c != *format)
            {
                if(c != EOF)
                    ungetc(c, f);
                break;
            }
        }
        format++;
    }
    if(ferror(f))
        return (EOF);
    else
        return (nconv);
}
/* Blocco 6: ft_scanf
E' il punto d'ingresso pubblico. Raccoglie gli argomenti variadic con va_start,
li passa a ft_vfscanf insieme a stdin, poi chiude la lista con va_end.
Flusso:
I. Dichiara ap per la lista degli argomenti variadic e ret per il valore di ritorno.
II. Inizializza la lista variadica con va_start(ap, format). Questo dice al sistema
"gli argomenti variadic iniziano dopo il parametro format".
III. Chiama ft_vfscanf passando stdin come file da cui leggere, la stringa di formato,
e la lista di argometi. Salva il risultato in ret.
IV. Chiude la lista variadica con va_end(ap). Questo libera le risorse interne 
usate da va_list.
V. Ritorna ret, che contiene il numero di conversioni riuscite (o EOF in caso di errore).
*/

int ft_scanf(const char *format, ...)
{
    va_list ap;
    int ret;

    va_start(ap, format);
    ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return (ret);
}