 #include<stdio.h>
 #include<stdlib.h>
 int main(){

 	int **mat , resource , process = 0 , edge = 0  , i = 0 , j = 0 , temp1 = 0 , temp2 = 0, k = 0 , l = 0;
	 
	 printf("\nENTER THE NUMBER OF RESOURCE!\n");
	 scanf("%d",&resource);
	 printf("\nENTER THE NUMBER OF PROCESS!\n");
	 scanf("%d",&process);
	 printf("\nENTER THE NUMBER OF EDGE!\n");
	 scanf("%d",&edge);
	 
	 mat = (int**)malloc( (process + resource) * sizeof(int*));
	 for( i = 0 ; i < edge ; i++){
	 	mat[i] = (int*)malloc( (process + resource) * sizeof(int) );
	 	
	 }
	  for( i = 0 ; i < (resource + process) ; i++){
	 		  for( j = 0 ; j < (resource + process) ; j++){
	 		  		mat[i][j] = 0;
			   }
	 	
	 }
	 printf("\nEnter the no. of processes, no. of resources, no. of edges: \n");
	 printf("	-------------------------------------------------------------\n");
	 printf("	|Conventions are given below =>                             |\n");
	 printf("	|   i) Process names start from 0 i.e. 0, 1, 2, etc.	    |\n");
	 printf("	|   ii)Resource names start at 100 i.e. 100, 101, 102 etc.  |\n");
	 printf("	-------------------------------------------------------------\n");
	 for( i = 0 ; i < edge ; i++){
	 		k = 0 ;
	 		l = 0;
	 		printf(" Enter at %d no. line: ",i+1);
	 		scanf("%d %d",&temp1,&temp2);
	 		if(temp1 >= 100){
	 			k = (temp1 % 100 ) + process ;
	 			l = temp2;
	 			
			 }
			 if(temp1 < 100){
			 	k = temp1;
			 	l = (temp2 % 100) + process;
		
			 }
			mat[k][l] = 1; 
		 }
		 
	 printf("\n ***************************{ ADJACENCY MATRIX }************************************\n\n");
	 printf("  ||<------------ALLOCATION EDGE---------->||<------------REQUEST EDGE----------->||\n");
	 printf("       0   ||  1   ||  2   ||  3   ||   4  ||  5   ||  6   ||  7   ||  8   ||  9  ||\n");
	 printf("    ................................................................................\n");
	  for( i = 0 ; i < (process + resource) ; i++){
	  		  printf("%d || ",i);
	 		  for( j = 0 ; j < (process + resource) ; j++){
	 		  		printf("  %d   | ",mat[i][j]);
			   }
				printf("\n    ................................................................................\n");
		}

	printf("\nProcesses : ");
	for( i = 0 ; i < process ; i++ ){
		printf("%d ",i);
	}
	printf("\n");
	printf("\nResources : ");
	for( i = 0 ; i < resource ; i++ ){
		printf("%d ",(100+i));
	}
	printf("\n");
	
	printf("\nRequest edges\n");
	for(i = 0 ; i < process + resource ; i++ ){
		for( j = process ; j < (process + resource) ; j++){
			if(mat[i][j] == 1){
				k = (j - process) + 100 ;
				printf("\n%d => %d\n",i,k);
			}
		}
	}
	printf("\nALlocation edges\n");
	for(i = 0 ; i < process + resource ; i++ ){
		for( j = 0 ; j < process; j++){
			if(mat[i][j] == 1){
				k = (i - process) + 100 ;
				printf("\n%d <= %d\n",k,j);
			}
		}
	}
	 return 0;
	 
}
