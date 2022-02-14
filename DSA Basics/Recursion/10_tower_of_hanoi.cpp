#include <iostream>
using namespace std;


// void tower_of_hanoi(int number_of_discs, char source_tower, char auxilliary_tower, char destination_tower)
void tower_of_hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Move disc 1 from " << a << " to " << c << endl;
        return;
    }

    tower_of_hanoi(n - 1, a, c, b);

    cout << "Move disc " << n << " from " << a << " to " << c << endl;

    tower_of_hanoi(n - 1, b, a, c);
}

int main()
{

    tower_of_hanoi(4, 'A', 'B', 'C');

    return 0;
}