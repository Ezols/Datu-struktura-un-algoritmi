#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;
void quickSort(int arr[], int p, int r);



int main()
{

	cout << "First task!";
	int n = 100;
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
	// Otrais uzd
	int key;
	cout << "Enter the key: ";
	cin >> key;
	while (arr[i] != key)
	{
		i++;
		coutner++;
	}
	cout << endl;

	arr[n] = key;

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << setw(4) << arr[i];
	cout << endl;


	while (arr[i] != key) i++;
	{
		//coutner++;
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
		cout << "Counter: " << coutner << endl;
	}

	//uzd 3 ------ start
	//int arr2[10] = { 2, 30, 1, 99, 46, 33, 48, 67, 23, 76 };

	cout << endl << endl;
	cout << "Third task!" << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	cout << "arr after quicksort: ";
	cout << endl;

	quickSort(arr, 0, 9);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}



	//uzd 3 ------ end
	cout << endl;


	system("PAUSE");
	return 0;
}

int hoare_partition(int arr[], int p, int r){
	int x = arr[p];
	int i = p - 1;
	int j = r + 1;
	while (true){
		do{
			j--;
		} while (arr[j] > x);
		do{
			i++;
		} while (arr[i] < x);
		if (i < j){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
		else
			return j;
	}
}

void quickSort(int arr[], int p, int r){
	if (p < r){
		int q = hoare_partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}