#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define LINES 10000
#define CHARACTER 200
#define WORD 15


struct instruction_s{
	int step;
	int index;
};

/**
 * Finds the n.th word in a given string
 * @param s a string
 * @param n The word we want to find
 * @return n.th word
 */
char* get_word(char* s, int n) 
{
	char* name = (char*) malloc(sizeof(char) * WORD );
	int i = 0;
	int count = 0;
	char *bef; // for to catch spaces
	bef = NULL;
	
	while( *s != '\0' )
	{
		if ( *s != ' ' ) //it finds a character
		{
			if  ( ( bef == NULL ) || ( *bef == ' ' ) ) 
			{
				count++;
			}
			if ( count == n ) //We found the word
			{
				if ( isalnum(*s) ) //Process if it is a digit or letter
				{
					if( isupper(*s) )
					{
						name[i] = tolower( *s );// Convert the letter to lowercase 
					}
					else
					{
						name[i] = *s;
					}
					i++;
				}
			}
			
			s++;
			bef = s - 1;
		}
		else if ( *s == ' ' ) 
        {                  
			s++; 
			bef = s - 1;                         
        }   
	}
	name[i] = '\0';
	return name;
 
}

/**
 * Construct the sentence from given lines and instructions
 * @param lines given book
 * @param instructions sequence of numbers to follow for finding sentence
 * @param n_instructions number of instructions
 * @param sentence an array to store hidden sentence
 * @return hidden sentence
 */
void get_sentence(char** lines, struct instruction_s* instructions, int n_instructions, char* sentence)
{
	
	int total = 0;
	char* temp;
	for(int i=0; i<n_instructions; i++)
	{
		total = total + (instructions+i)->step;
		temp=get_word(lines[total-1], (instructions+i)->index);
		strcat(sentence, temp);// Add the word we found to the sentence
		strcat(sentence, " ");
		free(temp);
	}
}	




int main(int argc, char *argv[])
{
	FILE* bookptr;
	FILE* instptr;
	int l;
	char hidden[CHARACTER];
	char** book=malloc(LINES * sizeof(char*));
	for(int i=0; i<LINES; i++)
	{
		book[i]=malloc(CHARACTER * sizeof(char));
	}
	struct instruction_s inst[LINES];
	bookptr=fopen( argv[1], "r");
	

	if( bookptr == NULL )
	{
		printf("Book file could not be found\n");
		return EXIT_FAILURE;
	}
	else
	{	
		l=0;	
		while(!feof(bookptr))//storing the lines of book
		{
			fgets(book[l], CHARACTER, bookptr);
			strcat(book[l], "\0");
			l++;
		}
		instptr=fopen( argv[2], "r");
		if( instptr == NULL)
		{
			printf("Instructions file could not be found\n");
			return EXIT_FAILURE;
		}
	
		else
		{		
			l=0;
			while(!feof(instptr) && l<LINES)//getting instructions
			{
				fscanf(instptr, "%d%d", &inst[l].step, &inst[l].index);
				l++;
			}
		
			//Here it brings the hidden sentence from given book
			
			get_sentence(book, inst, l, hidden);
		}
		
			puts(hidden);
	}
	for(int i=0; i<CHARACTER; i++)
	{
		free(book[i]);	
	}
	fclose(bookptr);
	fclose(instptr);
	
	
	return EXIT_SUCCESS;
	
}
