# C - More Malloc, Free

## Concepts clés

### malloc_checked — 0-malloc_checked.c

Une version de `malloc` qui **arrête le programme** si l'allocation échoue :

```c
void *malloc_checked(unsigned int b)
{
    void *ptr;

    ptr = malloc(b);
    if (ptr == NULL)
        exit(98);   /* termine le programme avec le code 98 */
    return (ptr);
}
```

- `exit(98)` : termine immédiatement le processus avec le statut 98.
- Utile pour les allocations critiques où le programme ne peut pas continuer sans mémoire.

---

### calloc — 2-calloc.c

`calloc` est comme `malloc` mais **initialise la mémoire à zéro** :

```c
void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *cal;
    unsigned int i;

    if (nmemb == 0 || size == 0)
        return (NULL);
    cal = malloc(nmemb * size);
    if (cal == NULL)
        return (NULL);
    for (i = 0; i < (nmemb * size); i++)
        cal[i] = 0;
    return (cal);
}
```

**Comparaison malloc vs calloc :**

| Fonction | Initialisation | Signature |
|----------|----------------|-----------|
| `malloc(size)` | Non (données quelconques) | 1 paramètre |
| `calloc(nmemb, size)` | Oui (tout à 0) | 2 paramètres |

---

### realloc — Redimensionner une zone mémoire

```c
void *realloc(void *ptr, size_t size);
```

- Redimensionne une zone précédemment allouée.
- Si `ptr == NULL`, se comporte comme `malloc(size)`.
- Si `size == 0`, se comporte comme `free(ptr)`.
- Peut copier les données vers une nouvelle adresse si nécessaire.

```c
int *arr = malloc(5 * sizeof(int));
arr = realloc(arr, 10 * sizeof(int));
```

**Toujours utiliser une variable temporaire :**
```c
int *tmp = realloc(arr, new_size);
if (tmp == NULL)
{
    free(arr);
    return (NULL);
}
arr = tmp;
```

---

### string_nconcat — 1-string_nconcat.c

Concatène au maximum `n` octets de `s2` à la fin de `s1` :

```c
/* Allouer : longueur(s1) + min(n, longueur(s2)) + 1 */
/* Copier s1, puis les n premiers caractères de s2 */
```

---

### array_range — 3-array_range.c

Crée un tableau d'entiers contenant toutes les valeurs de `min` à `max` inclus :

```c
int *array_range(int min, int max)
{
    int *arr;
    int i;

    if (min > max)
        return (NULL);
    arr = malloc(sizeof(int) * (max - min + 1));
    if (arr == NULL)
        return (NULL);
    for (i = 0; i <= max - min; i++)
        arr[i] = min + i;
    return (arr);
}
```

---

### exit() et les codes de retour

```c
#include <stdlib.h>

exit(0);    /* succès */
exit(1);    /* erreur générique */
exit(98);   /* code spécifique à ce projet */
```

- `exit()` termine le programme et libère les ressources.
- Le code de retour est accessible par le shell avec `$?`.

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-malloc_checked.c` | malloc avec exit() en cas d'échec |
| `1-string_nconcat.c` | Concaténation limitée à n octets |
| `2-calloc.c` | calloc : malloc + initialisation à 0 |
| `3-array_range.c` | Tableau de valeurs consécutives |
