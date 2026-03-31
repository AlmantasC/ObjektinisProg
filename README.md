# ObjektinisProg

## Spartos tyrimas

Tyrimui naudojami prieš tai sugeneruoti failai. Bandyti visi rūšiavimo ir galutinio skaičiavimo būdai, rezultatai išreikšti vidurkiu.

**Specs:** AMD Ryzen 5 3600 · HyperX DDR4 16GB · SSD 970 M.2 250GB

---

### Nuskaitymas (ms)

| Studentų sk. | vector | list  | deque |
|-------------:|-------:|------:|------:|
| 1 000        | 4      | 8     | 3     |
| 10 000       | 50     | 45    | 45    |
| 100 000      | 437    | 441   | 454   |
| 1 000 000    | 4358   | 4408  | 4548  |
| 10 000 000   | 43856  | 44377 | 45548 |

### Rūšiavimas (ms)

| Studentų sk. | vector | list  | deque |
|-------------:|-------:|------:|------:|
| 1 000        | 4      | 0     | 4     |
| 10 000       | 32     | 12    | 33    |
| 100 000      | 438    | 139   | 462   |
| 1 000 000    | 5630   | 1681  | 6363  |
| 10 000 000   | 72303  | 20698 | 80866 |

### Skirstymas (ms)

| Studentų sk. | vector | list | deque |
|-------------:|-------:|-----:|------:|
| 1 000        | 0      | 0    | 0     |
| 10 000       | 4      | 0    | 0     |
| 100 000      | 15     | 20   | 13    |
| 1 000 000    | 145    | 204  | 166   |
| 10 000 000   | 1373   | 2225 | 1657  |