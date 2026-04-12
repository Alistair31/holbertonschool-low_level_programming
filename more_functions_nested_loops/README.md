# C - More Functions, More Nested Loops

## Concepts clés

### Fonctions de test de caractères

Ces fonctions réimplémentent les fonctions de `<ctype.h>` en utilisant les plages ASCII.

#### _isupper — 0-isupper.c

```c
int _isupper(int c)
{
    return (c >= 'A' && c <= 'Z');
}
```
- Retourne **1** si `c` est une majuscule, **0** sinon.
- `'A'` = 65, `'Z'` = 90.

#### _isdigit — 1-isdigit.c

```c
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}
```
- Retourne **1** si `c` est un chiffre (`0`–`9`), **0** sinon.
- `'0'` = 48, `'9'` = 57.

---

### Multiplication et modulo

#### _mul — 2-mul.c

```c
int _mul(int a, int b)
{
    return (a * b);
}
```

---

### FizzBuzz — 9-fizz_buzz.c

Le problème classique FizzBuzz : afficher les nombres de 1 à 100 en remplaçant les multiples de 3 par "Fizz", les multiples de 5 par "Buzz", et les multiples des deux par "FizzBuzz".

```c
for (nb = 1; nb <= 100; nb++)
{
    if (nb % 3 == 0 && nb % 5 == 0)
        printf("FizzBuzz ");
    else if (nb % 5 == 0)
        printf("Buzz ");
    else if (nb % 3 == 0)
        printf("Fizz ");
    else
        printf("%i ", nb);
}
```

- **Ordre des tests important** : tester d'abord le cas `% 3 == 0 && % 5 == 0` avant les cas individuels.
- L'opérateur `%` (modulo) retourne le reste de la division entière.

---

### Dessiner avec des boucles imbriquées

#### print_square — 8-print_square.c

```
####
####
####
####
```

```c
for (row = 0; row < size; row++)
{
    for (col = 0; col < size; col++)
        _putchar('#');
    _putchar('\n');
}
```

#### print_triangle — 10-print_triangle.c

```
    #
   ##
  ###
 ####
#####
```

```c
for (ln = 1; ln <= size; ln++)
{
    for (ht = size; ht > ln; ht--)    /* espaces */
        _putchar(' ');
    for (hsh = 1; hsh < ln + 1; hsh++)  /* '#' */
        _putchar('#');
    _putchar('\n');
}
```

**Logique du triangle :**
- Ligne 1 : `size-1` espaces + 1 `#`
- Ligne 2 : `size-2` espaces + 2 `#`
- Ligne `n` : `size-n` espaces + `n` `#`

---

### Afficher des diagonales — 7-print_diagonal.c

```
\
 \
  \
```

```c
for (i = 0; i < size; i++)
{
    for (j = 0; j < i; j++)
        _putchar(' ');
    _putchar('\\');
    _putchar('\n');
}
```

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-isupper.c` | Test majuscule (plage ASCII) |
| `1-isdigit.c` | Test chiffre (plage ASCII) |
| `2-mul.c` | Multiplication, retour de valeur |
| `3-print_numbers.c` | Afficher chiffres sans `printf` |
| `4-print_most_numbers.c` | Boucle avec exclusions |
| `5-more_numbers.c` | Boucle, conversion entier→char |
| `6-print_line.c` | Boucle simple, tiret |
| `7-print_diagonal.c` | Boucles imbriquées, diagonale |
| `8-print_square.c` | Carré de `#` |
| `9-fizz_buzz.c` | FizzBuzz, modulo, conditions |
| `10-print_triangle.c` | Triangle de `#`, boucles imbriquées |
