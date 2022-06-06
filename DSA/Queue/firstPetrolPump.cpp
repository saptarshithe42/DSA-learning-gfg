#include<iostream>
using namespace std;


int firstPetrolPump(int petrol[], int dist[], int n)
{
    int prev_pet = 0, curr_pet = 0, start = 0;

    for(int i = 0; i < n; i++)
    {
        curr_pet += (petrol[i] - dist[i]);

        if(curr_pet < 0)
        {
            prev_pet += curr_pet;
            curr_pet = 0;
            start = i+1;
        }

    }

    return ((curr_pet + prev_pet >= 0) ? (start + 1) : -1);
}


int main()
{
    int petrol[] = {4,8,7,4};
    int dist[] = {6,5,3,5};
    int n = 4;

    cout << firstPetrolPump(petrol, dist, n) << endl;



    return 0;
}