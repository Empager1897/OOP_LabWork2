#define _USE_MATH_DEFINES
#include <OOP labwork1.h>
int main()
{
    int generator_number;
    int number_of_intervals;
    bool check = false;
    while (!check) {
        cout << "Enter the number between 1-10 in order to choose your RNG\n";
        cin >> generator_number;
        cout << "Enter the number of intervals in your RNG\n";
        cin >> number_of_intervals;
        declare_intervals(number_of_intervals);
        switch (generator_number) {
        case 1:
            first_rng();
            check = true;
            break;
        case 2:
            second_rng();
            check = true;
            break;
        case 3:
            third_rng();
            check = true;
            break;
        case 4:
            fourth_rng();
            check = true;
            break;
        case 5:
            fifth_rng();
            check = true;
            break;
        case 6:
            sixth_rng();
            check = true;
            break;
        case 7:
            seventh_rng();
            check = true;
            break;
        case 8:
            eighth_rng();
            check = true;
            break;
        case 9:
            nineth_rng();
            check = true;
            break;
        case 10:
            tenth_rng();
            check = true;
            break;
        default:
            cout << "You should enter a positive integer between 1 and 10,try again" << endl;
        }
    }
    return 0;
}

ld first_rng(int repeat, bool sum, bool floating) { // WORKS PROPERLY
    const ull m = 68719476731;
    ld sum12 = 0;
    int hist_height = 100000;
    const int a = 74, c = 75;
    if (repeat)
        hist_height = repeat;
    ull x0 = 1, x = 0;
    ld d = 1;
    for (int i = 0; i < hist_height; i++) {
        if (sum && i > 11)
            break;
        x = (a * x0 + c) % m;
        d = (ld)x / m;
        sum12 += d;
        x0 = x;
        if (!repeat) {
            for (auto j : intervals_uniform) {
                if (d >= j.first[0] && d <= j.first[1]) {
                    intervals_uniform[{j.first[0], j.first[1]}].push_back(d);
                    break;
                }
            }
        }
    }
    if(sum)
       return sum12;
    if (!repeat) {
        show(intervals_uniform);
        show_interval_frequency(intervals_uniform, hist_height);
    }
    if (floating)
        return d;
    else
        return x;
}

ld second_rng(int repeat, bool sum , bool floating) { // WORKS PROPERLY
    const ull m = 2097143;
    ld sum12 = 0;
    int hist_height = 100000;
    const int a = 2097144   , c = 49;
    if (repeat)
        hist_height = repeat;
    ld x0 = 1, x = -1;
    ld d = 1, dd = 8;
    for (int i = 0; i < hist_height; i++) {
        if (sum && i > 11)
            break;
        x = ull(dd * x0 * x0 + a * x0 + c) % m;
        d = ld(x / m);
        x0 = x;
        sum12 += d;
        if (!repeat) {
            for (auto j : intervals_uniform) {
                if (d >= j.first[0] && d <= j.first[1]) {
                    intervals_uniform[{j.first[0], j.first[1]}].push_back(d);
                    break;
                }
            }
        }
    }
    if ((repeat && sum) || sum)
        return sum12;
    if (!repeat) {
        show(intervals_uniform);
        show_interval_frequency(intervals_uniform, hist_height);
    }
    if (floating)
        return d;
    else
        return x;
}

ld third_rng(int repeat, bool sum , bool floating) { // WORKS PROPERLY
    const ull m = 131071;
    int hist_height = 100000;
    if (repeat)
        hist_height = repeat;
    ull x0 = 1, x1 = 2, x = 1;
    ld d = 1, sum12 = 0;
    for (int i = 0; i < hist_height; i++) {
        if (sum && i > 11)
            break;
        x = (x0 + x1) % m;
        d = (ld)x / m;
        x0 = x1;
        x1 = x;
        sum12 += d;
        if (!repeat) {
            for (auto j : intervals_uniform) {
                if (d >= j.first[0] && d <= j.first[1]) {
                    intervals_uniform[{j.first[0], j.first[1]}].push_back(d);
                    break;
                }
            }
        }
    }
    if ((repeat && sum) || sum)
        return sum12;
    if (!repeat) {
        show(intervals_uniform);
        show_interval_frequency(intervals_uniform, hist_height);
    }
    if (floating)
        return d;
    else
        return x;
}

ld fourth_rng(int repeat, bool sum , bool floating) { // WORKS PROPERLY
    const ull m = 16381;
    int hist_height = 100000;
    if (repeat)
        hist_height = repeat;
    ull x0 = 1, x;
    ull a = 101, c = 103;
    ld d = 1, sum12 = 0;
    for (int i = 0; i < hist_height; i++) {
        if (sum && i > 11)
            break;
        x = (a * x0 + c) % m;
        if (m % x != 0)
            x0 = modInverse(x, m);
        d = (ld)x / m;
        x0 = x;
        if (!repeat) {
            for (auto j : intervals_uniform) {
                if (d >= j.first[0] && d <= j.first[1]) {
                    intervals_uniform[{j.first[0], j.first[1]}].push_back(d);
                    break;
                }
            }
        }
    }
    if ((repeat && sum) || sum)
        return sum12;
    if (!repeat) {
        show(intervals_uniform);
        show_interval_frequency(intervals_uniform, hist_height);
    }
    if (floating)
        return d;
    else
        return x;
}

ld fifth_rng(const int repeat, const bool sum, const int offset) { // WORKS PROPERLY
    const ull m = 68719476731;
    int hist_height = 100000;
    if (repeat)
        hist_height = repeat;
    ull x;
    ld d = 1, sum12 = 0;
    for (int i = 0; i < hist_height; i++) {
        if (sum && i > 11)
            break;
        x = ull((first_rng(i % 1000 + 11 + offset) - second_rng(i % 1000 + 13 + offset))) % m;
        d = ld(x) / m;
        sum12 += d;
        if (!repeat) {
            for (auto j : intervals_uniform) {
                if (d >= j.first[0] && d <= j.first[1]) {
                    intervals_uniform[{j.first[0], j.first[1]}].push_back(d);
                    break;
                }
            }
        }
    }
    if (sum) {
        return sum12;
    }
    if (!repeat) {
        show(intervals_uniform);
        show_interval_frequency(intervals_uniform, hist_height);
    }
    return d;
}

void sixth_rng() { // WORKS PROPERLY 
    int hist_height = 100000;
    const int m = 0, sigma = 1;
    ld x, sum = 0;
    for (int i = 0; i < hist_height; i++) {
        sum = first_rng(i, true, i);
        x = m + (sum - 6) * sigma;
        for (auto j : intervals_normal) {
            if (x >= j.first[0] && x <= j.first[1]) {
                intervals_normal[{j.first[0], j.first[1]}].push_back(x);
                break;
            }
        }
    }
    show(intervals_normal);
    show_interval_frequency(intervals_normal, hist_height);
}

void seventh_rng() { // WORKS PROPERLY 
    int hist_height = 100000;
    long double v1, v2, u1, u2, x1, x2, s;
    for (int i = 0; i < hist_height; i++) {
        u1 = first_rng(i % 1000 + 1, false, true);
        u2 = second_rng(i % 1000 + 5, false, true);
        v1 = 2 * u1 - 1;
        v2 = 2 * u2 - 1;
        s = v1 * v1 + v2 * v2;
        if (s < 1) {
            x1 = v1 * sqrtl(-2 * log(s) / s);
            x2 = v2 * sqrtl(-2 * log(s) / s);
            for (auto i : intervals_normal) {
                if (x1 >= i.first[0] && x1 <= i.first[1]) {
                    intervals_normal[{i.first[0], i.first[1]}].push_back(x1);
                }
                if (x2 >= i.first[0] && x2 <= i.first[1]) {
                    intervals_normal[{i.first[0], i.first[1]}].push_back(x2);
                    break;
                }
            }
        }
    }
    show(intervals_normal);
    show_interval_frequency(intervals_normal, hist_height);
}

void eighth_rng() { // WORKS PROPERLY 
    int hist_height = 100000;
    long double v, u, x;
    for (int i = 0; i < hist_height; i++) {
        u = third_rng(i % 1400 + 1, false, true);
        v = fourth_rng(i % 1400 + 5, false, true);
        x = sqrtl(8 / M_E) * ((v - 0.5) / u);
        if (((x * x) <= 5 - 4 * exp(0.25) * u) && (x * x) < ((4 * exp(-1.35) / u) + 1.4) && ((x * x) <= -4 * log(u))) {
            for (auto i : intervals_normal) {
                if (x >= i.first[0] && x <= i.first[1]) {
                    intervals_normal[{i.first[0], i.first[1]}].push_back(x);
                    break;
                }
            }
        }
    }
    show(intervals_normal);
    show_interval_frequency(intervals_normal, hist_height);
}

void nineth_rng() { // WORKS PROPERLY 
    int hist_height = 100000;
    ld x, u, miu = 0.1;
    for (int i = 1; i < hist_height; i++) {
        u = first_rng(i % 1000 + 11, false, true);
        x = -miu * log(u);
        for (auto i : intervals_other9) {
            if (x >= i.first[0] && x <= i.first[1]) {
                intervals_other9[{i.first[0], i.first[1]}].push_back(x);
                break;
            }
        }
    }
    show(intervals_other9);
    show_interval_frequency(intervals_other9, hist_height);
}

void tenth_rng() { // WORKS PROPERLY
    int hist_height = 100000;
    const int a = 20;
    long double d, u, v, x, y;
    for (int i = 0; i < hist_height; i++) {
        u = first_rng(i % 2000 + 1, false, true);
        y = tan(M_PI * u);
        x = sqrtl(2 * a - 1) * y + a - 1;
        if (x <= 0)
            continue;
        v = second_rng(i % 2000 + 5, false, true);
        if (v <= ((1 + y * y) * exp((a - 1) * log(x / (a - 1)) - sqrtl(2 * a - 1) * y))) {
            for (auto i : intervals_other10) {
                if (x >= i.first[0] && x <= i.first[1]) {
                    intervals_other10[{i.first[0], i.first[1]}].push_back(x);
                    break;
                }
            }
        }
    }
    show(intervals_other10);
    show_interval_frequency(intervals_other10, hist_height);
}