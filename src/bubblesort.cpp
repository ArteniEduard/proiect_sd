#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <fstream>

void bubblesort(std::vector<int>& a) {
    int size = a.size();

    for (int i = 0; i < a.size(); i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);

    for (int& x : a) {
        std::cin >> x;
    }

    auto start = std::chrono::high_resolution_clock::now();

    bubblesort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}