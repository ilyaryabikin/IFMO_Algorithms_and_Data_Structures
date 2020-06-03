#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

static int current = 1;
static vector<vector<int>> field;

void fill_quarter(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (field[i][j] == 0) {
                field[i][j] = current;
            }
        }
    }
    current++;
}

void fill_field(int x1, int y1, int x2, int y2, int empty_x, int empty_y) {
    int center_x = x1 + (x2 - x1 + 1) / 2,
        center_y = y1 + (y2 - y1 + 1) / 2,
        quarter;

    if (x2 - x1 == 1) {
        fill_quarter(x1, y1, x2, y2);
        return;
    }

    if (empty_x >= center_x) {
        if (empty_y >= center_y) {
            quarter = 1;
            fill_field(center_x, center_y, x2, y2, empty_x, empty_y);
        } else {
            quarter = 2;
            fill_field(center_x, y1, x2, center_y - 1, empty_x, empty_y);
        }
    } else {
        if (empty_y >= center_y) {
            quarter = 3;
            fill_field(x1, center_y, center_x - 1, y2, empty_x, empty_y);
        } else {
            quarter = 4;
            fill_field(x1, y1, center_x - 1, center_y - 1, empty_x, empty_y);
        }
    }

    fill_quarter(center_x - 1, center_y - 1, center_x, center_y);

    if (quarter != 1) {
        fill_field(center_x, center_y, x2, y2, center_x, center_y);
    }
    if (quarter != 2) {
        fill_field(center_x, y1, x2, center_y - 1, center_x, center_y - 1);
    }
    if (quarter != 3) {
        fill_field(x1, center_y, center_x - 1, y2, center_x - 1, center_y);
    }
    if (quarter != 4) {
        fill_field(x1, y1, center_x - 1, center_y - 1, center_x - 1, center_y - 1);
    }
}

int main() {
    int n, empty_x, empty_y;
    cin >> n >> empty_x >> empty_y;
    n = pow(2, n);
    field.resize(n + 1, vector<int> (n + 1));

    fill_field(1, 1, n, n, empty_x, empty_y);
    field[empty_x][empty_y] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << field[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}