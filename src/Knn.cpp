#include "../include/Knn.h"
#include <algorithm>

bool sort_by_dist(const std::vector<double>& v1, const std::vector<double>& v2);

int Knn::predict_class(std::vector <std::vector<double>> dataset, std::vector<double> target) {
    std::vector <std::vector<double>> distances {};
    int zeros_count {};
    int ones_count {};
    int prediction {};

    distances = this->get_knn(dataset, target);
    for (auto pair: distances) {
        if (pair[1] == 0) {
            zeros_count += 1;
        }
        if (pair[1] == 1) {
            ones_count += 1;
        }
    }

    if (zeros_count > ones_count) {
        prediction = 0;
    } else if (ones_count > zeros_count) {
        prediction = 1;
    } else {
        return -1;
    }

    return prediction;
}

double Knn::euclidean_distance(std::vector<double> x, std::vector<double> y) {
    // the last element of each vector is the label
    double l2 {0.0};
    for (int i = 0; i < x.size()-1; i++) {
        l2 += pow((x[i]-y[i]), 2);
    }
    return sqrt(l2);
}

std::vector <std::vector<double>> Knn::get_knn(std::vector <std::vector<double>> x, std::vector<double> y) {
    std::vector <std::vector<double>> l2_distances {};
    double l2 {0.0};

    for (auto sample: x) {
        if (sample == y) continue; // do not use the same point 
        std::vector <double> neighbour {}; // structure: distance, label
        l2 = this->euclidean_distance(y, sample);
        neighbour.push_back(l2);
        neighbour.push_back(sample[sample.size()-1]);
        l2_distances.push_back(neighbour);
    }

    std::sort(l2_distances.begin(), l2_distances.end(), sort_by_dist);
    std::vector <std::vector<double>> d(l2_distances.begin(), l2_distances.begin() + this->neighbours_number);
    return d;
}

bool sort_by_dist(const std::vector<double>& v1, const std::vector<double>& v2) { 
    return v1[0] < v2[0]; 
}
