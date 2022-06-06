#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// iterative
// time comp : theta(n)
// aux sp : theta(n)
void reverseQueue(queue<int> &q)
{
    stack<int> st;

    while (q.empty() == false)
    {
        st.push(q.front());
        q.pop();
    }
    while (st.empty() == false)
    {
        q.push(st.top());
        st.pop();
    }
}

// recursive
// time comp : theta(n)
// aux sp : theta(n)
// void reverseQueue(queue<int> &q)
// {
//     if(q.empty() == true)
//         return;

//     int x = q.front();

//     q.pop();

//     reverseQueue(q);
//     q.push(x);
// }

int main()
{
    queue<int> q;

    q.push(10);
    q.push(5);
    q.push(15);
    q.push(20);

    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }

    q.push(10);
    q.push(5);
    q.push(15);
    q.push(20);

    reverseQueue(q);
    cout << endl;

    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}