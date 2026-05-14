
/* sub: Implementazione di una funzione ft_scanf che emula il comportamento della scanf standard,
con supporto limitato ai conversion specifier c, d e s.
La funzione deve leggere da stdin e gestire solo i formati specificati, senza supporto per
opzioni avanzate come *, m, ', field width, o modifier di tipo (h, hh, l, ecc.).
*/

/* Blocco 0: Librerie
- stdarg.h -> fornisce funzioni per gestire argomenti variabili (va_list, va_start, va_arg, va_end)
- stdio.h -> fornisce funzioni per I/O (fgetc, ungetc, ferror)
- ctype.h -> fornisce funzioni per la classificazione dei caratteri (isspace)
*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

/* Blocco 1: match_space -> Salta tutti gli spazi bianchi nel file.
Come funziona:
- Legge caratteri dal file finche' non trova un carattere non bianco o EOF.
- Se trova un carattere non bianco, lo rimette nel buffer con ungetc.
- Restituisce 0 se la lettura e' avvenuta con successo, -1 in caso di errore.
*/
int match_space(FILE *f)
{
    int c;
    while ((c = fgetc(f)) != EOF && isspace(c))
        ;
    if (c != EOF)
        ungetc(c, f);
    return (0);
}

/* Blocco 2: match_char -> Confronta un carattere letto dal file con un carattere atteso.
Come funziona:
- Legge un carattere dal file.
- Se il carattere letto non corrisponde a quello atteso, lo rimette nel buffer con ungetc.
- Restituisce 1 se il carattere corrisponde, 0 altrimenti.
*/
int match_char(FILE *f, char c)
{
    int read_c = fgetc(f);
    if (read_c != c)
    {
        if (read_c != EOF)
            ungetc(read_c, f);
        return (0);
    }
    return (1);
}

/* Blocco 3: scan_char -> Legge un singolo carattere dal file e lo salva nella posizione puntata da dest.
Come funziona:
- Legge un carattere dal file.
- Se incontra EOF, restituisce 0 (nessun carattere letto) o -1 (errore).
- Salva il carattere in *dest (puntatore ottenuto da va_arg).
- Restituisce 1 se la lettura e' avvenuta con successo.
*/
int scan_char(FILE *f, va_list ap)
{
    int c = fgetc(f);
    if (c == EOF)
    {
        if (ferror(f))
            return (-1);
        else
            return (0);
    }
    char *dest = va_arg(ap, char *);
    *dest = (char)c;
    return (1);
}

/* Blocco 4: scan_int -> Legge un intero dal file e lo salva nella posizione puntata da dest.
Come funziona:
- Salta eventuali spazi bianchi iniziali (gestito da match_space nella ft_vfscanf).
- Legge un carattere per controllare il segno (+ o -).
- Legge cifre numeriche finche' non trova un carattere non numerico.
- Costruisce il valore intero moltiplicando per 10 e aggiungendo la cifra corrente.
- Se non ci sono cifre o c'e' un errore, restituisce 0 o -1.
- Salva il valore in *dest (puntatore ottenuto da va_arg).
- Restituisce 1 se la lettura e' avvenuta con successo.
*/
int scan_int(FILE *f, va_list ap)
{
    int c;
    int sign = 1;
    int value = 0;
    int digits = 0;

    c = fgetc(f);
    if (c == '+')
        c = fgetc(f);
    else if (c == '-')
    {
        sign = -1;
        c = fgetc(f);
    }

    while (isdigit(c))
    {
        value = value * 10 + (c - '0');
        digits++;
        c = fgetc(f);
    }

    if (c != EOF)
        ungetc(c, f);

    if (ferror(f) || !digits)
    {
        if (ferror(f))
            return (-1);
        else
            return (0);
    }

    int *dest = va_arg(ap, int *);
    *dest = value * sign;
    return (1);
}

/* Blocco 5: scan_string -> Legge una stringa dal file e la salva nella posizione puntata da dest.
Come funziona:
- Salta eventuali spazi bianchi iniziali (gestito da match_space nella ft_vfscanf).
- Legge caratteri finche' non trova uno spazio bianco o EOF.
- Salva ogni carattere in *s (puntatore ottenuto da va_arg) e incrementa s.
- Aggiunge il terminatore di stringa '\0' alla fine.
- Se non ci sono caratteri o c'e' un errore, restituisce 0 o -1.
- Restituisce 1 se la lettura e' avvenuta con successo.
*/
int scan_string(FILE *f, va_list ap)
{
    int c;
    int n = 0;
    char *s = va_arg(ap, char *);

    while ((c = fgetc(f)) != EOF && !isspace(c))
    {
        *s = (char)c;
        s++;
        n++;
    }

    if (c != EOF)
        ungetc(c, f);

    if (ferror(f) || !n)
    {
        if (ferror(f))
            return (-1);
        else
            return (0);
    }

    *s = '\0';
    return (1);
}

/* Blocco 6: match_conv -> Gestisce i conversion specifier (%c, %d, %s).
Come funziona:
- Riceve un puntatore al formato e un puntatore al file.
- In base al carattere successivo a '%', chiama la funzione appropriata:
  - %c: scan_char
  - %d: scan_int (dopo aver saltato gli spazi con match_space)
  - %s: scan_string (dopo aver saltato gli spazi con match_space)
- Restituisce il risultato della funzione chiamata o -1 se il formato non e' supportato.
*/
int match_conv(FILE *f, const char **format, va_list ap)
{
    switch (**format)
    {
        case 'c':
            return scan_char(f, ap);
        case 'd':
            match_space(f);
            return scan_int(f, ap);
        case 's':
            match_space(f);
            return scan_string(f, ap);
        case EOF:
            return -1;
        default:
            return -1;
    }
}

/* Blocco 7: ft_vfscanf -> Funzione principale che gestisce la lettura formattata.
Come funziona:
- Inizializza il conteggio delle conversioni (nconv) a 0.
- Legge un carattere per controllare se il file e' vuoto o in errore.
- Scorre il formato finche' non trova il terminatore.
- Se incontra '%', chiama match_conv per gestire il conversion specifier.
  - Se match_conv restituisce 1, incrementa nconv.
  - Altrimenti, interrompe il ciclo.
- Se incontra uno spazio nel formato, chiama match_space per saltare gli spazi nel file.
- Se incontra un carattere letterale, chiama match_char per confrontarlo.
- Restituisce EOF se c'e' un errore, altrimenti restituisce nconv.
*/
int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
    int nconv = 0;

    int c = fgetc(f);
    if (c == EOF)
        return EOF;
    ungetc(c, f);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (match_conv(f, &format, ap) != 1)
                break;
            else
                nconv++;
        }
        else if (isspace(*format))
        {
            if (match_space(f) == -1)
                break;
        }
        else if (match_char(f, *format) != 1)
            break;
        format++;
    }

    if (ferror(f))
        return EOF;
    return nconv;
}

/* Blocco 8: ft_scanf -> Wrapper per ft_vfscanf che gestisce gli argomenti variabili.
Come funziona:
- Inizializza la lista di argomenti variabili (va_list) con va_start.
- Chiama ft_vfscanf con stdin come file e il formato fornito.
- Chiude la lista di argomenti variabili con va_end.
- Restituisce il risultato di ft_vfscanf.
*/
int ft_scanf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return ret;
}

/* Codice gia' implementato:

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
        // You may insert code here
    return (0);
}

int match_char(FILE *f, char c)
{
        // You may insert code here
    return (0);
}

int scan_char(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}

int scan_int(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}

int scan_string(FILE *f, va_list ap)
{
        // You may insert code here
    return (0);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	// ...
	int ret = ft_vfscanf(stdin, format, ap);
	// ...
	return ret;
}


*/