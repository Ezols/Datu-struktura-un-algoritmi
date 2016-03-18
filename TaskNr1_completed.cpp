#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void hoareSort(int list[], int left, int right);
void swapItems(int list[], int left, int right);
void searchTester2000();
int search(int arr[], int key, int size);

int main()
{
	searchTester2000();
	// First task
	cout << "First task!";
	
	int i = 0;
	const int n = 10;
	int arr[n] = {};

	//int *arr;
	int coutner = 0;
	//arr = new int[n];


	srand(time(NULL));
	cout << endl << endl << endl;

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 40 + 1;
		cout << setw(4) << arr[i];
	}
	cout << endl;
	cout << "Second task!" << endl << endl;
	// Second task
	int key;
	cout << "Enter the key: ";
	cin >> key;

	cout << endl;
	arr[n] = key;

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << setw(4) << arr[i];
	cout << endl;
	int position = search(arr, key, n);
	if (position >= 0)
		cout << "Element: " << arr[position]
		<< " \t found at position: " << position
		<< " \t counter: " << position + 1
		<< endl;

	else
		cout << "Nothing found" << endl;

	//Third task

	cout << endl << endl;
	cout << "Third task!" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << arr[i];
	}
	cout << endl << endl;
	cout << "arr after quicksort: ";
	cout << endl;

	hoareSort(arr, 0, n);

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << arr[i];
	}
	cout << endl;

	// Binary search
	while (arr[i] != key)
	{
		i++;
		coutner++;
	}
	int j = n - 1; // last element
	int m = (i + j) / 2; // middle element
	while ((i <= j) && (arr[m] != key))
	{
		if (arr[m]>key)
			j = m - 1;

		else i = m + 1;
		m = (i + j) / 2;

	}

	cout << endl;

	cout << endl;
	if (arr[m] == key)
	{
		cout << "Element: " << arr[m]
			<< " \t found at position: " << m
			<< " \t counter: " << m + 1
			<< endl;
	}
	else
	{
		cout << "Not found";
	}

	//Third task ------ end
	cout << endl;


	system("PAUSE");
	return 0;
}

int search(int arr[], int key, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			//cout << "arr[i]: " << arr[i] << "key: " << key << endl;
			return i; // atgriez poziciju, ja arr[i] atgrieþ vertîbu
		}
	}
	cout << "-1 ";
	return -1;
}

void hoareSort(int list[], int left, int right)
{
	if (left < right)
	{
		int boundary = left;
		for (int i = left + 1; i < right; i++)
		{
			if (list[i] < list[left])
			{
				swapItems(list, i, ++boundary);
			}
		}
		swapItems(list, left, boundary);
		hoareSort(list, left, boundary);
		hoareSort(list, boundary + 1, right);
	}
}

void swapItems(int list[], int left, int right)
{
	int tmp = list[left];
	list[left] = list[right];
	list[right] = tmp;
}

void searchTester2000()
{
	srand(time(NULL));
	int key;
	int times = 10; // cik reizes ies cauri masivam, video aritmetisko
	int step = 100; // pa cik palielinas +
	int size = 0;
	float totalCounter2000 = 0;
	float totalCounter2001 = 0;
	int counter;
	
	for (int i = 0; i < 10; i++)
	{
		size = size + step;
		totalCounter2000 = 0;
		int *array = new int[size];

		for (int k = 0; k < size; k++)
		{
			array[k] = rand() % 1000 + 1;
			//cout << setw(4) << array[k] << endl;
		}
		
		for (int j = 0; j < times; j++)
		{
			//key = rand() % size;
			key = array[rand() % size];
			counter = search(array, key, size) + 1;
			cout << counter << "\t";
			totalCounter2000 = totalCounter2000 + counter;		

		}
		cout << totalCounter2000 / times << endl;	
	}
	cout << endl;

	size = 0;
	for (int i = 0; i < 10; i++)
	{
		
		size = size + step;		
		totalCounter2001 = 0;
		int *array = new int[size];

		for (int k = 0; k < size; k++)
		{
			array[k] = rand() % 1000 + 1;
			//cout << setw(4) << array[k] << endl;
		}

		for (int j = 0; j < times; j++)
		{
			hoareSort(array, 0, size);
			key = array[rand() % size];
			counter = search(array, key, size) + 1;
			cout << counter << "\t";
			totalCounter2001 = totalCounter2001 + counter;
		}
		cout << totalCounter2001 / times << endl;


	}

}