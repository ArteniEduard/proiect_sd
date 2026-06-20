#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <fstream>

void heapify(std::vector<int>& a, int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && a[left] > a[largest]) {
            largest = left;
        }

        if (right < n && a[right] > a[largest]) {
            largest = right;
        }

        if (largest == i) {
            break;
        }

        std::swap(a[i], a[largest]);
        i = largest;
    }
}

void heapsort(std::vector<int>& a) {
    int n = static_cast<int>(a.size());

    // Construim max-heap-ul
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // Extragem maximul pe rând și îl punem la final
    for (int end = n - 1; end > 0; end--) {
        std::swap(a[0], a[end]);
        heapify(a, end, 0);
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

    heapsort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}