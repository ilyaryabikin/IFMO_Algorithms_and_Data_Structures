#include <iostream>

#define print_deleted(var1, var2) cout << #var1 << #var2 << "-" << endl
#define print_added(var1, var2) cout << #var1 << #var2 << "+" << endl

using namespace std;

void delete_duons(uint16_t &first, uint16_t &second) {
    first--;
    second--;
}

void add_duons(uint16_t &first, uint16_t &second) {
    first++;
    second++;
}

int main() {
    uint16_t A, B, C, D, E, F, G, H;

    cin >> A >> B >> C >> D >> E >> F >> G >> H;

    if (A + C + F + H != B + D + E + G) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    while (A + B + C + D + E + F + G + H > 0) {
        if (A > 0) {
            if (B > 0) {
                delete_duons(A, B);
                print_deleted(A, B);
            } else if (D > 0) {
                delete_duons(A, D);
                print_deleted(A, D);
            } else if (E > 0) {
                delete_duons(A, E);
                print_deleted(A, E);
            } else if (G > 0) {
                add_duons(B, F);
                print_added(B, F);
                delete_duons(G, F);
                print_deleted(G, F);
                delete_duons(A, B);
                print_deleted(A, B);
            }
        }
        if (C > 0) {
            if (B > 0) {
                delete_duons(C, B);
                print_deleted(C, B);
            } else if (D > 0) {
                delete_duons(C, D);
                print_deleted(C, D);
            } else if (G > 0) {
                delete_duons(C, G);
                print_deleted(C, G);
            } else if (E > 0) {
                add_duons(G, H);
                print_added(G, H);
                delete_duons(E, H);
                print_deleted(E, H);
                delete_duons(C, G);
                print_deleted(C, G);
            }
        }
        if (F > 0) {
            if (B > 0) {
                delete_duons(F, B);
                print_deleted(F, B);
            } else if (E > 0) {
                delete_duons(F, E);
                print_deleted(F, E);
            } else if (G > 0) {
                delete_duons(F, G);
                print_deleted(F, G);
            } else if (D > 0) {
                add_duons(A, E);
                print_added(A, E);
                delete_duons(E, F);
                print_deleted(E, F);
                delete_duons(A, D);
                print_deleted(A, D);
            }
        }
        if (H > 0) {
            if (D > 0) {
                delete_duons(H, D);
                print_deleted(H, D);
            } else if (E > 0) {
                delete_duons(H, E);
                print_deleted(H, E);
            } else if (G > 0) {
                delete_duons(H, G);
                print_deleted(H, G);
            } else if (B > 0) {
                add_duons(G, F);
                print_added(G, F);
                delete_duons(G, H);
                print_deleted(G, H);
                delete_duons(B, F);
                print_deleted(B, F);
            }
        }
    }

    return 0;
}