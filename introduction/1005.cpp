#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, sum = 0;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> stones[i];
        sum += stones[i];
    }

    int capacity = sum / 2;
    vector<int> heap(capacity + 1, 0);
    int heap_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int w = capacity - stones[i]; w >= 0; w--) {
            if (heap[w + stones[i]] < stones[i] + heap[w]) {
                heap[w + stones[i]] = stones[i] + heap[w];
                if (heap[w + stones[i]] > heap_sum) {
                    heap_sum = heap[w + stones[i]];
                }
            }
        }
    }

    cout << sum - 2 * heap_sum;

    return 0;
}