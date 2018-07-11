/*
    This file is part of the String Manipulation program, it provides function prototypes for all the functions
    defined in utility.c file

    File name: utility.h
*/

#ifndef UTILITY_H_
#define UTILITY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/*  #####################################################################################################################
                                                    MACROS
    ######################################################################################################################
*/
#define NEW_LINE {printf("\n");}                //new line macro

#define UNKNOWN_COMMAND "UNKNOWN COMMAND "     //unknown command macro
#define WRONG_ARGUMENTS "WRONG ARGUMENTS "      //wrong arguments macro
#define FEW_ARGUMENTS "FEW ARGUMENTS "          //few arguments macro
#define MESSAGE "MESSAGE "                      //message macro
#define RESULT "RESULT "                        //the result macro
#define HELP "HELP "                            //the help macro
#define ERROR "ERROR "                          //the general error macro

/*
    ######################################################################################################################
                                                    FUNCTION PROTOTYPES
    ######################################################################################################################
*/


/* 	function to interprete the commands typed at the terminal
    it takes the a pointer to the constant character string to be interpreted
    it ruturns nothing
*/
void command_interpreter(const char *command);

/* 	function to print a message at the terminal
    it takes a pointer to the character string to be printed to the screen and the type of the message
    it ruturns nothing
*/
void print_message(char *message, char *msg_type);

/* 	function to print error message on the terminal 
    it takes a pointer to the character string to be printed to the terminal
    and a pointer to the character string having the error type 'error_type'
    it ruturns nothing
*/
void print_error(char *error_msg, char *error_type);

/* 
    function to print the prompt and capture the command from the terminal
    it takes as input a buffer where the command is stored
    it returns the buffer to which the command is written
*/
const char *prompt(char buffer[]);

/*
    Function to print the help menu for the list of permitted commands in the string manipulation program
    it takes nothing
    it returns nothing
*/
void print_help_menu(void);


/*
    Function to check if the entered string is a number, it looks at each character in the string entered, when it encounters a 
    character that is not a number, it returns 0 (false)
    it takes a string 'str' to be checked if it is a number
    it returns 1 if all the characters in the string are numbers or 0 (false) if at least one of the characters in the string 
    is not a number
*/
int is_anumber(char str[]);


/*
	function to swap two integers
	it takes two pointers to integers and interchanges them i.e 'from' is set 'to' and 'to' is set to 'from'
*/
void swap(int *from, int *to);

/*
	function to sort an array of integers in ascending order (bubble sort)
	it takes an array of integers before sorting
	it returns the array after sorting in ascending order
*/
int *sort_positions(int positions_array[], int size_);

void debug(void);   //to be removed

#endif