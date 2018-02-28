#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int fd;
    char buff[5];

    //OPen the storage file
    if((fd = open("storage", O_RDWR, 0755)) == -1) {
        perror("Error opening file: ");
        exit(0);
    }

    //Read the storage file
    if(read(fd, buff, sizeof buff) == -1) {
        perror("Error reading file: ");
        exit(0);   
    };

    int numInStorage = atoi(buff);

    numInStorage -= 3;

    //COnvert int to string
    sprintf(buff, "%d", numInStorage);

    //Seek to beginning of file and write new number
    lseek(fd, 0, SEEK_SET);
    if((write(fd, buff, sizeof buff)) < sizeof buff) {
        perror("Error writing to file: ");
        exit(0);   
    }else{
        printf("from consumer: current total is %d\n", numInStorage); 
        fflush();
        execl("./producer","producer", (char *)0); 
    }

}
















