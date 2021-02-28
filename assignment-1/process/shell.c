#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
 
int main(int argc,char *argv[])
{
 pid_t cpid;
 int max_size =100;
 char cmd[max_size]; //cmd is for command
 int j=0;
 while(j<10)//10 for max it can 10 cmds
 {
 printf("\nEnter command:");
 
 scanf("%s",cmd);
 printf("cmd = %s\n",cmd);
 pid_t ret;
 ret=fork();
 if(ret==0)
 {
 int i;
 i=execlp(cmd,cmd,NULL);
 if(i<0)
 {
 perror("execlp");
 exit(1);
 }
 exit(0);
 }
 else
 if(ret>0)
 {
 int status;
 cpid=waitpid(-1,&status,0);
 printf("\nExit status %d",WEXITSTATUS(status));
 }
 else
 { 
 perror("fork error");
 exit(3);
 }
 j++;
 }
}
