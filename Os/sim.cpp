#include<iostream>
using namespace std;
void swap(int *a, int *b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}


int main() 
{
   int num; 
   cout<<"Enter number of processes: "; cin>>num;
   int p[6][num];

   // dymanic input
   cout<<"Enter details of each p: "<<endl;
   for(int i = 0; i<num;i++)
   {
      cout<<"Enter burst time for p "<<i+1<<" :"; cin>>p[1][i];
      cout<<"Enter arrival time for p "<<i+1<<" :"; cin>>p[2][i];
      p[0][i] = i+1;
   }

  

   cout<<"p Id\tBurst Time\tArrival Time "<<endl;
   for(int i = 0; i<num; i++)
   {
      cout<<p[0][i]<<"\t\t"<<p[1][i]<<"\t\t"<<p[2][i]<<endl;
   }

   //sorting of processes on the basis of arrival time nad burst time
   
   for(int i = 0;i<num;i++)  // i is row
   {
      for(int j = 0;j<num;j++) // j is column
      {
         if(p[2][j]>p[2][j+1])          // sort on basis of arrival time
         {
           int swap = p[i][j];   
           p[i][j] = p[i][j+1];
           p[i][j+1] = swap;
         }
      }
   }
   for(int i = 0;i<num;i++)  // i is row
   {
      for(int j = 0;j<num;j++) // j is column
      {
         if(p[2][j]==p[2][j+1])          // sort on basis of burst time if arrival time is same
         {
           int swap = p[i][j];   
           p[i][j] = p[i][j+1];
           p[i][j+1] = swap;
         }
      }
   }
   cout<<"After sorting"<<endl;
   cout<<"Process_Id\tBurst Time\tArrival Time "<<endl;
   for(int i = 0; i<num; i++)
   {
      cout<<p[0][i]<<"\t\t"<<p[1][i]<<"\t\t"<<p[2][i]<<endl;
   }



   // calculating waiting and turnaround time

   int temp, val;
   p[3][0] = p[2][0] + p[1][0]; // completion time
   p[5][0] = p[3][0] - p[2][0]; // turnaround time
   p[4][0] = p[5][0] - p[1][0]; // burst time
   for(int i = 1; i < num;i++)
   {
      temp = p[3][i-1];
      int low = p[1][i];
      for(int j = i; j <num;j++)
      {
         if(temp>=p[2][j] && low >= p[1][j])
         {
            low = p[1][j];
            val = j;
         }
      }
      p[3][val] = temp + p[1][val]; // completion time
      p[5][val] = p[3][val] - p[2][val]; // turnaround time
      p[4][val] = p[5][val] - p[1][val]; // burst time

      for(int k = 0;k<6;k++)
      {
         swap(p[k][val],p[k][i]);
      }
   }
   cout<<"Calculation of waiting and turnaround time: "<<endl;
   cout<<"Process_Id\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time"<<endl;
   for(int i = 0; i<num; i++)
   {
      cout<<p[0][i]<<"\t\t"<<p[1][i]<<"\t\t"<<p[2][i]<<"\t\t"<<p[4][i]<<"\t\t"<<p[5][i]<<endl;
   }

   // calculating priority
   double priority[num] = {0.0};
   cout<<"priority of process "<<p[0][0]<<" is: "<<priority[0]<<endl;
   for(int i = 1;i<num;i++)
   {
      float a = (float)p[4][i]/(float)p[5][i];
      priority[i] = 1+a;
      cout<<"priority of process "<<p[0][i]<<" is: "<<priority[i]<<endl;
   }
   cout<<"Process_Id\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\t\tPriority"<<endl;
   for(int i = 0; i<num; i++)
   {
      cout<<p[0][i]<<"\t\t"<<p[1][i]<<"\t\t"<<p[2][i]<<"\t\t"<<p[4][i]<<"\t\t"<<p[5][i]<<"\t\t\t"<<priority[i]<<endl;
   }


   cout<<"\n\n";
   // gantt chart
   int start = p[2][0];
   int end = p[3][num-1];
   int total_time = 0;
   cout<<" Gantt Chart \n";
   cout<<"|";
   for (int i = 0; i < num; i++) 
   {
      for (int j = 0; j < p[1][i]; j++) 
      {
         cout<<" P"<<p[0][i];  
      }
      cout<<" |";
   }
   cout<<endl;
   for(int i = start;i<=end;i++)
   {
      cout<<""<<i<<"  ";
   }
   
    

}

