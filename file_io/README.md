# C - File I/O

## Concepts clés

### Les descripteurs de fichiers (File Descriptors)

En Unix, tout est fichier. Un **descripteur de fichier** (fd) est un entier qui identifie un fichier ouvert dans un processus.

| fd | Fichier standard |
|----|-----------------|
| 0 | `STDIN_FILENO` — entrée standard |
| 1 | `STDOUT_FILENO` — sortie standard |
| 2 | `STDERR_FILENO` — sortie d'erreur |

Les fichiers ouverts par le programme reçoivent les fd suivants (3, 4, etc.).

---

### open() — Ouvrir un fichier

```c
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```

- Retourne un fd (≥ 0) en cas de succès, **-1** en cas d'erreur.
- Doit être fermé avec `close()` quand on a fini.

#### Flags courants

| Flag | Signification |
|------|---------------|
| `O_RDONLY` | Lecture seule |
| `O_WRONLY` | Écriture seule |
| `O_RDWR` | Lecture + écriture |
| `O_CREAT` | Créer si n'existe pas |
| `O_TRUNC` | Vider le fichier s'il existe |
| `O_APPEND` | Écrire en fin de fichier |

**Exemple :**
```c
int fd = open("fichier.txt", O_RDONLY);
int fd = open("out.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
```

#### Permissions (mode)

- `0600` : lecture + écriture pour le propriétaire seulement
- `0664` : propriétaire (rw) + groupe (r) + autres (r)

---

### read() — Lire depuis un fd

```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
```

- Lit jusqu'à `count` octets dans `buf`.
- Retourne le nombre d'octets lus, **0** en fin de fichier, **-1** en erreur.

**Exemple — read_textfile (0-read_textfile.c) :**
```c
fd = open(filename, O_RDONLY);
count = read(fd, buffer, letters);
write(STDOUT_FILENO, buffer, count);
close(fd);
```

---

### write() — Écrire vers un fd

```c
ssize_t write(int fd, const void *buf, size_t count);
```

- Écrit `count` octets depuis `buf` vers le fd.
- Retourne le nombre d'octets écrits, **-1** en erreur.

**Exemple — create_file (1-create_file.c) :**
```c
int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (text_content != NULL)
    write(fd, text_content, strlen(text_content));
close(fd);
```

---

### close() — Fermer un fd

```c
int close(int fd);
```

- Libère le descripteur de fichier.
- **Toujours fermer** les fd ouverts pour éviter les fuites de ressources.

---

### dprintf() — Écrire sur un fd avec formatage

```c
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
```

Comme `printf` mais écrit sur un fd spécifique (ici stderr).

---

### Copie de fichier par blocs — 3-cp.c

```c
char buffer[1024];
ssize_t r, w;

while ((r = read(fd_from, buffer, 1024)) > 0)
{
    w = write(fd_to, buffer, r);
    if (w == -1 || w != r)
        exit(99);
}
```

**Codes d'exit :**
| Code | Signification |
|------|---------------|
| 97 | Mauvais nombre d'arguments |
| 98 | Impossible de lire le fichier source |
| 99 | Impossible d'écrire dans la destination |
| 100 | Impossible de fermer un fd |

---

## Résumé des fichiers

| Fichier | Concept principal |
|---------|-------------------|
| `0-read_textfile.c` | `open()`, `read()`, `write()`, `close()` |
| `1-create_file.c` | Créer/vider un fichier, `O_CREAT`, `O_TRUNC` |
| `2-append_text_to_file.c` | Ajouter en fin de fichier, `O_APPEND` |
| `3-cp.c` | Copie par blocs, gestion des erreurs, `dprintf` |
