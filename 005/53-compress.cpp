// input chars = {"a,a,b,c,c,c"}
// output chars = {"a,2,b,c,3"}
// if c is present 12 times then , chars = {a,2,b,c,1,2}
// return size of compressed vetor

#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    int len = chars.size();
    int index = 0;
    int i = 0;

    while (i < len)
    {
        int j = i + 1;
        while (j < len && chars[j] == chars[i])
            j++;

        // here after - complete vector traversed or a new char encountered

        chars[index++] = chars[i];
        int count = j - i;
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char ch : cnt)
                chars[index++] = ch;
        }
        i = j;
    }
    chars.resize(index);
    return index;
}

int main()
{
    vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    cout << "Before compressing : " << endl;
    for (char c : chars)
        cout << c << " ";
    cout << endl;
    // cout << compress(chars) << endl;
    compress(chars);
    cout << "After compressing : " << endl;
    for (char c : chars)
        cout << c << " ";
    cout << endl;

    return 0;
}