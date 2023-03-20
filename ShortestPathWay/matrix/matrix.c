#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main()
{                                                    
	int weights[11][11];
	int rows, cols, i, j;
	int row, col;
	int summation[11][11];
	int path[11];
	int getcol;
	char fix[3] = { ' ','[',']' };


	printf("please  enter the number of rows:");
	scanf_s("%d", &rows);

	printf("please  enter the number of columns:");
	scanf_s("%d", &cols);


	if (rows > 0 && cols > 0 && rows < 11 && cols < 11)
	{
		srand(time(NULL));

		for (i = 0; i <= rows; i++)
		{
			for (j = 0; j <= cols; j++)
			{
				weights[i][j] = rand() % 10;
			}
		}

		for (i = 0; i < cols; i++)
			summation[0][i] = weights[0][i];

		for (row = 1; row < rows; row++)
		{
			for (col = 0; col < cols; col++)
			{

				getcol = col;

				if (col > 0 && summation[row - 1][col - 1] < summation[row - 1][getcol])
					getcol = col - 1;

				if (col < cols - 1 && summation[row - 1][col + 1] < summation[row - 1][getcol])
					getcol = col + 1;

				summation[row][col] = summation[row - 1][getcol] + weights[row][col];

			}
		}

		path[rows];

		col = 0;

		for (i = 1; i < cols; i++)
		{
			if (summation[rows - 1][i] < summation[rows - 1][col])
				col = i;
		}

		row = rows - 1;

		do
		{
			path[row] = col + 1;

			if (col > 0 && summation[row - 1][col - 1] + weights[row][col] == summation[row][col])
				col = col - 1;
			else if (col < cols - 1 && summation[row - 1][col + 1] + weights[row][col] == summation[row][col])
				col = col + 1;

			row--;

		} while (row > 0);

		path[0] = col + 1;


		int sum = 0;

		printf("\n\n");
		for (row = 0; row < rows; row++)
		{
			for (col = 0; col < cols; col++)
			{
				char first = fix[0];
				char last = fix[0];

				if (col == path[row] - 1)
				{
					sum += weights[row][col];

					first = fix[1];
					last = fix[2];
				}

				printf(" %c%d%c ", first, weights[row][col], last);
			}
			printf("\n");
		}

		printf("\n\n");
		printf("Sum of weights: %d", sum);
	}
	else
	{
		printf("\n\n");
		printf("Error! Row and column numbers must be greater than 0 and less than 11.");

	}
	printf("\n\n");
	system("pause");
}

