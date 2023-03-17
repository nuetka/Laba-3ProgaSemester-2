#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Rus");
	typedef struct {
		char surname[20];              /* Фамилия */
		int education;/*  - метка активного компонента */
		union {
			struct {
				int year;
				char uni_name[20];
			}higher_education;

			int age;
		} un;// имя объединения - переменног компонента
		
		
	} employee;  

	employee list[30];
	int  n;       /* Количество элементов в массиве seats */

	/* Ввод списка */
	do {
		printf("\n Введите количество сотрудников n (n<30): ");
		scanf("%d", &n); while (getchar() != '\n');
	} while (n < 1 || n>20);

	printf("Введите список из %d сотрудников:\n", n);
	for (int i = 0; i < n; i++) {
		printf("Фамилия:");
		scanf("%s", &list[i].surname); ; (getchar() != '\n');
		do {
			printf("образование(1-высшее, 2-среднее):"); scanf("%d", &list[i].education);
		} while (list[i].education != 1 && list[i].education != 2);
		if (list[i].education == 1) {
			printf("Год окончания ВУЗа: "); scanf("%d", &list[i].un.higher_education.year);
			printf("Название ВУЗа: "); scanf("%s", &list[i].un.higher_education.uni_name); while (getchar() != '\n');
		}
		else {
			printf("Возраст сотрудника: "); scanf("%d", &list[i].un.age);

		}
		printf("\n");
	}
	/* Вывод основного списка */
	printf("Вы ввели (Фамилия, образование, если 1-год окончания и название вуза, 2 - возраст)\n");
	for (int i = 0; i < n; i++)
		switch (list[i].education) {
		case 1: 
			printf("%12s %2d %6d %12s\n", list[i].surname, list[i].education, list[i].un.higher_education.year, list[i].un.higher_education.uni_name);
		break;
		case 2:
			printf("%12s %2d %6d\n", list[i].surname, list[i].education, list[i].un.age);
			break;
		}
	// осоставление списка сотрубников без высшего
	
	employee list2[30];
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (list[i].education == 2) {
			list2[count] = list[i];
			count += 1;	
		}
	}
	
	int k; /* к - номер просмотра */
	employee c; /* Вспомогательная переменная для перестановки 2-х элементов */
	for (k = 1; k < count; k++) {
		for (int i = 0; i < count - k; i++) {
			if (list2[i].un.age < list2[i + 1].un.age)
			{
				c = list2[i];
				list2[i] = list2[i + 1];
				list2[i + 1] = c;
			}
		}
	}

	printf("\nОтсортированный по возрасту список:\n");
	for (int i = 0; i < count; i++) {
		printf("%12s %2d %6d\n", list2[i].surname, list2[i].education, list2[i].un.age);
	}
}
