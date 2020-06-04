#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct hub_connection {
    int from;
    int to;
    int length;
};

bool hub_connection_comparator(hub_connection a, hub_connection b) {
    return a.length < b.length;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<hub_connection> connections(m);
    for (int i = 0; i < m; i++) {
        int from, to, length;
        cin >> from >> to >> length;
        connections[i] = {from, to, length};
    }

    sort(connections.begin(), connections.end(), hub_connection_comparator);

    vector<int> trees_indexes(n);
    for (int i = 0; i < n; i++) {
        trees_indexes[i] = i;
    }

    int max_length = INT32_MIN;
    vector<hub_connection> result;
    for (int i = 0; i < m; i++) {
        int a = connections[i].from - 1;
        int b = connections[i].to - 1;
        int l = connections[i].length;

        if (trees_indexes[a] != trees_indexes[b]) {
            if (l > max_length) {
                max_length = l;
            }

            result.push_back({a + 1, b + 1, l});

            int old_tree_index = trees_indexes[b];
            int new_tree_index = trees_indexes[a];
            for (int j = 0; j < n; j++) {
                if (trees_indexes[j] == old_tree_index) {
                    trees_indexes[j] = new_tree_index;
                }
            }
        }
    }

    cout << max_length << endl << result.size() << endl;
    for (hub_connection connection : result) {
        cout << connection.from << " " << connection.to << endl;
    }
    return 0;
}
