#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

int main()
{
	int n = 10;
	int *arr;
	arr = new int[n];

	srand(time(NULL));
	cout << endl << endl << endl;

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 40 + 1;
		cout << setw(4) << arr[i];
	}

	cout << endl << endl << endl;
	int key;
	cout << "Enter the key: ";
	cin >> key;
		
	cout << endl;

	arr[n] = key;

	cout << endl;
	for (int i = 0; i < n; i++)
		cout << setw(4) << arr[i];
	cout << endl;

	int i = 0;
	while (arr[i] != key) i++;
	{
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

	}

	cout << endl;


	system("PAUSE");
	return 0;
}