#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

struct point {
    int x;
    int y;
    double angle;
    int position;
};

bool angle_comparator(const point* a, const point* b) {
    if (a->angle - b->angle > 1e-10) {
        return true;
    } else if (a->angle - b.)
}

int main() {
    int n;
    cin >> n;
    vector<point> points(n);
    cin >> points[0].x >> points[0].y;
    points[0].position = 1;
    points[0].angle = INT32_MIN;

    for (int i = 1; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].position = i + 1;
    }

    for (int i = 1; i < n; i++) {
        if (points[i].x == points[0].x) {
            points[i].angle = (points[i].y > points[0].y) ? M_PI / 2 : -M_PI / 2;
        } else if (points[i].y == points[0].y) {
            points[i].angle = (points[i].x > points[0].x) ? 2 * M_PI : -2 * M_PI;
        } else {
            double angle = atan((points[i].y - points[0].y) /
                                ((double)points[i].x - points[0].x));
            points[i].angle = (points[i].x < points[0].x) ? angle + (2 * M_PI) : angle;
        }
    }

    sort(points.begin(), points.end(), angle_comparator);

    cout << points.size() << endl;
    for (point point: points) {
        cout << point.position  << endl;
    }
    return 0;
}