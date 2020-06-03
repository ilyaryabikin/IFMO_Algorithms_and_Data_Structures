#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool desc_count_comparator(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    int k;
    cin >> k;

    int total = 0;
    vector<pair<int, int>> signs(k);
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        total += c;
        signs[i] = {i + 1, c};
    }
    sort(signs.begin(), signs.end(), desc_count_comparator);

    int prev = -1;
    while (total-- > 0) {
        bool found = false;
        for (int i = 0; i < k; i++) {
            if (signs[i].second != 0 && signs[i].first != prev) {
                cout << signs[i].first << " ";
                signs[i].second--;
                prev = signs[i].first;
                if (i != k - 1 && signs[i].second < signs[i + 1].second) {
                    swap(signs[i + 1], signs[i]);
                }
                found = true;
                break;
            }
        }

        if (!found) {
            cout << signs[0].first << " ";
            signs[0].second--;
        }
    }
    return 0;
}
