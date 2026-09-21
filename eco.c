#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Uso: %s TESTO INTERO REALE\n", argv[0]);
        return 2;
    }

    const char *testo = argv[1];

    /* Lettura e controlli sono gia' forniti: completa solo la stampa. */
    char *fine = NULL;
    errno = 0;
    const long valore = strtol(argv[2], &fine, 10);
    if (errno != 0 || fine == argv[2] || *fine != '\0'
        || valore < INT_MIN || valore > INT_MAX) {
        fprintf(stderr, "Il secondo argomento deve rappresentare un int.\n");
        return 2;
    }
    const int intero = (int)valore;

    errno = 0;
    const float reale = strtof(argv[3], &fine);
    if (errno != 0 || fine == argv[3] || *fine != '\0' || !isfinite(reale)) {
        fprintf(stderr, "Il terzo argomento deve rappresentare un float finito.\n");
        return 2;
    }

    /* Mantengono compilabile il template anche prima della stampa. 
    * da rimuovere una volta implementata la stampa. */
    (void)testo;
    (void)intero;
    (void)reale;

    /* TODO: scrivi una sola chiamata a printf che stampi testo, intero e reale,
     * separati da uno spazio e seguiti da un carattere di nuova riga. */

    return 0;
}
