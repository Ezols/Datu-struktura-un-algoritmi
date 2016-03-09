#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void hoareSort(int list[], int left, int right);
void swapItems(int list[], int left, int right);

int main()
{
	// First task
	cout << "First task!";
	int n = 10;
	int i = 0;
	
	int *arr;
	int coutner = 0;
	arr = new int[n];


	srand(time(NULL));
	cout << endl << endl << endl;

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 40 + 1;
		cout << setw(4) << arr[i];
	}

	cout << endl << endl << endl;
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


	while (arr[i] != key) i++;
	{	
		coutner++;	
		cout << endl;
		if (i < n)
		{
			cout << endl;
			cout << "Element: ";
			cout << arr[i];
			cout << " found at position: ";
			cout << i;
		}
		else
		{
			cout << "Not found";
		}
		cout << endl;
		
	}
	cout << "Counter: " << coutner << endl;
	//Third task

	cout << endl << endl;
	cout << "Third task!" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	cout << "arr after quicksort: ";
	cout << endl;

	hoareSort(arr, 0, n);

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
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
		cout << "Element: " << key << " found at position: " << m << endl;
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

