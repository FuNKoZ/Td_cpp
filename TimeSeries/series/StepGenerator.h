//
// Created by Thibaut Hérault on 24/12/2023.
//

#ifndef TIMESERIES_STEPGENERATOR_H
#define TIMESERIES_STEPGENERATOR_H

#include "TimeSeriesGenerator.h"

class StepGenerator: public TimeSeriesGenerator {
private:
    int value = 0;
public:
    StepGenerator() = default;
    std::vector<double> generateTimeSeries(int) override;
};


#endif //TIMESERIES_STEPGENERATOR_H
