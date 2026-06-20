#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <fstream>

void insertionsort(std::vector<int> &a) {
    int n = a.size();

    for (int i = 1; i < n; i++) {
        int x = a[i];
        int j = i - 1;

        bool modified = false;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
            modified = true;
        }
        if (modified)
            a[j + 1] = x;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int &x: a) {
        std::cin >> x;
    }

    auto start = std::chrono::high_resolution_clock::now();

    insertionsort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}
