//Name: Paul Barrett (pba243)
//      Tirth Patel (tjpa229)



//#include<iostream>
#include<string>
extern "C"{
    #include"csapp.h"
}
//#include"sserver.h"

struct serverStruct{
    unsigned int secretKey;
    unsigned int pKey;
    unsigned int pads;
}
int main(int argc, char* argv[])
{
    int listenfd, connfd, port;
    socklen_t clientlen;
    struct sockaddr_in clientaddr;
    struct hostent *hp;
    char *haddrp;
    if (argc != 3) {
	fprintf(stderr, "usage: ./smalld port secret\n");
	exit(0);
    }
    port = atoi(argv[1]);
    
    listenfd = Open_listenfd(port);
    while(1){
    connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen)
    
    }


}


