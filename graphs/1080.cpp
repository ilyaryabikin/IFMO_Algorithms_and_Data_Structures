#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int max_n = 100;
const int none_color = -1;
const int red_color = 0;
const int blue_color = 1;

multimap<int, int> graph;
vector<int> colors(max_n, none_color);

bool has_solution = true;

int invert_color(int color) {
    return color == red_color ? blue_color : red_color;
}

void depth_first_search(int node, int color) {
    colors[node] = color;
    auto values_range = graph.equal_range(node);
    for (auto iterator = values_range.first; iterator != values_range.second; iterator++) {
        if (colors[iterator->second] == none_color) {
            depth_first_search(iterator->second, invert_color(color));
        } else if (colors[iterator->second] == color) {
            has_solution = false;
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        while (--v > 0) {
            graph.insert(make_pair(i, v));
            graph.insert(make_pair(v, i));
            cin >> v;
        }
    }

    depth_first_search(0, red_color);

    if (has_solution) {
        if (graph.empty()) {
            cout << colors[0];
        } else {
            for (auto iterator = graph.begin(), end = graph.end(); iterator != end;
                 iterator = graph.upper_bound(iterator->first)) {
                cout << colors[iterator->first];
            }
        }
    } else {
        cout << -1;
    }
    return 0;
}