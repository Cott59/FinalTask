#include<fstream>
#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<fstream>

template <typename T>
void memory_mx(T**& pointer, int rows, int cols) {
	pointer = new T * [rows];
	for (int i = 0; i < rows; i++)
		pointer[i] = new T[cols]{};
}
template <typename T>
void clear_mx(T**& pointer, int rows) {
	for (int i = 0; i < rows; i++)
		delete[] pointer[i];
	delete[] pointer;
	pointer = nullptr;
}

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

// вывод массива в консоль
template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << '[';
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

template <typename T>
T* positive(T arr1[], const int length1, T arr2[], const int length2, int& var) {
	T* tmp = new T[length1 + length2];
	var = 0;
	for (int i=0;i<length1;i++)
		if (arr1[i] > 0) 
			tmp[var++] = arr1[i];
	for (int i = 0; i < length2; i++)
		if (arr2[i] > 0)
			tmp[var++] = arr2[i];
		
	T* result = new T[var];
	for (int i = 0; i < var; i++)
		result[i] = tmp[i];

	delete[] tmp;
	return result;

}



bool number_name(int num, std::string file_path) {
	if (num < 10 || num>99)
		return false;

	static const char* tens[]{
		"",
		"двадцать",
		"тридцать",
		"сорок",
		"пятьдесят",
		"шестьдесят",
		"семьдесят",
		"восемьдесят",
		"девяноста"
	};
	static const char* ones[]{
		"",
		" один",
		" два",
		" три",
		" четыре",
		" пять",
		" шесть",
		" семь",
		" восемь",
		" девять"
	};
	static const char* exceps[]{
		"десять",
		"одиннадцать",
		"двенадцать",
		"тринадцать",
		"четырнадцать",
		"пятнадцать",
		"шестнадцать",
		"семнадцать",
		"восемнадцать",
		"девятнадцать",

	};
	int num1 = num / 10;
	int num2 = num % 10;
	std::ofstream file;
	file.open(file_path);
	if (num1 == 1) {
		file << exceps[num2] << '\n';
		file.close();
		return true;

	}

	file << tens[num1 - 2]<< ones[num2]<<'\n'; // 23
	file.close();
	return true;
}



int main() {

	setlocale(LC_ALL, "Ru");
	int n, m;


	//задача 1 двумерный дин массив
	/*
	std::cout << " Введите высоту массива :";
	std::cin >> n;
	std::cout << " Введите ширину массива :";
	std::cin >> m;

	int** mx = nullptr;

	memory_mx(mx, n, m);
	std::cout << " Итоговый массив \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			std::cout << mx[i][j] << '\t';
		std::cout << std::endl;
	}
	clear_mx(mx, n);
	std::cout << '\n';
	*/

	//задача 2  массив положительных элементов
	/*
	std::cout << " Первый массив \n";
	const int size1 = 7, size2 = 6;
	int arr1[size1], arr2[size2];
	fill_arr(arr1, size1, -10, 15);
	fill_arr(arr2, size2, -15, 10);
	print_arr(arr1, size1);
	std::cout << " Второй массив \n";
	print_arr(arr2, size2);

	int size3;
	int* arr3 = positive(arr1, size1, arr2, size2, size3);
	std::cout << " Третий массив \n";
	print_arr(arr3, size3);

	delete[] arr3;
	*/
	//задача 3

	std::cout << " Введите двузначное число -> ";
	std::cin >> n;
	
	if (number_name(n, "number.txt"))
		std::cout << "Число записано в файл \n\n";
	else
		std::cout << "Ошибка \n\n";



	return 0;
}