#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    int fd;
    
    if((fd = open("storage", O_RDWR, 0755)) == -1) {
        perror("Error opening file: ");
        exit(0);
    }

    
   

}
