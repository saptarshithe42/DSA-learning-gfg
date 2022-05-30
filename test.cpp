#include<iostream>
#include<vector>
using namespace std;


//sort an array of 0s, 1s and 2s

void mySort(vector<int>& v)
{
    int beg = 0;

    for(int i = 0; i < v.size(); i++)
    {
        if (v[i] != 2)
        {
            swap(v[i], v[beg]);
            beg++;
        }
    }

    int k = 0;
    for(int i = 0; i < beg; i++)
    {
        if (v[i] != 1)
        {
            swap(v[i], v[k]);
            k++;
        }
    }

}

int main()
{

    vector <int> v = {1,0,2,2,1,0,1,0,2,1,0,1,2,0,0,0,1,2,1,2};

    cout << "\nbefore sorting" << endl;
    for(auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    mySort(v);

    cout << "\nAfter sorting" << endl;
    for(auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}