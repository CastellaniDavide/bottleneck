#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    queue <pair <int, int> > a, b;
    a.push(make_pair(2, 3));
    a.push(make_pair(3, 4));
    swap(a, b);

    cout << "a\t";
    while(!a.empty()) {
        cout << a.front().first << "-" << a.front().second << " ";
        a.pop();
    }
    cout << endl;

    cout << "b\t";
    while(!b.empty()) {
        cout << b.front().first << "-" << b.front().second << " ";
        b.pop();
    }
    cout << endl;

    return 0;
}
