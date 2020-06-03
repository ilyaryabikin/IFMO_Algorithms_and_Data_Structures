#include <iostream>

using namespace std;

int main() {
    int n, sum = 0, min_sum = 0, potential = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        sum += p;
        potential = max(potential, sum - min_sum);
        min_sum = min(sum, min_sum);
    }

    cout << potential;

    return 0;
}