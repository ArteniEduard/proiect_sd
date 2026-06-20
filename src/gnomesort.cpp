#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <chrono>
#include <fstream>

void gnomesort(std::vector<int> &a) {
    int n = a.size();

    int i = 0;

    while (i < n) {
        if (i == 0 || a[i - 1] <= a[i]) {
            i++;
        } else {
            std::swap(a[i - 1], a[i]);
            i--;
        }
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

    gnomesort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}
