#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int max_n = 10000, max_k = 50000;

struct city {
    long long money;
    int days_on_top;
    string name;
} init_cities[max_n + max_k];

struct person {
    long long money;
    city* location;
} init_persons[max_n];

int main() {
    unordered_map<string, person*> billionaires;
    unordered_map<string, city*> cities;
    set<pair<long long, city*>, greater<>> top_cities;

    int n, city_counter = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, location;
        long long money;
        cin >> name >> location >> money;
        if (!cities[location]) {
            cities[location] = &init_cities[city_counter++];
        }
        billionaires[name] = &init_persons[i];
        billionaires[name]->location = cities[location];
        billionaires[name]->money = money;
        cities[location]->name = location;
        cities[location]->money += money;
    }

    for (const auto &c : cities) {
        top_cities.insert({c.second->money, c.second});
    }

    int m, k;
    cin >> m >> k;
    int day, previous_day = 0;
    string name, destination;

    for (int i = 0; i <= k; i++) {
        cin >> day >> name >> destination;
        if (i == k) {
            day = m;
        }

        if (day != previous_day) {
            auto top_city = top_cities.begin();
            auto next_city = top_city++;
            if (top_city == top_cities.end() || next_city->first > top_city->first) {
                next_city->second->days_on_top += day - previous_day;
            }
        }

        if (i == k) {
            break;
        }

        if (!cities[destination]) {
            cities[destination] = &init_cities[city_counter++];
            cities[destination]->name = destination;
        }

        auto next_destination = cities[destination];
        auto billionaire = billionaires[name];
        auto previous_destination = billionaire->location;
        auto previous_money = previous_destination->money;

        top_cities.erase({previous_money, previous_destination});
        previous_destination->money -= billionaire->money;
        top_cities.insert({previous_destination->money, previous_destination});
        top_cities.erase({next_destination->money, next_destination});
        next_destination->money += billionaire->money;
        top_cities.insert({next_destination->money, next_destination});
        billionaire->location = next_destination;
        previous_day = day;
    }

    vector<pair<string, int>> result;
    for (auto r : top_cities) {
        if (r.second->days_on_top) {
            result.emplace_back(r.second->name, r.second->days_on_top);
        }
    }
    sort(result.begin(), result.end());

    for (const auto& leader : result) {
        cout << leader.first << " " << leader.second << endl;
    }

    return 0;
}