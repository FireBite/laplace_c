#include <stdio.h>
#include <stdlib.h>

int call_n = 0;

int calc_laplace(int **matrix, int size){
	//Fancy debug
	printf("--| LAPLACE |--\n");
	printf(">N:    %d\n", size);
	printf(">CPLX: %d\n", call_n);
	
	for(int i = 0; i < size; i++){
		for(int n = 0; n < size; n++){
			printf("%d ", matrix[i][n]);
		}
		printf("\n");
	}
	
	//"Calculate" the quickest row
	int y = 0;
	int det = 0;
	
	//Edge/End case, calculate det normally
	if(size == 2){
		det = matrix[0][0] * matrix[1][1] 
			- matrix[0][1] * matrix[1][0];
		
		call_n--;
		printf("|STND| (%d)\n", det);
		return det;
	}
	
	//Divide and calculate det using laplace
	for(int i = 0; i < size; i++){	
		//Alloc new smaller matrix
		int **new_matrix = (int**) malloc((size-1) * (size-1) * sizeof(int));
		for(int n = 0; n < size-1; n++){
			new_matrix[n] = (int*) malloc((size-1) * sizeof(int));
		}
		
		int populated = 0;
		int row = 0;
		
		//Calc matrix multiplication scalar
		int scalar = matrix[y][i];
		if((y+i+2)&1)
			scalar *= -1;
		
		//No need to solve if scalar is 0
		printf(">Scalar: %d\n", scalar);
		if(!scalar){
			printf("|SKIP|\n");
			continue;
		}
		
		//Populate complement matrix
		for(int p = 0; p < size; p++){
			populated = 0;
			
			//Skip row
			if(p == y)
				continue;
			
			for(int q = 0; q < size; q++){
				//Skip col
				if(q == i)
					continue;
				
				//Populate
				printf(">ADD %d:%d -> %d:%d (%d)\n", p, q, row, populated, matrix[p][q]);
				new_matrix[row][populated] = matrix[p][q];
				populated++;
			}
			row++;
		}
		
		//Finnaly call recursively new laplace
		call_n++;
		printf("|RCSV|\n");
		det += calc_laplace(new_matrix, size-1) * scalar;
		
		//Free memory
		for(int n = 0; n < size-1; n++){
			free(new_matrix[n]);
		}
		free(new_matrix);
	}
	
	//Exit and return calculated det
	printf("|EXIT| [%d]\n", call_n);
	call_n--;
	return det;
}

int main()
{
	int size;
	scanf("%d", &size);
	
	int** matrix = (int**) malloc(size * size * sizeof(int));
	int el = 0;
	
	// Scan matrix into memory
	for(int i = 0; i < size; i++){
		matrix[i] = (int*) malloc(size * sizeof(int));
		
		for(int n = 0; n < size; n++){
			scanf("%d", &el);
			matrix[i][n] = el;
		}
	}
	
	int det = 0;
	
	//Calculate det using laplace
	switch(size){
		case 1:  //Easy case, return single el
			det = matrix[0][0];
			printf("|EZZY|\n");
			printf("|QUIT|\n");
			break;
		default: //Solve matrix recursively
			det = calc_laplace(matrix, size);
			printf("|QUIT|\n");
			break;
	}
	
	printf("\n~~~~| DET: %d |~~~~\n", det);
	
	//Free memory
	for(int n = 0; n < size; n++){
		free(matrix[n]);
	}
	free(matrix);
	
	return 0;
}