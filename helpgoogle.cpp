#include <bits/stdc++.h>
using namespace std;
#define fl(i, t) for (int i = 0; i < t; i++)
vector<int> aval;
vector<int> combinations;
int sum = 0;
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

int calsum(vector<int> sum){
    int sumval=0;
    fl(i,sum.size()){
        sumval += sum[i];
    }
    return sumval;
}
int sumhalf(int offset, int k)
{
    if (k == 0)
    {
        pretty_print(combinations);
        int newsum = calsum(combinations);
        newsum =(11 + (sum- (2*newsum))%11)%11;

        return newsum;
    }
    for (int i = offset; i <= aval.size() - k; ++i)
    {
        combinations.push_back(aval[i]);
        return sumhalf(i + 1, k - 1);
        combinations.pop_back();
    } return -1;
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
        if(sumhalf(0,(aval.size()/2)))
            cout<<"Case #"<<(i+1)<<": YES"<<"\n";
        else 
            cout<<"Case #"<<(i+1)<<": NO"<<"\n";
        //clear all data
        combinations.clear();
        aval.clear();
        sum = 0;

    }
}