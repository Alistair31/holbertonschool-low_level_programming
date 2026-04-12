# C - Hash Tables

## Concepts clés

### Qu'est-ce qu'une table de hachage ?

Une **table de hachage** (hash table) associe des **clés** à des **valeurs** en utilisant une fonction de hachage pour calculer un index dans un tableau.

```
clé "name" → hash → index 3 → valeur "Alice"
clé "age"  → hash → index 7 → valeur "30"
```

**Complexité moyenne :** O(1) pour l'insertion, la recherche et la suppression.

---

### Structure — hash_tables.h

```c
/* Nœud de la liste chaînée (pour gérer les collisions) */
typedef struct hash_node_s
{
    char *key;                  /* clé (chaîne unique) */
    char *value;                /* valeur associée */
    struct hash_node_s *next;   /* pointeur vers le nœud suivant (collision) */
} hash_node_t;

/* Table de hachage */
typedef struct hash_table_s
{
    unsigned long int  size;    /* taille du tableau */
    hash_node_t      **array;   /* tableau de listes chaînées */
} hash_table_t;
```

---

### Fonction de hachage — hash_djb2

La fonction **DJB2** est une fonction de hachage populaire pour les chaînes :

```c
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;  /* hash * 33 + c */
    return (hash);
}
```

- Transforme n'importe quelle chaîne en un grand entier.
- Pour obtenir l'index dans le tableau : `hash % size`.

```c
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
    return (hash_djb2(key) % size);
}
```

---

### Créer la table — 0-hash_table_create.c

```c
hash_table_t *hash_table_create(unsigned long int size)
{
    hash_table_t *ht = malloc(sizeof(hash_table_t));
    if (ht == NULL)
        return (NULL);

    ht->size  = size;
    ht->array = calloc(size, sizeof(hash_node_t *));
    /* calloc initialise tout à NULL — parfait pour les listes chaînées */
    if (ht->array == NULL)
    {
        free(ht);
        return (NULL);
    }
    return (ht);
}
```

---

### Insérer une paire clé/valeur — hash_table_set

```c
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
    unsigned long int idx = key_index((unsigned char *)key, ht->size);
    hash_node_t *new_node;

    /* Vérifier si la clé existe déjà (mettre à jour) */
    hash_node_t *tmp = ht->array[idx];
    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
        {
            free(tmp->value);
            tmp->value = strdup(value);
            return (1);
        }
        tmp = tmp->next;
    }

    /* Nouvelle clé : créer un nœud et l'insérer en tête de liste */
    new_node = malloc(sizeof(hash_node_t));
    new_node->key   = strdup(key);
    new_node->value = strdup(value);
    new_node->next  = ht->array[idx];
    ht->array[idx]  = new_node;
    return (1);
}
```

---

### Collisions et chaînage

Deux clés différentes peuvent produire le même index — c'est une **collision**.

La solution utilisée ici est le **chaînage** (chaining) : chaque case du tableau est une liste chaînée. En cas de collision, les nœuds sont ajoutés à la liste.

```
array[3] → ["name"/"Alice"] → ["city"/"Paris"] → NULL
```

---

### Rechercher une valeur — hash_table_get

```c
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int idx = key_index((unsigned char *)key, ht->size);
    hash_node_t *node = ht->array[idx];

    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }
    return (NULL);
}
```

---

### Facteur de charge (load factor)

```
load_factor = nombre_d_éléments / taille_du_tableau
```

- Un faible facteur de charge (< 0.7) garantit de bonnes performances.
- Un facteur élevé augmente les collisions et dégrade les performances vers O(n).

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `hash_tables.h` | Structures `hash_node_t` et `hash_table_t` |
| `0-hash_table_create.c` | Créer la table avec `calloc` |
| `hash_djb2` (dans le header) | Fonction de hachage DJB2 |
| `key_index` | Calculer l'index : `hash % size` |
| `hash_table_set` | Insertion avec gestion des collisions |
| `hash_table_get` | Recherche par clé |
| `hash_table_print` | Afficher toutes les paires clé/valeur |
| `hash_table_delete` | Libérer toute la table |
