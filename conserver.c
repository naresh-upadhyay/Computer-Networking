#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
//server code
int main()
{
    int portno;
    printf("Enter child server port no.");
    scanf("%d", &portno);
    int portno1;
    printf("Enter parent server port no.");
    scanf("%d", &portno1);
    int pid = fork();
    if (pid == 0)
    {
        int sockfd, n;
        struct sockaddr_in server_add, client_add;
        socklen_t clilen;
        char buffer[255];
        //socket

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
            perror("Error in socket file descripter");
        }

        bzero((char *)&server_add, sizeof(server_add));
        server_add.sin_family = AF_INET;
        server_add.sin_addr.s_addr = INADDR_ANY;
        server_add.sin_port = htons(portno);
        //bind
        if (bind(sockfd, (struct sockaddr *)&server_add, sizeof(server_add)) < 0)
        {
            perror("Not bind");
        }
        listen(sockfd, 10);
        clilen = sizeof(client_add);

        int newsockfd = accept(sockfd, (struct sockaddr *)&client_add, &clilen);
        if (newsockfd < 0)
            perror("Accepting client error");
        while (1)
        {
            bzero(buffer, 255);
            read(newsockfd, buffer, sizeof(buffer));
            printf("Client child: %s\n", buffer);
            //bzero(buffer, 255);
            //fgets(buffer, 255, stdin);
            //write(newsockfd, buffer, sizeof(buffer));
            //if (strncmp("bye", buffer, 3) == 0)
            //  break;
        }
        close(sockfd);
        close(newsockfd);
    }
    else
    {
        int sockfd, n;
        struct sockaddr_in server_add, client_add;
        socklen_t clilen;
        char buffer[255];
        //socket

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
            perror("Error in socket file descripter");
        }

        bzero((char *)&server_add, sizeof(server_add));
        server_add.sin_family = AF_INET;
        server_add.sin_addr.s_addr = INADDR_ANY;
        server_add.sin_port = htons(portno1);
        //bind
        if (bind(sockfd, (struct sockaddr *)&server_add, sizeof(server_add)) < 0)
        {
            perror("Not bind");
        }
        listen(sockfd, 10);
        clilen = sizeof(client_add);

        int newsockfd = accept(sockfd, (struct sockaddr *)&client_add, &clilen);
        if (newsockfd < 0)
            perror("Accepting client error");
        while (1)
        {
            bzero(buffer, 255);
            read(newsockfd, buffer, sizeof(buffer));
            printf("Client parent : %s\n", buffer);
            /*bzero(buffer, 255);
            fgets(buffer, 255, stdin);
            write(newsockfd, buffer, sizeof(buffer));
            if (strncmp("bye", buffer, 3) == 0)
                break;*/
        }
        close(sockfd);
        close(newsockfd);
    }
}