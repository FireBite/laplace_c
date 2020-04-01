# laplace_c
Quick and dirty program that calculates square matrix det using Laplace method  
Currently segfaults for sizes >= 4 :))

## Usage
from STDIN:
```
./laplace
[MATRIX_SIZE]
[MATRIX_ELEMENTS...]
```
from file:
`./laplace < [MATRIX_SIZE] [MATRIX_ELEMENTS...]`

## Examples
Calculate 3x3 matrix:
```
./laplace
3
1 2 3
1 8 5
4 5 6
```
Calculate 4x4 matrix using m4 file:
```
./laplace < m4
```
