#include <fstream>
#include <random>
using namespace std;

// ofstream fout("small_01.in");
// ofstream fout("small_02.in");
// ofstream fout("small_03.in");
// ofstream fout("small_04.in");
// ofstream fout("big_01.in");
// ofstream fout("big_02.in");
// ofstream fout("big_03.in");
ofstream fout("data/big_04.in");

void ordered20k() {
    int nr = 20000;
    fout << nr << endl;
    for (int i = 0; i < nr; i++) {
        fout << i << " ";
    }
}

void reverseOrder20k() {
    int nr = 20000;
    fout << nr << endl;
    for (int i = nr; i >= 1; i--) {
        fout << i << " ";
    }
}

void rand20kInts() {
    int nr = 20000;
    fout << nr << endl;
    for (int i = 0; i < nr; i++) {
        fout << rand() << " ";
    }
}

void almostOrdered20k() {
    int nr = 20000;
    fout << nr << endl;

    int a[20000];
    for (int i = 0; i < nr; i++) {
        a[i] = i;
    }

    for (int k = 0; k < 500; k++) {
        int pos = rand() % (nr - 1);
        swap(a[pos], a[pos + 1]);
    }

    for (int i = 0; i < nr; i++) {
        fout << a[i] << " ";
    }
}

void ordered10mil() {
    int nr = 10000000;
    fout << nr << endl;
    // -5 -4 -3 -2 -1 0 1 2 3 4
    for (int i = -5000000; i < nr/2; i++) {
        fout << i << " ";
    }
}

void reverse10mil() {
    int nr = 10000000;
    fout << nr << endl;
    for (int i = nr/2; i > -5000000; i--) {
        fout << i << " ";
    }
}

void rand10mil() {
    int n = 10000000;
    fout << n << endl;

    mt19937 rng(random_device{}());

    uniform_int_distribution<int> dist(
        numeric_limits<int>::min(),
        numeric_limits<int>::max()
    );

    for (int i = 0; i < n; i++) {
        fout << dist(rng) << " ";
    }
}

void duplicates10mil() {
    int nr = 10000000;
    fout << nr << endl;

    mt19937 rng(12345);
    uniform_int_distribution<int> dist(-500, 500);

    for (int i = 0; i < nr; i++) {
        fout << dist(rng) << " ";
    }
}

int main() {
    // reverseOrder20k();
    // rand20kInts();
    // almostOrdered20k();
    // ordered10mil();
    // reverse10mil();
    // rand10mil();
    duplicates10mil();
}
