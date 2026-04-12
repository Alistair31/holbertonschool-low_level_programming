# C - Structures, Typedef

## Concepts clés

### Les structures (struct)

Une **structure** regroupe plusieurs variables de types différents sous un seul nom. C'est l'équivalent d'un objet simple en C.

#### Définition

```c
struct dog
{
    char  *name;
    float  age;
    char  *owner;
};
```

#### Déclaration et accès

```c
struct dog my_dog;

my_dog.name  = "Poppy";
my_dog.age   = 3.5;
my_dog.owner = "Bob";

printf("%s is %.1f years old\n", my_dog.name, my_dog.age);
```

- L'opérateur `.` accède aux membres d'une structure déclarée directement.

#### Accès via un pointeur

```c
struct dog *d = &my_dog;

d->name = "Rex";   /* équivalent à (*d).name = "Rex" */
```

- L'opérateur `->` accède aux membres via un pointeur.

---

### typedef

`typedef` crée un **alias** pour un type existant, évitant de répéter `struct dog` à chaque déclaration.

```c
typedef struct dog dog_t;
```

Maintenant `dog_t` est équivalent à `struct dog` :
```c
dog_t my_dog;   /* au lieu de : struct dog my_dog; */
```

**Combiné en une seule déclaration :**
```c
typedef struct dog
{
    char  *name;
    float  age;
    char  *owner;
} dog_t;
```

---

### init_dog — 1-init_dog.c

Initialise une structure existante via un pointeur :

```c
void init_dog(struct dog *d, char *name, float age, char *owner)
{
    if (d == NULL)
        return;
    d->name  = name;
    d->age   = age;
    d->owner = owner;
}
```

- On passe `&my_dog` pour modifier la structure originale.
- Vérifier toujours que le pointeur n'est pas NULL.

---

### new_dog — 4-new_dog.c

Crée une nouvelle structure sur le **tas (heap)** avec `malloc` :

```c
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *newdog = malloc(sizeof(dog_t));
    if (newdog == NULL)
        return (NULL);

    newdog->name  = malloc(strlen(name) + 1);
    newdog->owner = malloc(strlen(owner) + 1);
    newdog->age   = age;

    return (newdog);
}
```

**Pourquoi dupliquer les chaînes ?**
En dupliquant avec `malloc`, la structure possède sa propre copie indépendante de l'appelant.

---

### free_dog — 5-free_dog.c

Libère toute la mémoire allouée par `new_dog` :

```c
void free_dog(dog_t *d)
{
    if (d == NULL)
        return;
    free(d->name);
    free(d->owner);
    free(d);
}
```

**Ordre de libération :** Libérer d'abord les membres alloués, **puis** la structure elle-même.

---

### sizeof(struct)

La taille d'une structure peut dépasser la somme des tailles de ses membres à cause du **padding** (alignement mémoire).

```c
struct dog
{
    char  *name;   /* 8 octets (pointeur 64 bits) */
    float  age;    /* 4 octets */
    char  *owner;  /* 8 octets */
};
/* sizeof(struct dog) = 24 octets */
```

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `dog.h` | Définition de `struct dog`, typedef `dog_t` |
| `1-init_dog.c` | Initialiser une structure via pointeur |
| `2-print_dog.c` | Afficher les membres d'une structure |
| `4-new_dog.c` | Allouer une structure dynamiquement |
| `5-free_dog.c` | Libérer une structure et ses membres |
