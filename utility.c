/*
    This file is part of the String Manipulation program, it provides function definitions for all the functions
    declared in utility.h file

    File utility.c
*/

#include "utility.h"
#include "string_utility.h"

char *result;       //holds the result after the string has been manipulated

/* 	function to interprete the commands typed at the terminal
    it takes the a pointer to the constant character string to be interpreted
    it ruturns nothing
*/
void command_interpreter(const char *command){

    /* check to see if the command entered is not empty */
    if(command == NULL){
        return;
    }
    /* for doubling a string */
    if(strncmp(command, "double", 6) == 0){
        /* implement the  double string command double <string> */

        strtok((char *)command, " ");           //discard the double keyword in the command

        /* ensure that the argument <string> is provided */
        char *string;
        if((string = strtok(NULL, " ")) == NULL){   //extract the string from the command typed
            print_error((char *)command, FEW_ARGUMENTS);  //print error message
            return;
        }      

        result = (char *)double_string((const char *)string);   //double the string

        if(result != NULL){
            print_message(result,RESULT);

        }
        else{
            print_error("It seems you have not entered the word to double", FEW_ARGUMENTS);
            return;
        }

    }
    else if(strncmp(command, "reverse", 7) == 0){
       /* implement the  reverse string command reverse <string> */

        strtok((char *)command, " ");           //discard the revers keyword in the command

        /* ensure that the argument <string> is provided */
        char *string;
        if((string = strtok(NULL, " ")) == NULL){   //extract the string from the command typed
            print_error((char *)command, FEW_ARGUMENTS);  //print error message
            return;
        }      

        result = reverse_string(string);   //reverse the string

        if(result != NULL){
            print_message(result,RESULT);

        }
        else{
            print_error("It seems you have not entered the word to reverse", FEW_ARGUMENTS);
            return;
        }


    }
    else if(strncmp(command, "delete", 6) == 0){
        //implement the delete command >> delete <pos1, postn2,....,postnn> from <string>
        strtok((char *)command, " ");           //discard the delete word from the command

        char *postions_string;
        char *from_keyword;
        char *string;

        //********ensure that the four arguments are provided in the command
        if((postions_string = strtok(NULL, " ")) == NULL){  //extract the positions string "<pos1, postn2,....,postnn>""
            print_error((char *)command, FEW_ARGUMENTS);   //print error message
            return;
        }
        if((from_keyword = strtok(NULL, " ")) == NULL){      //extract the from keyword "from"
            print_error((char *)command, FEW_ARGUMENTS);   //print error message
            return;
        }

        if((string = strtok(NULL, " ")) == NULL){           //extract the string from which the characters are to be deleted "<string>"
            print_error((char *)command, FEW_ARGUMENTS);   //print error message
            return;
        }
        //****************************************************************

        int positions[strlen(postions_string)];   //the array to contain the converted positions from string to int
        char *token;                              //token extracted
        int index = 0;                            //index to go through the positions[]
        //ensure that the from keyword is in the typed command
        if(strncmp(from_keyword, "from", 4) == 0){
            /* extract the positions specified in <pos1, postn2,....,postnn> and */
            token = strtok(postions_string, ",");

            while(token != NULL) {

                //convert the token to an int if it is a digit
                if(is_anumber(token)){           //****************fix this
                    positions[index] = atoi(token);
                    ++index;                    //go to next position
                }
                else{
                    print_error("wrong arguments in the command", WRONG_ARGUMENTS);
                    return;                         //if any of the argumens is wrong, return (do not process other arguments)
                }
                NEW_LINE;
                token = strtok(NULL, ",");
            }
            /* do the deletioin of the characters in the specified positions */
            int pos_size = (int)(sizeof(positions) / (sizeof(positions[0])));
            sort_positions(positions, pos_size);        //sort the positions array in ascending order

            result = delete_characters(string, positions, pos_size);
            if(result != NULL){
                print_message(result, RESULT);

            }
            else{
                print_error("One of the postions you want to delete does not exit in the string provided", WRONG_ARGUMENTS);
                return;
            }
        }
        else{
            print_error((char *)command, UNKNOWN_COMMAND);
        }

    }
    else if(strncmp(command, "replace", 7) == 0){
        /*implement the replace command replace <pos1-char1, pos2-char2, ....., posn-charn> in <string> */
        strtok((char *)command, " ");           //discard the replace word from the command

        //some variables
        char *replacements;         
        char *in_keyword;
        char *string;

        char *new_chars_and_pos;        //string that has the position and the char i.e. <pos-char> eg 3-h
        

        //********ensure that the four arguments are provided in the command
        if((replacements = strtok(NULL, " ")) == NULL){  //extract the positions string "<pos1-char1, pos2-char2, ....., posn-charn>"
            print_error((char *)command, FEW_ARGUMENTS);  //print error message
            return;
        }
        if((in_keyword = strtok(NULL, " ")) == NULL){      //extract the from keyword "in"
            print_error((char *)command, FEW_ARGUMENTS);   //print error message
            return;
        }

        if((string = strtok(NULL, " ")) == NULL){           //extract the string from which the characters are to be replaced "<string>"
            print_error((char *)command, FEW_ARGUMENTS);   //print error message
            return;
        }
        //****************************************************************
        
        //ensure that the keyword "in" is present in the command
        if(strncmp(in_keyword, "in", 2) == 0){

            int number_of_elements = (int)((strlen(replacements) + 1) / 4);     //the number of new characters to replace
            char new_chars[number_of_elements];                                 //the array to contain the new characters (the new char extracted form <pos-char> eg "h")
            int positions[number_of_elements];                                  //the position extracted form <pos-char> eg "3"

            /* obtain the individual segments of the position and new char combination ie <pos-char> */
            char pos_char_tokens[number_of_elements][3];
            int char_counter,index = 0;

            new_chars_and_pos = strtok(replacements, ",");  //extract the first pos-char combination
            while(new_chars_and_pos != NULL){
                
                for(char_counter = 0; char_counter < 3; ++char_counter){
                    pos_char_tokens[index][char_counter] = new_chars_and_pos[char_counter];
                }
                pos_char_tokens[index][char_counter] = '\0';             //terminate the pos-char combination
                
                new_chars_and_pos = strtok(NULL, ",");          //extract another pos-char combination
                ++index;
            }

            /*load the new_chars[] array and the positions[] array with their respective contents*/
            index = 0;
            char buff[2];       //temporary buffer for containg the "<pos>" to be converted to integer
            while(index < number_of_elements){
                /* check if the "<pos>" is a number */
                if(isdigit(pos_char_tokens[index][0])){
                    buff[0] = pos_char_tokens[index][0];        //add the "<pos>" to the buff
                    buff[1] = '\0';                             //terminate the buff

                    positions[index] = atoi(buff);                  //convert the "<pos>" to an integer and load it to the positions[] array
                    new_chars[index] = pos_char_tokens[index][2];   //add the "<char>" to the new_chars[] array

                }
                else{
                    print_error("wrong arguments in the command", WRONG_ARGUMENTS);
                    return; 
                }
                ++index;
            }

            /* do the replacements of the characters on the string 'str' */
            result = replace_characters(string, new_chars, positions, number_of_elements);
            if(result != NULL){
                print_message(result,RESULT);

            }
            else{
                print_error("One of the postions you want to replace does not exit in the string provided", WRONG_ARGUMENTS);
                return;
            }

            
        }
        else {
            print_error((char *)command, UNKNOWN_COMMAND);
        }


        
    }
    else if (strncmp(command, "encrypt", 7) == 0){
        //do waht you want with encrypt command
    }
    else if(strcmp(command, "help") == 0){
        //do what you want with the help command
    }
    else if(strcmp(command, "exit") == 0){
        //do what you want with exit command
        NEW_LINE;
        print_message("Bye...", MESSAGE);
        exit(EXIT_SUCCESS);             //exit the program
    }
    //* In case of unsupported command 
    else{
        print_error((char *)command, UNKNOWN_COMMAND);   //print error message
    }
    
}

/* 
    function to print the prompt and capture the command from the terminal
    it takes as input a buffer where the command is stored, the buffer can accept a maximum of 1000 bytes (1000 ASCII characters)
    it returns the buffer to which the command is written
*/
const char *prompt(char buffer[]){
    NEW_LINE;
    printf(" Enter a command> ");
    fgets(buffer, 1000, stdin);
    NEW_LINE;
    buffer = strtok(buffer, "\n");  //remove the new line character which is appended implicitly by the fgets() function

    return (const char *)buffer;
}

/* 	function to print a message at the terminal
    it takes a pointer to the character string to be printed to the screen and the type of the message
    it ruturns nothing
*/
void print_message(char *message, char *msg_type){
    
    printf(" %s: %s",msg_type, message);
    NEW_LINE;
}

/* 	function to print error message on the terminal 
    it takes a pointer to the character string to be printed to the terminal
    and a pointer to the character string having the error type 'error_type'
    it ruturns nothing
*/
void print_error(char *error_msg, char *error_type){

    NEW_LINE;
    printf(" ERROR: %s> \" %s \", Type help to see the list of permitted commands!",error_type, error_msg);
    NEW_LINE;
}
/*
    function to check if the entered string is a number, it looks at each character in the string entered, 
    when it encounters a character that is not a number, it returns 0 (false)
    it takes a string 'str' to be checked if it is a number
    it returns 1(true) if all the characters in the string are numbers or 0 (false) if at least one of the characters in the string 
    is not a number
*/

int is_anumber(char *str){
    int counter = 0;
    int isDigit = 0;
	/*	loop through the string 'str' and if a character at any position is not a number return false (0)
		otherwise if all the characters in the str are numbers return true (1) 
	*/
	do{
		if(isdigit(*str)){
			isDigit = 1;		//the char at this position is a number (true)
		}
		else{
			isDigit = 0;		//the char at this position is not a number (false)
		}
		*str++;
		++counter;
	}while((isDigit == 1) && (*str != '\0'));	

    return isDigit;
}

/*
	function to swap two integers
	it takes two pointers to integers and interchanges them i.e 'from' is set 'to' and 'to' is set to 'from'
*/
void swap(int *from, int *to){
	int temp;			//temporary holder for the value to be swapped
	temp = *from;
	*from = *to;
	*to = temp;
}

/*
	function to sort an array of integers in ascending order (bubble sort)
	it takes an array of integers before sorting
	it returns the array after sorting in ascending order
*/
int *sort_positions(int positions_array[], int size_){

	int outer_counter;		//passes through the positions_array[]
	int swap_counter;		//for comparing and swapping any two positions

	for(outer_counter = 0; outer_counter < size_; ++outer_counter){	//go through the entire positions_array

		for(swap_counter = 0; swap_counter < size_; ++swap_counter){

			if(positions_array[swap_counter] > positions_array[outer_counter]){
				swap(&positions_array[swap_counter], &positions_array[outer_counter]);	//swap the two numbers if the next value in the positions_array is greater than the previous
			}
		}
	}
	return positions_array;
}
/* to beremoved */
void debug(void){
    printf("####> I havefailed ### \n");
}