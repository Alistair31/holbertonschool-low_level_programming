# C - Pointers, Arrays and Strings

## Concepts clés

### Les pointeurs

Un **pointeur** est une variable qui stocke l'**adresse mémoire** d'une autre variable.

```c
int n = 42;
int *p = &n;   /* p contient l'adresse de n */

printf("%d\n", *p);  /* déréférencement : affiche 42 */
*p = 100;            /* modifie n via le pointeur */
```

| Opérateur | Signification |
|-----------|---------------|
| `&` | Adresse de (référence) |
| `*` | Valeur à l'adresse (déréférencement) |

**Exemple — swap_int (1-swap.c) :**
```c
void swap_int(int *a, int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
```
- Passage par pointeur : la fonction **modifie les variables originales** de l'appelant.
- Sans pointeurs, C passe les arguments par valeur (copie) — la modification serait locale.

---

### Les chaînes de caractères (strings)

En C, une chaîne est un **tableau de `char`** terminé par le caractère nul `'\0'` (valeur 0).

```c
char str[] = "Hello";
/* En mémoire : ['H', 'e', 'l', 'l', 'o', '\0'] */
```

- Un `char *` peut pointer vers une chaîne.
- La fin de chaîne est toujours signalée par `'\0'`.

---

### Calculer la longueur d'une chaîne — 2-strlen.c

```c
int _strlen(char *s)
{
    int len = 0;
    while (*s != '\0')
    {
        len++;
        s++;     /* avance le pointeur au caractère suivant */
    }
    return (len);
}
```

- `*s` déréférence le pointeur — lit le caractère courant.
- `s++` fait avancer le pointeur d'un octet (un `char`).

---

### Les fonctions de manipulation de chaînes

#### _memset — 0-memset.c

Remplit `n` octets d'une zone mémoire avec la valeur `b` :
```c
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i = 0;
    while (i < n)
    {
        s[i] = b;
        i++;
    }
    return (s);
}
```

#### _memcpy — 1-memcpy.c

Copie `n` octets de `src` vers `dest` :
```c
char *_memcpy(char *dest, char *src, unsigned int n)
{
    unsigned int i = 0;
    while (i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
```

#### _strcpy — 9-strcpy.c

Copie la chaîne `src` (avec `'\0'`) dans `dest` :
```c
char *_strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
```

#### _strcmp — 3-strcmp.c

Compare deux chaînes caractère par caractère :
```c
int _strcmp(char *s1, char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}
```
- Retourne **0** si égales, valeur positive si `s1 > s2`, négative si `s1 < s2`.

---

### Tableaux et arithmétique sur les pointeurs

```c
char str[] = "Hello";
char *p = str;    /* p pointe sur str[0] */

p[2]   /* == *(p + 2) == 'l' */
p + 3  /* adresse de str[3] == 'l' */
```

- `tableau[i]` est équivalent à `*(tableau + i)`.
- Un tableau est en réalité un pointeur constant vers son premier élément.

---

### Manipulation de chaînes avancée

#### _strcat (0-strcat.c) — Concaténer deux chaînes

Ajoute `src` à la fin de `dest` :
```c
/* Trouver la fin de dest, puis copier src */
while (*dest) dest++;
while (*src)  { *dest = *src; dest++; src++; }
*dest = '\0';
```

#### _strchr (2-strchr.c) — Trouver un caractère

Retourne un pointeur vers la première occurrence de `c` dans `s` :
```c
while (*s)
{
    if (*s == c) return (s);
    s++;
}
return (NULL);
```

---

### reset_to_98 — 0-reset_to_98.c

```c
void reset_to_98(int *n)
{
    *n = 98;
}
```
- Utilise un pointeur pour modifier la variable de l'appelant directement.

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-reset_to_98.c` | Modifier via pointeur |
| `1-swap.c` | Échange de valeurs via pointeurs |
| `2-strlen.c` | Longueur de chaîne, parcours par pointeur |
| `3-puts.c` | Afficher une chaîne avec `_putchar` |
| `4-print_rev.c` | Afficher chaîne à l'envers |
| `5-rev_string.c` | Inverser une chaîne en place |
| `6-puts2.c` | Afficher un caractère sur deux |
| `7-puts_half.c` | Deuxième moitié d'une chaîne |
| `8-print_array.c` | Afficher un tableau d'entiers |
| `9-strcpy.c` | Copie de chaîne |
| `0-memset.c` | Remplir mémoire |
| `1-memcpy.c` | Copier mémoire |
| `0-strcat.c` | Concaténation |
| `2-strchr.c` | Recherche de caractère |
| `3-strcmp.c` | Comparaison de chaînes |
| `100-atoi.c` | Convertir chaîne en entier |
