#include <iostream>
#include <vector>

using namespace std;

struct gas_line {
    int from;
    int to;
    int income;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<gas_line> lines(m);
    for (int i = 0; i < m; i++) {
        int from, to, income;
        cin >> from >> to >> income;
        lines[i] = {from - 1 , to - 1, income};
    }
    int start, end;
    cin >> start >> end;
    start = start - 1;
    end = end - 1;

    vector<int> incomes(n, INT32_MIN);
    incomes[start] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (incomes[lines[j].from] != INT32_MIN &&
                    incomes[lines[j].to] < incomes[lines[j].from] + lines[j].income) {
                incomes[lines[j].to] = incomes[lines[j].from] + lines[j].income;
            }
        }
    }

    if (incomes[end] == INT32_MIN) {
        cout << "No solution";
    } else {
        cout << incomes[end];
    }
    return 0;
}