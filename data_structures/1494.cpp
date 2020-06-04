#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> rolled;
    int n;
    cin >> n;

    int last_deleted = -1;
    bool cheated = false;

    for (int i = 0; i < n; i++) {
        int current;
        cin >> current;

        if (current > last_deleted) {
            for (int j = last_deleted + 1; j < current; j++) {
                rolled.push(j);
            }
            last_deleted = current;
        } else {
            if (rolled.top() == current) {
                rolled.pop();
            } else {
                cheated = true;
                break;
            }
        }
    }

    cout << (cheated ? "Cheater" : "Not a proof");
}