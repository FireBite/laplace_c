# laplace_c
Quick and dirty program that calculates square matrix det using Laplace method

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
Calculate 4x4 matrix using example m4 file:
```
./laplace < m4
```

Available examples:

* `./m2` - 2x2 matrix
* `./m3` - 3x3 matrix
* `./m4` - 4x4 matrix
* `./m6` - 6x6 matrix
