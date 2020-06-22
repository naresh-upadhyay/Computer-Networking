#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
vector<int> people;
vector<int> combination;

void pretty_print(const vector<int> &v)
{
    static int count = 0;
    cout << "combination no " << (++count) << ": [ ";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "] " << endl;
}

void go(int offset, int k)
{
    if (k == 0)
    {
        pretty_print(combination);
        return;
    }
    for (int i = offset; i <= people.size() - k; ++i)
    {
        combination.push_back(people[i]);
        go(i + 1, k - 1);
        combination.pop_back();
    }
}

int main()
{
    int n = 5, k = 3;
    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; ++i)
    {
        people.push_back(i + 1);
    }
    go(0, k);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}