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

bool asc_coord_comparator(const point& a, const point& b) {
    if (a.y == b.y) {
        return a.x < b.x;
    } else {
        return a.y < b.y;
    }
}

bool asc_angle_comparator(const point& a, const point& b) {
    return a.angle < b.angle;
}

int main() {
    int n;
    cin >> n;
    vector<point> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].position = i + 1;
    }

    point& min_point = *min_element(points.begin(), points.end(), min_coord_comparator);

    for (point& point: points) {
        if (min_point.x == point.x) {
            point.angle = M_PI / 2;
        } else if (min_point.y == point.y) {
            point.angle = 0;
        } else {
            double angle = atan((point.y - min_point.y) /
                                     (double)(point.x - min_point.x));
            point.angle = angle < 0 ? angle + (2 * M_PI) : angle;
        }
    }

    min_point.angle = -1;
    sort(points.begin(), points.end(), angle_comparator);

    cout << points[0].position << " " << points[n / 2].position;
    return 0;
}