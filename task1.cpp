#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	struct seat {
		int seat_number;// номер кресла
		int number_of_things;// <=4
		double weight_of_things[4];
		double max_weight;//вес самой тяжёлой вещи у одного из пассажиров;
	};
	seat seats[20];
	int  n;       /* Количество элементов в массиве seats */

	/* Ввод списка */
	do {
		printf("Введите количество кресел n (n<20): ");
		scanf("%d", &n); while (getchar() != '\n');
	} while (n < 1 || n>20);
	printf("\nВведите список из %d кресел. Если кресло пустует, то кол-во вещей и вес каждой вещи должны равняться 0!:\n\n", n);
	for (int i = 0; i < n; i++) {

		printf("Номер кресла %d: \n", i + 1);  seats[i].seat_number = i + 1;

		do {
			printf("Общее кол-во вещей (не более 4): "); scanf("%d", &seats[i].number_of_things);
		} while (seats[i].number_of_things > 4 || seats[i].number_of_things < 0);
		if (seats[i].number_of_things == 0) {
			for (int j = 0; j < 4; j++) {
				seats[i].weight_of_things[j] = 0.0;
			}
		}
		else {
			int kk;
			for (kk = 0; kk < seats[i].number_of_things; kk++) { 
do {
printf("Вес вещи # %d:  ", kk+1);
					scanf("%lf", &seats[i].weight_of_things[kk]);
				} while (seats[i].weight_of_things[kk] <= 0);				
			}
			for (int j = kk; j < 4; j++) {
				seats[i].weight_of_things[j] = 0.0;
			}
		}
		printf("\n");
	}
	/* Вывод основного списка */
	printf("\nВы ввели (номер кресла кол-во вещей, вес 1-й, 2-й, 3-й и 4-й вещи):\n");
	for (int i = 0; i < n; i++)
		printf(" %4d  %4d %7.3lf %7.3lf %7.3lf %7.3lf\n", seats[i].seat_number, seats[i].number_of_things, seats[i].weight_of_things[0], seats[i].weight_of_things[1], seats[i].weight_of_things[2], seats[i].weight_of_things[3]);
	/* Обработка списка и вывод результата */
	// сначала найдём вес самой тяжёлой вещи у каждого из пассажиров
	for (int i = 0; i < n; i++) {
		if (seats[i].number_of_things != 0) {
			seats[i].max_weight = seats[i].weight_of_things[0];
			for (int j = 1; j < 4; j++) {
				if (seats[i].weight_of_things[j] > seats[i].max_weight) seats[i].max_weight = seats[i].weight_of_things[j];
			}
		}
		else seats[i].max_weight = 0;
	}


	// сортировка пузырьком по убыванию 
	int k; /* к - номер просмотра */
	seat c; /* Вспомогательная переменная для перестановки 2-х элементов */
	for (k = 1; k < n; k++)
		for (int i = 0; i < n - k; i++)
			if (seats[i].max_weight < seats[i + 1].max_weight)
			{
				c = seats[i];
				seats[i] = seats[i + 1];
				seats[i + 1] = c;
			}
	printf("\nУпорядоченный список (номер кресла кол-во вещей, вес 1-й, 2-й, 3-й и 4-й вещи):\n");
	for (int i = 0; i < n; i++) {
		printf(" %4d  %4d %7.3lf %7.3lf %7.3lf %7.3lf\n", seats[i].seat_number, seats[i].number_of_things, seats[i].weight_of_things[0], seats[i].weight_of_things[1], seats[i].weight_of_things[2], seats[i].weight_of_things[3]);
		printf("(Вес самой тяжёлоё вещи %lf:)\n", seats[i].max_weight);
	}
}