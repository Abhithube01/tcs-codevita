#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int countInvertIndex(vector<int>& arr,int &n)
{
  int invert = 0;

    for (int i = 0; i <n; i++) {
        for (int j = i + 1; j <n; j++) {
            if (arr[i] > arr[j]) {
                invert++;
            }
        }
    }
    return invert;
}

int minimumSwap(vector<int>& arr,int &n)
{
  	int ascendingInvert = countInvertIndex(arr,n);
    vector<int> descendingArr = arr;
    reverse(descendingArr.begin(), descendingArr.end());
    int descendingInvert = countInvertIndex(descendingArr,n);
    return min(ascendingInvert, descendingInvert);
}

int main()
{
  	int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << minimumSwap(arr,n) << endl;
    return 0;
}
