#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// gets the amount of cordinates in the file that was rediected in.
int get_corners(double x[], double y[]) {
	int i = 0, num_items;

	do{
		num_items = scanf( "%lf %lf", &x[i], &y[i]);

		i++;
	} while (num_items > 0);
	num_items = --i;

	return i;
}


// prints the files coords to the screen.
void output_coords(double x[], double y[], int n, double area) {

	// I used this spaceing to match the example.
	printf("  X           Y   \n");
	printf("  -           -   \n");
	for (int i = 0; i < n; ++i){
		printf("%.2lf        %.2lf\n",  x[i],  y[i]);
	}
	printf("\n");

	printf("The area of this polygon is %lf ", area);
	
}
// this is the area of the polygon determined from reading the corrdnates.
double polygon_area(double x[], double y[], int n) {
	
	double area = 0;

	for (int i = 0; i < n; i++){
		// my area function  found the correct area but it was a negative.
		area += ((x[i] * y[i+1]) - (y[i] * x[i+1]))/2;
		
	}
	// to get my area to positive I used the absolute value for a double.
	return fabs(area);

}


int main() {
	

	double x[20], y[20], area;

	int num_coords;
	// this was shown in class as part of the example.
	printf("\n\n\n");
	
	//reads in coords to get_corners
	num_coords = get_corners(x, y);
	// uses the amount of coords given by num_coords, and the coords to find area.
	area = polygon_area(x, y, num_coords);
	//prints all the coords found in the file and the area of the ploygon.
	output_coords(x, y, num_coords, area);
	
	printf("\n\n\n");

	return 0;

		

}

