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
	//searchTester2000();
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
	cout << "asdasd " << key << endl;
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

	cout << "Counter: " << coutner;
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
			return i; // atgriez poziciju, ja arr[i] atgrie� vert�bu
		}
	}

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
	int key = rand() % 100 + 1;
	int times = 2; // cik reizes ies cauri masivam, video aritmetisko
	int step = 1000; // pa cik palielinas +
	int size = 1000;
	cout << "Key: " << key << endl;
	for (int i = 0; i < 10; i++)
	{
		int startTime;
		int totalTime = 0;
		int *array = new int[size];
		

		
		cout << endl << endl << endl;

		for (int k = 0; k < size; k++)
		{
			array[k] = rand() % 10000 + 1;
			//cout << setw(4) << array[k];
		}

		for (int j = 0; j < times; j++)
		{
			startTime = time(NULL); // TODO: Nom�ra s�kuma �trumu	
			search(array, key, size);
			totalTime = totalTime + time(NULL) - startTime;// TODO: Dar�t darb�bu			
		}

		// TODO: Vid�jais �trumus
		cout << "Avarage speed: " << size << "\t" << totalTime / times << endl;

		size = size + step;
	}
}