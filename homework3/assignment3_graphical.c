#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50 

int main()
{
	
	void safest_slot(int locations[][75], int size, int cars); 
	int size;
	int cars;
	
	printf("Size: ");
	scanf("%d", &size);
	//Error checking 
	while(size <= 0 || size > 50 )
	{
		
		printf("Size must be between 50 and 1");
		printf("\n");
		printf("Size: ");
		scanf("%d", &size);
		
	}
	int capacity = size * size;
	
	printf("Cars: ");
	scanf("%d", &cars);
	//Error checking
	while(cars < 0 || cars > capacity )
	{
		if(cars < 0)
		{	
			printf("Enter appropriate number\n");
			printf("Cars: ");
			scanf("%d", &cars);
		}
		if(cars > capacity)
		{
			printf("Number of cars can not exceed the limits of the parking area\n");
			printf("Cars: ");
			scanf("%d", &cars);
		}
	}
	
	int locations[75][75];
	int i;  // X locations
	int j;  // Y locations
	
	
	
	if ( cars == size * size)
	{
		printf("Best Slot Found In: 0 0\n");
	}
	else if(cars == 0)
	{
		printf("Best Slot Found In: 1 1\n");
	}
	else
	{
		for(int a = 0; a < cars; a++)
		{
			printf("Locations: ");
			scanf("%d", &i);
			scanf("%d", &j);
			if ( i <= size && j <= size)
			{
				locations[i-1][j-1] = 1;
			}
		}
	
		safest_slot(locations, size, cars);

	}
	//CONTROL
    printf("\n\n");
	for (int b = (size-1); b >= 0 ; b--)
	{
		for ( int c = 0; c < size; c++)
		{
			if(locations[c][b] == 1)
			{
				printf(" X ");
			}	
			else
			{
				printf(" O ");
			}
		}
		printf("\n");
	}
	printf("\n\n");
	//CONTROL
	
	
	return EXIT_SUCCESS;
	
}

/**
 * Prints the safest slot where it has largest distance to the nearest car.
 * @param locations holds the places of cars parked
 * @param size area of parking space
 * @param cars numbers of cars in the parking space
 */ 
void safest_slot(int locations[][75], int size, int cars)
{
	int distance_x;
	int distance_y;
	int least = MAX_SIZE * MAX_SIZE;
	int distances_to_nearest_car[75][75];
	int distance;
	
	//SEARCHING FOR EMPTY SLOTS
	for (int i = 0; i < size; i++)
	{
		for ( int j = 0; j < size; j++)
		{
			if(locations[i][j] == 0 )
			{
				least = MAX_SIZE * MAX_SIZE;
				
				//SEARCHING FOR CARS
				for ( int a = 0; a < size; a++)
				{
					for ( int b = 0; b < size; b++)
					{
		
						if(locations[a][b] == 1) //Manhattan distance 
						{
							distance_x = a - i;
							if(distance_x < 0)
							{
								distance_x *= (-1);
							}
							distance_y = b-j;
							if(distance_y < 0)
							{
								distance_y *= (-1);
							}
							
							distance = distance_x + distance_y;
							if(distance < least) // UPDATES DiSTANCE TO NEAREST CAR
							{
								least = distance;
							}
						}
				
					}
				}
				distances_to_nearest_car[i][j] = least; //STORES EVERY EMPTY SLOT'S NEAREST DiSTANCE IN AN ARRAY
			}	
		}
		
	}  
	int safest_x;
	int safest_y;
	int largest = distances_to_nearest_car[0][0];
	for (int c = 0; c < size; c++) //FIND THE EMPTY SLOT WITH LARGEST DISTANCE TO THE NEAREST CAR AND SAVES ITS COORDINATES
	{
		for ( int d = 0; d < size; d++)
		{
			if(distances_to_nearest_car[c][d] > largest)
			{
				safest_x = c;
				safest_y = d;
				largest = distances_to_nearest_car[c][d];
			}
			
		}
	}
	
	printf("Best Slot Found In: %d %d\n",safest_x+1, safest_y+1);
	
}
