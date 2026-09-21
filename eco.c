#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Esempio di riferimento: https://en.cppreference.com/c/string/byte/strtol */
static int leggi_intero(const char *testo)
{
    char *fine;
    errno = 0;
    const long valore = strtol(testo, &fine, 10);

    /* Nessuna cifra letta oppure caratteri rimasti dopo il numero. */
    if (fine == testo || *fine != '\0') {
        fprintf(stderr, "Il secondo argomento deve essere un intero in base 10.\n");
        exit(2);
    }
    /* strtol restituisce long: controlliamo anche i limiti di int. */
    if (errno == ERANGE || valore < INT_MIN || valore > INT_MAX) {
        fprintf(stderr, "Il secondo argomento e' fuori dall'intervallo di int.\n");
        exit(2);
    }
    return (int)valore;
}

/* Esempio di riferimento: https://en.cppreference.com/c/string/byte/strtof
 * Per ottenere un double usiamo strtod, descritta nella stessa pagina. */
static double leggi_reale(const char *testo)
{
    char *fine;
    errno = 0;
    const double valore = strtod(testo, &fine);

    if (fine == testo || *fine != '\0') {
        fprintf(stderr, "Il terzo argomento deve essere un numero reale.\n");
        exit(2);
    }
    /* Rifiutiamo valori fuori intervallo, infinito e NaN. */
    if (errno == ERANGE || !isfinite(valore)) {
        fprintf(stderr, "Il terzo argomento deve rappresentare un double finito nell'intervallo ammesso.\n");
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

    const char *testo = argv[1];

    /* Lettura e controlli sono gia' forniti: completa solo la stampa. */
    const int intero = leggi_intero(argv[2]);
    const double reale = leggi_reale(argv[3]);

    /* Mantengono compilabile il template anche prima della stampa. 
    * da rimuovere una volta implementata la stampa. */
    (void)testo;
    (void)intero;
    (void)reale;

    /* TODO: scrivi una sola chiamata a printf che stampi testo, intero e reale,
     * separati da uno spazio e seguiti da un carattere di nuova riga. */

    return 0;
}
