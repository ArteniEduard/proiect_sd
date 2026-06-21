#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <queue>


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

int partitionHoare(std::vector<int>& a, int left, int right) {
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

void insertionSortRange(std::vector<int>& a, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int x = a[i];
        int j = i - 1;

        while (j >= left && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void heapifyRange(std::vector<int>& a, int left, int heapSize, int root) {
    while (true) {
        int largest = root;
        int leftChild = 2 * root + 1;
        int rightChild = 2 * root + 2;

        if (leftChild < heapSize && a[left + leftChild] > a[left + largest]) {
            largest = leftChild;
        }

        if (rightChild < heapSize && a[left + rightChild] > a[left + largest]) {
            largest = rightChild;
        }

        if (largest == root) {
            break;
        }

        std::swap(a[left + root], a[left + largest]);
        root = largest;
    }
}

void heapSortRange(std::vector<int>& a, int left, int right) {
    int heapSize = right - left + 1;

    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapifyRange(a, left, heapSize, i);
    }

    for (int end = heapSize - 1; end > 0; end--) {
        std::swap(a[left], a[left + end]);
        heapifyRange(a, left, end, 0);
    }
}

void introsort_rec(std::vector<int>& a, int left, int right, int depthLimit) {
    while (right - left > 16) {
        if (depthLimit == 0) {
            heapSortRange(a, left, right);
            return;
        }

        depthLimit--;

        int pivotIndex = partitionHoare(a, left, right);

        if (pivotIndex - left < right - pivotIndex) {
            introsort_rec(a, left, pivotIndex, depthLimit);
            left = pivotIndex + 1;
        } else {
            introsort_rec(a, pivotIndex + 1, right, depthLimit);
            right = pivotIndex;
        }
    }

    insertionSortRange(a, left, right);
}

int getDepthLimit(int n) {
    int depth = 0;

    while (n > 1) {
        depth++;
        n /= 2;
    }

    return 2 * depth;
}

void introsort(std::vector<int>& a) {
    int n = static_cast<int>(a.size());

    if (n <= 1) {
        return;
    }

    int depthLimit = getDepthLimit(n);
    introsort_rec(a, 0, n - 1, depthLimit);
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

    introsort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}