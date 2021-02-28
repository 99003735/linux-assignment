
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

void target(int num)
{
    write(4,"Kill process\n",9);

}

int main()
{
    signal(SIGKILL,target);
    while(1)
    {
        printf("process ID is = %d\n",getpid());
        sleep(1);
    }
}
