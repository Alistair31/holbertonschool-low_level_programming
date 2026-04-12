# C - Variables, If/Else, While

## Concepts clés

### Les variables en C

Une variable est un espace mémoire nommé qui stocke une valeur d'un type donné.

```c
int n;          /* déclaration */
n = 42;         /* affectation */
int x = 10;     /* déclaration + initialisation */
```

#### Types fondamentaux

| Type | Taille | Plage (signé) |
|------|--------|----------------|
| `char` | 1 octet | -128 à 127 |
| `int` | 4 octets | -2 147 483 648 à 2 147 483 647 |
| `float` | 4 octets | virgule flottante simple précision |
| `double` | 8 octets | virgule flottante double précision |

---

### Les structures conditionnelles

#### if / else if / else

```c
if (n > 0)
    printf("%d is positive\n", n);
else if (n < 0)
    printf("%d is negative\n", n);
else
    printf("%d is zero\n", n);
```

- Le bloc `else if` permet de tester plusieurs conditions en chaîne.
- Le bloc `else` est le cas par défaut si aucune condition n'est vraie.
- En C, **toute valeur non nulle est vraie**, 0 est faux.

**Exemple — 0-positive_or_negative.c :**
```c
srand(time(0));
n = rand() - RAND_MAX / 2;
if (n > 0)       printf("%d is positive\n", n);
else if (n < 0)  printf("%d is negative\n", n);
else             printf("%d is zero\n", n);
```
- `srand(time(0))` initialise le générateur aléatoire avec l'heure actuelle.
- `rand()` génère un entier pseudo-aléatoire entre 0 et `RAND_MAX`.

---

### La boucle while

```c
while (condition)
{
    /* corps de la boucle */
}
```

La boucle `while` répète le bloc tant que la condition est vraie.

**Exemple — afficher l'alphabet (2-print_alphabet.c) :**
```c
char c = 'a';
while (c <= 'z')
{
    putchar(c);
    c++;
}
putchar('\n');
```

- Les caractères sont des entiers en C : `'a'` vaut 97, `'z'` vaut 122.
- `putchar(c)` affiche un caractère.
- `c++` incrémente la variable (équivalent à `c = c + 1`).

---

### La boucle for

```c
for (initialisation; condition; incrément)
{
    /* corps de la boucle */
}
```

**Exemple — afficher les chiffres (9-print_comb.c) :**
```c
for (nb = 48; nb <= 57; nb++)
{
    putchar(nb);
    if (nb < 57)
    {
        putchar(',');
        putchar(' ');
    }
}
putchar('\n');
```

- `48` est le code ASCII de `'0'`, `57` celui de `'9'`.
- Cette boucle affiche : `0, 1, 2, 3, 4, 5, 6, 7, 8, 9`

---

### La table ASCII

Les caractères imprimables courants :

| Code | Caractère | Code | Caractère |
|------|-----------|------|-----------|
| 48–57 | `0`–`9` | 97–122 | `a`–`z` |
| 65–90 | `A`–`Z` | 32 | espace |

**Astuce :** Pour convertir minuscule en majuscule : `'a' - 32 = 'A'`

---

### Opérateurs utiles

| Opérateur | Signification |
|-----------|---------------|
| `==` | Égal à |
| `!=` | Différent de |
| `<`, `>` | Inférieur, supérieur |
| `<=`, `>=` | Inférieur ou égal, supérieur ou égal |
| `&&` | ET logique |
| `\|\|` | OU logique |
| `!` | NON logique |
| `%` | Modulo (reste de la division) |

---

### last_digit — 1-last_digit.c

```c
n = rand() - RAND_MAX / 2;
last_digit = n % 10;
if (last_digit > 5)
    printf("... and is greater than 5\n");
else if (last_digit == 0)
    printf("... and is 0\n");
else
    printf("... and is less than 6 and not 0\n");
```

- L'opérateur modulo `%` extrait le dernier chiffre d'un nombre.
- En C, `(-13) % 10 == -3` (le signe suit celui du dividende).

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-positive_or_negative.c` | if/else if/else, `rand()`, `srand()` |
| `1-last_digit.c` | Modulo `%`, conditions imbriquées |
| `2-print_alphabet.c` | Boucle `while`, codes ASCII |
| `3-print_alphabets.c` | Boucle `while`, deux alphabets |
| `4-print_alphabt.c` | Boucle `while`, exclusion de caractères |
| `5-print_numbers.c` | Afficher les chiffres avec `putchar` |
| `6-print_numberz.c` | Chiffres sans `printf` |
| `7-print_tebahpla.c` | Alphabet à l'envers |
| `8-print_base16.c` | Hexadécimal (0-9, a-f) |
| `9-print_comb.c` | Boucle `for`, affichage formaté |
