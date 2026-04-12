# C - Singly Linked Lists

## Concepts clés

### Qu'est-ce qu'une liste chaînée simple ?

Une **liste chaînée simple** est une structure de données où chaque élément (nœud) contient :
- Une **donnée** (ici une chaîne de caractères)
- Un **pointeur vers le nœud suivant**

```
[str|len|next] → [str|len|next] → [str|len|next] → NULL
    nœud 1            nœud 2            nœud 3
```

Contrairement à un tableau, les nœuds ne sont **pas contigus en mémoire** — ils sont reliés par des pointeurs.

---

### Structure du nœud — lists.h

```c
typedef struct list_s
{
    char         *str;   /* chaîne de caractères (allouée avec malloc) */
    unsigned int  len;   /* longueur de la chaîne */
    struct list_s *next; /* pointeur vers le nœud suivant */
} list_t;
```

- `struct list_s *next` : auto-référence — la structure pointe vers elle-même.
- `NULL` signifie la fin de la liste.

---

### Parcourir une liste — 0-print_list.c

```c
size_t print_list(const list_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        if (h->str == NULL)
            printf("[0] (nil)\n");
        else
            printf("[%u] %s\n", h->len, h->str);
        h = h->next;   /* avancer vers le nœud suivant */
        count++;
    }
    return (count);
}
```

**Technique :** On avance en faisant `h = h->next` jusqu'à ce que `h == NULL`.

---

### Compter les nœuds — 1-list_len.c

```c
size_t list_len(const list_t *h)
{
    size_t len = 0;

    while (h != NULL)
    {
        len++;
        h = h->next;
    }
    return (len);
}
```

---

### Ajouter un nœud en tête — 2-add_node.c

```c
list_t *add_node(list_t **head, const char *str)
{
    list_t *new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    new_node->str  = strdup(str);   /* copie la chaîne */
    new_node->len  = strlen(str);
    new_node->next = *head;         /* pointe vers l'ancienne tête */
    *head = new_node;               /* la nouvelle tête est ce nœud */

    return (new_node);
}
```

**Pourquoi `list_t **head` (double pointeur) ?**
Pour modifier le pointeur `head` lui-même (lui faire pointer vers le nouveau nœud), il faut passer l'**adresse** de ce pointeur.

```
Avant : head → [A] → [B] → NULL
Après : head → [new] → [A] → [B] → NULL
```

---

### Ajouter un nœud en fin — 3-add_node_end.c

```c
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *tmp = *head;

    /* configurer le nouveau nœud */
    new_node->str  = strdup(str);
    new_node->len  = strlen(str);
    new_node->next = NULL;

    if (*head == NULL)      /* liste vide */
    {
        *head = new_node;
        return (new_node);
    }
    while (tmp->next != NULL)   /* aller jusqu'au dernier nœud */
        tmp = tmp->next;
    tmp->next = new_node;       /* attacher le nouveau nœud */

    return (new_node);
}
```

---

### Libérer la liste — 4-free_list.c

```c
void free_list(list_t *head)
{
    list_t *tmp;

    while (head != NULL)
    {
        tmp = head->next;   /* sauvegarder le pointeur suivant */
        free(head->str);    /* libérer la chaîne */
        free(head);         /* libérer le nœud */
        head = tmp;         /* avancer */
    }
}
```

**Important :** Sauvegarder `head->next` **avant** de `free(head)`, car après la libération la mémoire est invalide.

---

### Comparaison tableau vs liste chaînée

| | Tableau | Liste chaînée |
|--|---------|----------------|
| Accès par index | O(1) | O(n) |
| Insertion en tête | O(n) | O(1) |
| Insertion en fin | O(1) amortie | O(n) (sans pointeur de fin) |
| Mémoire | Contiguë | Fragmentée |
| Taille fixe ? | Oui (statique) | Non (dynamique) |

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `lists.h` | Structure `list_t`, prototypes |
| `0-print_list.c` | Parcours de liste, `while (h != NULL)` |
| `1-list_len.c` | Compter les nœuds |
| `2-add_node.c` | Insertion en tête, double pointeur |
| `3-add_node_end.c` | Insertion en fin, parcours jusqu'au dernier |
| `4-free_list.c` | Libération de tous les nœuds |
