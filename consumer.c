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
    printf("%d", numInStorage); 

    if((numInStorage + 8) >= 100) {
        exit(0);
    }else{
        numInStorage += 8;
    }

    //COnvert int to string
    sprintf(buff, "%d", numInStorage);

    

}
