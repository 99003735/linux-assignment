
#include<unistd.h>
#include<stdio.h>
int main()
{
 pid_t ret;
 char p[100],q[100];
 printf("enter for compilation\n");
 gets(p);
  printf("enter for compilation\n");
 gets(q);
 ret=fork();
  if(ret==0)
    {

 execlp(p,NULL);

    }
    else
    {
    int ret1=fork();
    if(ret1==0)
    {
    execlp(q,NULL);
    }
    else
    {
    }
    }
    printf("Thank you\n");
    }
    
    
    
