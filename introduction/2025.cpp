#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, k = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        int sum = 0;
        vector<int> teams(k, 0);
        for (int j = 0; j < n; j++) {
            teams[j % k]++;
        }

        for (int j = 0; j < k; j++) {
            int current_team = teams[j];
            for (int v = j + 1; v < k; v++) {
                sum += current_team * teams[v];
            }
        }

        cout << sum << endl;

    }
    return 0;
}