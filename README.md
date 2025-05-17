# Graph Project — Maximum Flow Algorithm — DINIC

This C project implements a **maximum flow algorithm** on a net using a **residual graph** structure.  
The program reads an input file in **DIMACS format**, builds the corresponding graph, and computes the maximum flow between a source and a sink using a path-augmenting algorithm.

📄 This README is available in French:
👉 [🇫🇷 Version française](README.fr.md)

## ⚙️ Compilation

This project can be compiled using `gcc`:

```bash
gcc main.c src/*.c -Iinclude -o graphe -Wall -Wextra
```

Make sure the include paths and file organization are correct.

## 📚 Usage

The executable can be run as follows:

```bash
./graphe [dimacs_file] [verbose]
```

- `<dimacs_file>`: Input file containing the graph definition in DIMACS format.
- `[verbose]` _(optional)_:
  - `"true"` or `"1"`: Enables verbose mode (detailed step-by-step display).
  - If omitted: the algorithm runs silently.

## 📄 Input Format

The DIMACS file must follow this standard format:

```
c comment
p max N M         # N nodes, M edges
n <id> s|t        # Node marked as source (s) or sink (t)
a u v c           # Edge from node u to v with capacity c
```

## 📝 Example

```
p max 4 5
n 1 s
n 4 t
a 1 2 10
a 1 3 5
a 2 4 10
a 3 2 15
a 3 4 10
```

## 🧪 Debug & Verbose Mode

Use `"true"` as the second argument to:

- Display the internal structure of the graph (successor lists)
- Show each step of the flow update process
- Facilitate debugging or help understand the algorithm pedagogically
