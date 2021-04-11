#include <iostream>
#include <fftw3.h>
#include <chrono>
namespace ch = std::chrono;


# define REAL 0
# define IMAG 1
int main() {

    fftw_complex* in, * out;
    fftw_plan p;

    int N = 1024;

    fftw_complex x[1024];
    fftw_complex y[1024];
    for (int j = 0; j < N; j++) {
        x[j][REAL] = j + 1;
        x[j][IMAG] = 0;
    }

    p = fftw_plan_dft_1d(N, x, y, FFTW_FORWARD, FFTW_ESTIMATE);

    
    ch::high_resolution_clock timer;
    auto start = timer.now();
    fftw_execute(p);
    auto end = timer.now();
    auto nsecs = ch::duration_cast<ch::nanoseconds>(end - start).count();
    std::cout << nsecs << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << y[i][REAL] << " " << y[i][IMAG] << std::endl;
    }
    fftw_destroy_plan(p);
	system("pause");
	return 0;
}