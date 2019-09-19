#include "pch.h"
#include <iostream>

template <typename T>
class Matrix
{
public:

	Matrix();
	void Interface();
	~Matrix();


private:
	
	struct  Node
	{
		Node *next;
		T data;
		unsigned int line;
		unsigned int column;
	};

	Node *head;
	Node *last;

	T **arr; 
	unsigned int sizeL; //line
	unsigned int sizeC; //column


	bool ZeroCheck();
	bool condition; // true is list, false is array
	bool is_first_input;

	void InputMatrix();
	void setMatrix();
	void OutputMatirx();
	void Change();

	void getArray();
	void PushBack(T, unsigned int, unsigned int);

	void cleanList();
	void cleanArray();

};

template<typename T>
Matrix<T>::Matrix()
{
	condition = false;
	head = last = nullptr;
	is_first_input = true;
}

template<typename T>
void Matrix<T>::Interface()
{
	InputMatrix();

	while (true)
	{
		std::cout << "1 - Output" << std::endl;
		std::cout << "2 - Change" << std::endl;
		std::cout << "3 - Exit" << std::endl;

		int x;
		std::cin >> x;
		if (x == 3) { break; }

		switch (x)
		{
		case 1:
			system("cls");
			OutputMatirx();
			break;
		case 2:
			system("cls");
			Change();
			break;
		default:
			system("cls");
			std::cout << "Invalid input, try again" << std::endl;
			break;
		}

	}


}

template<typename T>
Matrix<T>::~Matrix()
{
	if (condition)
	{
		cleanList();
	}
	else
	{
		cleanArray();
	}

}

template<typename T>
bool Matrix<T>::ZeroCheck()
{

	if (condition)
	{
		getArray();
		cleanList();
		ZeroCheck();
	}
	else
	{
		unsigned int counter_of_zero = 0;

		for (size_t i = 0; i < sizeL; ++i)
		{
			for (size_t j = 0; j < sizeC; ++j)
			{
				if (this->arr[i][j] == 0)
				{
					++counter_of_zero;
				}
			}

		}

		return counter_of_zero >= ((sizeL * sizeC) / 2) ? true : false;
	}

}

template<typename T>
void Matrix<T>::InputMatrix()
{
	std::cout << "Enter the number of lines" << std::endl;
	std::cin >> sizeL;
	std::cout << "Enter the number of columns" << std::endl;
	std::cin >> sizeC;
	std::cout << "Start filling the matrix" << std::endl;

	this->arr = new T*[sizeL];
	for (size_t i = 0; i < sizeL; i++)
	{
		arr[i] = new T[sizeC];

	}


	for (size_t i = 0; i < sizeL; i++)
	{
		for (size_t j = 0; j < sizeC; j++)
		{
			std::cin >> this->arr[i][j];
		}
	}

	setMatrix();
}

template<typename T>
void Matrix<T>::setMatrix()
{
	if (ZeroCheck() && condition == false)
	{
		for (size_t i = 0; i < sizeL; i++)
		{
			for (size_t j = 0; j < sizeC; j++)
			{
				this->PushBack(arr[i][j], i, j);

			}

		}

		cleanArray();
		condition = true;
	}
	else if(!is_first_input)
	{
		getArray();
		cleanList();
	}
	else
	{
		is_first_input = false;
	}
	
}

template<typename T>
void Matrix<T>::OutputMatirx()
{
	if (condition)
	{
		std::cout << "Our matrix is a list of nonzero elements" << std::endl;
		Node *temp = head;
		while (temp)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
	else
	{
		std::cout << "Our matrix is a two - dimensional array" << std::endl;
		for (size_t i = 0; i < sizeL; ++i)
		{
			for (size_t j = 0; j < sizeC; ++j)
			{
				std::cout << arr[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}

}

template<typename T>
void Matrix<T>::Change()
{
	
	unsigned int l = 0, c = 0;

	std::cout << "Enter the line number of the element you want to change" << std::endl;
	std::cin >> l;
	std::cout << "Enter the column number of the element you want to change" << std::endl;
	std::cin >> c;

	T temp;
	std::cout << "Enter new value" << std::endl;
	std::cin >> temp;

	getArray();
	this->arr[l][c] = temp;
	

	setMatrix();
}

template<typename T>
void Matrix<T>::getArray()
{
	if (condition)
	{
		this->arr = new T*[sizeL];
		for (size_t i = 0; i < sizeL; i++)
		{
			arr[i] = new T[sizeC];

		}

		for (size_t i = 0; i < sizeL; i++)
		{
			for (size_t j = 0; j < sizeC; j++)
			{
				this->arr[i][j] = 0;
			}
		}

		Node *temp = head;
		while (temp)
		{

			this->arr[temp->line][temp->column] = temp->data;

			temp = temp->next;
		}

		condition = false;
		cleanList();
	}

	
}

template<typename T>
void Matrix<T>::PushBack(T t, unsigned int line, unsigned int column)
{
	if (t == 0)
	{
		return;
	}

	Node *temp = new Node;
	temp->data = t;
	temp->line = line;
	temp->column = column;
	temp->next = nullptr;
	if (head == nullptr)
	{
		head = last = temp;
	}
	else
	{
		last->next = temp;
		last = temp;
	}
}

template<typename T>
void Matrix<T>::cleanList()
{
	while (head)
	{
		Node *temp = head->next;
		delete head;
		head = temp;
	}
}

template<typename T>
void Matrix<T>::cleanArray()
{
	for (size_t i = 0; i < sizeL; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}





int main()
{
	Matrix<int> m;
	m.Interface();
}

