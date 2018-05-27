#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE .. 

int main () 
{
	
	int year;
	int month;
	int day;
	int end_year; 


	//GET A DATE FROM THE USER

	printf("Enter date [year month day]: ");
	scanf("%d %d %d", &year, &month, &day);

		
	//CHECK WHETHER THE DATE IS VALÝD

	if ( day < 1 || day > 30 ) 
	{
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	if ( month < 1 || month > 12 )
	{
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}
	if ( year < 0 )
	{
		printf("Invalid date.\n");
		return EXIT_FAILURE;
	}						

					
	//GET AN END YEAR FROM USER

	printf("Enter end year: ");
	scanf("%d", &end_year);

	//DETERMINE THE DAY OF THE WEEK AND PRINT IT


	int q = day;    //assigning new values for formula
	int m = month;  //assigning new values for formula
	int y = year;	//assigning new values for formula
	
	if ( month == 1 || month == 2 ) 	//Checking January and February
	{
		m = m + 12;
		y = y - 1;
	}
	
	int last_two = y % 100; // last two digits of the year the user entered
	int first_two = (y - last_two) / 100; // first two digits of the year the user entered
	
	int k = last_two;	//assigning new values for formula 
	int j = first_two;  //assigning new values for formula
	
	

	/*
	int weekday =  q + ( 13 * ( m + 1 ) / 5.0 ) + k + k / 4.0 + j / 4.0 + 5 * j; //Zeller's congruence..
	printf("weekday:%d\n", weekday);
	printf("mod:%d\n", weekday % 7);
	*/
	
	int weekday =  q + ( 13 * ( m + 1 ) / 5 ) + k + k / 4 + j / 4 + 5 * j; //Zeller's congruence..
	weekday = weekday % 7;
	
	
	switch( weekday ) //Determining which weekday is the date
	{
	
		case 0 : printf("It's a Saturday.\n"); break;
		case 1 : printf("It's a Sunday.\n"); break;
		case 2 : printf("It's a Monday.\n"); break;
		case 3 : printf("It's a Tuesday.\n"); break;
		case 4 : printf("It's a Wednesday.\n"); break;
		case 5 : printf("It's a Thursday.\n"); break;
		case 6 : printf("It's a Friday.\n"); break;
	
	}


	//COUNT REPETITIONS

	unsigned int counter = 0;
	int i;
	int new_weekday;
	
	for ( i = year + 1; i <= end_year; i++ )
	{
		y = y + 1;
		
		last_two = y % 100; // last two digits of the year the user entered
		first_two = (y - last_two) / 100; // first two digits of the year the user entered
	
		k = last_two;
		j = first_two;
		
		new_weekday =  q + ( 13 * ( m + 1 ) / 5 ) + k + k / 4 + j / 4 + 5 * j; //Zeller's congruence..	
		new_weekday = new_weekday % 7;
		
		if ( new_weekday == weekday )
		{
			counter ++;
		}
	}
	
	printf("Same day-and-month on same weekday between %d and %d: %d\n", year + 1, end_year, counter);	

	//END THE PROGRAM WITH A SUCCESS CODE				

	return EXIT_SUCCESS;
}
