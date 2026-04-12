# C - Doubly Linked Lists

## Concepts clés

### Qu'est-ce qu'une liste doublement chaînée ?

Une **liste doublement chaînée** étend la liste simple : chaque nœud possède deux pointeurs, l'un vers le **suivant** et l'autre vers le **précédent**.

```
NULL ← [prev|n|next] ⇄ [prev|n|next] ⇄ [prev|n|next] → NULL
           nœud 1            nœud 2           nœud 3
```

Cela permet de parcourir la liste **dans les deux sens** et de supprimer ou insérer un nœud en O(1) si on a un pointeur dessus.

---

### Structure du nœud — lists.h

```c
typedef struct dlistint_s
{
    int               n;    /* valeur stockée */
    struct dlistint_s *prev; /* pointeur vers le nœud précédent */
    struct dlistint_s *next; /* pointeur vers le nœud suivant */
} dlistint_t;
```

- Le premier nœud a `prev == NULL`.
- Le dernier nœud a `next == NULL`.

---

### Ajouter en tête — 2-add_dnodeint.c

```c
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new = malloc(sizeof(dlistint_t));
    if (new == NULL)
        return (NULL);

    new->n    = n;
    new->prev = NULL;    /* nouveau premier nœud, pas de précédent */
    new->next = *head;

    if (*head != NULL)
        (*head)->prev = new;  /* l'ancienne tête pointe en arrière vers new */

    *head = new;
    return (new);
}
```

---

### Insérer à un index — 7-insert_dnodeint.c

```c
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new, *current;
    unsigned int i = 0;

    if (idx == 0)
        return (add_dnodeint(h, n));  /* insertion en tête */

    /* Avancer jusqu'au nœud à l'index idx-1 */
    current = *h;
    while (current && i < idx - 1)
    {
        current = current->next;
        i++;
    }

    if (current == NULL)
        return (NULL);   /* index hors limites */

    if (current->next == NULL)
        return (add_dnodeint_end(h, n));  /* insertion en fin */

    /* Insertion au milieu */
    new = malloc(sizeof(dlistint_t));
    new->n             = n;
    new->next          = current->next;
    new->prev          = current;
    current->next->prev = new;  /* le nœud suivant pointe en arrière vers new */
    current->next      = new;

    return (new);
}
```

**Schéma de l'insertion au milieu :**
```
Avant : A ⇄ B
Après : A ⇄ NEW ⇄ B

Liens à mettre à jour :
  new->next          = B
  new->prev          = A
  A->next            = new
  B->prev            = new
```

---

### Supprimer un nœud — 8-delete_dnodeint.c

Pour supprimer le nœud à l'index `idx` :
1. Avancer jusqu'à ce nœud.
2. Reconnecter les voisins directement.
3. `free()` le nœud.

```c
/* Si nœud en tête */
*head = current->next;
if (*head)
    (*head)->prev = NULL;

/* Si nœud en fin */
current->prev->next = NULL;

/* Si nœud au milieu */
current->prev->next = current->next;
current->next->prev = current->prev;

free(current);
```

---

### sum_dlistint — 6-sum_dlistint.c

```c
int sum_dlistint(dlistint_t *head)
{
    int sum = 0;

    while (head != NULL)
    {
        sum += head->n;
        head = head->next;
    }
    return (sum);
}
```

---

### Comparaison liste simple vs doublement chaînée

| Opération | Liste simple | Liste double |
|-----------|-------------|--------------|
| Insertion en tête | O(1) | O(1) |
| Insertion à un index | O(n) | O(n) pour trouver, O(1) pour insérer |
| Suppression (avec pointeur) | O(n) (chercher le précédent) | O(1) |
| Parcours inverse | Impossible | O(n) |
| Mémoire par nœud | 1 pointeur extra | 2 pointeurs extra |

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `lists.h` | Structure `dlistint_t`, prototypes |
| `0-print_dlistint.c` | Afficher la liste |
| `1-dlistint_len.c` | Longueur de la liste |
| `2-add_dnodeint.c` | Insertion en tête, mise à jour de `prev` |
| `3-add_dnodeint_end.c` | Insertion en fin |
| `4-free_dlistint.c` | Libérer tous les nœuds |
| `5-get_dnodeint.c` | Obtenir le nœud à un index |
| `6-sum_dlistint.c` | Somme des valeurs |
| `7-insert_dnodeint.c` | Insertion à un index arbitraire |
| `8-delete_dnodeint.c` | Suppression à un index |
