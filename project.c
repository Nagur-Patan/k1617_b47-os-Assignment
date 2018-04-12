#include<stdio.h> 
#include<conio.h>
int main() 
{ 
  int i,j,n,time,left,flag=0,TQ; 
  int wt=0,TAT=0,at[10],bt[10],rt[10]; 
  printf("                                             ROUND ROBIN ALGORITHM \n");
  printf("                                             _____________________ \n");
  printf("Enter Number of Processes:\t"); 
  scanf("%d",&n); 
  left=n;  
  i=0;
  while(i<n)
  { 
    printf("\nPlease Enter Arrival & Burst time :",i+1);  
    scanf("%d",&at[i]); 
    scanf("%d",&bt[i]); 
    rt[i]=bt[i]; 
    i++;
  } 
  printf("Please Enter The Time Quantum:\t"); 
  scanf("%d",&TQ); 
  printf("-------------------------------------\n");
  printf("Process\t|Turnaround Time|Waiting Time\n"); 
  printf("--------|---------------|------------\n");
  for(time=0,i=0;left!=0;) 
  { 
    if(rt[i]<=TQ && rt[i]>0) 
    { 
      time+=rt[i]; 
      rt[i]=0; 
      flag=1; 
    } 
    else if(rt[i]>0) 
    { 
      rt[i]-=TQ; 
      time+=TQ; 
    } 
    if(rt[i]==0 && flag==1) 
    { 
      left--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-at[i],time-at[i]-bt[i]); 
      wt+=time-at[i]-bt[i]; 
      TAT+=time-at[i]; 
      flag=0; 
    } 
    if(i==n-1) 
      i=0; 
    else if(at[i+1]<=time) 
      i++; 
    else 
      i=0; 
  }
  printf("-------------------------------------\n"); 
  printf("\nAvg Waiting Time= %f\n",wt*1.0/n); 
  printf("Avg Turnaround Time = %f",TAT*1.0/n); 
  return 0; 
}
