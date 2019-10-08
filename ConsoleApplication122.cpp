#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <random>

typedef std::vector<int> int_vector;
typedef std::map<int, int> int_map;


void Fill(int_map &map, int_vector &vector, unsigned int size)
{
	int low_value = 1;
	int high_value = 9;

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(low_value, high_value);

	for (size_t i = 0; i < size; ++i)
	{
		map.emplace(i, dis(gen));
		vector.push_back(dis(gen));
	}
}

void Print(int_map &map, int_vector &vector)
{
	std::cout << "Map: " << std::endl;
	for (auto &var : map)
	{
		std::cout << "key " << var.first << ") " << var.second << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Vector: " << std::endl;
	for (auto &var : vector)
	{
		std::cout << var << std::endl;
	}
	std::cout << std::endl;

}

void Delete_random_items(int_map &map, int_vector &vector)
{
	int low_value = 1;
	int high_value = 15;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(low_value, high_value);

	int delete_from_map = dis(gen);
	int delete_from_vec = dis(gen);

	for (size_t i = 0; i < delete_from_map; ++i)
	{
		map.erase(i);
	}

	vector.erase(vector.begin(), vector.begin() + delete_from_vec);

}

void Synchronization(int_map &map, int_vector &vector)
{
	std::sort(vector.begin(), vector.end()); //сортируем для бинарного поиска


	bool check = false; // если не найдём элемент, то удалим его

	for (auto i = map.begin(); i != map.end();)
	{
		 int first_index = 0;
	     int avarage_index = 0;
		 int last_index = vector.size() - 1;

		while (true)
		{
			avarage_index = (first_index + last_index) / 2;

			if (i->second < vector[avarage_index])
			{
				last_index = avarage_index - 1;
			}
			else if (i->second > vector[avarage_index])
			{
				first_index = avarage_index + 1;
			}
			else
			{
				check = true;
				break;
			}

			if (first_index > last_index)
			{
				break;
			}
		}

		if (!check)
		{
			i = map.erase(i); //erase возвращает итератор на след.элемент, потому присваем его текущему
		}
		else
		{
			++i;
			check = false;
		}
		
	}


	check = false;
	for (auto i = vector.begin(); i != vector.end();)
	{

		for (auto j = map.begin(); j != map.end(); ++j)
		{
			if (*i == j->second)
			{
				check = true;
				break;
			}

		}

		if (!check)
		{
			i = vector.erase(i);  //erase возвращает итератор на след.элемент, потому присваем его текущему
		}
		else
		{
			++i;
			check = false;
		}

	}

}

int main()
{
	unsigned const int SIZE = 16;  //чтобы остался как минимум 1 элемент в контейнере иначе получим ошибку в синхронизации

	int_map myMap;
	int_vector myVector;

	Fill(myMap, myVector, SIZE);
	Print(myMap, myVector);
	Delete_random_items(myMap, myVector);
	std::cout << "------------------------" << std::endl;
	std::cout << "after Delete_random_items" << std::endl;
	Print(myMap, myVector);
	Synchronization(myMap, myVector);
	std::cout << "------------------------" << std::endl;
	std::cout << "after Synchronization" << std::endl;
	Print(myMap, myVector);
}

