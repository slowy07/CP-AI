#include "kmeans.hpp"
#include <time.h>
#include <random>

#define CONTINUOUS

#if defined(STANDARD)

int main(int argc, const char *argv[]) {
    srand((int)time(NULL));
    artificial::kemans test(2, 2);
    std::vector<artificial::vec> vecss(6);

    vecs[0] = artificial::vec(2);
	vecs[0][0] = 1.0;
	vecs[0][1] = 1.0;
	
	vecs[1] = artificial::vec(2);
	vecs[1][0] = 2.0;
	vecs[1][1] = 1.0;
	
	vecs[2] = artificial::vec(2);
	vecs[2][0] = 1.0;
	vecs[2][1] = 2.0;
	
	vecs[3] = artificial::vec(2);
	vecs[3][0] = 3+ 1.0;
	vecs[3][1] = 3+ 1.0;
	
	vecs[4] = artificial::vec(2);
	vecs[4][0] = 3+ 2.0;
	vecs[4][1] = 3+ 1.0;
	
	vecs[5] = artificial::vec(2);
	vecs[5][0] = 3+ 1.0;
	vecs[5][1] = 3+ 2.0;

    const int cicles = 3;
    for (int i = 0;  i < cicles; i++) {
        for (int k = 0; k < (int)test.getcentroids().size(); k++) {
            printf("Centroid: %d X:%f Y:%f\n", k, test.getcentroids()[k][0], test.getcentroids()[k][1]);
        }

        std::vector<artificial::vec>ps(1);
        ps[0] = vec[rand() % (int)vecs.size()];
        test.fit_continuous(vecs, 0.1, 1);
    }

    printf("fitted in: %d\n", cicles);

    for (int i = 0; i < (int)vec.size(); i++) {
        printf("Point:%d Cluster:%d\n", i, test.getcluster(vecs[i]));
    }

    return 0;
}

#endif