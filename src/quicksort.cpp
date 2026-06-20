#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <fstream>

int medianOfThree(const std::vector<int> &a, int left, int right) {
    int mid = left + (right - left) / 2;

    int x = a[left];
    int y = a[mid];
    int z = a[right];

    if ((x <= y && y <= z) || (z <= y && y <= x)) {
        return y;
    }

    if ((y <= x && x <= z) || (z <= x && x <= y)) {
        return x;
    }

    return z;
}

int partitionHoare(std::vector<int> &a, int left, int right) {
    int pivot = medianOfThree(a, left, right);

    int i = left - 1;
    int j = right + 1;

    while (true) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j) {
            return j;
        }

        std::swap(a[i], a[j]);
    }
}

void quicksort_rec(std::vector<int> &a, int left, int right) {
    while (left < right) {
        int pivotIndex = partitionHoare(a, left, right);

        // Sortăm recursiv partea mai mică,
        // iar pe partea mai mare continuăm cu while.
        // Asta reduce riscul de stack overflow.
        if (pivotIndex - left < right - pivotIndex) {
            quicksort_rec(a, left, pivotIndex);
            left = pivotIndex + 1;
        } else {
            quicksort_rec(a, pivotIndex + 1, right);
            right = pivotIndex;
        }
    }
}

void quicksort(std::vector<int> &a) {
    int n = a.size();
    if (n == 0) {
        return;
    }


    quicksort_rec(a, 0, n - 1);
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

    quicksort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}
