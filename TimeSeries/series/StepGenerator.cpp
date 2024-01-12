//
// Created by Thibaut Hérault on 24/12/2023.
//

#include "StepGenerator.h"

std::vector<double> StepGenerator::generateTimeSeries(int number) {
    std::vector<double> vector;
    int u;

    vector.reserve(number);
    for (int i=0; i<number; i++) {
        if ((rand() / (RAND_MAX + 1.0)) < 0.5) vector.push_back(this->value);
        else {
            u = (rand() / (RAND_MAX + 1.0)) * 100;
            this->value = u;
            vector.push_back(value);
        }
    }
    return vector;
}
