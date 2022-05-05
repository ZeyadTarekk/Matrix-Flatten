#include<iostream>
using namespace std;

int main() {
	int n, m, p, q, y;
	cout << "Enter the dimensions of the 3D Matrix: ";
	cin >> n >> m >> p;
	q = n * m * p;
	int*** arr3D;
	int* arr1D;
	arr1D = new int[q];
	arr3D = new int** [n];
	// First allocation of the space for the 3D matrix this is O(n*m)
	for (int i = 0; i < n; i++) {
		arr3D[i] = new int* [m];

		for (int j = 0; j < m; j++)
			arr3D[i][j] = new int[p];
	}
	cout << "Enter " << q << " Elements: ";
	
	// Here taking the elements from the user and this is O(n*m*p)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < p; k++)
				cin >> arr3D[i][j][k];

	// Here looping through the 3D array to copy its elements to the 1D array
	// this is also O(n*m*p) but the indexing from 3D to 1D is only O(1)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < p; k++) {
				y = i * m * p + j * p + k;
				arr1D[y] = arr3D[i][j][k];
				cout << arr1D[y] << " ";
				//cout << i << " " << j << " " << k << " => " << y << endl;
			}
			cout << endl;
		}
		cout << endl;
	}

}