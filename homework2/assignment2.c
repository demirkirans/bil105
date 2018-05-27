#include <stdio.h>
#include <stdlib.h>


/**
 * Takes the segment and ring of a throw then computes the point for the throw
 * @param segment one of the twenty numbered zones which dart has landed
 * @param ring small areas which decide what will be do with segment points(double,triple,single,inner,outer)
 * @return the point value for throw
 */ 
int point_of_throw(int segment, char ring)
{
	
	int point = 0;
	const int single = 1;
	const int doubles = 2;
	const int triple = 3;
	const int inner = 50;
	const int outer = 25;
	
	if (ring == 'S' || ring == 's')
	{
		point = segment * single;
	}
	else if (ring == 'D' || ring == 'd')
	{
		point = segment * doubles;
	}
	else if (ring == 'T' || ring == 't')
	{
		point = segment * triple;
	}
	else if (ring == 'O' || ring == 'o')
	{
		point = outer;
	}
	else if (ring == 'I' || ring == 'i')
	{
		point = inner;
	}
	else
	{
		printf("Wrong statement\n");
		return EXIT_FAILURE;
	}
	
	return point;
}

/**
 * takes current points, the segment and the ring then computes remaining points
 * @param current_points the present point 
 * @param segment the value between 1-20
 * @param ring small areas in the board
 * @return remaining points after throw
 */ 
int remaining_points(int target_point, int current_points, int segment, char ring)
{
	int points_after_throw; 
	
	//Condition of starting of the game
	if ( current_points == target_point )
	{
		if (ring == 'D' || ring == 'd')
		{
			points_after_throw = current_points - point_of_throw(segment, ring);
		}
		else
		{
			points_after_throw = target_point;
		}
	}
	//Condition of ending of the game
	else if( (current_points - point_of_throw(segment, ring) == 0) && (ring == 'D' || ring == 'd') )
	{
		points_after_throw = 0;
	}
	//After the throw, if remaining point is equal or less than 1; it is not counted!!
	else if (current_points - point_of_throw(segment, ring) <= 1)
	{
		points_after_throw = current_points;
	}
	//Any throw
	else
	{
		points_after_throw = current_points - point_of_throw(segment, ring);
	}
	
	return points_after_throw;
}


int main()
{
	int target;
	int points;
	int segment_of_throw;
	char ring_of_throw;
	printf("Target: ");
	scanf("%d", &target);
	printf("\n");
	points = target;
	
	while ( points != 0 )
	{
		printf("Throw: ");
		scanf("%d %c", &segment_of_throw, &ring_of_throw);
		printf("Points: %d\n", remaining_points(target, points, segment_of_throw, ring_of_throw));
		points = remaining_points(target, points, segment_of_throw, ring_of_throw);
	}
	
	
	return EXIT_SUCCESS;
}

