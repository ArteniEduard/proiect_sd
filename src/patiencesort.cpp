#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <queue>

struct HeapNode {
    int value;
    int pile;
};

struct CompareHeapNode {
    bool operator()(const HeapNode& a, const HeapNode& b) const {
        return a.value > b.value;
    }
};

void patience_sort(std::vector<int>& a) {
    int n = static_cast<int>(a.size());

    if (n <= 1) {
        return;
    }

    std::vector next(n, -1);
    std::vector<int> pileTop;
    std::vector<int> topValues;

    pileTop.reserve(n);
    topValues.reserve(n);

    // Construirea grămezilor
    for (int i = 0; i < n; i++) {
        int x = a[i];

        auto it = std::lower_bound(topValues.begin(), topValues.end(), x);
        int pileIndex = static_cast<int>(it - topValues.begin());

        if (it == topValues.end()) {
            // Creăm o grămadă nouă
            topValues.push_back(x);
            pileTop.push_back(i);
        } else {
            // Punem elementul peste grămada găsită
            next[i] = pileTop[pileIndex];
            pileTop[pileIndex] = i;
            topValues[pileIndex] = x;
        }
    }

    // Punem vârful fiecărei grămezi într-un min-heap
    std::priority_queue<
        HeapNode,
        std::vector<HeapNode>,
        CompareHeapNode
    > heap;

    int numberOfPiles = static_cast<int>(pileTop.size());

    for (int i = 0; i < numberOfPiles; i++) {
        heap.push({a[pileTop[i]], i});
    }

    // Reconstruim vectorul sortat
    std::vector<int> sorted;
    sorted.reserve(n);

    while (!heap.empty()) {
        HeapNode current = heap.top();
        heap.pop();

        int pileIndex = current.pile;
        int elementIndex = pileTop[pileIndex];

        sorted.push_back(a[elementIndex]);

        pileTop[pileIndex] = next[elementIndex];

        if (pileTop[pileIndex] != -1) {
            heap.push({a[pileTop[pileIndex]], pileIndex});
        }
    }

    a.swap(sorted);
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

    patience_sort(a);

    auto stop = std::chrono::high_resolution_clock::now();

    assert(std::is_sorted(a.begin(), a.end()));

    std::chrono::duration<double> elapsed = stop - start;
    std::cout << "Time: " << elapsed.count() << " seconds\n";

    return 0;
}