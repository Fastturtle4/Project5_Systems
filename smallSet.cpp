#include<iostream>
#include<string>
#include<vector>
extern "C"{
    #include"csapp.h"
}
//#include"sserver.h"
using namespace std;
struct set{
    unsigned int secretKey;
    unsigned short pKey=0;
    unsigned short pad =0;
    char name[16];
    char value[16];
 };
int main(int argc, char **argv)
{
    set baz;
    int clientfd, port;
    char *host, buf[MAXLINE];
    rio_t rio;
    int sKey = atoi(argv[3]);
    char* name1 = baz.name;
    char* value1 = baz.value;
    if (argc != 6) {
    fprintf(stderr, "incorrect argument!!!s\n!");
	exit(0);
    }
    host = argv[1];
    
    baz.secretKey=sKey;
    strcpy(name1, argv[4]);
    strcpy(value1, argv[5]);
    port = atoi(argv[2]);
    for(int i=0;i<8;i++)
    {
            cout<<baz.name[i];
    }
    cout<<""<<endl;
    clientfd = Open_clientfd(host, port);
    Rio_readinitb(&rio, clientfd);
    send(clientfd, &baz, sizeof(struct set),0);
    Close(clientfd);
    exit(0);
}