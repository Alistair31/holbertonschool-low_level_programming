# ARGV & ARGC

## Command-Line Utilities

This documentation covers five C programs demonstrating command-line argument handling. Each utility illustrates a unique use case for **argc** and **argv**.

### 0-whatsmyname.c

This utility prints its own name. It ignores any additional arguments and outputs **argv[0]**.

#### Purpose
- Display the executable’s filename.
- Illustrate use of **argv[0]**.

#### Compilation
```bash
gcc -Wall -Wextra -Werror 0-whatsmyname.c -o whatsmyname
```

#### Usage
```bash
./whatsmyname any other args
```
Output:
```plaintext
./whatsmyname
```

#### Parameters
| Name | Type    | Description                         |
| ---- | ------- | ----------------------------------- |
| argc | int     | Argument count (unused)             |
| argv | char**  | Array of argument strings           |

#### Key Lines
Key operations include:
- **Suppress unused warning** via `(void)argc;`
- **Print program name** with `printf`

```c
(void)argc;
printf("%s\n", argv[0]);
```

---

### 1-args.c

This program prints the number of arguments passed, excluding the program name. It highlights simple **argc** arithmetic.

#### Purpose
- Count user-supplied arguments.
- Demonstrate subtraction on **argc**.

#### Compilation
```bash
gcc -Wall -Wextra -Werror 1-args.c -o args_count
```

#### Usage
```bash
./args_count one two three
```
Output:
```plaintext
3
```

#### Code Walkthrough
| Step | Code Snippet                      | Description                      |
| ---- | --------------------------------- | -------------------------------- |
| 1    | `(void)argv;`                     | Suppress unused warning          |
| 2    | `printf("%d\n", argc - 1);`       | Print count minus program name   |
| 3    | `return (0);`                     | Exit with success status         |

---

### 2-args.c

This utility lists all arguments on separate lines. It includes the program name first, then each argument in order.

#### Purpose
- Display each **argv** entry.
- Show array traversal with a loop.

#### Compilation
```bash
gcc -Wall -Wextra -Werror 2-args.c -o args_list
```

#### Usage
```bash
./args_list alpha beta gamma
```
Output:
```plaintext
./args_list
alpha
beta
gamma
```

#### Code Details
- Initialize loop index `i` to zero.
- Iterate while `i < argc`.
- Print `argv[i]` per iteration.
- Return success.

```c
for (i = 0; i < argc; i++)
{
    printf("%s\n", argv[i]);
}
```

---

### 3-mul.c

This program multiplies two integers provided as command-line arguments. It enforces strict argument count and basic error reporting.

#### Purpose
- Multiply two integer inputs.
- Handle incorrect usage with an error message.

#### Compilation
```bash
gcc -Wall -Wextra -Werror 3-mul.c -o mul
```

#### Usage
```bash
./mul 6 7
```
Output:
```plaintext
42
```
Incorrect usage:
```bash
./mul 5
```
Output:
```plaintext
Error
```

#### Logic Flow
1. Check if **argc** equals 3.
2. If not, print **Error** and return status **1**.
3. Convert `argv[1]` and `argv[2]` to integers using `atoi`.
4. Print their product.
5. Return **0** on success.

---

### 4-add.c ➕

This utility sums positive integers given as arguments. It validates that each argument contains only digits and handles errors gracefully.

#### Purpose
- Sum non-negative integer inputs.
- Validate each argument using **isdigit**.

#### Compilation
```bash
gcc -Wall -Wextra -Werror 4-add.c -o add
```

#### Usage
```bash
./add 10 20 30
```
Output:
```plaintext
60
```
No arguments:
```bash
./add
```
Output:
```plaintext
0
```
Invalid input:
```bash
./add 5 �
```
Output:
```plaintext
Error
```

#### Input Validation
- If **argc** is 1, print **0** and exit.
- For each `argv[i]`, ensure every character is a digit.
- On validation failure, print **Error** and return **1**.
- Otherwise, convert with `atoi` and accumulate.

```c
if (argc == 1)
{
    printf("0\n");
    return (0);
}

for (i = 1; i < argc; i++)
{
    for (j = 0; argv[i][j] != '\0'; j++)
    {
        if (!isdigit(argv[i][j]))
        {
            printf("Error\n");
            return (1);
        }
    }
    sum += atoi(argv[i]);
}
printf("%d\n", sum);
```

```card
{
  "title": "Negative Numbers",
  "content": "This program accepts only non-negative integer arguments."
}
```

---
