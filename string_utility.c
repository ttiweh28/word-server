/*
    This file is part of the String Manipulation program, it provides function definitions for all the functions
    declared in string_utility.h file

    File name: string_utility.c
*/



#include "string_utility.h"


/* 	function to reverse the string 
	it returns NULL if the string 'str' is empty or NULL is passed to it or the string 'str' in the reverse order
*/
char *reverse_string(char *str){

	//check for null
	if(str == 0){
		return NULL;
	}
	//skip empty string
	if(*str == 0){
		return NULL;
	}

	//obtain the range of the string
	char *beginning = str;
	char *end = beginning + strlen(str) - 1; //remove the null terminater '\0'
	char temp;	//for swapping

	//as long as end is greater than beginning continue to reverse
	while(end > beginning){

		//swap
		temp = *beginning;
		*beginning = *end;
		*end = temp;

		//go to the next position
		++beginning;
		--end;
	}

	return str;
}

/* 	function to remove a specified character from the string 
	returns the string 'str' without the character at 'position' and or NULL when pos > length of str
*/
char *remove_character(char *str, int position){
	char buffer[strlen(str)];		//create a buffer of the same size as the string where u want to store the characters that you need
	int counter = 1;
	int pos = 0;
	
	/*	check if the position is less than or greater than the number of characters in the str 
		i.e. strlen(str) >= position 
	*/
	
	if(position > strlen(str)){
		return NULL;
	}
	else if(position < 0){
		return NULL;
	}
	
	/* loop through the str and identify the character that is not required */
	while(*str != '\0'){			//as long as the string has more characters

		if(counter != position){
			buffer[pos++] = *str;	//add the character to the buffer 
		}
		else{
			buffer[pos] = '\0';		//delete the character that is not needed
		}

		*str++;
		counter++;
	}
	buffer[pos] = '\0';		//terminate the string
	
	strcpy(str,buffer);		//copy the buffer to the str
	
	return str;
}

/* 	function to remove a series of characters specified in the positions array 'positions[]' 
    it takes the pointer to a character string 'str' , the number of elements in the positions 'positions_size'
	array and the positions array which contain the positions which are to be removed returns the
	string 'str' without the characters at 'positions' specified in the positions arry 
    or NULL when str is NULL;
*/
char *delete_characters(char *str, int positions[], int positions_size){

	if(str == NULL){
		return NULL;		//if the string 'str' is empty return NULL
	}

	int length = strlen(str);	//number of characters in the  string 'str'
	char buffer[length];		//create a buffer of the same size as the string where u want to store the characters that you need

	int index = 0;				//counter to loop through the buffer
	for(int i = 1; i <= length; ++i){
		bool keep = true;		//boolean to use to decide whether the character at the specified position is needed or not
		for(int j = 0; j < positions_size; ++j){
			if(i == positions[j]){
				keep = false;	//set keep to false and skip this character if it is at the unwanted position
				break;
			}
		}
		//if the character at the position i in the str is wanted then copy it to the buffer
		if(keep){
			buffer[index] = str[i-1];
			++index;
		}
	}

	buffer[index] = '\0';			//terminate the buffer
	strcpy(str, buffer);			//copy the buffer back to the string 'str'

	return str;
}

/* 	function to replace a specified character from the string with another supplied character 'new_char'
	returns the string 'str' with the character at 'position' replaced with 'new_char'
    and or NULL when pos > length of str
*/
char *replace_character(char *str, unsigned char new_char, int position){
    char buffer[strlen(str)];		//create a buffer of the same size as the string where u want to store the characters that you need
	int counter = 1;                //counter to go through the entire string 'str'
	int pos = 0;                    //tracks the position in the buffer
	
	/*	check if the position is less than or greater than the number of characters in the str 
		i.e. strlen(str) >= position 
	*/
	
	if(position > strlen(str)){
		return NULL;
	}
	else if(position < 0){
		return NULL;
	}
	
	/* loop through the str and identify the character that is to be replaced */
	while(*str != '\0'){			//as long as the string has more characters
		if(counter != position){
			buffer[pos] = *str;	//add the character to the buffer 
		}
		else{
			buffer[pos] = new_char;		//replace that character at the required position
		}

		*str++;
		pos++;
		counter++;
	}
	buffer[pos] = '\0';		//terminate the string
	
	strcpy(str,buffer);		//copy the buffer to the str
	
	return str;
}
/*	function to replace a number of different character in the string at specified positions using the replace_character() function
	it takes in the string 'str' some of whose characters are to be replaced, an array having the new characters 'new_chars' , the
	size number of positions 'number_pos' and an array having the positions 'positions'
	it returns NULL if the string 'str' is null or the string 'str' whose characters at the specified positions have been modified
*/
char *replace_characters(char *str, char new_chars[], int positions[], int number_pos){
	
	/* check that the string 'str' is empty  */
	if(str == NULL){
		return NULL;
	}
	
	int pos = 0;	//position in a string str
	
	while(pos < number_pos){
		str = replace_character(str, new_chars[pos], positions[pos]);	//replace that specific char
		++pos;
	}
	return str;
}

/* 	function to double the string 'str'
	it takes in a string 'str' to be doubled
    it return the string doubled or NULL if the string str supplied is empty ("") or if NULL is passed 
*/
const char *double_string(const char *str){

    /* check if the string is empty and return NULL if true */
    if(*str == 0){
        return NULL;
    }
    /* check if the string is NULL and return NULL */
    if(str == NULL){
        return NULL;
    }

    char *str_duplicate = strdup(str);   //create a duplicate copy of the provided string

    strcat((char *)str, (const char *)str_duplicate);   //concatenate it to the previous str

    return str;
}