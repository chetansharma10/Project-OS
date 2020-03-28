#include<stdio.h>
int processes[100][4],NP,scheduler[1000],arrivedProcesses[100],NAP=0;
unsigned int time=0;
int waitList[100];
void getSystem()
{
	printf("\nEnter Number Of Processes:" );
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
		printf("\nTAT P(%d)=%d",i+1,waitList[i]+processes[i][1s]);
		
		sum=sum+waitList[i]+processes[i][1];

	}
	ATAT=sum/(float)NP;
	printf("\nAverage Turn Arround Time=%f",ATAT);


}

int main()
{
getSystem();
printSystem();
schedule();
printScheduler();
waitingTime();
printWaitingTime();
printTurn();
}