#ifndef KMEANS_HPP
#define KMEANS_HPP

#include <vector>
#include <random>
#include <math.h>

namespace artificial {
    typedef std::vector<double> vec;
    typedef std::vector<vec> vec2;

    class kmeans {
        public:
            kmeans(int k, int dimension, float init_mean = 0.0, float init_dev = 1.0);
            void fit(const std::vector<vec> &data, int max_iterations);
            void fit_continuous(const std::vector<vec>&data, float learningrate, int iterations);
            int getiterations();
            int getcluster(const vec &data);
            const std::vector<vec>&getcentroids();
            void setcentroid(int id, const vec& centroid);
        
        private:
            int _k, _dimensions;
            float _init_mean, _init_dev;
            int _fit_iterations;
            std::vector<vec> _centroids;
    };
}

#endif