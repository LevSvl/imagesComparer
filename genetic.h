#pragma once

#include "utils.h"
#include "binary_operations.h"

#define POPULATION_SIZE 500 // Размер популяции (должен быть кратным 100)
#define NUMBER_OF_POPULATIONS 250 // Количество популяций
#define PROBABILITY_OF_CROSSOVER 0.6 // Вероятность скрещивания
#define PROBABILITY_OF_MUTATION 0.02 // Вероятность мутации
const double L = 0.5;// Порог отсечения (Давление селекции)


struct Model
{
	uint32 x,y;
	bitset<16> bitString;
	double fxy;
	bool relevantForCrossOver; // Коэфициент приспособленности
};

void fitting(Model* population, img* image1, img* image2);

void selection(Model* population);

void cross_over(Model* population);

void mutation(Model* population);

void merge_sort(Model* population, int size);