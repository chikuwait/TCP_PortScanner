#define _GNU_SOURCE
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define START 0
#define END 65535

int
main(int argc, char **argv)
{
    int dstSock = 0, dstConnect = 0;
    struct sockaddr_in dstAddr;

    dstAddr.sin_family = AF_INET;
    dstAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    printf("Starting the portscan \n");

    for(int i = START; i <= END; i++){
        dstAddr.sin_port = htons(i);
        dstSock = socket(AF_INET, SOCK_STREAM, 0);
        if(dstSock < 0){
            fprintf(stderr, "Fail to create Socket\n");
            return -1;
        }
        dstConnect = connect(dstSock, (struct sockaddr*)&dstAddr, sizeof(dstAddr));
        if(dstConnect != -1){
            printf("%d : Open\n",i);
        }
        close(dstSock);
    }
    return 0;
}
