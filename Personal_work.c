//-----------------------------------------------------------------//
/*
 * This Program is to print the details of the work per day wise and
 * the expenditure cost used for the day in the file


Author : Subbaram1993


//----------------------------------------------------------------//
//			REVISION HISTORY					  //
//----------------------------------------------------------------//
// 25-06-2022  - Added the Initial Code changes for the Work details
// 		 stored into a file entered by the user.
//----------------------------------------------------------------//


*/

// Program begind from here//
// ----------------------------------------------------------------//

#include<stdio.h>
#include<stdlib.h>

struct Work{
  char work_name[25];
  int no_of_workers;
  float expenditure_cost;
  float workers_cost;
}*c[5];

int main()
{
  int i,j,k,n;
  static float a = 0.0;
  float Total =0.0,Total_workers_cost,Total_expenditure_cost,Total_Cost;
  struct Work *c[5];
  FILE *fp;
  fp = fopen("work.txt","a+");
  printf("\nEnter Total Number of Days:.\n");
  scanf("%d",&n);
  if(fp == NULL)
  {
    printf("\nMemory is FULL\n");
    fclose(fp);
    return 0;
  }
  else
  {
    for(i=0;i<n;i++)
    {
      fprintf(fp,"Day :%d",i+1);
      c[i] = (struct Work*)malloc(sizeof(struct Work));
      printf("\nEnter Name of Work :\n");
      scanf("%s",c[i]->work_name);
      printf("\nEnter Number of Workers :\n");
      scanf("%d",&c[i]->no_of_workers);
      printf("\nEnter Day : %d expenditure cost: \n ",i+1);
      scanf("%f",&c[i]->expenditure_cost);
      printf("\nEnter the worker's daily wage:\n");
      scanf("%f",&c[i]->workers_cost);
    }
  }
  //Printing the data into the file
  for(i=0;i<n;i++)
  {
    fprintf(fp,"\n-------------------------------------------------------\n");
    fprintf(fp,"\n\tDay:  %d  \n\t",i+1);
    fprintf(fp,"\n-------------------------------------------------------\n");
    fprintf(fp,"\nName of Work: %s\n",c[i]->work_name);
    fprintf(fp,"\nName of Workers: %d\n",c[i]->no_of_workers);
    fprintf(fp,"\nToday's Expenditure cost: %f\n",c[i]->expenditure_cost);
    fprintf(fp,"\nToday's Worker's Wages: %f\n",c[i]->workers_cost);
    Total_workers_cost = c[i]->no_of_workers*c[i]->workers_cost;
    fprintf(fp,"\nTotal Worker's cost for Day- %d is %f",i+1,Total_workers_cost );
    Total_expenditure_cost = c[i]->expenditure_cost + Total_workers_cost;
    fprintf(fp,"\nTotal Day -%d Expenditure is : %f\n",i+1,Total_expenditure_cost);
    Total_Cost = Total_workers_cost + Total_expenditure_cost;
    a = a + Total_Cost;
    printf("\nTotal_Cost=%f", Total_Cost);
    printf("WC = %f, Ex.Cost :%f\n",Total_workers_cost, Total_expenditure_cost);
    fprintf(fp,"Total Expenditure is : %f\n",Total_Cost);
    fprintf(fp,"\n-------------------------------------------------------\n");
  }
  fprintf(fp,"\n-------------------------------------------------------\n");
  fprintf(fp,"Total Expenditure is : %f\n",a);
  printf("Total Expenditure is : %f\n",a);
  fprintf(fp,"\n-------------------------------------------------------\n");
  fclose(fp);
  return 0;
}
