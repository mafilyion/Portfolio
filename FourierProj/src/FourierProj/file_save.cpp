#include "file_save.h"


void save_to_file::saveVector(const std::vector<double> wejscie, const std::string name, int N) {
	std::ofstream file(name + ".csv"); // generacja pliku .csv, o nazwie podanej na wejœciu
	if (!file.is_open()) { throw std::runtime_error("blad zapisu pliku"); } // wykrywanie b³êdów
	for (int i = 0; i < N; i++) {
		file << std::to_string(wejscie[i]) + ";"; // zapisanie wartoœci do pliku, poszczególne wartoœci oddzielone znakiem ";", powoduje to zapis nastêpuj¹cych po sobie wartoœci w nastêpnych kolumnach
	}
	std::cout << "zapis zakonczony" << std::endl;
	wejscie.~vector();
	file.close(); // zamkniêcie pliku
}

void save_to_file::saveVectorComplex(const std::vector<std::complex<double>> wejscie, const std::string name, int N) {
	std::ofstream file(name + ".csv"); // generacja pliku .csv, o nazwie podanej na wejœciu
	if (!file.is_open()) { throw std::runtime_error("blad zapisu pliku"); } // wykrywanie b³êdów
	for (int i = 0; i < N; i++) {
		file << Complex_toString(wejscie[i]) + "\n"; // zamiana liczby zespolonej na string + przejœcie do nastêpnego wiersza
	}
	std::cout << "zapis zakonczony" << std::endl;
	wejscie.~vector();
	file.close(); // zamkniêcie pliku
}