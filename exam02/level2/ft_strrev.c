#include <unistd.h>

/* sottofunzione: ft_strlen,calcola la lunghezza di una stringa fino a quando non arriva a \0 escluso.*/
int ft_strlen(char *str)
{
	int i;

	while(str[i] != '\0')
		i++;
	return(i);
}
/* sub: ricreare la funzione strrev,che rigira una stringa nella stessa stringa e ritorna la medesima. */

/* 1. dichiarazione della funzione con ritorno di tipo char *, e che prende in input una stringa.
 * dichiarazione variabili di indici e il carattere temporaneo in cui immagazzino i char.*/
char *ft_strrev(char *str)
{
	int 	i;
	int 	j;
	char 	temp;
	
	i = ft_strlen(str);
	j = 0;
	/* 2. loop che va avanti fino a quando j e' piu' piccolo di i - 1, e rigira la stringa nella medesima 
	 * grazie alla variabile temporanea.*/
	while(j < i - 1)
	{
		temp = str[j];
		str[j] = str[i - 1];
		str[i - 1] = temp;
		j++;
		i--;
	}
	// 3. ritorna la stringa girata.
	return(str);
}
