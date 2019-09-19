#include <iostream>
#include <algorithm>
#include <ctime>

template <typename T>
class Complex
{
public:

	void Bubble_Sort(T*, unsigned int);
	void Bubble_Sort(T**, unsigned int, unsigned int);
	void Bubble_Sort(T***, unsigned int, unsigned int, unsigned int);
	void Selection_Sort(T*, unsigned int);
	void Selection_Sort(T**, unsigned int, unsigned int);
	void Insertion_Sort(T*, unsigned int);
	void Insertion_Sort(T**, unsigned int, unsigned int);
	void Shell_Sort(T*, unsigned int); 
	void Comb_Sort(T*, unsigned int);
	void Bozo_Sort(T*, unsigned int);
	void Bozo_Sort(T**, unsigned int, unsigned int);
	void Bogo_Sort(T*, unsigned int);
	void Bogo_Sort(T**, unsigned int, unsigned int);

	void Flip_Line(T*, unsigned int);
	void Flip_Line(T**, unsigned int, unsigned int);
	void Flip_Column(T**, unsigned int, unsigned int);
	void Flip_Line_Column(T**, unsigned int, unsigned int);


	void Print_Array(T*, unsigned int);
	void Print_Array(T**, unsigned int, unsigned int);
	void Print_Array(T***, unsigned int, unsigned int, unsigned int);
	

	bool Is_Sorted(T*, unsigned int);
	bool Is_Sorted(T**, unsigned int, unsigned int);
	bool Is_Sorted(T***, unsigned int, unsigned int, unsigned int);

	T Get_Min(T*, unsigned int);
	T Get_Min(T**, unsigned int, unsigned int);
	T Get_Min(T***, unsigned int, unsigned int, unsigned int);
	T Get_Max(T*, unsigned int);
	T Get_Max(T**, unsigned int, unsigned int);
	T Get_Max(T***, unsigned int, unsigned int, unsigned int);

	unsigned int Binary_Search(T*, unsigned int, T); // return index of value


	bool Is_number_perfect(unsigned long long int);


private:
	T Sum_of_Array(T*, T);
};

template<typename T>
void Complex<T>::Bubble_Sort(T *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		for (unsigned int j = 0; j < size - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}

		}
	}

}

template<typename T>
void Complex<T>::Bubble_Sort(T **arr, unsigned int line, unsigned int column)
{
	
	for (unsigned int i = 0; i < line*column; ++i)
	{
		for (unsigned int j = 0; j < line; ++j)
		{
			for (unsigned int k = 0; k < column; ++k)
			{
				if (j != line - 1 && k == column - 1)
				{
					if (arr[j][k] > arr[j + 1][0])
					{
						std::swap(arr[j][k], arr[j + 1][0]);
					}

				}
				else if (j == line - 1 && k == column - 1) { break; }
				else if (arr[j][k] > arr[j][k + 1])
				{
					std::swap(arr[j][k], arr[j][k + 1]);
					
				}

			}
		}
	}
	
}

template<typename T>
void Complex<T>::Bubble_Sort(T ***arr, unsigned int size_1, unsigned int size_2, unsigned int size_3)
{
	for (unsigned int i = 0; i < size_1*size_2*size_3; ++i)
	{
		for (unsigned int j = 0; j < size_1; ++j)
		{
			for (unsigned int k = 0; k < size_2; ++k)
			{
				for (unsigned int l = 0; l < size_3; ++l)
				{
					if (j != size_1 - 1 && k == size_2 - 1 && l == size_3 - 1)
					{
						if(arr[j][k][l]>arr[j+1][0][0])
						{
							std::swap(arr[j][k][l], arr[j + 1][0][0]);
						}
					}
					else if (k != size_2 - 1 && l == size_3 - 1)
					{
						if (arr[j][k][l] > arr[j][k + 1][0])
						{
							std::swap(arr[j][k][l], arr[j][k + 1][0]);
						}
					}
					else if (j == size_1 - 1 && k == size_2 - 1 && l == size_3 - 1) { break; }
					else if (arr[j][k][l] > arr[j][k][l + 1])
					{
						std::swap(arr[j][k][l], arr[j][k][l + 1]);
					}
				}
			}
		}
	}


}

template<typename T>
void Complex<T>::Selection_Sort(T *arr, unsigned int size)
{

	for (unsigned int i = 0; i < size; ++i)
	{
		T min = arr[i];
		unsigned int number_of_min = i;

		for (unsigned int j = i + 1; j < size; ++j)
		{
			if (min > arr[j])
			{
				min = arr[j];
				number_of_min = j;
			}
		}

		std::swap(arr[number_of_min], arr[i]);

	}

}

template<class T>
void  Complex<T>::Selection_Sort(T** arr, unsigned int line, unsigned int column)
{
	for (unsigned int i = 0; i < line; ++i)
	{
		for (unsigned int j = 0; j < column; ++j)
		{
			T min = arr[i][j];
			unsigned int number_of_first = i;
			unsigned int number_of_second = j;
			unsigned int k = i;
			unsigned int l = j;

			for (; k < line; ++k)
			{
				for (; l < column; ++l)
				{
					if (min > arr[k][l])
					{
						min = arr[k][l];
						number_of_first = k;
						number_of_second = l;
					}

					if (l == column - 1)
					{
						l = 0;
						break;
			
					}

				}

			}

			std::swap(arr[i][j], arr[number_of_first][number_of_second]);
		}
	}
}

template<typename T>
void Complex<T>::Insertion_Sort(T *arr, unsigned int size)
{
	for (unsigned int i = 1; i < size; ++i)
	{
		unsigned int j = i;

		while (arr[j] < arr[j - 1] && j != 0)
		{
			std::swap(arr[j], arr[j - 1]);
			j--;
		}

	}

}

template<typename T>
void Complex<T>::Insertion_Sort(T **arr, unsigned int line, unsigned int column)
{
	for (unsigned int i = 0; i < line; ++i)
	{
		for (unsigned int j = 0; j < column; ++j)
		{
			label:

			if (i == 0 && j == 0)
			{
				j = 1;
			}

			if (j != 0)
			{

				while (arr[i][j] < arr[i][j - 1])
				{
					std::swap(arr[i][j], arr[i][j - 1]);
					--j;

					if (j == 0)
					{
						break;
					}
				}
			}

			if (i != 0 && j == 0)
			{

				if(arr[i][j] < arr[i - 1][column - 1])
				{
					std::swap(arr[i][j], arr[i - 1][column - 1]);
					j = column - 1;
					--i;
					goto label;
				}
			}

		}

	}


}

template<typename T>
void Complex<T>::Shell_Sort(T *arr, unsigned int size)
{
	for (unsigned int i = size / 2; i > 0; i /= 2)
	{
		for (unsigned int j = i; j < size; ++j)
		{
			for (unsigned int k = j - i; arr[k] > arr[k + i] && k >= 0; k -= i)
			{
				std::swap(arr[k], arr[k + i]);
			}

		}
	}

	
}

template<typename T>
void Complex<T>::Comb_Sort(T *arr, unsigned int size)
{
	double fakt = 1.2473309;

	for (unsigned int i = size - 1; i >= 1; i /= fakt)
	{
		for (unsigned int j = 0; j + i < size; ++j)
		{
			if (arr[j] > arr[j + i])
			{
				std::swap(arr[j], arr[j + i]);
			}

		}
	}

	this->Bubble_Sort(arr, size);

}

template<typename T>
void Complex<T>::Bozo_Sort(T *arr, unsigned int size)
{
	unsigned int i = 0;
	unsigned int j = 0;

	do
	{
		i = rand() % size;
		j = rand() % size;

		while (i == j && size != 1)
		{
			i = rand() % size;
			j = rand() % size;
		}
	

		std::swap(arr[i], arr[j]);

	} while (!this->Is_Sorted(arr, size));

}

template<typename T>
void Complex<T>::Bozo_Sort(T **arr, unsigned int line, unsigned int column)
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int k = 0;
	unsigned int l = 0;

	do
	{
		i = rand() % line;
		j = rand() % column;

		k = rand() % line;
		l = rand() % column;

		while (i == k && j == l && (line != 1 || column != 1))
		{
			i = rand() % line;
			j = rand() % column;

			k = rand() % line;
			l = rand() % column;

		}

		std::swap(arr[i][j], arr[k][l]);

	} while (!this->Is_Sorted(arr, line, column));

}

template<typename T>
void Complex<T>::Bogo_Sort(T *arr, unsigned int size)
{
	do
	{
		unsigned int index_for_swap = 0;

		for (unsigned int i = 0; i < size; ++i)
		{
			index_for_swap = rand() % size;

			while (i == index_for_swap && size != 1 && size != 2)
			{
				index_for_swap = rand() % size;
			}

			std::swap(arr[i], arr[index_for_swap]);
		}

	} while (!this->Is_Sorted(arr, size));


}

template<typename T>
void Complex<T>::Bogo_Sort(T **arr, unsigned int line, unsigned int column)
{
	do
	{
		unsigned int number_of_first = 0;
		unsigned int number_of_second = 0;

		for (unsigned int i = 0; i < line; ++i)
		{
			for (unsigned int j = 0; j < column; ++j)
			{
				number_of_first = rand() % line;
				number_of_second = rand() % column;

				while (i == number_of_first && j == number_of_second && line > 2 && column > 2)
				{
					number_of_first = rand() % line;
					number_of_second = rand() % column;
				}


				std::swap(arr[i][j], arr[number_of_first][number_of_second]);

			}
		}
	} while (!this->Is_Sorted(arr, line, column));


}

template<typename T>
void Complex<T>::Flip_Line(T *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size/2; ++i)
	{
		std::swap(arr[i], arr[size - i - 1]);
	}

}

template<typename T>
void Complex<T>::Flip_Line(T **arr, unsigned int line, unsigned int column)
{
	for (unsigned int i = 0; i < line / 2; ++i)
	{
		for (unsigned int j = 0; j < column; ++j)
		{
			std::swap(arr[i][j], arr[line - i - 1][j]);
		}

	}

}

template<typename T>
void Complex<T>::Flip_Column(T **arr, unsigned int line, unsigned int column)
{
	for (unsigned int i = 0; i < line; ++i)
	{
		for (unsigned int j = 0; j < column / 2; ++j)
		{
			std::swap(arr[i][j], arr[i][column - 1 - j]);
		}

	}

}

template<typename T>
void Complex<T>::Flip_Line_Column(T **arr, unsigned int line, unsigned int column)
{
	this->Flip_Column(arr, line, column);
	this->Flip_Line(arr, line, column);

}

template<typename T>
void Complex<T>::Print_Array(T *arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;

}

template<typename T>
void Complex<T>::Print_Array(T **arr, unsigned int line, unsigned int column)
{
	for (unsigned int i = 0; i < line; ++i)
	{
		for (unsigned int j = 0; j < column; ++j)
		{

			std::cout << arr[i][j] << "\t";
		}

		std::cout << std::endl;
	}

}

template<typename T>
void Complex<T>::Print_Array(T ***arr, unsigned int size_1, unsigned int size_2, unsigned int size_3)
{
	for (int i = 0; i < size_1; ++i)
	{
		for (int j = 0; j < size_2; ++j)
		{
			for (int k = 0; k < size_3; ++k)
			{

				std::cout << arr[i][j][k] << "\t";



			}
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

}

template<typename T>
bool Complex<T>::Is_Sorted(T * arr, unsigned int size)
{
	for (unsigned int i = 0; i < size - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}

	return true;
}

template<typename T>
bool Complex<T>::Is_Sorted(T **arr, unsigned int line, unsigned int column)
{
	for (unsigned int i = 0; i < line; ++i)
	{
		
		for (unsigned int j = 0; j < column; ++j)
		{
			if (j == column - 1 && i != line - 1)
			{
				if (arr[i][j] > arr[i + 1][0])
				{
					return false;
				}

			}
			else if (i == line - 1 && j == column - 1) { break; }
			else if (arr[i][j] > arr[i][j + 1])
			{
				return false;
			}


		}
	}

	return true;

}

template<typename T>
bool Complex<T>::Is_Sorted(T ***arr, unsigned int size_1, unsigned int size_2, unsigned int size_3)
{

	for (int i = 0; i < size_1; ++i)
	{
		for (int j = 0; j < size_2; ++j)
		{
			for (int k = 0; k < size_3; ++k)
			{

				if (i != size_1 - 1 && j == size_2 - 1 && k == size_3 - 1)
				{
					if (arr[i][j][k] > arr[i + 1][0][0])
					{
						return false;
					}

					
				}
				else if (j != size_2 - 1 && k == size_3 - 1)
				{
					if (arr[i][j][k] > arr[i][j + 1][0])
					{
						return false;
					}

				}
				else if (i == size_1 - 1 && j == size_2 - 1 && k == size_3 - 1) { break; }
				else if(arr[i][j][k] > arr[i][j][k + 1])
				{
					return false;
				}

			}
		}
	}

	return true;
}

template<typename T>
T Complex<T>::Get_Min(T *arr, unsigned int size)
{
	T min = arr[0];

	for (unsigned int i = 1; i < size; ++i)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}

	return min;
}

template<typename T>
T Complex<T>::Get_Min(T **arr, unsigned int line, unsigned int column)
{
	T min = arr[0][0];

	for (unsigned int i = 0; i < line; ++i)
	{
		for (unsigned int j = 0; j < column; ++j)
		{
			if (i == 0 && j == 0) { break; }

			if (min > arr[i][j])
			{
				min = arr[i][j];
			}
		}
	}

	return min;
}

template<typename T>
T Complex<T>::Get_Min(T ***arr, unsigned int size_1, unsigned int size_2, unsigned int size_3)
{
	T min = arr[0][0][0];

	for (unsigned int i = 0; i < size_1; ++i)
	{
		for (unsigned int j = 0; j < size_2; ++j)
		{
			for (unsigned int k = 0; k < size_3; ++k)
			{
				if (i == 0 && j == 0 && k == 0) { break; }

				if (min > arr[i][j][k])
				{
					min = arr[i][j][k];
				}
			}
		}
	}




	return min;
}

template<typename T>
T Complex<T>::Get_Max(T *arr, unsigned int size)
{
	T max = arr[0];

	for (unsigned int i = 0; i < size; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	return max;
}

template<typename T>
T Complex<T>::Get_Max(T **arr, unsigned int line, unsigned int column)
{
	T max = arr[0][0];

	for (unsigned int i = 0; i < line; ++i)
	{
		for (unsigned int j = 0; j < column; ++j)
		{
			if (i == 0 && j == 0) { break; }

			if (max < arr[i][j])
			{
				max = arr[i][j];
			}
		}
	}

	return max;
}

template<typename T>
T Complex<T>::Get_Max(T ***arr, unsigned int size_1, unsigned int size_2, unsigned int size_3)
{

	T max = arr[0][0][0];

	for (unsigned int i = 0; i < size_1; ++i)
	{
		for (unsigned int j = 0; j < size_2; ++j)
		{
			for (unsigned int k = 0; k < size_3; ++k)
			{
				if (i == 0 && j == 0 && k == 0) { break; }

				if (max < arr[i][j][k])
				{
					max = arr[i][j][k];
				}
			}
		}
	}

	return max;
}

template<typename T>
T Complex<T>::Sum_of_Array(T *arr, T size)
{
	T sum = 0;

	for (T i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	return sum;
}

template<typename T>
unsigned int Complex<T>::Binary_Search(T *arr, unsigned int size, T search_value)
{
	if (!this->Is_Sorted(arr, size) || size == 0)
	{
		std::abort();
	}

	unsigned int first_index = 0;
	unsigned int avarage_index = 0;
	unsigned int last_index = size - 1;

	while (true)
	{
		avarage_index = (first_index + last_index) / 2;

		if (search_value < arr[avarage_index])
		{
			last_index = avarage_index - 1;
		}
		else if(search_value > arr[avarage_index])
		{
			first_index = avarage_index + 1;
		}
		else
		{
			return avarage_index;
		}

		if (first_index > last_index)
		{
			std::abort();
		}
	}

}

template<typename T> 
bool Complex<T>::Is_number_perfect(unsigned long long int value)
{
	unsigned long long  int size = 0;
	unsigned long long int *arr = (unsigned long long int*)malloc(size * sizeof(unsigned long long int));

	for (unsigned long long int i = value - 1; i > 0; --i)
	{
		if (value % i == 0)
		{
			++size;
			arr = (unsigned long long int*)realloc(arr, size * sizeof(unsigned long long int));
			arr[size - 1] = i;
		}

	}

	Complex<unsigned long long int> c;

	std::cout << c.Sum_of_Array(arr, size) << std::endl;

	if (value == c.Sum_of_Array(arr, size))
	{
		free(arr);
		return true;
	}
	else
	{
		free(arr);
		return false;
	}

}


int main()
{

}

