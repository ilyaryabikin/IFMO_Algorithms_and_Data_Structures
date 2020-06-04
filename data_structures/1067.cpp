#include <iostream>
#include <vector>
#include <map>

using namespace  std;

struct disk_tree {
    map<string , disk_tree> children;

    void print_tree(int depth = 0) {
        for (auto& child : children) {
            for (int i = 0; i < depth; i++) {
                cout << " ";
            }
            cout << child.first << endl;
            child.second.print_tree(depth + 1);
        }
    }
};

vector<string> split(const string& str, char delimiter = '\\') {
    size_t current = str.find(delimiter),
           previous = 0;
    vector<string> parts;
    while (current != string::npos) {
        parts.push_back(str.substr(previous, current - previous));
        previous = current + 1;
        current = str.find(delimiter, previous);
    }
    parts.push_back(str.substr(previous, current - previous));
    return parts;
}

int main() {
    int n;
    cin >> n;

    disk_tree tree;

    for (int i = 0; i < n; i++) {
        disk_tree* current_directory = &tree;
        string path;
        cin >> path;
        vector<string> parts = split(path);
        for (auto& part : parts) {
            disk_tree child;
            current_directory->children.insert(pair<string, disk_tree>(part, child));
            current_directory = &current_directory->children[part];
        }
    }
    tree.print_tree();
    return 0;
}