#include "kmeans.hpp"
#include <stdlib.h>

namespace artificial {
    kmeans::kmeans(int k, int dimensions, float init_mean, float init_dev) {
        _k = k;
        _dimensions = dimensions;
        _init_mean = init_mean;
        _init_dev = init_dev;

        _centroids = std::vector<vec>(k);
        for (int i = 0; i < k; i++) {
            _centroids[i] = vec(dimensions);
            for (int j = 0; j < _dimensions; j++) {
                _centroids[i][j] = init_mean - init_dev + ((double)rand() / RAND_MAX) * 2 * init_dev;
            }
        }
    }

    void kmeans::fit(const std::vector<vec>&data, int max_iterations) {
        std::vector<int> datavec_clutser(data.size());
        std::vector<int> datavec_clutser_old(data.size());
        bool finished = false;
        bool force_iteration = false;

        for (int q = 0; q < max_iterations; q++) {
            datavec_clutser_old = datavec_clutser;
            for (int d = 0; d < (int)data.size(); d++)
                datavec_clutser[d] = getcluster(data[d]);
            
            if (q != 0 && !force_iteration) {
                finished = true;
                for (int d = 0; d < (int)data.size(); d++) {
                    if (datavec_clutser[d] != datavec_clutser_old[d]) {
                        finished = false;
                        break;
                    }
                }

                if (finished) {
                    _fit_iterations = q;
                    return;
                }
            }
            force_iteration = false;
            int cluster_size = 0;
            vec newcentroid(_dimensions);
            for (int i = 0; i < _k; i++) {
                std::fill(newcentroid.begin(), newcentroid.end(), 0);

                for (int d = 0; d < (int)data.size(); d++) {
                    if (datavec_clutser[d] != i)
                        continue;
                    else
                        cluster_size++;

                    for (int j = 0; j < _dimensions; j++) {
                        newcentroid[j] += data[d][j];
                    }
                }

                if (cluster_size != 0) {
                    for (int j = 0; j < _dimensions; j++) {
                        newcentroid[j]  /= (double)cluster_size;
                    }
                } else {
                    for(int j = 0; j < _dimensions; j++) {
                        newcentroid[j] = _init_mean - _init_dev + ((double)rand() / RAND_MAX) * 2 * _init_dev;
                    }
                    force_iteration = true;
                }
                _centroids[i] = newcentroid;
            }
        }
        _fit_iterations = max_iterations;
    }

    void kmeans::fit_continuous(const std::vector<vec>&data, float learningrate, int iterations) {
        std::vector<int>datavec_clutser(data.size());

        for (int q = 0; q < iterations; q++) {
            for (int d = 0; d < (int)data.size(); d++)
                datavec_clutser[d] = getcluster(data[d]);

            int clutser_size = 0;
            vec newcentroids(_dimensions);
            for (int i = 0; i < _k; i++) {
                std::fill(newcentroids.begin(), newcentroids.end(), 0);

                for (int d = 0; d < (int)data.size(); d++) {
                    if (datavec_clutser[d] != i)
                        continue;
                    else
                        clutser_size++;
                    
                    for (int j = 0; j < _dimensions; j++) {
                        newcentroids[j] += data[d][j];
                    }
                }

                if (clutser_size != 0) {
                    for (int j = 0; j < _dimensions; j++)
                        newcentroids[j] /= (double)clutser_size;
                } else {
                    //TODO
                }

                _centroids[i] = newcentroid;
            }
        }
    }

    int kmeans::getiterations() {
        return _fit_iterations;
    }

    int kmeans::getcluster(const vec &data) {
        double dist;
        double best_dist = 0xFFFFFF;
        int best_clutser = 0;

        for (int i = 0; i < _k; i++) {
            dist = 0.0;
            for (int j = 0; j < _dimensions; j++) {
                dist += pow(data[j] - _centroids[i][j], 2);
            }
            dist = sqrt(dist);

            if (dist < best_dist) {
                best_dist = dist;
                best_clutser = 1;
            }
        }
        return best_clutser;
    }

    const std::vector<vec>&kmeans::getcentroids() {
        return _centroids;
    }

    void kmeans::setcentroid(int id, const vec& centroid) {
        _centroids[id] = centroid;
    }
}
