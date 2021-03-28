#include "file_save.h"


void save_to_file::saveVector(const std::vector<double> wejscie, const std::string name, int N) {
	std::ofstream file(name + ".csv"); // generacja pliku .csv, o nazwie podanej na wej�ciu
	if (!file.is_open()) { throw std::runtime_error("blad zapisu pliku"); } // wykrywanie b��d�w
	for (int i = 0; i < N; i++) {
		file << std::to_string(wejscie[i]) + ";"; // zapisanie warto�ci do pliku, poszczeg�lne warto�ci oddzielone znakiem ";", powoduje to zapis nast�puj�cych po sobie warto�ci w nast�pnych kolumnach
	}
	std::cout << "zapis zakonczony" << std::endl;
	wejscie.~vector();
	file.close(); // zamkni�cie pliku
}

void save_to_file::saveVectorComplex(const std::vector<std::complex<double>> wejscie, const std::string name, int N) {
	std::ofstream file(name + ".csv"); // generacja pliku .csv, o nazwie podanej na wej�ciu
	if (!file.is_open()) { throw std::runtime_error("blad zapisu pliku"); } // wykrywanie b��d�w
	for (int i = 0; i < N; i++) {
		file << Complex_toString(wejscie[i]) + "\n"; // zamiana liczby zespolonej na string + przej�cie do nast�pnego wiersza
	}
	std::cout << "zapis zakonczony" << std::endl;
	wejscie.~vector();
	file.close(); // zamkni�cie pliku
}