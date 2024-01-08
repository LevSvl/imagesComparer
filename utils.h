#pragma once

#include <iostream>
#include <string>
#include<fstream>
#include<string.h> 
#include<ctime>
#include<stdlib.h>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bit>
#include <bitset>
#include <sstream>
using namespace std;


#define uint8 unsigned int
#define uint16 unsigned short
#define uint32 unsigned int
#define uint64 unsigned long

struct img {
	int width;
	int height;
	unsigned int* image;
};


uint8 randomize(unsigned int min, unsigned int max);

double roundToNDecimalPlaces(double value, int decimalPlaces);

std::string roundNumber(double value, int precision);