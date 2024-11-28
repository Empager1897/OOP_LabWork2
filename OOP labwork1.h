#ifndef generator2
#define generator2
#include <iostream>
#include <vector>
#include <cmath> 
#include <algorithm>
#include <map>
#include <string>
#include <numeric>
#include <iomanip>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
static map<vector<long double>, vector<long double>> intervals_uniform;
static map<vector<long double>, vector<long double>> intervals_normal;
static map<vector<long double>, vector<long double>> intervals_other9;
static map<vector<long double>, vector<long double>> intervals_other10;
ld first_rng(int repeat = 0, bool sum = false , bool floating = false);
ld second_rng(int repeat = 0, bool sum = false , bool floating = false);
ld third_rng(int repeat = 0, bool sum = false , bool floating = false);
ld fourth_rng(int repeat = 0, bool sum = false , bool floating = false);
ld fifth_rng(int repeat = 0, bool sum = false, int offset = 0);
void sixth_rng();
void seventh_rng();
void eighth_rng();
void nineth_rng();
void tenth_rng();
void show_gist(vector<unsigned int>, const ld height);
void declare_intervals(ld num_of_inters = 10);
void show_interval_frequency(map<vector<long double>, vector<long double>> intervals, const ld height);
void show(const map<vector<ld>, vector<ld>> interval_num);
ull modInverse(ull A, ll M);
ull nearest_prime(ull n);
bool is_prime(ull n);

void declare_intervals(ld num_of_inters) {
    for (ld i = 0; i < num_of_inters; i++)
    {
        intervals_uniform[{i / num_of_inters, 1.0 / num_of_inters + i / num_of_inters}] = { };
        intervals_normal[{-3.0 + i * 6.0 / num_of_inters, -3.0 + 6.0 / num_of_inters + i * 6.0 / num_of_inters}] = {};
        intervals_other9[{i * 3.0 / num_of_inters, 3.0 / num_of_inters + i * 3.0 / num_of_inters}] = { };
        intervals_other10[{i * 10.0 / num_of_inters, 10.0 / num_of_inters + i * 10.0 / num_of_inters}] = { };
    }
}

bool is_prime(ull n) {
    if (n <= 1) {
        return false;
    }
    for (ull i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

ull nearest_prime(ull n) {
    ull prime = 0;
    for (ull i = n - 1; i >= 2; i--) {
        if (is_prime(i)) {
            prime = i;
            break;
        }
    }
    return prime;
}

ull modInverse(ull A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1 && M != 0) {
        ull q = A / M;
        ull t = M;

        M = A % M, A = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

void show(const map<vector<ld>, vector<ld>> interval_num) {
    vector<ld> sizes(interval_num.size());
    unsigned int s = 0;
    for (const auto& pair : interval_num) {
        ld p = pair.second.size();
        p = p / 100;
        sizes[s]+= p;
        s += 1;
    }

    int max_value = *max_element(sizes.begin(), sizes.end());
    int k = 0;
    for (int i = max_value; i > 0; --i) {
       cout.width(2);
       cout << i << " | ";

       for (int j = 0; j < interval_num.size(); ++j) {
           if (sizes[j] >= i) {
               cout << "x ";
               sizes[j] -= 1;
           }
           else if (sizes[j] != 0) {
               cout << "  ";
           }
       }
    cout << endl;
    }
    cout << "---------------------------------------" << endl << endl;
    }

void show_interval_frequency(map<vector<long double>, vector<long double>> intervals, const ld height) {
    for (const auto& pair : intervals) {
        ld frequency = pair.second.size() / height;
        cout << "[" << pair.first[0] << "," << pair.first[1] << "]" << setw(14) << frequency << "\n";
    }
}
#endif