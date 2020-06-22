#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<time.h>
#include<unistd.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
    time_t clock;
    char dataSending[1025];
    int clintListn = 0,clintConnt = 0;
    struct sockaddr_in ipOfServer;
    clintListn = socket(AF_INET,SOCK_STREAM,0);
    memset(&ipOfServer,'0',sizeof(ipOfServer));
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
    ipOfServer.sin_port = htons(2017);
    bind(clintListn,(struct sockaddr*)&ipOfServer,sizeof(ipOfServer));
    listen(clintListn,20);
    while(1){
        printf("\n\nHi,I am running server. Some Client hit me\n");
        clintConnt = accept(clintListn,(struct sockaddr*)NULL,NULL);
        clock = time(NULL);
        snprintf(dataSending,sizeof(dataSending),"%.24s\r\n",ctime(&clock));
        write(clintConnt,dataSending,strlen(dataSending));
        close(clintConnt);
        sleep(1);
    }
    return 0;
}