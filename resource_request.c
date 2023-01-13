#include <stdio.h>
#include <stdlib.h>
int checker(int *, int *, int);
int r_chceker(int* , int* , int);
void print_status(int *, int *, int);
int banker(int** , int** ,int** , int* , int* , int , int);
int main(){
	int **max, **allocation, **need, *avail, *visit, p_num, r_num, i = 0, j = 0 , decession ; 
	printf("\nENTER THE NUMBER OF RESOURCE!\n");
	scanf("%d", &r_num);
	printf("\nENTER THE NUMBER OF PROCESS!\n");
	scanf("%d", &p_num);
	max = (int **)malloc(p_num * sizeof(int *));
	allocation = (int **)malloc(p_num * sizeof(int *));
	need = (int **)malloc(p_num * sizeof(int *));
	avail = (int *)calloc(r_num, sizeof(int));
	visit = (int *)calloc(p_num, sizeof(int));
	for (i = 0; i < p_num; i++)
	{
		max[i] = (int *)malloc(r_num * sizeof(int));
		allocation[i] = (int *)malloc(r_num * sizeof(int));
		need[i] = (int *)malloc(r_num * sizeof(int));
	}

	printf("\nInput the maximum matrix! \n");
	for (i = 0; i < p_num; i++)
	{

		for (j = 0; j < r_num; j++)
		{

			scanf("%d", &max[i][j]);
		}
	}
	printf("\nInput the allocation matrix! \n");
	for (i = 0; i < p_num; i++)
	{

		for (j = 0; j < r_num; j++)
		{

			scanf("%d", &allocation[i][j]);
		}
	}
	printf("\nInput the available matrix! \n");
	for (i = 0; i < r_num; i++)
	{

		scanf("%d", &avail[i]);
	}
	for (i = 0; i < p_num; i++)
	{

		for (j = 0; j < r_num; j++)
		{

			need[i][j] = max[i][j] - allocation[i][j];
		}
	}
	printf("\nNeed matrix ==>\n");
	for (i = 0; i < p_num; i++)
	{

		for (j = 0; j < r_num; j++)
		{

			printf(" %d ", need[i][j]);
		}
		printf("\n");
	}
	 int k = 0 , *request;
	 printf("\nEnter the process no. for requesting!\n");
	 scanf("%d",&k);
	 request = (int *)calloc(r_num, sizeof(int));
	 printf("\nEnter the request vector!\n");
	 for(i = 0 ; i < r_num ; i++){
	 	scanf("%d",&request[i]);
	 }
	 if(r_checker(request,need[k-1],r_num)){
	 	 printf("\nRequest of process %d exceeded its maximum claim!\n",k);
	 	 exit(0);
	 }
	 else{
	 	if(r_checker(request,avail,r_num)){
	 		printf("\nProcess %d must wait,since the resources are not available\n",k);
	 		exit(0);
		 }
		else{
			for(i = 0 ; i < r_num ; i++){
				avail[i] = avail[i] - request[i];
				allocation[k-1][i] = allocation[k-1][i] + request[i];
				need[k-1][i] = need[k-1][i] - request[i];
			}
		}
	 }
	
	decession = banker(max,allocation,need, avail,visit,p_num ,r_num);
	if(decession == 1){
		printf("\nSo the request of process %d can be granted!\n",k);
	}
	else{
			printf("\nSo the request of process %d can't' be granted!\n",k);
	}
	return 0;
}

int banker(int **max, int **allocation, int **need, int *avail, int *visit, int p_num , int r_num){
	int *rank , i = 0 , j = 0 , r = 0 , flag = 0 , count = 0 , temp = 0;
	rank = (int *)calloc(p_num, sizeof(int));
while (1)
	{
		flag = 0;
		for (i = 0; i < p_num; i++)
		{
			if (visit[i] != -1)
			{
				printf("\n.......Status of process %d.......\n", i + 1);
				print_status(avail, need[i], r_num);
			}
			temp = checker(avail, need[i], r_num);
			if (temp == 0)
			{
				printf("\n*********************************\n");
				printf("|Process no %d can't be assigned!|", i + 1);
				printf("\n*********************************\n");
			}
			if (visit[i] != -1 && temp)
			{
				rank[r] = i + 1;
				r++;
				printf("\n***************************\n");
				printf("|Process no %d is assigned!|", i + 1);
				printf("\n***************************\n");
				visit[i] = -1;
				for (j = 0; j < r_num; j++)
				{

					avail[j] = allocation[i][j] + avail[j];
				}
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
	printf("\nThe sequence is==> ");
	for (i = 0; i < p_num; i++)
	{
		if (visit[rank[i] - 1] == -1)
		{
			if (i == p_num - 1)
			{
				printf("[%d]", rank[i]);
			}
			else
			{
				printf("[%d]=>", rank[i]);
			}
			count++;
		}
	}
	if (count == p_num)
	{
		printf("\n\n************System is in safe state!************\n");
		return 1;
	}
	else
	{
		printf("\n\n************System is in unsafe state!************\n");
		return 0;
	}
	
	
}


int checker(int *avail, int *need, int size)
{

	int i = 0;
	for (i = 0; i < size; i++)
	{
		if (need[i] != avail[i] && avail[i] < need[i])
		{
			return 0;
		}
	}
	return 1;
}
int r_checker(int *first, int *second, int size)
{

	int i = 0 , cout = 0;
	for (i = 0; i < size; i++)
	{
		if (first[i] <= second[i])
		{
			cout++;
		}
	}
	if(cout == size){
		return 0;
	}
	else{
		return 1;
	}
}

void print_status(int *avail, int *need, int size)
{

	int i = 0;
	printf("Need => ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", need[i]);
	}
	printf("\nAvailable => ");
	for (i = 0; i < size; i++)
	{
		printf("%d ", avail[i]);
	}
}
