# Esercitazione 0 – Primo programma C

## Obiettivi

Questa esercitazione serve a verificare il funzionamento dell'ambiente di lavoro e a familiarizzare con:

- GitHub Codespaces;
- compilazione di un programma C;
- comandi Git essenziali;
- test automatici con GitHub Actions.

## Consegna

Completa `hello.c` in modo che il programma stampi esattamente:

```text
Hello, computational physics!
```

seguito da un carattere di nuova riga.

## Compilazione ed esecuzione

Nel terminale esegui:

```bash
make
./hello
```

Per eliminare il programma compilato:

```bash
make clean
```

## Consegna con Git

Controlla le modifiche:

```bash
git status
git diff
```

Registra e invia il lavoro:

```bash
git add hello.c
git commit -m "Completa l'esercitazione 0"
git push
```

Dopo il push, controlla il risultato dei test nella scheda **Actions** del repository.