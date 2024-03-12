#include<iostream>
#include<climits>
#include <ctime>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyds(int p[10][10], int n) {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i != j)
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
}

int main() {
    int p[10][10], n, i, j;
    
    cout << "\nEnter the number of vertices: ";
    cin >> n;

    cout << "\nEnter the weight matrix (999 if no edge)\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cin>>  p[i][j];
    }
    clock_t start = clock();
  
    floyds(p, n);

    clock_t end = clock();
    

    cout << "\nTransitive closure:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cout << p[i][j] << "\t";
        cout << "\n";
    }

    double execution_time = double(end - start) / double(CLOCKS_PER_SEC);

    // Display execution time
	cout << "Time taken by function: " << fixed<< execution_time << " seconds" << endl;
    return 0;
}
