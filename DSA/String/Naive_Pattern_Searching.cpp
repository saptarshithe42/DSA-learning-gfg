#include<iostream>
using namespace std;


// time comp : O((txt_len - pat_len + 1) * pat_len)
void naive_pattern_searching(string& txt, string& pat)
{
    int pat_len = pat.length();
    int txt_len = txt.length();

    for(int i = 0; i <= (txt_len - pat_len); i++)
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

    }
}


int main()
{
    string txt = "ABABABCD";
    string pat = "ABAB";

    naive_pattern_searching(txt, pat);

    
    return 0;
}