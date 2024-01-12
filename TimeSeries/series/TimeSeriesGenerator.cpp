//
// Created by Thibaut Hérault on 23/12/2023.
//

#include "TimeSeriesGenerator.h"
#include <iostream>

TimeSeriesGenerator::TimeSeriesGenerator(int value): seed(value) {}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& vector) {
    std::cout << "Vector : ";

    for (int i=0; i < vector.size()-1; i++) {
        std::cout << vector[i] << ", ";
    }
    std::cout << vector[vector.size()-1];
    std::cout << std::endl;
}
