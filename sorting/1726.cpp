#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;
    const long long walks = n * (n - 1);
    vector<int> x_coord(n);
    vector<int> y_coord(n);

    for (size_t i = 0; i < n; i++) {
        cin >> x_coord[i] >> y_coord[i];
    }
    sort(x_coord.begin(), x_coord.end());
    sort(y_coord.begin(), y_coord.end());

    long long sum = 0;
    for (size_t i = 1; i < n; i++) {
        long long delta = (x_coord[i] - x_coord[i - 1]) +
                (y_coord[i] - y_coord[i - 1]);
        long long passes_number = i * (n - i) * 2;
        sum += delta * passes_number;
    }

    cout << sum / walks;
    return 0;
}
