"""Controlla lo step scelto senza prescrivere le righe da completare."""

import argparse
from pathlib import Path
import subprocess


def check_hello():
    executable = str(Path(__file__).resolve().with_name("hello"))
    expected = "Hello, computational physics!\n"
    result = subprocess.run(
        [executable], capture_output=True, text=True, timeout=5
    )
    if result.returncode != 0 or result.stdout != expected or result.stderr:
        print(f"stdout atteso: {expected!r}")
        print(f"stdout ottenuto: {result.stdout!r}")
        print(f"codice di uscita: {result.returncode}")
        if result.stderr:
            print(f"stderr: {result.stderr!r}")
        return 1
    print("Saluto corretto, con nuova riga e uscita regolare.")
    return 0


def check_eco():
    executable = str(Path(__file__).resolve().with_name("eco"))
    cases = [
        (("ciao", "12", "3.5"), "ciao 12 3.500000\n"),
        (("due parole", "+007", "1.25e1"), "due parole 7 12.500000\n"),
        (("0012", "-4", "-0.125"), "0012 -4 -0.125000\n"),
        (("", "0", "0"), " 0 0.000000\n"),
    ]
    failures = 0
    for args, expected in cases:
        result = subprocess.run(
            [executable, *args], capture_output=True, text=True, timeout=5
        )
        if result.returncode != 0 or result.stdout != expected or result.stderr:
            failures += 1
            print(f"Da controllare con argomenti {args!r}:")
            print(f"  stdout atteso: {expected!r}")
            print(f"  stdout ottenuto: {result.stdout!r}")
            print(f"  codice di uscita: {result.returncode}")
            if result.stderr:
                print(f"  stderr: {result.stderr!r}")

    # Queste parti sono gia' implementate nel codice fornito.
    invalid = [
        (),
        ("testo", "1"),
        ("testo", "1", "2", "extra"),
        ("testo", "abc", "2"),
        ("testo", "3.5", "2"),
        ("testo", "999999999999999999999999", "2"),
        ("testo", "1", "abc"),
        ("testo", "1", "2.5x"),
        ("testo", "1", "nan"),
        ("testo", "1", "inf"),
        ("testo", "1", "1e1000"),
    ]
    for args in invalid:
        result = subprocess.run(
            [executable, *args], capture_output=True, text=True, timeout=5
        )
        if result.returncode != 2 or result.stdout or not result.stderr:
            failures += 1
            print(f"Controllo degli argomenti non riuscito per {args!r}.")

    if failures:
        print("Controlla la stampa e confrontala con le previsioni.")
        return 1
    print("Eco e conversioni corrette; argomenti non validi riconosciuti.")
    return 0


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("programma", choices=("hello", "eco"))
    args = parser.parse_args()
    raise SystemExit(check_hello() if args.programma == "hello" else check_eco())
