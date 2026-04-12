# C - Hello, World

## Concepts clés

### Le processus de compilation en C

En C, le code source passe par **4 étapes** avant de devenir un exécutable :

```
Source (.c)  →  Préprocesseur  →  Compilateur  →  Assembleur  →  Éditeur de liens  →  Exécutable
```

| Étape | Outil | Flag | Résultat |
|-------|-------|------|----------|
| Préprocessing | `gcc -E` | `-E` | Fichier `.i` (macros résolues, headers inclus) |
| Compilation | `gcc -S` | `-S` | Fichier `.s` (code assembleur) |
| Assemblage | `gcc -c` | `-c` | Fichier `.o` (code objet binaire) |
| Édition de liens | `gcc` | _(aucun)_ | Exécutable final |

#### Exemples des scripts de ce projet

```bash
# 0-preprocessor : ne fait que le préprocessing
gcc -E $CFILE -o c

# 1-compiler : compile sans lier (produit un .o)
gcc -c $CFILE

# 2-assembler : génère le code assembleur (.s)
gcc -S $CFILE

# 3-name : compile et lie, nomme l'exécutable "cisfun"
gcc -o cisfun $CFILE
```

---

### Structure d'un programme C minimal

```c
#include <stdio.h>      /* inclusion du header standard pour printf/puts */

/**
 * main - Point d'entrée du programme
 *
 * Return: 0 en cas de succès
 */
int main(void)
{
    /* instructions */
    return (0);
}
```

- `#include <stdio.h>` : inclut les déclarations des fonctions d'entrée/sortie standard.
- `int main(void)` : point d'entrée obligatoire ; retourne un entier (0 = succès).
- `return (0)` : convention UNIX — 0 signifie "pas d'erreur".

---

### puts vs printf

#### `puts` — 4-puts.c

```c
puts("\"Programming is like building a multilingual puzzle");
```

- Affiche une chaîne **puis ajoute automatiquement `\n`**.
- Plus simple que `printf` pour du texte fixe.
- `\"` est une séquence d'échappement pour afficher un guillemet littéral.

**Sortie :**
```
"Programming is like building a multilingual puzzle
```

#### `printf` — 5-printf.c

```c
printf("with proper grammar, but the outcome is a piece of art,\n");
```

- Affiche une chaîne formatée. Le `\n` en fin de chaîne doit être explicite.
- Supporte les **spécificateurs de format** : `%d`, `%f`, `%s`, `%zu`, etc.

**Sortie :**
```
with proper grammar, but the outcome is a piece of art,
```

---

### sizeof et les types primitifs — 6-size.c

```c
printf("Size of a char: %zu byte(s)\n", sizeof(char));
printf("Size of an int: %zu byte(s)\n", sizeof(int));
printf("Size of a long int: %zu byte(s)\n", sizeof(long int));
printf("Size of a long long int: %zu byte(s)\n", sizeof(long long int));
printf("Size of a float: %zu byte(s)\n", sizeof(float));
```

- `sizeof` est un **opérateur** (pas une fonction) qui retourne la taille en octets d'un type ou d'une variable.
- `%zu` est le spécificateur de format pour `size_t` (valeur retournée par `sizeof`).

| Type | Taille typique (64 bits) |
|------|--------------------------|
| `char` | 1 octet |
| `int` | 4 octets |
| `long int` | 8 octets |
| `long long int` | 8 octets |
| `float` | 4 octets |

> Les tailles peuvent varier selon l'architecture (32 vs 64 bits).

---

### Séquences d'échappement courantes

| Séquence | Signification |
|----------|---------------|
| `\n` | Saut de ligne (newline) |
| `\t` | Tabulation |
| `\\` | Antislash littéral |
| `\"` | Guillemet double littéral |
| `\'` | Guillemet simple littéral |

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-preprocessor` | Étape de préprocessing (`gcc -E`) |
| `1-compiler` | Compilation sans lien (`gcc -c`) |
| `2-assembler` | Génération d'assembleur (`gcc -S`) |
| `3-name` | Compilation complète avec nom personnalisé |
| `4-puts.c` | `puts()` et séquences d'échappement |
| `5-printf.c` | `printf()` et `\n` explicite |
| `6-size.c` | `sizeof` et types primitifs C |
