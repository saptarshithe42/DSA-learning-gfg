#include<iostream>
using namespace std;

// pattern has all distinct characters
void naive_pattern_searching(string& txt, string& pat)
{
    int pat_len = pat.length();
    int txt_len = txt.length();

    for(int i = 0; i <= (txt_len - pat_len); )
    {
        int j;
        for(j = 0; j < pat_len; j++)
        {
            if(pat[j] != txt[i + j])
                break;
        }

        if(j ==  pat_len)
        {
            cout << i << " ";
        }

        if(j == 0)
            i++;
        else
            i = (i + j);

    }
}


int main()
{
    string txt = "GEEKSFORGEEKS";
    string pat = "EKS";

    naive_pattern_searching(txt, pat);

    
    return 0;
}