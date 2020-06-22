#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>
//server code
int main(int argc , char *argv[]){
    int sockfd,portno,n;
    struct sockaddr_in server_add,client_add;
    socklen_t clilen;
    char buffer[255];
    if(argc < 2){
        perror("Enter port number too");
        exit(1);
    }
    //socket
    sockfd = socket(AF_INET, SOCK_STREAM , 0);
    if(sockfd < 0){
        perror("Error in socket file descripter");
    }
    portno = atoi(argv[1]);

    bzero((char *)&server_add,sizeof(server_add));
    server_add.sin_family = AF_INET;
    server_add.sin_addr.s_addr = INADDR_ANY;
    server_add.sin_port = htons(portno);
    //bind
    if(bind(sockfd,(struct sockaddr *) &server_add,sizeof(server_add))<0){
        perror("Not bind");
    } 
    listen(sockfd,10);
    clilen = sizeof(client_add);
    int newsockfd = accept(sockfd,(struct sockaddr *)&client_add ,&clilen);
    if(newsockfd < 0 )
        perror("Accepting client error");
    while(1){
        bzero(buffer,255);
        read(newsockfd,buffer,sizeof(buffer));
        printf("Client : %s\n",buffer);
        bzero(buffer,255);
        fgets(buffer,255,stdin);
        write(newsockfd,buffer,sizeof(buffer));
        if(strncmp("bye",buffer,3) == 0)break;
    }
    close(sockfd);
    close(newsockfd);
}