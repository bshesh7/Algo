// Floyd-Warshall all-pairs shortest paths with successors (Notes 16)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define oo (INT_MAX) // Infinity

int n;              // Number of vertices
int **dist,**succ;  // Distance and successor matrices
int **dist_odd,**succ_odd;
int **dist_even,**succ_even;
void readInput()
{
// Read weighted edges into adjacency matrix.
int i,j,k;

scanf("%d",&n);

//
//define dist_odd, dist_even, succ_odd, succ_even
dist_odd=(int**) malloc(n*sizeof(int*));
succ_odd=(int**) malloc(n*sizeof(int*));

dist_even=(int**) malloc(n*sizeof(int*));
succ_even=(int**) malloc(n*sizeof(int*));


dist=(int**) malloc(n*sizeof(int*));
succ=(int**) malloc(n*sizeof(int*));

if (!dist || !succ)
{
  printf("dist or succ malloc failed %d\n",__LINE__);
  exit(0);
}
//main
for (i=0;i<n;i++)
{
  dist[i]=(int*) malloc(n*sizeof(int));
  succ[i]=(int*) malloc(n*sizeof(int));
  if (!dist[i] || !succ[i])
  {
    printf("dist or succ row malloc failed %d\n",__LINE__);
    exit(0);
  }
}
//odd
for (i=0;i<n;i++)
{
  dist_odd[i]=(int*) malloc(n*sizeof(int));
  succ_odd[i]=(int*) malloc(n*sizeof(int));
  if (!dist_odd[i] || !succ_odd[i])
  {
    printf("dist or succ row malloc failed %d\n",__LINE__);
    exit(0);
  }
}
//even
for (i=0;i<n;i++)
{
  dist_even[i]=(int*) malloc(n*sizeof(int));
  succ_even[i]=(int*) malloc(n*sizeof(int));
  if (!dist_even[i] || !succ_even[i])
  {
    printf("dist or succ row malloc failed %d\n",__LINE__);
    exit(0);
  }
}





for (i=0;i<n;i++)
  for (j=0;j<n;j++)
  {
    dist[i][j]=oo;
    succ[i][j]=j;
  }
while (1)
{
  scanf("%d %d %d",&i,&j,&k);
  if (i==(-1))
    break;
  dist[i][j]=k;
}
//Initialise odd matrix
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		dist_odd[i][j] = dist[i][j];
		succ_odd[i][j]=j;
       	}
}
//Initialise even matrix
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		dist_even[i][j] = oo;
	 	succ_even[i][j]=j;
        }
}
}
//-----Print-----Print-----Print-----Print-----Print-----Print-----Print-----Print-----Print-----Print-----Print-----Print-----Print
void printMatrix()
{
int i,k;

printf("    ");
for (i=0;i<n;i++)
  printf("%3d   ",i);
printf("\n");
for (i=0;i<n;i++)
{
  printf("%3d ",i);
  for (k=0;k<n;k++)
    if (dist[i][k]<oo)
      printf("%3d %d ",dist[i][k],succ[i][k]);
    else
      printf(" oo   ");
  printf("\n");
}
printf("\n\n #############odd############\n\n");
printf("    ");
for (i=0;i<n;i++)
  printf("%3d   ",i);
printf("\n");
for (i=0;i<n;i++)
{
  printf("%3d ",i);
  for (k=0;k<n;k++)
    if (dist_odd[i][k]<oo)
      printf("%3d %d ",dist_odd[i][k],succ_odd[i][k]);
    else
      printf(" oo   ");
  printf("\n");
}

printf("\n\n #############even############\n\n");
printf("    ");
for (i=0;i<n;i++)
  printf("%3d   ",i);
printf("\n");
for (i=0;i<n;i++)
{
  printf("%3d ",i);
  for (k=0;k<n;k++)
    if (dist_even[i][k]<oo)
      printf("%3d %d ",dist_even[i][k],succ_even[i][k]);
    else
      printf(" oo   ");
  printf("\n");
}
}
/* Floyd-Warshall *//* Floyd-Warshall *//* Floyd-Warshall *//* Floyd-Warshall *//* Floyd-Warshall *//* Floyd-Warshall *//* Floyd-Warshall */
void floydWarshall()
{
int i,j,k;
int newDist,newDist_odd,newDist_even ;

//
printf("----------------------------------\n");
/* Floyd-Warshall */
for (j=0;j<n;j++)
{
 printf("------------------- %d ---------------\n",j);
  for (i=0;i<n;i++){
    if (dist[i][j]<oo){
      for (k=0;k<n;k++)
      {  
        	if (dist[j][k]<oo)//if1
        	{
          	newDist=dist[i][j]+dist[j][k];
          		//check for main
          		if (newDist<dist[i][k])
         	 	{
            			dist[i][k]=newDist;
            			succ[i][k]=succ[i][j];
          		}
          
          	 	//check for odd
          
          		if(newDist%2 == 1)
          		{
            				if (newDist<dist_odd[i][k])
            				{
            					dist_odd[i][k]=newDist;
            						succ_odd[i][k]=succ[i][j];
            				}
          		}
          		//check for even
          		if(newDist%2 == 0)
          		{
           		 if (newDist<dist_even[i][k])
            			{
            				dist_even[i][k]=newDist;
            					succ_even[i][k]=succ[i][j];
            			}
          		}
        	}//if1
      }//for
    }// if
    
    //
    
   //


  }// i1
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
for (i=0;i<n;i++){
    if (dist_odd[i][j]<oo){
      for (k=0;k<n;k++)
      {  
        	if (dist_odd[j][k]<oo)//if1
        	{
          	newDist=dist_odd[i][j]+dist_even[j][k];
          		//check for main
          		
          
          	 	//check for odd
          
          		if(newDist%2 == 1)
          		{
            				if (newDist<dist_odd[i][k])
            				{
            					dist_odd[i][k]=newDist;
            						succ_odd[i][k]=succ[i][j];
            				}
          		}
          		newDist=dist_odd[i][j]+dist_odd[j][k];
          		//check for main
          		
          
          	 	//check for odd
          
          		if(newDist%2 == 0)
          		{
            				if (newDist<dist_even[i][k])
            				{
            					dist_even[i][k]=newDist;
            						succ_even[i][k]=succ[i][j];
            				}
          		}
          		
        	}//if1
      }//for
    }// if
}//i2

//i333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
for (i=0;i<n;i++){
    if (dist_even[i][j]<oo){
      for (k=0;k<n;k++)
      {  
        	if (dist_even[j][k]<oo)//if1
        	{
          	newDist=dist_even[i][j]+dist_even[j][k];
          		//check for main
          		
          
          	 	//check for odd
          
          		if(newDist%2 == 0)
          		{
            				if (newDist<dist_even[i][k])
            				{
            					dist_even[i][k]=newDist;
            						succ_even[i][k]=succ[i][j];
            				}
          		}

                  newDist=dist_even[i][j]+dist_odd[j][k];
          		//check for main
          		
          
          	 	//check for odd
          
          		if(newDist%2 == 1)
          		{
            				if (newDist<dist_odd[i][k])
            				{
            					dist_odd[i][k]=newDist;
            						succ_odd[i][k]=succ[i][j];
            				}
          		}
 
          		//check for even
          		
        	}//if1
      }//for
    }// if
}//i2
//////////////////////////////////////////////////////////////////////////////////////////////////////

  printMatrix();
  printf("----------------------------------\n");
}// j
}

void printPaths()
{
int i,j,k;

for (i=0;i<n;i++)
  for (j=0;j<n;j++)
    if (dist[i][j]==oo)
      printf("No path from %d to %d\n",i,j);
    else
    {
      printf("Distance %d for %d ",dist[i][j],i);
      for (k=succ[i][j];
           k!=j;
           k=succ[k][j])
        printf("%d ",k);
      printf("%d\n",j);
    }
}

void deallocate()
{
int i;

for (i=0;i<n;i++)
{
  free(dist[i]);
  free(succ[i]);
}
free(dist);
free(succ);

for (i=0;i<n;i++)
{
  free(dist_odd[i]);
  free(succ_odd[i]);
}
free(dist_odd);
free(succ_odd);

for (i=0;i<n;i++)
{
  free(dist_even[i]);
  free(succ_even[i]);
}
free(dist_even);
free(succ_even);


}

int main()
{

readInput();
printMatrix();
floydWarshall();
printPaths();
deallocate();
}

