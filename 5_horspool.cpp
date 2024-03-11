#include <iostream>
#include <cstring>
#include <chrono>
#include <ctime>
#include <sys/time.h>
#include <sys/resource.h>
using namespace std;


char str[100], ptn[20];
int res, m, n, len, i, j, k, table[256];

void shift(const char p[]) {
    len = strlen(p);
    for (i = 0; i < 256; i++)
        table[i] = len;
    for (j = 0; j < len - 1; j++)
        table[p[j]] = len - 1 - j;
}

int horspool(const char p[], const char t[]) {
    shift(p);
    m = strlen(p);
    n = strlen(t);
    i = m - 1;
    while (i < n) {
        k = 0;
        while (k < m && p[m - 1 - k] == t[i - k])
            k++;
        if (k == m)
            return i - m + 1;
        else
            i += table[t[i]];
    }
    return -1;
}

int main() {
    struct timeval tv1, tv2;
    struct rusage r_usage;

    cout << "Enter the text: \n";
    cin.getline(str, sizeof(str));
    cout << "Enter the pattern to be found: \n";
    cin.getline(ptn, sizeof(ptn));

    gettimeofday(&tv1, nullptr);
    res = horspool(ptn, str);
    gettimeofday(&tv2, nullptr);

    if (res == -1)
        cout << "\nPattern not found\n";
    else
        cout << "Pattern found at position " << res + 1 << "\n";

    cout << "Time of Horsepool's Algorithm = "
              << (double)(tv2.tv_usec - tv1.tv_usec) << " microseconds \n";

    getrusage(RUSAGE_SELF, &r_usage);
    cout << "Memory usage: " << r_usage.ru_maxrss << " kilobytes \n";

    return 0;
}

