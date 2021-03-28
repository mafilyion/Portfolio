#include "file_read.h"

std::vector<double> file_read::odczytplik(const std::string nazwa) {
	file.open(nazwa, std::ios::in); //std::ios::in otwiera plik tylko do odczytu
	if (!file.is_open()) { throw std::runtime_error("blad otwarcia pliku"); } //Obs³uga b³êdów
	std::string buffor; // tworzê jakiœ tymczasowy bufor
	std::vector<std::string> dane; // tymczasowy wektor stringów przechowuj¹cy to co siedzi w pliku .csv
	while (std::getline(file, buffor, ';')) { // pobieranie kolejnych linii tego co tam siedzi w tym pliku
		dane.push_back(buffor); // dodawanie tego do wektora dane
	}

	std::vector<double> wyniki; // tworzê wektor liczb typu double, który w dalszej czêœci programu bêdzie przechowywa³ wynik operacji zamiany stringa na double'a
	if (ceil(log2(dane.size())) != floor(log2(dane.size()))) { throw std::range_error("rozmiar danych nie jest potega 2-ki"); } // je¿eli rozmiar wektora, czyli iloœæ danych wejœciowych jest równa jakiejœ potêdze dwójki to niech se tam program dzia³a
	for (size_t i = 0; i < dane.size(); i++) {
		// tutaj nastêpuje zamiana string na double
		std::istringstream iss(dane[i]); // strumieñ danych, którego argumentem jest poszczególna komórka naszego pliku z sygna³em wejœciowym
		double instances;
		iss >> instances;
		wyniki.push_back(instances); 
	}
	file.close();
	return wyniki;
}