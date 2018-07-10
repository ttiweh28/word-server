
/*
    This file is part of the String Manipulation program, it provides function prototypes for all the functions
    defined in string_utility.c file

    File name: string_utility.h
*/

#ifndef STRING_UTILITY_H_
#define STRING_UTILITY_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/*
    ######################################################################################################################
                                                    FUNCTION PROTOTYPES
    ######################################################################################################################
*/

/* 	function to reverse the string 
	it returns NULL if the string 'str' is empty or NULL is passed to it or the string 'str' in the reverse order
*/
char *reverse_string(char *str);

/* 	function to remove a specified character from the string 
    it takes the pointer to a character string and the position where athe character is to be removed
	returns the string 'str' without the character at 'position' and or NULL when pos > length of str
*/
char *remove_character(char *str, int position);

/* 	function to remove a series of characters specified in the positions array 'positions[]' 
    it takes the pointer to a character string 'str' , the number of elements in the positions 'positions_size'
	array and the positions array which contain the positions which are to be removed returns the
	string 'str' without the characters at 'positions' specified in the positions arry 
    or NULL when str is NULL;
*/
char *delete_characters(char *str, int positions[], int positions_size);

/* 	function to replace a specified character from the string with another supplied character 'new_char'
	returns the string 'str' with the character at 'position' replaced with 'new_char'
    and or NULL when pos > length of str
*/
char *replace_character(char *str, unsigned char new_char, int position);

/*	function to replace a number of different character in the string at specified positions using the replace_character() function
	it takes in the string 'str' some of whose characters are to be replaced, an array having the new characters 'new_chars' , the
	size number of positions 'number_pos' and an array having the positions 'positions'
	it returns NULL if the string 'str' is null or the string 'str' whose characters at the specified positions have been modified
*/
char *replace_characters(char *str, char new_chars[], int positions[], int number_pos);

/* 	function to double the string 'str'
	it takes in a string 'str' to be doubled
    it return the string doubled or NULL if the string str supplied is empty ("") or if NULL is passed 
*/
const char *double_string(const char *str);
#endif