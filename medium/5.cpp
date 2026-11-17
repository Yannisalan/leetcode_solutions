class Solution {
public:
string longestPalindrome(string s) {
int start = 0;
int maxLength = 1;

    for (int i = 0; i < s.length(); i++) {
        // Odd-length palindrome
        int left = i;
        int right = i;

        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        if (right - left - 1 > maxLength) {
            start = left + 1;
            maxLength = right - left - 1;
        }

        left = i;
        right = i + 1;

        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {
            left--;
            right++;
        }

        if (right - left - 1 > maxLength) {
            start = left + 1;
            maxLength = right - left - 1;
        }
    }

    return s.substr(start, maxLength);
}


};
