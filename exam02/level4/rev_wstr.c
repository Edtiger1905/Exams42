#include <unistd.h>

/* sub: scrivi un programma che stampa le parole di una 
stringa al contrario,senza invertire le lettere,ma invertendo
l'ordine delle parole. */

int main(int argc, char **argv)
{
	/* 1. dichiarazione variabili,inzializzazione i 
	e check argomenti */
	int start;
	int end;
	int i;
	int  flag;
	
	i = 0;
		
	if(argc == 2)
	{   
		/* 2. equivalente di strlen */
		while(argv[1][i] != '\0')
			i++;
		/* 3. ciclo principale per stampare le parole al
		contrario */
		while(i >= 0)
		{
			/* 4. fino a quando c'e' uno spazio o la fine
			della stringa, lo salta (i--). 
			Quando trova la fine della parola inizializza 
			end al valore dell'indice. */
			while( argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--;
			end = i;
			/* 5. fino a quando av esiste ed e' una lettera, 
			torna all'inizio della parola,segna l'inzio della
			parola(i + 1 perche' quando il compilatore va a 
			controllare se c'e' la parola e' gia' passato
			oltre,quindi torna indietro di 1)*/
			while(argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			start = i + 1;
			flag = start;
			/* 6. stampa la parola trovata */
			while(start <= end)
			{
				write (1, &argv[1][start],1);
				start++;		
			}
			/* 7. stampa uno spazio se non siamo all'inizio
			della stringa,perche' lo avevamo tolto prima per
			contare la parola */
			if (flag != 0)
			{
				write(1, " ", 1);
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}