/*
    This file is part of the String Manipulation program, it provides test mechanism for the function written
    defined in string_utility.c file

    File main.c
*/

#include "string_utility.h"
#include "utility.h"

int main(int argc, char const *argv[])
{
    const char *input_string;
    input_string = malloc(1024);        //allocate 1Mb of storage area for the command

    while(1){
        input_string = prompt((char *)input_string);    //print the prompt
        command_interpreter(input_string);              //interprete the command typed in
        free(input_string);             //free up the memory where the commanda was stored
    }

}

