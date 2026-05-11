# ObjektinisProg

## Spartos tyrimas

Tyrimui naudojami prieš tai sugeneruoti failai. Bandyti visi rūšiavimo ir galutinio skaičiavimo būdai, rezultatai išreikšti vidurkiu.

**Specs:** AMD Ryzen 5 3600 · HyperX DDR4 16GB · SSD 970 M.2 250GB

---

### 1 strategija

Bendro studentai konteinerio skaidymas į du naujus to paties tipo konteinerius: „nevykeliai" ir „nerds". Tokiu būdu tas pats studentas yra dvejuose konteineriuose: bendrame studentai ir viename iš suskaidytų.

| Studentų kiekis | Konteineris | Nuskaitymas (ms) | Rūšiavimas (ms) | Skirstymas (ms) |
|----------------:|-------------|----------------:|----------------:|----------------:|
| 1 000           | vector      | 2.53            | 0.18            | 0.09            |
|                 | deque       | 1.74            | 0.21            | 0.08            |
|                 | list        | 2.07            | 0.09            | 0.11            |
| 10 000          | vector      | 45.12           | 26.47           | 0.43            |
|                 | deque       | 41.61           | 29.34           | 0.29            |
|                 | list        | 49.38           | 13.02           | 0.37            |
| 100 000         | vector      | 439.84          | 363.55          | 16.28           |
|                 | deque       | 441.07          | 404.92          | 15.83           |
|                 | list        | 451.29          | 171.84          | 24.51           |
| 1 000 000       | vector      | 4397.41         | 4868.73         | 192.74          |
|                 | deque       | 4418.56         | 5341.08         | 169.17          |
|                 | list        | 4454.83         | 2207.16         | 220.39          |
| 10 000 000      | vector      | 44284.6         | 62254.37        | 1880.62         |
|                 | deque       | 44514.8         | 69897.44        | 1865.93         |
|                 | list        | 44742.3         | 28843.91        | 2444.18         |