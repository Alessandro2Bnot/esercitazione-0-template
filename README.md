# Esercitazione 0 — Compilazione, esecuzione e Git

Riprendiamo la compilazione e l'esecuzione di un programma C, già affrontate
l'anno scorso. Poi useremo Git per registrare e condividere il lavoro.

Lavora **in locale**, sulla copia del repository assegnato clonata sul tuo
computer. Puoi usare GCC e gli altri strumenti installati sul computer oppure
l'ambiente Docker del corso, descritto nel repository `ambiente-docker`.

## Step 1 — Hello World: quale programma ho eseguito?

Completa il TODO in `hello.c` in modo che il programma stampi esattamente:

```text
Hello, computational physics!
```

seguito da una nuova riga. Il template iniziale compila, ma non stampa ancora
nulla.

### Compilazione ed esecuzione

Dalla cartella del repository puoi compilare ed eseguire direttamente:

```sh
gcc -std=c17 -Wall -Wextra -Wpedantic hello.c -o hello
./hello
```

Il `Makefile` fornito permette anche di usare:

```sh
make             # compila hello se il sorgente è cambiato
make check       # verifica soltanto Hello World; richiede Python 3
make clean       # elimina gli eseguibili
```

`make check` fallisce sul template iniziale: completa la stampa prima di
usarlo per verificare il tuo lavoro. Per consultare la documentazione della
stampa, se installata, puoi usare `man 3 printf`.

### Domande stimolo

- Che differenza c'è tra `hello.c` e `hello`? Se modifichi il messaggio nel
  sorgente e avvii subito l'eseguibile, quale versione stai usando?
- Che cosa cambia quando ricompili? Come potresti rendere evidente la
  differenza con una prova?
- Come puoi distinguere ciò che stampa il programma da ciò che mostra il
  terminale? Che cosa osservi salvando l'output con `> saluto.txt`?

Scegli una domanda e raccogli in `osservazioni.md` previsione, comando e
risultato. Dopo le prove, ripristina il messaggio richiesto e ricompila.

### Registrare e condividere con Git

- Che differenza c'è fra salvare un file, creare un commit e fare push?
- Quali modifiche mostra `git diff`? Quali file occorrono a un compagno per
  ricompilare il programma sul proprio computer?
- Come puoi verificare che su GitHub ci sia proprio la versione provata?

I comandi a disposizione sono:

```sh
git status
git diff
git add hello.c osservazioni.md
git commit -m "Completa Hello World e la prima verifica"
git push
```

Annota in `osservazioni.md` una verifica del passaggio dal lavoro locale al
repository remoto. Gli eseguibili sono ignorati da Git: si ricostruiscono dal
sorgente. Se usi Docker, puoi eseguire i comandi Git anche dal terminale del
computer sulla stessa cartella.

**Checkpoint:** sai compilare, eseguire e spiegare quale versione del
programma hai provato e registrato su GitHub. Discuti una tua prova con il
docente, poi passa allo [step 2 — Eco degli argomenti](step-2.md), nello
stesso repository.

## Consegna finale

Consegna `hello.c`, `eco.c` e `osservazioni.md` dopo aver completato entrambi
gli step. `make check-all` verifica i due programmi; gli eventuali controlli
remoti dipendono dalla configurazione del docente.

Per la consegna esplicita con Classroom 50 usa `gh student submit` dal
repository assegnato, se l'estensione è installata. In alternativa, dopo
aver registrato e inviato tutte le modifiche:

```sh
submission_tag="submit/$(date -u +%Y%m%dT%H%M%SZ)"
git tag "$submission_tag"
git push origin "$submission_tag"
```
