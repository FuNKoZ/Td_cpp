//
// Created by Thibaut Hérault on 10/01/2024.
//

#include <algorithm>
#include <unordered_map>
#include <utility>
#include <stdexcept>
#include "KNN.h"

double euclidean_distance(const std::vector<double> & X, const std::vector<double> & Y) {
    double distance = 0;

    for (int i=0; i < std::min(X.size(), Y.size()); i++) {
        distance += (X[i] + Y[i]) * (X[i] + Y[i]);
    }
    return std::sqrt(distance);
}

double dtw(const std::vector<double> & X, const std::vector<double> & Y) {
    std::vector<std::vector<double>> matrix = std::vector<std::vector<double>>(X.size(), std::vector<double>(Y.size()));

    matrix[0][0] = 0;

    for (int i=0; i<X.size(); i++) {
        for (int j=1; j<Y.size(); j++) {
            matrix[i][j] = std::numeric_limits<double>::infinity();
        }
    }

    double cost;
    for (int i=1; i<X.size(); i++) {
        for (int j=1; j<Y.size(); j++) {
            cost = (X[i]-Y[j]) * (X[i]-Y[j]);
            matrix[i][j] = cost + std::min(std::min(matrix[i-1][j], matrix[i][j-1]), matrix[i-1][j-1]);
        }
    }
    return std::sqrt(matrix[X.size()-1][Y.size()-1]);
}

double levenshtein_distance(const std::vector<double> & X, const std::vector<double> & Y) {
    std::vector<std::vector<double>> matrix = std::vector<std::vector<double>>(X.size(), std::vector<double>(Y.size()));

    for (int i=0; i<X.size(); i++) {
        for (int j=0; j<Y.size(); j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i=0; i<X.size(); i++) {
        matrix[i][0] = i;
    }

    for (int j=0; j<Y.size(); j++) {
        matrix[0][j] = j;
    }

    double cost;
    for (int i=1; i<X.size(); i++) {
        for (int j=1; j<Y.size(); j++) {
            if (X[i] == Y[j]) cost = 0;
            else cost = 1;
            matrix[i][j] = std::min(std::min(matrix[i-1][j] + 1, matrix[i][j-1] + 1), matrix[i-1][j-1] + cost);
        }
    }
    return matrix[X.size()-1][Y.size()-1];
}

KNN::KNN(int k, string similarity_measure): k(k) {
    if (similarity_measure == "dtw" || similarity_measure == "euclidean_distance" || similarity_measure == "levenshtein_distance") similarity_measure = similarity_measure;
    else throw std::invalid_argument("This measure is not supported, try dtw, euclidean_distance or levenshtein_distance.");
}

std::vector<int> KNN::findKNearestNeighbors(const std::vector<double>& testInstance, const TimeSeriesDataset& trainData) const {

    double (*func)(const std::vector<double> &, const std::vector<double> &);

    if (this->similarity_measure == "dtw") func = dtw;
    else if (this->similarity_measure == "euclidean_distance") func = euclidean_distance;
    else func = levenshtein_distance;

    std::vector<pair<double, int>> distancesWithLabels;

    // Calculate distances between the test instance and all training instances
    for (size_t i = 0; i < trainData.getData().size(); ++i) {
        double distance = func(testInstance, trainData.getData()[i]);
        distancesWithLabels.emplace_back( distance, trainData.getLabels()[i] );
    }

    // Sort distances in ascending order
    std::sort(distancesWithLabels.begin(), distancesWithLabels.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.first < rhs.first;
    });

    // Extract labels of the k-nearest neighbors
    vector<int> kNearestLabels;
    for (int i = 0; i < k && i < distancesWithLabels.size(); ++i) {
        kNearestLabels.push_back(distancesWithLabels[i].second);
    }

    return kNearestLabels;
}

int KNN::predict(const vector<double> &testInstance, const TimeSeriesDataset &trainData) const {
    vector<int> kNearestLabels = findKNearestNeighbors(testInstance, trainData);

    // Voting to determine the predicted label
    std::unordered_map<int, int> labelCounts;
    for (int label : kNearestLabels) {
        labelCounts[label]++;
    }

    int maxCount = 0;
    int predictedLabel = -1;

    for (const auto& entry : labelCounts) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            predictedLabel = entry.first;
        }
    }

    return predictedLabel;
}

double KNN::evaluate(const TimeSeriesDataset& trainData, const TimeSeriesDataset& testData, const vector<int>& groundTruth) const {
    int correctPredictions = 0;

    for (size_t i = 0; i < testData.getData().size(); ++i) {
        int predictedLabel = predict(testData.getData()[i], trainData);
        int trueLabel = groundTruth[i];

        if (predictedLabel == trueLabel) {
            correctPredictions++;
        }
    }

    // Calculate accuracy
    double accuracy = static_cast<double>(correctPredictions) / testData.getNumberOfSamples();

    return accuracy;
}