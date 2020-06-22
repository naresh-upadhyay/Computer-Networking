#include <bits/stdc++.h>
using namespace std;
#define fl(i, t) for (int i = 0; i < t; i++)
vector<int> aval;
vector<int> combinations;
int sum = 0;
int flag = 1;
int check = 0;

int calsum(vector<int> sum)
{
    int sumval = 0;
    fl(i, sum.size())
    {
        sumval += sum[i];
    }
    return sumval;
}
void sumhalf(int offset, int k)
{
    if (k == 0)
    {
        int newsum1 = calsum(combinations);
        int newsum = (11 + (sum - (2 * newsum1)) % 11) % 11;
        if (newsum == 0)
        {
            flag = 0;
            check = 1;
        }
        //cout <<"sum : "<<sum<<" new sum : "<<newsum1<<"\n";
        return;
    }
    if (flag)
    {
        for (int i = offset; i <= aval.size() - k; ++i)
        {
            combinations.push_back(aval[i]);
            sumhalf(i + 1, k - 1);
            combinations.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    fl(i, t)
    {
        int a;
        fl(k, 9)
        {
            cin >> a;
            sum += (a * (k + 1));
            if (a)
            {
                fl(j, a)
                {
                    aval.push_back(k + 1);
                }
            }
        }
        sumhalf(0, (aval.size() / 2));
        if (check)
        {
            cout << "Case #" << (i + 1) << ": YES"
                 << "\n";
        }
        else
        {
            cout << "Case #" << (i + 1) << ": NO"
                 << "\n";
        }
        //clear all data
        combinations.clear();
        aval.clear();
        sum = 0;
        flag = 1;
        check =0;
    }
}