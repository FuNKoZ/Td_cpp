//
// Created by Thibaut Hérault on 24/12/2023.
//

#include "SinWaveGenerator.h"

SinWaveGenerator::SinWaveGenerator(double _a, double _omega, double _phi): a(_a), omega(_omega), phi(_phi) {}

std::vector<double> SinWaveGenerator::generateTimeSeries(int number) {
    std::vector<double> vector;

    vector.reserve(number);
    for (int i=0; i<number; i++) vector.push_back(a * sin(omega*i+phi));
    return vector;
}


