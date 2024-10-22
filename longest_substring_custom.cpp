// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#include <iostream>
#include <string>
using namespace std;

// Function to find the length of the longest substring without repeating characters
int longestSubstringWithoutRepeating(string s) {

    int arr[26+9] = {0};
    int numb[26+9] = {0};
    int numbIndex = 0;


    for (int i=0; i<s.length(); i++){
        if (arr[s[i]-97]!=0){
            numbIndex ++;
            int arr[26+9] = {0};
        }

        arr[s[i]-97] = 1;
        numb[numbIndex]++;

    }

    int intMax = -1;

    for (int i=0; i<26+9; i++){
        if (numb[i]>intMax){
            intMax = numb[i];
        }
    }

    return intMax;

}
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = longestSubstringWithoutRepeating(input);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}

