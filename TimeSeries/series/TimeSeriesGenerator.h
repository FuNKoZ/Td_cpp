//
// Created by Thibaut Hérault on 23/12/2023.
//

#ifndef TIMESERIES_TIMESERIESGENERATOR_H
#define TIMESERIES_TIMESERIESGENERATOR_H

#include <vector>

class TimeSeriesGenerator {
public:
    int seed = 0;
    TimeSeriesGenerator() = default;
    explicit TimeSeriesGenerator(int);
    virtual std::vector<double> generateTimeSeries(int) = 0;
    static void printTimeSeries(const std::vector<double>&);
};


#endif //TIMESERIES_TIMESERIESGENERATOR_H
