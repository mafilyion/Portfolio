#include "file_read.h"

std::vector<double> file_read::odczytplik(const std::string nazwa) {
	file.open(nazwa, std::ios::in); //std::ios::in otwiera plik tylko do odczytu
	if (!file.is_open()) { throw std::runtime_error("blad otwarcia pliku"); } //Obs�uga b��d�w
	std::string buffor; // tworz� jaki� tymczasowy bufor
	std::vector<std::string> dane; // tymczasowy wektor string�w przechowuj�cy to co siedzi w pliku .csv
	while (std::getline(file, buffor, ';')) { // pobieranie kolejnych linii tego co tam siedzi w tym pliku
		dane.push_back(buffor); // dodawanie tego do wektora dane
	}

	std::vector<double> wyniki; // tworz� wektor liczb typu double, kt�ry w dalszej cz�ci programu b�dzie przechowywa� wynik operacji zamiany stringa na double'a
	if (ceil(log2(dane.size())) != floor(log2(dane.size()))) { throw std::range_error("rozmiar danych nie jest potega 2-ki"); } // je�eli rozmiar wektora, czyli ilo�� danych wej�ciowych jest r�wna jakiej� pot�dze dw�jki to niech se tam program dzia�a
	for (size_t i = 0; i < dane.size(); i++) {
		// tutaj nast�puje zamiana string na double
		std::istringstream iss(dane[i]); // strumie� danych, kt�rego argumentem jest poszczeg�lna kom�rka naszego pliku z sygna�em wej�ciowym
		double instances;
		iss >> instances;
		wyniki.push_back(instances); 
	}
	file.close();
	return wyniki;
}