// adicionar ler do arquivo e quicksort(?)

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#define SPOTS 15

struct coord
{
	float x;
	float y;
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

				float tempX = x[j].x;
				x[j].x = x[j + 1].x;
				x[j + 1].x = tempX;

				float tempY = x[j].y;
				x[j].y = x[j + 1].y;
				x[j + 1].y = tempY;
			}
}

double calcula_dist(float x, float y)
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

int main(void)
{
	int i;
	Coord coord[SPOTS];

	printf("Insira as coordenadas dos ba%cs de Recursos de Guerra, no formato 'xx.xx yy.yy':\n", 163);
	for (i = 0; i < SPOTS; i++)
	{
		scanf("%f %f", &coord[i].x, &coord[i].y);
		coord[i].dist = calcula_dist(coord[i].x, coord[i].y);
	}

	ordena_coord(coord, SPOTS);

	printf("\nA ordem otimizada das localiza%c%ces de ba%cs a partir do ponto origem '00.00, 00.00' %c:\n", 135, 148, 163, 130);
	for (i = 0; i < SPOTS; i++)
	{
		printf("%.2f %.2f\n", coord[i].x, coord[i].y);
	}

	printf("\n");
	return 0;
}