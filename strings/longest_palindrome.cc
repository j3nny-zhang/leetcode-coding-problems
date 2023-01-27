#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int is_palindrome(int l,  int r, string &s) {
    while (l >= 0 && r < s.length()) {
        if (s[l] != s[r]) {
            break;
        }
        l--;
        r++;
    }
    return r - l - 1;
}

string longest_palindrome(string s) {
    int length = s.size();
    int start_index = 0;
    int end_index = 0;
    string result = "";
    for (int i = 0; i < length; i++) {
        int odd = is_palindrome(i, i, s);
        int even = is_palindrome(i, i+1, s);

        int pal_length = max(odd, even);

        if (pal_length > end_index) {
            end_index = pal_length;
            start_index = i - (pal_length - 1)/2;
        }
    }
    result = s.substr(start_index, end_index);
    return result;
}

int main() {
    string s = "cbbd";
    cout << longest_palindrome(s) << endl;
}
