#include "FFT.h"

std::vector<std::complex<double>> ditfft2::CooleyTukeyAlgorithm(const std::vector<double> x, double N, int s) {
	const double pi = std::acos(-1); // liczba pi
	const std::complex<double> i(0, 1); // liczba urojona
	std::vector<std::complex<double>> wynik; // zmienna lokalna bêd¹ca wektorem liczb zespolonych typu double
	std::vector<std::complex<double>> ditfft_buf; // bufor
	std::complex<double> t; // zmienna lokalna t bêd¹ca wektorem liczb zespolonych typu double
	std::vector<double> wektor;
		if (N == 1) {
			wynik.push_back(x[0]); // przypadek bazowy trywialnego rozmiaru DFT = 1
		}
		else {

			    wektor.resize(x.size() - s); // zmiana rozmiaru wektora
			    std::copy(x.begin() + s, x.end(), wektor.begin()); // kopiowanie

			    ditfft_buf = CooleyTukeyAlgorithm(x, N / 2, 2 * s); // rekurencja realizowana wedle algorytmu
				wynik.insert(wynik.end(), ditfft_buf.begin(), ditfft_buf.end());

				ditfft_buf = CooleyTukeyAlgorithm(wektor, N / 2, 2 * s); // rekurencja realizowana wedle algorytmu
				wynik.insert(wynik.end(), ditfft_buf.begin(), ditfft_buf.end()); // wpisanie wyników fft do wektora wynik
				
			for (double k = 0; k <= N / 2 - 1; k++) {
				t = wynik[k];
				wynik[k] = t + std::exp(-2 * pi * i * k / N) * wynik[k + N / 2];
				wynik[k + N / 2] = t - std::exp(-2 * pi * i * k / N) * wynik[k + N / 2];
			}
		}
	return wynik;
}