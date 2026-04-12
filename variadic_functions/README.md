# C - Variadic Functions

## Concepts clés

### Qu'est-ce qu'une fonction variadique ?

Une **fonction variadique** accepte un nombre variable d'arguments. La fonction la plus connue est `printf`.

Pour les utiliser, on inclut `<stdarg.h>`.

### Syntaxe

```c
#include <stdarg.h>

int sum_them_all(const unsigned int n, ...)
{
    va_list args;      /* liste des arguments variables */

    va_start(args, n); /* initialise la liste, n = dernier paramètre fixe */

    /* Lire chaque argument : */
    int val = va_arg(args, int);

    va_end(args);      /* libère la liste */
    return (result);
}
```

---

### Les macros de `<stdarg.h>`

| Macro | Rôle |
|-------|------|
| `va_list args` | Déclare la liste d'arguments |
| `va_start(args, last_fixed)` | Initialise à partir du dernier paramètre fixe |
| `va_arg(args, type)` | Lit le prochain argument du type donné |
| `va_end(args)` | Termine l'utilisation de la liste |

---

### sum_them_all — 0-sum_them_all.c

```c
int sum_them_all(const unsigned int n, ...)
{
    int s = 0;
    unsigned int i;
    va_list args;

    if (n == 0)
        return (0);

    va_start(args, n);
    for (i = 0; i < n; i++)
        s += va_arg(args, int);
    va_end(args);

    return (s);
}
```

**Utilisation :** `sum_them_all(4, 10, 20, 5, 3)` → `38`

---

### print_numbers — 1-print_numbers.c

Affiche n entiers séparés par un séparateur :

```c
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;

    va_start(args, n);
    for (i = 0; i < n; i++)
    {
        if (i > 0 && separator != NULL)
            printf("%s", separator);
        printf("%d", va_arg(args, int));
    }
    va_end(args);
    printf("\n");
}
```

---

### print_strings — 2-print_strings.c

Même principe avec des chaînes (`char *`) :

```c
void print_strings(const char *separator, const unsigned int n, ...)
{
    va_list args;
    char *str;

    va_start(args, n);
    for (unsigned int i = 0; i < n; i++)
    {
        str = va_arg(args, char *);
        if (str == NULL)
            str = "(nil)";
        if (i > 0 && separator != NULL)
            printf("%s", separator);
        printf("%s", str);
    }
    va_end(args);
    printf("\n");
}
```

---

### print_all — 3-print_all.c (avancé)

Utilise une chaîne de format (`"cifs"`) pour déterminer le type de chaque argument, et un tableau de structures pour dispatcher vers la bonne fonction d'impression :

```c
typedef struct allformat
{
    char c;
    void (*f)(va_list);
} allformat;

void print_all(const char * const format, ...)
{
    allformat formats[] = {
        {'c', printchar},
        {'i', printint},
        {'f', printfloat},
        {'s', printstring}
    };
    va_list args;
    va_start(args, format);

    while (format && *format)
    {
        /* chercher le format courant dans le tableau */
        /* appeler la fonction correspondante */
    }
    va_end(args);
}
```

**Formats supportés :**
- `'c'` : caractère
- `'i'` : entier
- `'f'` : flottant
- `'s'` : chaîne

---

### Précautions importantes

1. **Toujours appeler `va_end`** — sinon comportement indéfini.
2. **Le type doit correspondre** : passer le mauvais type à `va_arg` cause des erreurs.
3. **Les `float` sont promus en `double`** lors du passage d'arguments variadiques : utiliser `va_arg(args, double)`.
4. **Pas de détection automatique du nombre d'arguments** : il faut un mécanisme explicite (comme `n` ou une chaîne de format).

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-sum_them_all.c` | `va_list`, `va_start`, `va_arg`, `va_end` |
| `1-print_numbers.c` | Afficher n entiers avec séparateur |
| `2-print_strings.c` | Afficher n chaînes avec séparateur |
| `3-print_all.c` | Format dynamique, dispatch par tableau de fonctions |
