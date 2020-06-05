#include <iostream>
#include <vector>

using namespace std;

struct exchange_operation {
    int from;
    int to;
    double rate;
    double commissions;
};

int main() {
    int n, m, s;
    double v;
    cin >> n >> m >> s >> v;

    vector<exchange_operation> operations;
    for (int i = 0; i < m; i++) {
        int a, b;
        double rab, cab, rba, cba;
        cin >> a >> b >> rab >> cab >> rba >> cba;
        operations.push_back({a - 1, b - 1, rab, cab});
        operations.push_back({b - 1, a - 1, rba, cba});
    }

    vector<double> currencies(n * 2, -1);
    currencies[s - 1] = v;
    for (int i = 1; i < n; i++) {
        for (auto& operation : operations) {
            if (currencies[operation.from] != -1 &&
                currencies[operation.to] < (currencies[operation.from] - operation.commissions) * operation.rate) {
                currencies[operation.to] = (currencies[operation.from] - operation.commissions) *
                                           operation.rate;
            }
        }
    }

    //cout << (max_currency > v ? "YES" : "NO"); Some weird floating point calculations stuff below
    bool is_possible = false;
    for (auto& operation : operations) {
        if ((currencies[operation.from] - operation.commissions) * operation.rate - currencies[operation.to] >
            0.0001) {
            is_possible = true;
            break;
        }
    }
    cout << (is_possible ? "YES" : "NO");
    return 0;
}