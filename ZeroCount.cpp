#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    int l, k;
    cin >> l >> k;
    if (k == 0)
    {
        cout << l << endl;
    }

    else
    {
        int y = l - k;
        int placementlelo = y / (k + 1);
        if (y % (k + 1) != 0)
        {
            placementlelo++;
        }

        cout<<placementlelo<<endl;
    }
}