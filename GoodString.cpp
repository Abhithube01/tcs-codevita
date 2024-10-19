#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;

    // Read two lines of input
    getline(cin, s1);
    getline(cin, s2);

    vector<int> a;

    // Convert characters of s1 to their ASCII values and store in vector 'a'
    for (auto i : s1) {
        a.push_back((int)i);
    }

    // Sort the vector 'a'
    sort(a.begin(), a.end());

    int res = 0; // To store the final result
    int prev = (int)s1[0]; // Initialize previous character's ASCII value

    // Iterate over each character in s2
    for (auto i : s2) {
        int b = (int)i; // Get ASCII value of current character
        int l = 0, r = a.size() - 1; // Initialize left and right pointers
        int ans = INT_MAX; // Initialize minimum distance
        int curr = -1; // Current closest character

        // Binary search to find the closest character in 'a'
        while (l <= r) {
            int mid = (l + r) / 2;

            if (a[mid] == b) {
                curr = prev; // Found an exact match
                ans = 0; // Distance is zero
                break;
            } else if (a[mid] < b) {
                if (abs(a[mid] - b) < ans) {
                    ans = abs(a[mid] - b);
                    curr = a[mid];
                } else if (abs(a[mid] - b) == ans) {
                    if (abs(curr - prev) > abs(a[mid] - prev)) {
                        curr = a[mid];
                        ans = abs(a[mid] - prev);
                    } else {
                        ans = abs(curr - prev);
                    }
                }
                l = mid + 1; // Move to the right half
            } else {
                if (abs(a[mid] - b) < ans) {
                    ans = abs(a[mid] - b);
                    curr = a[mid];
                } else if (abs(a[mid] - b) == ans) {
                    if (abs(curr - prev) > abs(a[mid] - prev)) {
                        curr = a[mid];
                        ans = abs(a[mid] - prev);
                    } else {
                        ans = abs(curr - prev);
                    }
                }
                r = mid - 1; // Move to the left half
            }
        }

        prev = curr; // Update previous character
        res += ans; // Add the distance to the result
    }

    // Output the final result
    cout << res;

    return 0;
}
