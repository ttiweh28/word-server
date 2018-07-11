/*
    This file is part of the String Manipulation program, it provides function definitions for all the functions
    declared in client.h file

    File name: client.c
*/


#include "client.h"
#include "utility.h"

/*
    function to print the socket address
    it takes the structure for the socket address and prints information about it ie <ip-address : port> combination
    and the message to describe the nature of the socket address
    it returns nothing
*/
void print_socket_address(SocketAddress socket_address, char *msg){
    NEW_LINE;
	printf(" %s %s:%d",msg,inet_ntoa(socket_address.sin_addr), ntohs(socket_address.sin_port));
    NEW_LINE;
}

/*
    function to prepare / make the socket address of the destintion machine 
    it takes the machine name of the machine to receive the packets '<hostname>', the port number '<port>' on which the 
    destination machine listens and the a pointer to the socket address to be prepared '<dest_socket_addr>'.
    it returns nothing
*/
void prepare_destination_socket_address(SocketAddress *dest_socket_addr, char *hostname, int port){

    struct hostent *host;               //the host's ip addresse

    host = gethostbyname(hostname);     //get the host's ip address from its  DNS name <hostname>

    /* check if the valid host name is supplied otherwise close the program */
    if(host == NULL){
        printf(" %s : %s",UNKNOWN_HOST_NAME, hostname);
        NEW_LINE;
        print_message("Enter the correct host name name", HELP);
        exit(EXIT_FAILURE);
    }

    dest_socket_addr->sin_family = AF_INET;             //set the network domain to IPv4
    dest_socket_addr->sin_addr = *(struct in_addr *)(host->h_addr);
    dest_socket_addr->sin_port = htons(port);           //set the port
}

/*
    function to prepare / make a socket address using any free addresses of the local computer for the local socket on 
    the DEFAULT_PORT
    it takes a pointer to the socket address to be prepared '<local_socket_addr>'
    it returns nothing
*/
void prepare_local_socket_address(SocketAddress *local_socket_addr){

    local_socket_addr->sin_family = AF_INET;                    //set the network domain to IPv4
    local_socket_addr->sin_port = htons(DEFAULT_PORT);          //set the port to the DEFAULT_PORT
    local_socket_addr->sin_addr.s_addr = htonl(INADDR_ANY);     //assign any free addreess of the local machine available
}