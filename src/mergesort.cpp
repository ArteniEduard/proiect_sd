#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <fstream>

void merge_arrays(std::vector<int>& a, std::vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = a[i++];
    }

    while (j <= right) {
        temp[k++] = a[j++];
    }

    for (int p = left; p <= right; p++) {
        a[p] = temp[p];
    }
}

void mergesort_rec(std::vector<int>& a, std::vector<int>& temp, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergesort_rec(a, temp, left, mid);
    mergesort_rec(a, temp, mid + 1, right);

    merge_arrays(a, temp, left, mid, right);
}

void mergesort(std::vector<int>& a) {
    int n = a.size();

    if (n <= 1) {
        return;
    }

    std::vector<int> temp(n);
    mergesort_rec(a, temp, 0, n - 1);
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

    mergesort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}
