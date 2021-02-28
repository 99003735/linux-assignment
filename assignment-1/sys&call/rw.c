
#include <fcntl.h> 

int main() 
{ 
 int file_1,file_2 ; 
 char c[50];

 //char *c = (char *) calloc(50, sizeof(char)); 
 
 file_1 = open("file.txt", O_RDONLY); 

 if (file_1 < 0) 
 { 
 perror("ERROR :"); 
 exit(1); 
 }
 
 file_2 = read(file_1, c, 50); 

 c[file_2] = '\0'; 

printf(" Date Copied: % s\n", c); 
 
 int fd1 = open("New.txt", O_WRONLY | O_CREAT | O_TRUNC); 
 printf("Created file \n");

 write(fd1,c,strlen(c));

 printf("written data \n");
 
 //close(file_1);
}      

