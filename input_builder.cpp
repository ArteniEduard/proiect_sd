#include <fstream>
using namespace std;

// ofstream fout("small_01.in");
// ofstream fout("small_02.in");
// ofstream fout("small_03.in");
ofstream fout("small_04.in");

void ordered20k() {
    int nr = 20000;
    fout<<nr<<endl;
    for (int i = 0; i < nr; i++) {
        fout<<i<<" ";
    }
}

void reverseOrder20k() {
    int nr = 20000;
    fout<<nr<<endl;
    for (int i = nr; i >= 1; i--) {
        fout<<i<<" ";
    }
}

void rand20kInts() {
    int nr = 20000;
    fout<<nr<<endl;
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

int main() {
    // reverseOrder20k();
    // rand20kInts();
    almostOrdered20k();
}
