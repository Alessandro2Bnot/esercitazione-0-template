#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* Esempio di riferimento: https://en.cppreference.com/c/string/byte/strtol */
int leggi_intero(char *testo)
{
    char *fine;
    errno = 0; //Definito in <errno.h>, va azzerato un eventuale errore precedente
    
    long int valore = strtol(testo, &fine, 10);

    /* Nessuna cifra letta oppure caratteri rimasti dopo il numero. */
    if (fine == testo) {
      // Nessun numero trovato
      fprintf(stderr, "Il secondo argomento deve essere un intero in base 10.\n");
      exit(2);
    } else if (*fine != '\0') {
      // Caratteri residui, ad esempio "12abc"
      fprintf(stderr, "Il secondo argomento deve essere un intero in base 10.\n");
      exit(2);
    }
    else if (errno == ERANGE) {
      fprintf(stderr, "Il secondo argomento ha un valore fuori intervallo (overflow o underflow)\n");
      exit(2);
    }
    
    return (int)valore;
}

/* Esempio di riferimento: https://en.cppreference.com/c/string/byte/strtof
 * Per ottenere un double usiamo strtod, descritta nella stessa pagina. */
double leggi_reale(char *testo)
{
  char *fine;
  errno = 0; //Definito in <errno.h>, va azzerato un eventuale errore precedente
    
  double valore = strtod(testo, &fine);
  
  /* Nessuna cifra letta oppure caratteri rimasti dopo il numero. */
  if (fine == testo) {
    // Nessun numero trovato
    fprintf(stderr, "Il terzo argomento deve essere un numero reale.\n");      
    exit(2);
  } else if (*fine != '\0') {
      // Caratteri residui, ad esempio "12abc"
    fprintf(stderr, "Il terzo argomento deve essere un numero reale.\n");     
    exit(2);
  }
  else if (errno == ERANGE) {
    fprintf(stderr, "Il terzo argomento ha un valore fuori intervallo (overflow o underflow)\n");
    exit(2);
  }
  
  return valore;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Uso: %s TESTO INTERO REALE\n", argv[0]);
        return 2;
    }

    char *testo = argv[1];

    /* TODO: converti gli argomenti in tipi appropriati. */

    /* Evita una segnalazione finche' testo non viene usato nella stampa. */
    (void)testo;

    /* TODO: scrivi una sola chiamata a printf che stampi testo, intero e reale,
     * separati da uno spazio e seguiti da un carattere di nuova riga. */

    return 0;
}
