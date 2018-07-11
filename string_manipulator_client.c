m/*
    This file is part of the String Manipulation program, it provides functionality of the client program where the user
    interacts with the string manipultor by submitting jobs to the server for processing

    File name: string_manipulator_client.c
*/

#include "client.h"
#include "utility.h"


void client_run(const char **args);

SocketAddress client_soc_addr;                  //the socket address of the client
int snder_length = sizeof(client_soc_addr);     //the size of the client socket address
int client_socket;                              //client's socket file descriptor


int main(int argc, char const *argv[])
{
    /* validate the arguments passed */
    if(argc <= 1){
        NEW_LINE;
        print_message("Usage> name_of_cleint host_name", ERROR);
        exit(EXIT_FAILURE);         //exit the program if the host name is not specifed
    }
    //if the destination / host is provided then run the client
    else if(argc == 2){
        /* do what you want here */
        client_run(argv);
    }
    else {
        NEW_LINE;
        print_message("Usage> name_of_client host_name", ERROR);
        print_message("run the client by putting the name of the server machine as an argument.", HELP);
    }
    
    return 0;
}
/* 
    function for the main client program for the stringManipulator program 
    it takes the args containing the host name of the destination machine
    it returns nothing

*/
void client_run(const char **args){

    /****establish connection */
    if((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        print_message("Could not create client socket.", SOCKET_ERROR);
        close(client_socket);
        exit(EXIT_FAILURE);
    }
    print_message("Client socket created successfully", SUCCESS);

    /* prepare the socket address in structure for the receiver / server */
    memset((char *)&client_soc_addr, 0, sizeof(client_soc_addr));
    prepare_destination_socket_address(&client_soc_addr, (char *)args[1], DEFAULT_PORT);
    print_socket_address(client_soc_addr,"Destination's socket address");

    /* connect to the server */
}
