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

---

### 2 strategija

Bendro studentų konteinerio skaidymas panaudojant tik vieną naują konteinerį: „nevykeliai". Tokiu būdu, jei studentas yra nevykelis, jį turime įkelti į naująjį „nevykelių" konteinerį ir ištrinti iš bendro studentai konteinerio. Po šio žingsnio studentai konteineryje liks vien tik nerds.

| Studentų kiekis | Konteineris | Nuskaitymas (ms) | Rūšiavimas (ms) | Skirstymas (ms) |
|----------------:|-------------|----------------:|----------------:|----------------:|
| 1 000           | vector      | 4.67            | 2.00            | 0.36            |
|                 | deque       | 4.32            | 0.67            | 0.00            |
|                 | list        | 5.67            | 0.99            | 0.33            |
| 10 000          | vector      | 43.85           | 28.67           | 2.00            |
|                 | deque       | 49.99           | 29.15           | 0.00            |
|                 | list        | 45.86           | 14.33           | 0.99            |
| 100 000         | vector      | 427.02          | 377.19          | 12.96           |
|                 | deque       | 435.62          | 246.08          | 13.86           |
|                 | list        | 450.60          | 186.96          | 21.33           |
| 1 000 000       | vector      | 4294.58         | 5088.73         | 141.03          |
|                 | deque       | 4357.09         | 5189.21         | 161.02          |
|                 | list        | 4516.69         | 2378.67         | 259.93          |
| 10 000 000      | vector      | 45101.00        | 64604.73        | 1559.45         |
|                 | deque       | 42853.97        | 66047.37        | 1807.13         |
|                 | list        | 45069.80        | 30505.13        | 2956.44         |