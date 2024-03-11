#include <iostream>
using namespace std;

int min, cost[100][100], parent[100], i, j, x, y, n;

void find_min();
int find_set(int i);
void union_sets(int i, int j);

int main() {
    int count = 0, tot = 0, flag = 0;

    cout << "Enter the number of vertices" << endl;
    cin >> n;

    cout << "Enter the cost matrix" << endl;
    cout << "Enter 999 for No edges and self loops" << endl;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
        parent[i] = 0;
    }

    while (count != n - 1) {
        find_min();
        int set_x = find_set(x);
        int set_y = find_set(y);

        if (set_x != set_y) {
            cout << "\n" << x << "->" << y << "==" << cost[x][y] << endl;
            count++;
            tot += cost[x][y];
            union_sets(set_x, set_y);
        }

        cost[x][y] = cost[y][x] = 999;
    }

    cout << "\nThe total cost of the minimum spanning tree = " << tot << endl;

    return 0;
}

void find_min() {
    int min = 999;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (cost[i][j] < min) {
                min = cost[i][j];
                x = i;
                y = j;
            }
}

int find_set(int i) {
    while (parent[i] != 0) {
        i = parent[i];
    }
    return i;
}

void union_sets(int i, int j) {
    parent[j] = i;
}
