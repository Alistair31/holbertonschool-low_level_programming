# C - Malloc, Free

## Concepts clés

### Allocation statique vs dynamique

| Allocation statique | Allocation dynamique |
|--------------------|---------------------|
| Taille connue à la compilation | Taille connue seulement à l'exécution |
| Stockée sur la **pile** (stack) | Stockée sur le **tas** (heap) |
| Libérée automatiquement | Doit être libérée manuellement avec `free()` |
| `int arr[10];` | `int *arr = malloc(10 * sizeof(int));` |

---

### malloc — Allouer de la mémoire

```c
#include <stdlib.h>

void *malloc(size_t size);
```

- Alloue `size` octets contiguës sur le **tas (heap)**.
- Retourne un pointeur `void *` vers le début de la zone allouée.
- Retourne `NULL` si l'allocation échoue — **toujours vérifier !**

```c
char *buf;

buf = malloc(sizeof(char) * 10);
if (buf == NULL)
    return (NULL);   /* ou exit() en cas d'erreur fatale */
```

---

### free — Libérer la mémoire

```c
free(ptr);
```

- Libère la mémoire allouée par `malloc`.
- Après `free`, le pointeur est invalide (**dangling pointer**).
- Bonne pratique : remettre le pointeur à `NULL` après `free`.

```c
free(buf);
buf = NULL;
```

**Fuites mémoire (memory leaks) :** Si on oublie `free`, la mémoire reste occupée jusqu'à la fin du processus.

---

### create_array — 0-create_array.c

```c
char *create_array(unsigned int size, char c)
{
    char *cp;
    unsigned int i;

    if (size == 0)
        return (NULL);
    cp = malloc(sizeof(char) * size);
    if (cp == NULL)
        return (NULL);
    for (i = 0; i < size; i++)
        cp[i] = c;
    return (cp);
}
```

**Points clés :**
- Vérifier que `size != 0` avant de malloc.
- Toujours vérifier que le résultat de `malloc` n'est pas `NULL`.
- Retourner le pointeur vers le tableau alloué.

---

### _strdup — 1-strdup.c

Duplique une chaîne dans de la mémoire fraîchement allouée :

```c
char *_strdup(char *str)
{
    int len = 0;
    char *cpy;

    if (str == NULL)
        return (NULL);
    while (str[len] != '\0')
        len++;
    cpy = malloc(sizeof(char) * (len + 1));  /* +1 pour '\0' */
    if (cpy == NULL)
        return (NULL);
    for (int i = 0; i <= len; i++)
        cpy[i] = str[i];    /* copie aussi le '\0' final */
    return (cpy);
}
```

**Attention :** Allouer `len + 1` octets pour inclure le caractère nul `'\0'`.

---

### str_concat — 2-str_concat.c

Concatène deux chaînes dans une nouvelle zone allouée :

```c
char *str_concat(char *s1, char *s2)
{
    /* longueur de s1 + longueur de s2 + 1 pour '\0' */
    char *result = malloc(strlen1 + strlen2 + 1);
    /* copier s1, puis s2, puis terminer par '\0' */
}
```

---

### alloc_grid — 3-alloc_grid.c

Allouer un tableau 2D (tableau de tableaux) :

```c
int **alloc_grid(int width, int height)
{
    int **grid;
    int i;

    grid = malloc(sizeof(int *) * height);  /* tableau de pointeurs */
    if (grid == NULL)
        return (NULL);
    for (i = 0; i < height; i++)
    {
        grid[i] = malloc(sizeof(int) * width);  /* chaque ligne */
        if (grid[i] == NULL)
            return (NULL);
    }
    return (grid);
}
```

**Libération d'un tableau 2D :**
```c
for (i = 0; i < height; i++)
    free(grid[i]);   /* libérer chaque ligne */
free(grid);          /* libérer le tableau de pointeurs */
```

---

### sizeof et les types

| Expression | Valeur typique (64 bits) |
|-----------|--------------------------|
| `sizeof(char)` | 1 |
| `sizeof(int)` | 4 |
| `sizeof(int *)` | 8 (taille d'un pointeur) |
| `sizeof(double)` | 8 |

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-create_array.c` | malloc, initialisation d'un tableau |
| `1-strdup.c` | Dupliquer une chaîne dynamiquement |
| `2-str_concat.c` | Concaténer deux chaînes dynamiquement |
| `3-alloc_grid.c` | Tableau 2D dynamique |
| `4-free_grid.c` | Libérer un tableau 2D |
