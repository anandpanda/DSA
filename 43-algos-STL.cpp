#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // binary search
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << "Finding 6 : " << binary_search(v.begin(), v.end(), 6) << endl;

    // getting indices
    cout << "Lower Bound : " << lower_bound(v.begin(), v.end(), 6) - v.begin() << " ";
    cout << "Upper Bound : " << upper_bound(v.begin(), v.end(), 6) - v.begin() << endl;

    int a = 3, b = 5;
    cout << "Max (a,b) : " << max(a, b) << " ";
    cout << "Min (a,b) : " << min(a, b) << endl;

    swap(a, b);

    string s = " abcde";
    reverse(s.begin(), s.end());
    cout << "Rev string : " << s << endl;

    // rotating
    rotate(v.begin(), v.begin() + 1, v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;

    sort(s.begin(), s.end());
    for (int i : v)
        cout << i << " ";

    return 0;
}