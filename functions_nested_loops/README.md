# C - Functions, Nested Loops

## Concepts clés

### Les fonctions en C

Une fonction est un bloc de code réutilisable qui effectue une tâche spécifique.

#### Syntaxe

```c
type_retour nom_fonction(type paramètre1, type paramètre2)
{
    /* corps de la fonction */
    return (valeur);
}
```

#### Prototype (déclaration)

Avant d'utiliser une fonction, elle doit être **déclarée** dans un header (`.h`) ou avant son utilisation :

```c
int add(int a, int b);   /* prototype dans main.h */
```

**Exemple — 10-add.c :**
```c
int add(int a, int b)
{
    return (a + b);
}
```

#### Fonctions void

Une fonction `void` ne retourne aucune valeur :

```c
void times_table(void)
{
    /* affiche la table de multiplication */
}
```

---

### Les headers en C

Un fichier `.h` (header) contient les **prototypes** des fonctions et les `#include` partagés entre plusieurs fichiers.

```c
/* main.h */
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

int add(int a, int b);
int _islower(int c);
void times_table(void);

#endif /* MAIN_H */
```

- `#ifndef / #define / #endif` : **garde d'inclusion** — empêche les inclusions multiples.
- Dans les `.c`, on écrit `#include "main.h"` (guillemets = fichier local).

---

### Fonctions de caractère (reimplémenter la libc)

En C, les fonctions préfixées par `_` dans ce projet réimplémentent des fonctions standard de `<ctype.h>` :

#### _islower — 3-islower.c

```c
int _islower(int c)
{
    if (c >= 97 && c <= 122)
        return (1);
    else
        return (0);
}
```

- Retourne **1** si `c` est une lettre minuscule (`a`–`z`), **0** sinon.
- `'a'` = 97, `'z'` = 122 en ASCII.

#### _isalpha — 4-isalpha.c

Vérifie si `c` est une lettre (minuscule OU majuscule) :
```c
int _isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
```

#### _abs — 6-abs.c

Valeur absolue d'un entier :
```c
int _abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}
```

---

### Les boucles imbriquées

Une boucle à l'intérieur d'une autre boucle permet de traiter des tableaux 2D ou des combinaisons.

**Exemple — 9-times_table.c :**
```c
for (a = 0; a <= 9; a++)          /* ligne */
{
    for (b = 0; b <= 9; b++)      /* colonne */
    {
        int result = a * b;
        if (result > 9)
        {
            _putchar((result / 10) + '0');   /* dizaine */
            _putchar((result % 10) + '0');   /* unité */
        }
        else
        {
            _putchar(' ');
            _putchar(result + '0');
        }
        if (b != 9)
        {
            _putchar(',');
            _putchar(' ');
        }
    }
    _putchar('\n');
}
```

**Technique clé :** Convertir un chiffre entier en caractère ASCII : `chiffre + '0'`
- `3 + '0'` → `3 + 48` → `51` → caractère `'3'`

---

### Afficher avec _putchar

`_putchar` est une réimplémentation de `putchar` qui utilise `write()` :

```c
/* _putchar.c */
#include <unistd.h>
int _putchar(char c)
{
    return (write(1, &c, 1));
}
```

- `write(1, &c, 1)` : écrit 1 octet (`c`) sur le descripteur de fichier 1 (stdout).

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-putchar.c` | `_putchar`, affichage bas niveau |
| `1-alphabet.c` | Fonction, boucle `while` |
| `2-print_alphabet_x10.c` | Boucles imbriquées |
| `3-islower.c` | Fonction retournant int, test de plage |
| `4-isalpha.c` | Fonction booléenne, opérateur `\|\|` |
| `5-sign.c` | Fonction retournant un code (-1, 0, 1) |
| `6-abs.c` | Valeur absolue |
| `7-print_last_digit.c` | Modulo, retourner un résultat et afficher |
| `8-24_hours.c` | Boucles imbriquées, heures/minutes |
| `9-times_table.c` | Boucles imbriquées, conversion int→char |
| `10-add.c` | Addition simple, retour de valeur |
| `11-print_to_98.c` | Boucle décroissante |
| `_putchar.c` | Implémentation de `write()` |
