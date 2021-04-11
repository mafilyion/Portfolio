#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <vector>
#include <memory>

// Call _CrtDumpMemoryLeaks after main has returned and before program terminates.
struct AtExit
{
	~AtExit() { _CrtDumpMemoryLeaks(); }
} doAtExit;

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "file_read.h"
#include <complex>
#include "file_save.h"
#include "FFT.h"
#include <chrono>
namespace ch = std::chrono;

std::vector<std::complex<double>> metoda_naiwna(std::vector<double> dane_wejsciowe, double rozmiar_danych);
int main(int argc, char *argv[]) {
	std::vector<std::string> pliki_nazwy;
	for (int i = 0; i < argc; i++) {
		pliki_nazwy.push_back(argv[i]);
		if (i > 3) {
			std::cout << "za duza liczba danych wejsciowych" << std::endl;
			exit(EXIT_FAILURE);
		}
	}

	std::vector <double> dane;
	file_read plik; // tworzymy zmienna plik typu file_read
	try { // obsluga wyjatkow
		dane = plik.odczytplik(pliki_nazwy[1]);
	}
	catch (const std::runtime_error& error) { // wylapywanie wyjatkow
		std::cout << error.what(); // obsluga bledu
		exit(EXIT_FAILURE); // zakonczenie dzialania programu z niepowodzeniem
	}
	
	double N = dane.size(); // rozmiar danych jest typu double, bo inaczej nie dziala mno¿enie z liczb¹ zespolona zdefiniowana w dalszej czesci programu
	std::vector<std::complex<double>> wynik;
	//wynik = metoda_naiwna(dane, N);
	std::vector<double> wynikIFFT;
	FFT* fft = new ditfft2(dane, N, 1);
	wynik = fft->fftwektor();
	IFFT ifft(wynik, N);
	wynikIFFT = ifft.IFFTwektor();
	save_to_file vector; // tworzymy zmienn¹ vector typu save_to_file
	save_to_file vectorComplex; // tworzymy zmienn¹ vectorComplex typu save_to_file
	try {
		vectorComplex.saveVector(wynikIFFT, pliki_nazwy[2], N); // zapis wynikow operacji fft do pliku "nazwa1"
		vectorComplex.saveVectorComplex(wynik, pliki_nazwy[3], N); // zapis wynikow operacji fft do pliku "nazwa1"
	}
	catch (const std::runtime_error& error) { // wylapywanie wyj¹tków
		std::cout << error.what(); // wyswietlenie komunikatu bledu
		exit(EXIT_FAILURE); // zakonczenie dzialania aplikacji z niepowodzeniem
	}
	
	// Czyszczenie pamiêci - poni¿ej
	delete fft;
	ifft.~IFFT();
	vectorComplex.~save_to_file();
	dane.~vector();
	wynik.~vector();
	wynikIFFT.~vector();
	//_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}

std::vector<std::complex<double>> metoda_naiwna(std::vector<double> dane_wejsciowe, double rozmiar_danych) {
	const double pi = std::acos(-1); // liczba pi
	const std::complex<double> c(0, 1); // liczba urojona
	std::complex<double> omega;
	omega = std::exp(2 * pi * c / rozmiar_danych);
	std::vector<std::vector<std::complex<double>>> macierz;
	std::vector<std::complex<double>> wiersz;

	for (double k = 0; k < rozmiar_danych; k++) {
		for (double z = 0; z < rozmiar_danych; z++) {
			wiersz.push_back(std::pow(omega, z * k));
		}
		macierz.push_back(wiersz);
		wiersz.clear();
	}

	// mnozenie macierzy
	std::vector<std::complex<double>> wynik;
	for (int i = 0; i < rozmiar_danych; i++)
	{
		wynik.push_back(0);
		for (int j = 0; j < rozmiar_danych; j++)
		{
			wynik[i] += dane_wejsciowe[j] * macierz[i][j];
		}
	}

    return wynik;
}