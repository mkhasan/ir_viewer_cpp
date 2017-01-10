//
// Created by usrc on 17. 1. 10.
//

//
// Created by usrc on 17. 1. 10.
//

//
// Created by usrc on 17. 1. 10.
//

//
// Created by usrc on 17. 1. 10.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include "ir_viewer.h"




#define BUFSIZE 1024

/*
 * error - wrapper for perror
 */
void error(char *msg) {
    LOGE(1, "%s", msg);

}

int jni_ir_viewer_init(JNIEnv *env, jobject thiz) {

    int ret = 40;
    LOGE(1, "%d", ret);
    return ret;
}

int jni_ir_viewer_init1(JNIEnv *env, jobject thiz) {


    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char *hostname;
    char buf[BUFSIZE];
    char msg[100];

    hostname = "192.168.0.100";
    portno = 2004;


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
        return -1;
    }


    server = gethostbyname(hostname);
    if (server == NULL) {
        sprintf(msg,"ERROR, no such host as %s\n", hostname);
        error(msg);
        return -1;
    }

    // build the server's Internet address
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    // connect: create a connection with the server
    if (connect(sockfd, &serveraddr, sizeof(serveraddr)) < 0) {
        error("ERROR connecting");
        return -1;
    }

    // get message line from the user
    printf("Please enter msg: ");
    bzero(buf, BUFSIZE);
    strcpy(buf, "login admin admin");
    //fgets(buf, BUFSIZE, stdin);

    // send the message line to the server
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        error("ERROR writing to socket");
        return -1;
    }

    // print the server's reply
    bzero(buf, BUFSIZE);
    n = read(sockfd, buf, BUFSIZE);
    if (n < 0) {
        error("ERROR reading from socket");
        return -1;
    }
    sprintf(msg, "Echo from server: %s length of reply: %d \n", buf, n);

    LOGE(1, "%s", msg);
    close(sockfd);


    return 0;
}
