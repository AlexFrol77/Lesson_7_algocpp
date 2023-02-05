#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>

int** creator_arr_graf(int size_arr) {
	int** arr_graf;
	arr_graf = new int*[size_arr];
	for (int i = 0; i < size_arr; i++) {
		arr_graf[i] = new int[size_arr];
	}
	return arr_graf;
}

void dfs(int **arr_graf, std::vector <int> &vec_vertex, int size_arr, int &vertex) {
	if (size_arr != vec_vertex.size()) {
		for (int i = 0; i < size_arr; i++) {
			if (arr_graf[vertex - 1][i] == 1) {
				if (find(vec_vertex.begin(), vec_vertex.end(), (i + 1)) != vec_vertex.end()) {
					continue;
				}
				else {
					vec_vertex.push_back(i + 1);
					vertex = i + 1;
					dfs(arr_graf, vec_vertex, size_arr, vertex);
				}
			}
		}
	}
}

void print_arr_graf(int** arr_graf, int size_arr) {
	std::cout << "Вершина " << size_arr << std::endl;
	for (int i = 0; i < size_arr; i++) {
		for (int j = 0; j < size_arr; j++) {
			std::cout << arr_graf[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void print_vec_vertex(std::vector <int> vec_result) {
	std::cout << std::endl;
	std::cout << "Порядок обхода вершин: ";
	for (int i : vec_result) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size_arr,
		  vertex;
	int** arr_graf;

	std::ifstream in_num("input.txt");

	in_num >> size_arr;
	vertex = size_arr;
	std::vector <int> vec_vertex;

	arr_graf = creator_arr_graf(size_arr);
	if (!(in_num.is_open())) {
		std::cout << "Фвйл не открылся!" << std::endl;
		return -1;
	}
	else {
		for (int i = 0; i < size_arr; i++) {
			for (int j = 0; j < size_arr; j++) {
				in_num >> arr_graf[i][j];
			}
		}
	}
	in_num.close();

	print_arr_graf(arr_graf, size_arr);
	dfs(arr_graf, vec_vertex, size_arr, vertex);
	print_vec_vertex(vec_vertex);
	
	return 0;
}