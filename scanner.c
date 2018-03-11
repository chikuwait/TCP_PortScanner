#define _GNU_SOURCE
#include <arpa/inet.h>
#include <ctype.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define START 0
#define END 65535

int set_addr(struct sockaddr_in *dstAddr, char **addr) {
  struct hostent *host;
  char *IPBuffer;

  if (*(addr + 1) == '\0') {
    fprintf(stderr, "Error:Please specify the address as an argument\n");
    return 0;
  }
  dstAddr->sin_family = AF_INET;

  if (isdigit(*(*(addr + 1)))) {
    dstAddr->sin_addr.s_addr = inet_addr(*(addr + 1));
  } else if ((host = gethostbyname(*(addr + 1))) != 0) {
    IPBuffer = inet_ntoa(*((struct in_addr *)host->h_addr_list[0]));
    printf("Host resolved to IP: %s\n", IPBuffer);
    dstAddr->sin_addr.s_addr = inet_addr(IPBuffer);
  } else {
    herror(*(addr + 1));
    return 0;
  }
  return 1;
}

int server_connect(struct sockaddr_in *dstAddr, int port) {
  int dstSock = socket(AF_INET, SOCK_STREAM, 0);
  dstAddr->sin_port = htons(port);

  if (dstSock < 0) {
    fprintf(stderr, "Eroor:Fail to create Socket\n");
    return 0;
  }
  if (connect(dstSock, (struct sockaddr *)dstAddr, sizeof(*dstAddr)) != -1) {
    close(dstSock);
    return 1;
  }

  close(dstSock);
  return 0;
}

int main(int argc, char **argv) {
  struct sockaddr_in dstAddr;

  if (!set_addr(&dstAddr, argv))
    return -1;

  printf("Starting the portscan \n");
  for (int i = START; i <= END; i++) {
    if (server_connect(&dstAddr, i))
      printf("%d : Open\n", i);
  }
  return 0;
}
