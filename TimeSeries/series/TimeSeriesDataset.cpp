//
// Created by Thibaut Hérault on 24/12/2023.
//

#include "TimeSeriesDataset.h"

TimeSeriesDataset::TimeSeriesDataset(bool _znormalize): znormalize(_znormalize) {}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& vector) {
    addTimeSeries(vector, -1);
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& vector, int label) {
    if (znormalize) {
        // Perform Z-normalization
        double mean = 0.0, stdDev = 0.0;

        for (double value : vector) {
            mean += value;
        }

        mean /= (double) vector.size();

        for (double value : vector) {
            stdDev += pow(value - mean, 2);
        }

        stdDev = sqrt(stdDev / (double) vector.size());

        for (double& value : data.back()) {
            value = (value - mean) / stdDev;
        }
    }

    data.push_back(vector);
    labels.push_back(label);

    if (vector.size() > maxLength) {
        maxLength = (int) vector.size();
    }

    numberOfSamples++;
}

int TimeSeriesDataset::getNumberOfSamples() const {
    return numberOfSamples;
}

const std::vector<int> &TimeSeriesDataset::getLabels() const {
    return labels;
}

const std::vector<std::vector<double>> &TimeSeriesDataset::getData() const {
    return data;
}

