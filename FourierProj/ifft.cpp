#include "FFT.h"

std::vector<double> IFFT::IFFTwyliczenie(double N, const std::vector<std::complex<double>> dane) {
	const double pi = std::acos(-1); // liczba pi
	const std::complex<double> i(0, 1); // liczba urojona
	std::vector<std::complex<double>> wyniki;
	std::vector<double> koniec;
	std::complex<double> suma(0,0); // suma musi byc liczb¹ zespolon¹
	// realizacja IFFT zgodnie ze wzorem zawartym w sprawozdaniu
	for (double j = 0; j < N; j++) {
		for (double k = 0; k <= N - 1; k++) {
			suma = suma + (std::conj(dane[k]) * std::exp((-2 * pi * i * k * j) / N));
		}
		wyniki.push_back((1 / N) * std::conj(suma));
		koniec.push_back(wyniki[j].real());
		suma = 0; // suma jest zerowana
	}
	wyniki.~vector();
	return koniec;
}