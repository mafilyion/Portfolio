#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <typeinfo>
#include <complex>
#include <crtdbg.h>

/// <summary>
/// Klasa odpowiedzialna za zapis danych bezposrednio do pliku
/// </summary>
class save_to_file {
public:
	/// <summary>
	/// Funkcja inline, zamieniajaca liczbe zespolona na string'a
	/// </summary>
	std::string Complex_toString(const std::complex<double>& dane) {
		return std::to_string(dane.real()) + ";" + std::to_string(dane.imag());
	}
	/// <summary>
	/// Funkcja zapisujaca dane po IFFT do pliku
	/// </summary>
	void saveVector(const std::vector<double> wejscie, const std::string name, int N);
	/// <summary>
	/// Funkcja zapisujaca dane po FFT do pliku
	/// </summary>
	void saveVectorComplex(const std::vector<std::complex<double>> wejscie, const std::string name, int N);
	~save_to_file() {}
};