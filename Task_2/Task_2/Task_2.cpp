#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

int** creator_arr_graf(int size_arr) {
	int** arr_graf;
	arr_graf = new int* [size_arr];
	for (int i = 0; i < size_arr; i++) {
		arr_graf[i] = new int[size_arr];
	}
	return arr_graf;
}

void print_arr_graf(int** arr_graf, int size_arr) {
	std::cout << std::endl;
	for (int i = 0; i < size_arr; i++) {
		for (int j = 0; j < size_arr; j++) {
			std::cout << arr_graf[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void print_vertex(std::vector <int> vec_vertex) {
	for (int i : vec_vertex) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void bfs(int** arr_graf, std::vector <int>& vec_vertex, int size_arr, int& vertex) {
	if (vec_vertex.size() != size_arr) {
		for (int i = 0; i < size_arr; i++) {
			if (arr_graf[vertex - 1][i] == 1) {
				if (!(find(vec_vertex.begin(), vec_vertex.end(), (i + 1)) != vec_vertex.end())) {
					vec_vertex.push_back(i + 1);
				}
			}
		}
		vertex = vec_vertex.back();
		bfs(arr_graf, vec_vertex, size_arr, vertex);
	}
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size_arr;
	int** arr_graf;
	int vertex;
	std::vector <int> vec_vertex;

	std::fstream in_txt("input.txt");
	if (!(in_txt.is_open())) {
		std::cout << "Файл не открылся!" << std::endl;
		return -1;
	}
	else {
		in_txt >> size_arr;
		arr_graf = creator_arr_graf(size_arr);
		for (int i = 0; i < size_arr; i++) {
			for (int j = 0; j < size_arr; j++) {
				in_txt >> arr_graf[i][j];
			}
		}
	}

	std::cout << "В графе 7 вершин. Введите номер вершины, с которой начнётся обход: ";
	std::cin >> vertex;
	vec_vertex.push_back(vertex);
	print_arr_graf(arr_graf, size_arr);
	bfs(arr_graf, vec_vertex, size_arr, vertex);
	print_vertex(vec_vertex);

	return 0;
}


