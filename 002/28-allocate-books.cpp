// 1. Each student gets at least one book,
// 2. Each book should be allocated to a student,
// 3. Should be in a contiguous manner,
// You have to allocate the books to m students such that the maximum number Of pages
// assigned to a student is minimum.

#include <iostream>
using namespace std;

bool isPossible(int arr[], int books, int stu, int mid)
{
    int stuCount = 1, pageSum = 0;
    for (int i = 0; i < books; i++)
    {
        if (pageSum + arr[i] <= mid)
            pageSum += arr[i];
        else
        {
            stuCount++;
            if (stuCount > stu || arr[i] > mid)
                return false;
            pageSum = arr[i];
        }
    }
    return true;
}

int allocatebooks(int arr[], int books, int stu)
{
    int sum = 0, ans = -1;
    for (int i = 0; i < books; i++)
        sum += arr[i];

    int s = 0, e = sum, m;
    while (s <= e)
    {
        m = s + (e - s) / 2;
        if (isPossible(arr, books, stu, m))
        {
            ans = m;
            e = m - 1;
        }
        else
            s = m + 1;
    }

    return ans;
}

int main()
{
    int arr[4] = {10, 20, 30, 40};
    cout << "The minimum of the maximum no. of pages to be allocated is : " << allocatebooks(arr, 4, 2);
    return 0;
}