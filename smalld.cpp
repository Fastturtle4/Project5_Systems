//Name: Paul Barrett (pba243)
//      Tirth Patel (tjpa229)



#include<iostream>
#include<string>
#include<vector>
extern "C"{
    #include"csapp.h"
}
//#include"sserver.h"
using namespace std;
struct serverStruct{
    unsigned int secretKey;
    unsigned int pKey;
    unsigned int pads;
    char n[16];
    char v[16];
};
int main(int argc, char* argv[])
{
    
    char data[100];
    int valread;
    int listenfd, connfd, port;
    int clientlen;
    struct sockaddr_in clientaddr;
    struct hostent *hp;
    char *haddrp;
    serverStruct  bot;
    if (argc != 3) {
	    fprintf(stderr, "usage: ./smalld port secret\n");
	    exit(0);
    }
   
    port = atoi(argv[1]);
    int key = atoi(argv[2]);
    //cout<<key<<endl;
    listenfd = Open_listenfd(port);
    connfd = Accept(listenfd, (SA *)&clientaddr, (socklen_t*) &clientlen);
    read(connfd, &bot, 8);
    
    //cout<<bot.secretKey<<endl;
    if(key==bot.secretKey){
        read(connfd, bot.n, 16);
        read(connfd, bot.v, 16);
         if(key==bot.secretKey)
        {
            cout<<"Theyre equal!"<<endl;
        }
        char name[16];
        for(int i=0;i<sizeof(bot.n);i++)
        {
      
            cout<<bot.n[i];
        }

        cout<<""<<endl;
        for(int i=0;i<sizeof(bot.v);i++)
        {
            cout<<bot.v[i];
        }
        cout<<""<<endl;
        cout<<"The server key is: " <<key<<endl;
        cout<<"The client key is: "<<bot.secretKey<<endl;
        cout<<"-------------------------------"<<endl;
       
    }
    else{
        cout<<"Secret Key = "<<bot.secretKey<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"FAILED"<<endl;
    }
  Close(connfd);

   
   return 0;
   
   

    
}


