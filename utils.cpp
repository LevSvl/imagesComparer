#include "utils.h"
void initRandom() {
    srand(time(NULL));
}
uint32 randomize(unsigned int min,unsigned int max) {
	uint32 result = rand() % (max - min + 1);
	return result;
}

double roundToNDecimalPlaces(double value, int decimalPlaces) {
	double factor = std::pow(10, decimalPlaces);
	return std::round(value * factor) / factor;
}

std::string roundNumber(double value, int precision) {
    std::ostringstream oss;
    if (precision >= 0) {
        oss << std::fixed << std::setprecision(precision) << value;
    }
    else {
        double factor = std::pow(10, -precision);
        oss << std::fixed << std::setprecision(0) << std::round(value * factor) / factor;
    }
    return oss.str();
}