#include<stdio.h>
int processes[1000][4],NP,scheduler[1000],arrivedProcesses[1000],NAP=0;
unsigned int time=0;
int waitList[1000];
int time_quantum;


void CallSRTF(){

void getSystem()
{
	printf("\nEnter Total Number Of Processes:" );
	scanf("%d",&NP);

	for (int i = 0; i < NP; ++i)
	{
		
		printf("\nArrival Time of P%d:",i+1);
		scanf("%d",&processes[i][0]);
		printf("\nBurst Time of P%d:",i+1);
		scanf("%d",&processes[i][1]);
		processes[i][2]=processes[i][1];
		printf("\n");

	}
}

void printSystem()
{
	printf("\nOur System has Following data:");
	printf("\nProcesses \t AT \t BT \t RT");
	printf("\n");
	for (int i = 0; i < NP; ++i)
	{
		
		printf("P%d \t\t %d \t %d \t %d",i+1,processes[i][0],processes[i][1],processes[i][2]);
		printf("\n");
	}
}


int remainTime()
{
	for (int i = 0; i < NP; i++)
	{
		
		if(processes[i][2]>0)
		{
			return 1;
		}
	
	}
		return 0;
}


void addArrivedProcesses()
{
	for (int i = 0; i < NP; i++)
	{
		
		if(processes[i][0]==time)
		{   
			arrivedProcesses[NAP]=i;
			NAP++;
		}
	}
}

void printArrivedProcesses()
{
	printf("\n\nArrived Processes are %d :",NAP);
	for (int i = 0; i < NAP; ++i)
	{

		printf("%d",arrivedProcesses[i]+1);
	}
}

 
int getSRT()
{
	if(NAP==0)
	{
		return -1;
	}
	
		unsigned int smallestRTP,smallestRTPIndex;
		smallestRTPIndex=arrivedProcesses[0];
		smallestRTP=processes[arrivedProcesses[0]][2];
		for (int i = 0; i < NAP; i++)
		{
			/* code */
			if(processes[  arrivedProcesses[i]  ] [2]<smallestRTP )
			{
				smallestRTP=processes[arrivedProcesses[i]][2];
				smallestRTPIndex=arrivedProcesses[i];

			}

		}
		return smallestRTPIndex;

}


void removeFromArrivedProcesses(int toRun)
{
	int temp[100];
	int x=0;
	for (int i = 0; i <NAP; i++)
	{
		
		if (arrivedProcesses[i]!=toRun)
		{
		   temp[x]=arrivedProcesses[i];
		   x++;
		}

	}

	NAP=NAP-1;
	for (int i = 0; i < NAP; i++)
	{
		arrivedProcesses[i]=temp[i];
	}

}

void schedule()
{
	int x;
	int toRun;

	while(remainTime())
	{   
		addArrivedProcesses();
		printArrivedProcesses();
		toRun=getSRT();
		scheduler[time]=toRun;
        processes[toRun][2]=processes[toRun][2]-1;
		if(processes[toRun][2]==0)
		{
			removeFromArrivedProcesses(toRun);

		}

		else if(toRun==-1)
		{
			printf("\nRun-IDLE,TIME=%d",time);
		}
            
		else
		{  
            

			printf("\nRun-P%d,TIME=%d",toRun+1,time);

		}
		printSystem();
        time=time+1;
 

	
	}

}

void printScheduler()
{
	printf("\n\nScheduler:\n");
	for (int t = 0; t < time; t++)
	{


		if(scheduler[t]==-1)
		{
			printf("\n[%d,%d],IDLE",t,t+1);
		}
		else{
			printf("\n[%d,%d],P%d",t,t+1,scheduler[t]+1);
		}
	}
}


void waitingTime()
{

	unsigned int releaseTime,t;
	for (unsigned int i = 0; i < NP; i++)
	{
		
		for (t = time-1; scheduler[t]!=i;t--);
			releaseTime=t+1;
			processes[i][3]=releaseTime-processes[i][0]-processes[i][1];
	}
}

void printWaitingTime()
{


	int waitingTimeSum=0;
	float AWT;
	printf("\nWaiting Time for each Process:\n");
	for (unsigned int i = 0; i < NP; i++)
	{
		
		printf("\nWT(P%d) =%d",i+1,processes[i][3]);
		waitingTimeSum=waitingTimeSum+processes[i][3];
        waitList[i]=processes[i][3];
       
	}
	AWT=waitingTimeSum/(float)NP;
	printf("\nAverage Waiting Time=%f",AWT);
}

void printTurn()
{
    int sum=0;
    float ATAT;
	for (int i = 0; i < NP; ++i)
	{
		printf("\nTAT P(%d)=%d",i+1,waitList[i]+processes[i][1]);
		
		sum=sum+waitList[i]+processes[i][1];

	}
	ATAT=sum/(float)NP;
	printf("\nAverage Turn Arround Time=%f",ATAT);


}


getSystem();
printSystem();
schedule();
printScheduler();
waitingTime();
printWaitingTime();
printTurn();


}




void CallRR()
{

 int i, limit, total = 0, x, counter = 0,j; 
      
	  int wait_time = 0, turnaround_time = 0,pos,z,p[10],prio[10], a_time[10], b_time[10], temp[10],b; 
      
	  float average_wait_time, average_turnaround_time;
      
	  printf("\nEnter Total Number of Processes:"); 
      
	  scanf("%d", &limit); 
      
	  x = limit; 
      for(i = 0; i < limit; i++) 
      {
	    p[i]=i+1;
	   
	    prio[i]=0;
            printf("\nEnter total Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &a_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &b_time[i]); 
            temp[i] = b_time[i];
      }
	    
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\t Priority\n");
      for(total = 0, i = 0; x != 0;) 
      { 

		    for(z=0;z<limit;z++)
		    {
			int temp1;
			pos=z;
			for(j=z+1;j<limit;j++)
			{
			    if(prio[j]<prio[pos])
				pos=j;
			}
		 
		temp1=prio[z];
	
		prio[z]=prio[pos];
	
		prio[pos]=temp1;
		 
			temp1=b_time[z];
			b_time[z]=b_time[pos];
			b_time[pos]=temp1;
		 			temp1=a_time[z];
				a_time[z]=a_time[pos];
			a_time[pos]=temp1;

			temp1=p[z];
				p[z]=p[pos];
			p[pos]=temp1;

			temp1=temp[z];
				temp[z]=temp[pos];
			temp[pos]=temp1;
		    }
		{
		}
            
			if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            
			else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 

	for(b=0;b<limit;b++)
		{
			if(b==i)
			prio[b]+=1;
			else
			prio[b]+=2;
		}

            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\t\t%d", p[i], b_time[i], total - a_time[i], total - a_time[i] - b_time[i],prio[i]);
                  wait_time = wait_time + total - a_time[i] - b_time[i]; 
                  turnaround_time = turnaround_time + total - a_time[i]; 
                  counter = 0; 
            } 
            if(i == limit - 1) 
            {
                  i = 0; 
            
			}
            else if(a_time[i + 1] <= total) 
            {
                  i++;
            
			}
            else 
            {
                  i = 0;
            
			}		
      } 
      


















}
int main()
{

printf("\nEnter Time Quantum:");
scanf("%d",&time_quantum);
if(time_quantum>1)
{
	CallRR();
}
else{
    CallSRTF();
}

}




























































