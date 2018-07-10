/*
    This file is part of the String Manipulation program, it provides function prototypes for all the functions
    defined in client.c file

    File name: client.h
*/

#ifndef CLIENT_H_
#define CLIENT_H_

include <stdio.h>
#include <string.h>
#include <stdlib>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SOCKET_ERROR "SOCKET ERROR "                //macro for socket error
#define CONNECTION_CLOSED "CONNECTION CLOSED "      //macro for closing the connection between the server and the client
#define UNKNOWN_HOST_NAME "UNKNOWN HOST "           //macro for unknown host name

#define DEFAULT_BUFFER_SIZE 1024                //the default buffer size in bytes
#define DEFAULT_PORT    5150                    //the default port onto which the two processes i.e. client and server listen
typedef struct sockaddr_in SocketAddress;       //structure to represent socket address structure

/*********************************Function prototypes****************************/

/*
    function to print the socket address
    it takes the structure for the socket address and prints information about it ie <ip-address : port> combination
    it returns nothing
*/
void print_socket_address(SocketAddress socket_address);

/*
    function to prepare / make the socket address of the destintion machine 
    it takes the machine name of the machine to receive the packets '<hostname>', the port number '<port>' on which the 
    destination machine listens and the a pointer to the socket address to be prepared '<dest_socket_addr>'.
    it returns nothing
*/
void prepare_destination_socket_address(SocketAddress *dest_socket_addr, char *hostname, int port);

/*
    function to prepare / make a socket address using any free addresses of the local computer for the local socket on 
    the DEFAULT_PORT
    it takes a pointer to the socket address to be prepared '<local_socket_addr>'
    it returns nothing
*/
void prepare_local_socket_address(SocketAddress *local_socket_addr);

/* ################################################ */
typedef struct Job{
    char *data;
    char *type;
    int msg_ID;
    char *user_ID;

}Job;


void write_to_file(Job *mesage, FILE *file);
void read_from_file();
void print_error(char *error_msg);
void send();
void receive();
void dispatch();
void getdata(Job *job);

#endif