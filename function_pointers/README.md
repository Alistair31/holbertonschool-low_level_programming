# C - Function Pointers

## Concepts clés

### Qu'est-ce qu'un pointeur de fonction ?

En C, les fonctions ont une adresse en mémoire. Un **pointeur de fonction** stocke cette adresse et permet d'appeler la fonction indirectement — comme passer une fonction en paramètre.

### Syntaxe

```c
/* Déclarer un pointeur vers une fonction qui prend un char* et retourne void */
void (*f)(char *);

/* Assigner l'adresse d'une fonction */
void print_upper(char *name) { /* ... */ }
f = print_upper;

/* Appeler via le pointeur */
f("Alice");          /* appel normal */
(*f)("Alice");       /* appel explicite avec déréférencement */
```

---

### print_name — 0-print_name.c

Prend un nom et un **pointeur de fonction** en paramètre, et appelle la fonction avec le nom :

```c
void print_name(char *name, void (*f)(char *))
{
    if (name != NULL && f != NULL)
        f(name);
}
```

**Utilisation :**
```c
void print_upper(char *name) { /* affiche en majuscules */ }
void print_lower(char *name) { /* affiche en minuscules */ }

print_name("Alice", print_upper);
print_name("Bob",   print_lower);
```

---

### array_iterator — 1-array_iterator.c

Applique une fonction à **chaque élément** d'un tableau :

```c
void array_iterator(int *array, size_t size, void (*action)(int))
{
    size_t i;

    if (action == NULL || array == NULL)
        return;
    for (i = 0; i < size; i++)
        action(array[i]);
}
```

**Utilisation :**
```c
void print_elem(int n) { printf("%d\n", n); }

array_iterator(arr, 5, print_elem);
```

C'est le principe du **callback** : passer une fonction comme argument pour personnaliser le comportement.

---

### int_index — 2-int_index.c

Cherche dans un tableau le premier élément pour lequel une fonction de comparaison retourne vrai :

```c
int int_index(int *array, int size, int (*cmp)(int))
{
    int i;

    if (array == NULL || cmp == NULL || size <= 0)
        return (-1);
    for (i = 0; i < size; i++)
    {
        if (cmp(array[i]))
            return (i);
    }
    return (-1);
}
```

**Utilisation :**
```c
int is_even(int n) { return (n % 2 == 0); }

int idx = int_index(arr, 10, is_even);  /* index du premier nombre pair */
```

---

### Calculatrice avec tableau de structures — 3-get_op_func.c

Utilise un tableau de structures `op_t` associant un opérateur (chaîne) à une fonction :

```c
typedef struct op
{
    char *op;
    int (*f)(int a, int b);
} op_t;

int (*get_op_func(char *s))(int, int)
{
    op_t ops[] = {
        {"+", op_add},
        {"-", op_sub},
        {"*", op_mul},
        {"/", op_div},
        {"%", op_mod},
        {NULL, NULL}
    };
    int i = 0;

    while (ops[i].op != NULL && ops[i].op[0] != s[0])
        i++;
    if (ops[i].op == NULL)
        return (NULL);
    return (ops[i].f);
}
```

**Lecture de la signature :** `int (*get_op_func(char *s))(int, int)`
- `get_op_func` est une fonction qui prend `char *s`
- et **retourne** un pointeur vers une fonction `int f(int, int)`

---

### Pointeurs de fonctions en typedef

Pour rendre le code plus lisible, on peut créer un alias :

```c
typedef void (*print_fn)(char *);

/* Au lieu de : */
void print_name(char *name, void (*f)(char *));
/* On peut écrire : */
void print_name(char *name, print_fn f);
```

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-print_name.c` | Appeler une fonction via pointeur |
| `1-array_iterator.c` | Callback sur chaque élément d'un tableau |
| `2-int_index.c` | Recherche avec prédicat (fonction de comparaison) |
| `3-get_op_func.c` | Tableau de struct {opérateur, fonction}, dispatch |
| `3-op_functions.c` | Fonctions arithmétiques (+, -, *, /, %) |
| `3-calc.h` | typedef `op_t`, prototypes |
| `function_pointers.h` | Prototypes des fonctions du projet |
