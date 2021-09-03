#include <iostream>
#include <vector>
#include <math.h> 

class Knn {
    private:
        double euclidean_distance(std::vector<double> x, std::vector<double> y);
        std::vector <std::vector<double>> get_knn(std::vector <std::vector<double>> x, std::vector<double> y);
        
    public:    
        int neighbours_number;
        //std::vector <std::vector<double> > dataset;
        int predict_class(std::vector <std::vector<double>> dataset, std::vector<double> target);
};