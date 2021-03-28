#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <crtdbg.h>

/// <summary>
/// Klasa odpowiedzialna za odczyt danych z pliku z rozszerzeniem .csv
/// </summary>
class file_read {
private:
	std::fstream file; // Plik

public:
	file_read() : file() {}; // bezargumentowy konstruktor
	/// <summary>
	/// Funkcja odczytujaca dane z pliku
	/// </summary>
	/// <returns></returns>
	/// dane w postaci wektora liczb typu double
	std::vector<double> odczytplik(const std::string nazwa); //funkcja zwracaj¹ca wektor liczb typu double
	~file_read() {}; // destruktor
};