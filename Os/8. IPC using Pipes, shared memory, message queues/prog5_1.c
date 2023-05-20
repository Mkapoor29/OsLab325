#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#define MAX_TEST 512;
struct myMsg
{
	long int msg_type;
	char text[MAX_TEST];

};
int main()
{
	int running=1;
	int msgid;
	struct myMsg data;
	char buffer[50];
	msgid = msgget((key_t)14534,0666|IPC_CREAT);
	if(msgid==-1)
	{
		printf("error in creating queue\n");
		exit(0);
	}
	while(running)
	{
		printf("enter some text: \n");
		fgets(buffer,50,stdin);
		data.msg_type = 1;
		strcpy(data.text,buffer);
		if(msgsnd(msgid,(void *)&data, MAX_TEST,0)==-1)
		{
			printf("Msg not sent\n");
		}
		if(strncmp(buffer,"end",3)==0)
		{
			running=0;
		}
	}
}
		
