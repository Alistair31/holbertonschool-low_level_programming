# C - Recursion

## Concepts clés

### Qu'est-ce que la récursion ?

La **récursion** est une technique où une fonction s'appelle elle-même pour résoudre un problème en le décomposant en sous-problèmes plus simples.

Toute fonction récursive a besoin de deux éléments :
1. **Le cas de base** : condition qui arrête la récursion (sans quoi → boucle infinie)
2. **L'appel récursif** : l'appel de la fonction sur un sous-problème plus petit

```
f(n) → f(n-1) → f(n-2) → ... → f(0) [cas de base]
```

---

### Exemple fondamental : Factorielle — 3-factorial.c

La factorielle de `n` est définie comme :
- `0! = 1` (cas de base)
- `n! = n × (n-1)!` (appel récursif)

```c
int factorial(int n)
{
    if (n < 0)
        return (-1);      /* erreur */
    else if (n == 0)
        return (1);       /* cas de base */
    return (n * factorial(n - 1));  /* appel récursif */
}
```

**Trace d'exécution pour `factorial(4)` :**
```
factorial(4) = 4 * factorial(3)
                   = 3 * factorial(2)
                         = 2 * factorial(1)
                               = 1 * factorial(0)
                                     = 1
             = 4 * 3 * 2 * 1 = 24
```

---

### Longueur de chaîne — 2-strlen_recursion.c

```c
int _strlen_recursion(char *s)
{
    if (*s == '\0')
        return (0);           /* cas de base : fin de chaîne */
    return (1 + _strlen_recursion(s + 1));  /* +1 par caractère */
}
```

- `s + 1` avance d'un caractère dans la chaîne.
- La longueur est 1 (caractère courant) + longueur du reste.

---

### Afficher et inverser — 0 et 1

#### puts_recursion — 0-puts_recursion.c

```c
void _puts_recursion(char *s)
{
    if (*s == '\0')
    {
        _putchar('\n');
        return;
    }
    _putchar(*s);
    _puts_recursion(s + 1);
}
```

#### print_rev_recursion — 1-print_rev_recursion.c

```c
void _print_rev_recursion(char *s)
{
    if (*s == '\0')
        return;
    _print_rev_recursion(s + 1);  /* d'abord avancer jusqu'à la fin */
    _putchar(*s);                  /* puis afficher au retour */
}
```

**Astuce :** Pour afficher à l'envers, on effectue l'appel récursif **avant** d'afficher — on affiche donc au moment du "dépliage" de la pile.

---

### Puissance — 4-pow_recursion.c

```c
int _pow_recursion(int x, int y)
{
    if (y < 0)
        return (-1);
    if (y == 0)
        return (1);
    return (x * _pow_recursion(x, y - 1));
}
```

- `x^0 = 1` (cas de base)
- `x^y = x × x^(y-1)` (récursion)

---

### Racine carrée — 5-sqrt_recursion.c

```c
int sqrt_helper(int n, int i)
{
    if (i * i == n)
        return (i);
    if (i * i > n)
        return (-1);
    return (sqrt_helper(n, i + 1));
}

int _sqrt_recursion(int n)
{
    return (sqrt_helper(n, 0));
}
```

- On teste chaque entier `i` : si `i*i == n`, c'est la racine.
- Si `i*i > n` sans avoir trouvé, il n'y a pas de racine entière.
- Utilise une **fonction auxiliaire** avec un accumulateur.

---

### Nombre premier — 6-is_prime_number.c

```c
int is_prime_helper(int n, int div)
{
    if (div >= n)
        return (1);
    if (n % div == 0)
        return (0);
    return (is_prime_helper(n, div + 1));
}

int is_prime_number(int n)
{
    if (n <= 1)
        return (0);
    return (is_prime_helper(n, 2));
}
```

---

### La pile d'appels (call stack)

Chaque appel récursif crée un nouveau **cadre de pile** (stack frame) contenant les variables locales et l'adresse de retour.

```
[ factorial(4) ]  ← premier appel
[ factorial(3) ]
[ factorial(2) ]
[ factorial(1) ]
[ factorial(0) ]  ← cas de base, retourne 1
```

Attention : une récursion trop profonde provoque un **stack overflow** (dépassement de pile).

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-puts_recursion.c` | Parcours récursif d'une chaîne |
| `1-print_rev_recursion.c` | Affichage inverse, ordre des opérations |
| `2-strlen_recursion.c` | Longueur de chaîne récursive |
| `3-factorial.c` | Factorielle, cas de base, appel récursif |
| `4-pow_recursion.c` | Puissance récursive |
| `5-sqrt_recursion.c` | Racine entière, fonction auxiliaire |
| `6-is_prime_number.c` | Test de primalité récursif |
