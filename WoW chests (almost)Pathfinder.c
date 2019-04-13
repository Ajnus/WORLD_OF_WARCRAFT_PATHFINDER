/* Will add:
	read from file 
	linked list 
	quicksort(?)
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#define SPOTS 12

struct coord
{
	float x0, xpos;
	float y0, ypos;
	double dist;
};
typedef struct coord Coord;

void ordena_coord (Coord* x, int n)
{
	for (int i = n-1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (x[j].dist > x[j + 1].dist)
			{
				double temp = x[j].dist;
				x[j].dist = x[j + 1].dist;
				x[j + 1].dist = temp;

				float tempf = x[j].x0;			// +4 bytes, -2 warnings and clean output, worth it :P
				x[j].x0 = x[j + 1].x0;
				x[j + 1].x0 = tempf;

				tempf = x[j].y0;
				x[j].y0 = x[j + 1].y0;
				x[j + 1].y0 = tempf;
			}
}

double calcula_dist(float x, float y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

/*void coord_to_pos_ini(Coord coord, Coord pos_ini)
{
		coord[i].xpos = abs(pos_ini.x0 - coord[i].x0);
		coord[i].ypos = abs(pos_ini.y0 - coord[i].y0);
}*/

int main(void)
{
	int i;
	Coord pos_ini;
	Coord coord[SPOTS];

	printf("Insira a posi%c%co inicial, no formato 'xx.xx yy.yy': ", 135, 132);
	scanf("%f %f", &pos_ini.x0, &pos_ini.y0);

	printf("Insira as coordenadas dos ba%cs de Recursos de Guerra, no mesmo formato:\n", 163);
	for (i = 0; i < SPOTS; i++)
	{
		scanf("%f %f", &coord[i].x0, &coord[i].y0);
		/* bases for dist from pos_ini */
		coord[i].xpos = (float)fabs(pos_ini.x0 - coord[i].x0);
		coord[i].ypos = (float)fabs(pos_ini.y0 - coord[i].y0);

		coord[i].dist = calcula_dist(coord[i].xpos, coord[i].ypos);
	}

	ordena_coord(coord, SPOTS);

	printf("\nA ordem otimizada das localiza%c%ces de ba%cs a partir da posi%c%co inicial %c:\n", 135, 148, 163, 135, 132, 130);
	for (i = 0; i < SPOTS; i++)
	{
		printf("%.2f %.2f\n", coord[i].x0, coord[i].y0);
	}

	printf("\n");
	return 0;
}