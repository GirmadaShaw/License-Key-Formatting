/*
Given a string S that consists of only alphanumeric characters and dashes. 
The string is separated into N + 1 groups by N dashes. Also given an integer K.

We want to reformat the string S, such that each group contains exactly K characters, 
except for the first group, which could be shorter than K but still must contain at least
 one character. Furthermore, a dash must be inserted between two groups, and you should convert 
 all lowercase letters to uppercase.

Return the reformatted string.
Input: S = “5F3Z-2e-9-w”, K = 4
Output: “5F3Z-2E9W”
Explanation: The string S has been split into two parts,  
each part has 4 characters. 
Note that two extra dashes are not needed and can be removed.

Input: S = “2-5g-3-J”, K = 2
Output: “2-5G-3J”
Explanation: The string s has been split into three parts,  
each part has 2 characters except the first part 
as it could be shorter as mentioned above
*/

#include <bits/stdc++.h>
using namespace std;

// Function to compute the answer
string ReFormatString(string S, int K)
{
	// Create a temporary string to store
	// the alphanumeric characters only
	string temp;
	int n = S.length();
	for (int i = 0; i < n; i++) {
		if (S[i] != '-') {

			temp.push_back(toupper(S[i]));
		}
	}
	int len = temp.length();

	// String ans is created to store
	// the final string.
	string ans;
	int val = K;

	// Iterate over the string from right
	// to left and start pushing
	// characters at an interval of K
	for (int i = len - 1; i >= 0; i--) {
		if (val == 0) {
			val = K;
			ans.push_back('-');
		}
		ans.push_back(temp[i]);
		val--;
	}

	// Reverse the final string and
	// return it.
	reverse(ans.begin(), ans.end());
	return ans;
}

// Driver code
int main()
{
	string s = "5F3Z-2e-9-w";
	int K = 4;

	// Function Call
	cout << ReFormatString(s, K);
	return 0;
}
