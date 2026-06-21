#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <fstream>

unsigned int normalize(int a) {
    const unsigned int b = 1u << 31;
    return a + b;
}

void radixsort(std::vector<int>& a) {
    int n = a.size();
    if (n <= 1) return;
    std::vector<int> temp(n);

    const int base = 256;
    const int bytes = 4;
    for (int byte = 0; byte < bytes; byte++) {
        int shift = byte * 8;
        int count[base] = {0};
        for (int i = 0; i < n; i++) {
            unsigned int normalized = normalize(a[i]);
            int byteValue = (normalized >> shift) & 255;
            count[byteValue]++;
        }
        int position[base];
        position[0] = 0;

        for (int i = 1; i < base; i++) {
            position[i] = position[i-1] + count[i-1];
        }

        for (int i = 0; i < n; i++) {
            unsigned int normalized = normalize(a[i]);
            int byteValue = (normalized >> shift) & 255;
            temp[position[byteValue]] = a[i];
            position[byteValue]++;
        }

        a.swap(temp);

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

    radixsort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}