#include "utils.h"
#include "genetic.h"


void fitting(Model* population, img* image1, img* image2) {
	/* 
	Функция приспособляемости. Оценка каждой особи 
	по значению критериальной функции f(x)
	*/
	for (int n = 0; n < POPULATION_SIZE; n++) {
		uint64 f1, f2;
		double sum = 0.0;
		Model model = population[n];
		uint32 x = model.x, y = model.y;

        int xMax = image1->width - image2->width;
        int yMax = image1->height - image2->height;

        for (int i = 0; i < image2->height; i++) {
            // Если x или y превышает допустимое значение для изображения
            if (x > xMax)
                break;
            if(y > yMax)
                break;
            for (int j = 0; j < image2->width; j++) {

                f1 = image1->image[(j + x) + ((i + y) * image2->width)];
                f2 = image2->image[j + i * image2->width];
                sum += f1 * f2;
            }
        }

        sum = sum / (image2->height * image2->width);
        model.fxy = sum;

        population[n] = model;
    }
}

void selection(Model* population) {
	/* Функция отбора (усечением) */
    for (int i = 0; i < POPULATION_SIZE * L; i++)
        population[i].relevantForCrossOver = true;
}

void cross_over(Model* population) {
	/* Функция скрещивания */

    /* Массив где будут накапливаться потомки */
    Model newPopulation[POPULATION_SIZE];

    // Определяем переменную для записи случайного значения, 
    // В зависимости от которого будет приниматься решение о скрещивании
    int luckyOrUnlucky, numberOfChild = 0;
    
    while (numberOfChild < POPULATION_SIZE) {
        // Перебираются только особи, прошедшие отбор
        int parentIdx1 = randomize(0, POPULATION_SIZE * L - 1);
        int parentIdx2 = randomize(0, POPULATION_SIZE * L - 1);

        //if (parentIdx1 == parentIdx2)
        //    continue;

        Model parent1 = population[parentIdx1], parent2 = population[parentIdx2];

        // ??? todo Стоит переделать для L которые имеют больше одной цифры после запятой
        luckyOrUnlucky = randomize(1, 100);
        if ((double)luckyOrUnlucky/100 > PROBABILITY_OF_CROSSOVER)
            continue;

        // взаимный обмен битами двух координат (1-точечный кроссовер)
        uint32 parentX = parent1.x, parentY = parent2.y;

        int splitIdx = randomize(1, 31); // произвольная точка разрыва

        // преобразование чисел в код Грея
        parentX = convertToGrey(parentX);
        parentY = convertToGrey(parentY);

        // скрещиванием битов координат родителей
        // создаются координаты для двух потомков
        uint32 childx = convertToBinary(bitSwap(parentX, parentY,splitIdx));
        uint32 childy = convertToBinary(bitSwap(parentY, parentX, splitIdx));
        
        // создание потомков
        Model child1,child2;
        child1.x = childx, child1.y = childy, child1.relevantForCrossOver = false;
        child2.x = childy, child1.y = childx, child2.relevantForCrossOver = false;

        newPopulation[numberOfChild++] = child1;
        newPopulation[numberOfChild++] = child2;
    }
    
    for (int i = 0; i < POPULATION_SIZE; i++)
        population[i] = newPopulation[i];
}

void mutation(Model* population) {
	/* 
    Функция мутации. Мутация применяется ко всем 
    координатам с вероятностью мутации PROBABILITY_OF_MUTATION
    */
    int mutate_or_not = 0;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        Model model = population[i];
        uint32 x = convertToGrey(model.x);
        uint32 y = convertToGrey(model.y);

        // для каждого бита мутация выполняется 
        // мутация с вероятностью PROBABILITY_OF_MUTATION
        
        // мутация x
        for (int j = 0; j < 8; j++) {
            mutate_or_not = randomize(1, 100);
            if (mutate_or_not <= (int)(PROBABILITY_OF_MUTATION * 100))
                x = invertBit(x, j);
        }
        // мутация y
        for (int j = 0; j < 8; j++) {
            mutate_or_not = randomize(1, 100);
            if (mutate_or_not <= (int)(PROBABILITY_OF_MUTATION * 100))
                y = invertBit(y, j);
        }

        model.x = convertToBinary(x);
        model.y = convertToBinary(y);

        population[i] = model;
    }
}


void merge_sort(Model* population, int size) {
    /*
    Функция сортировки популяции. Сортировка по убыванию
    значения функции корреляции
    */
    if (size > 1) {
        int mid = size / 2;
        Model* left = new Model[mid], * right = new Model[size - mid];
        memcpy(left, &population[0], sizeof(Model) * mid);
        memcpy(right, &population[mid], sizeof(Model) * (size - mid));
        merge_sort(left, mid);
        merge_sort(right, size - mid);

        int i = 0, j = 0, k = 0;
        while (i < mid && j < size - mid) {
            if (left[i].fxy > right[j].fxy) {
                population[k] = left[i];
                i++;
            }
            else {
                population[k] = right[j];
                j++;
            }
            k++;
        }
        while (j < size - mid) {
            population[k] = right[j];
            j++; k++;
        }
        while (i < mid) {
            population[k] = left[i];
            i++; k++;
        }
    }
}