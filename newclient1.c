#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include <string.h>
#include <netdb.h>
int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in server_add;
    struct hostent *server;
    char buffer[255];
    if (argc < 3)
    {
        perror("Enter network id and port number correctly ");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket had been failed ");
        exit(1);
    }
    portno = atoi(argv[2]);
    bzero((char *)&server_add, sizeof(server_add));
    server_add.sin_family = AF_INET;
    server_add.sin_addr.s_addr = inet_addr(argv[1]);
    server_add.sin_port = htons(portno);
    //connect
    if (connect(sockfd, (struct sockaddr *)&server_add, sizeof(server_add)) < 0)
    {
        perror("No connection establish");
        exit(1);
    }
    while (1)
    {
        bzero((char *)buffer, 255);
        fgets(buffer, 255, stdin);
        write(sockfd, buffer, strlen(buffer));
        bzero((char *)buffer, 255);
        read(sockfd, buffer, 255);
        printf("Server :%s ", buffer);
        if (strncmp("bye", buffer, 3) == 0)
            break;
    }
    close(sockfd);
}