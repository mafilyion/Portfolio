#pragma once
#include <iostream>
#include <vector>
#include <complex>

/// <summary>
/// Klasa bazowa FFT
/// </summary>
class FFT {
protected:
	std::vector<double> dane_wejsciowe;
	/// <summary>
	/// Rozmiar danych wejsciowych
	/// </summary>
	double N;
	/// <summary>
	/// Krok
	/// </summary>
	int s;

public:
	FFT() : dane_wejsciowe(0), N(0), s(0) {};
	FFT(std::vector<double> data, double rozmiar, int s) : dane_wejsciowe(data), N(rozmiar), s(s) {};
	/// <summary>
	/// Metoda wirtualna zwracajaca pusty wektor liczb zespolonych tyu double
	/// </summary>
	/// <returns></returns>
	virtual std::vector<std::complex<double>> fftwektor() {
		std::vector<std::complex<double>> wektor_complex;
		wektor_complex.clear(); return wektor_complex;
	}
	/// <summary>
	/// Metoda wirtualna zwracajaca pusty wektor liczb typu double
	/// </summary>
	/// <returns></returns>
	virtual std::vector<double> IFFTwektor() {
		std::vector<double> wektor;
		wektor.clear(); return wektor;
	}
	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~FFT() {};
};

/// <summary>
/// Klasa ditfft2 dziedziczaca publicznie po FFT odpowiedzialna jest za wyliczenie FFT
/// </summary>
class ditfft2 : public FFT {
public:
	ditfft2() : FFT() {};
	ditfft2(std::vector<double> insert, double ilosc_danych, int s) : FFT(insert, ilosc_danych, s) {};
	/// <summary>
	/// Funkcja realizujaca algorytm Cooley'a Tukey'a do wyliczenia FFT
	/// </summary>
	/// <returns></returns>
	/// Zwraca wynik w postaci wektora liczb zespolonych typu double
	std::vector<std::complex<double>> CooleyTukeyAlgorithm(const std::vector<double> x, double N, int s);
	/// <summary>
	/// Metoda przeciazajaca metode wirtualna w klasie FFT, sluzy do wyliczenie FFT
	/// </summary>
	std::vector<std::complex<double>> fftwektor() override { return CooleyTukeyAlgorithm(dane_wejsciowe, N, s); }
	~ditfft2() {}
	// destruktor domyœlny, to destruktor klasy bazowej FFT
};

/// <summary>
/// Klasa IFFT dziedziczaca publicznie po FFT odpowiedzialna jest za obliczenie odwrotnej transformacji fouriera
/// </summary>
class IFFT : public FFT {
private:
	/// <summary>
	/// Dane w postaci sygnalu po FFT
	/// </summary>
	std::vector<std::complex<double>> dane;
	/// <summary>
	/// Rozmiar danych
	/// </summary>
	double N;

public:
	IFFT() : dane(0), N(0) {};
	IFFT(std::vector<std::complex<double>>dane_wejsciowe, double rozmiar) : dane(dane_wejsciowe), N(rozmiar) {}
	/// <summary>
	/// Funkcja odpowiedzialna za obliczenie IFFT
	/// </summary>
	std::vector<double> IFFTwyliczenie(double N, const std::vector<std::complex<double>> dane);
	/// <summary>
	/// Metoda przeciazajaca metode wirtualna w klasie FFT, sluzy do wyliczenie IFFT
	/// </summary>
	/// <returns></returns>
	std::vector<double> IFFTwektor() override { return IFFTwyliczenie(N, dane); }
	~IFFT() {};
};