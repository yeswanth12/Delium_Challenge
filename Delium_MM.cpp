
#include <iostream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;
 
// Declaring Globally
string charmap[10];

void generateHelper(string current, int index, string digits, vector<string> &ans)
{ 
    // storing each string in the vector
    // once the string is completely formed
    // Also, end condition of recursion
    if (index == digits.size()) {
        ans.push_back(current);
        return;
    }
    // convert char to int by subtracting
    // from ascii value of 0
    int digit = digits[index] - '0'; 

    // recursively calling each combination 
    // to form a string    
    for (int i = 0; i < charmap[digit].size(); i++)
    {
        current.push_back(charmap[digit][i]);
        generateHelper(current, index + 1, digits, ans);
        current.pop_back();
    }
    return;
}

// Function to check whether the charecter is vowel or not
bool is_vowel(char c) {
    switch(c)
    {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

// Function to check if the string has duplicates or not
// (reference from geeks for geeks)
bool is_unique(string str) {
     
    // Assuming string can have characters 
    // a-z, this has 32 bits set to 0
    int checker = 0;
     
    for (int i = 0; i < str.size(); i++) {
         
        int bitAtIndex = str[i] - 'a';
         
        // if that bit is already set in
        // checker, return false
        if ((checker & (1 << bitAtIndex)) > 0) {
            return false;
        }
         
       // otherwise update and continue by
       // setting that bit in the checker
       checker = checker | (1<<bitAtIndex);
    }
    return true;
}

// Function which prints the dictionary and returns the
// vector with max vowel strings
vector<string> print_dict(vector<string> all_matches)
{ 
    // vector string which stores the values
    // of max number of vowel strings
    vector<string> MAX_VOWEL;
    // variable to store max number value
    int max =0;
    cout<<"Possible Matches: ";
    for(int i=0;i<all_matches.size();i++) // iterate through all the matches
    {
        int count =0; // count of vowels in a string
        for(int j=0;j<3;j++) // iterate through all the char in the string
        {
            // check if that char is vowel
            if(is_vowel(all_matches[i][j])) 
            {
                count++; 
            }
        }
        // if there is atleast one vowel
        // and no duplicates in a string then print 
        if(count>0 && is_unique(all_matches[i]))
        {
            cout<<all_matches[i]<< " ";
            // updating the MAX_VOWEL string 
            // with highest number of vowels
            if(count>max){ 
                max = count;
                MAX_VOWEL.clear(); // clearing if it is not the max
                MAX_VOWEL.push_back(all_matches[i]);
            }
            else if(count==max){
                MAX_VOWEL.push_back(all_matches[i]);
            }
        }
    }
    cout<<" "<<endl;
    // sorting the MAX_VOWEL string in ascending order
    sort(MAX_VOWEL.begin(),MAX_VOWEL.end());
    return MAX_VOWEL;
}

// Function which returns all the possible combinations
vector<string> letterCombinations(string input) 
{
    // Mapping the digits string according to dialler
    // Assuming the digit 0 maps to 0 itself
    // and digit 1 maps to 1 itself
    charmap[0] = "0";
    charmap[1] = "1";
    charmap[2] = "abc";
    charmap[3] = "def";
    charmap[4] = "ghi";
    charmap[5] = "jkl";
    charmap[6] = "mno";
    charmap[7] = "pqrs";
    charmap[8] = "tuv";
    charmap[9] = "wxyz";
    // string which contains the all possible combinations
    vector<string> result;

    // initiating current to ""
    string current = "";

    generateHelper(current, 0, input, result);
    return result;
}

int main()
{
    string A;
    vector<string> best;
    cout << "Enter the 3 digits String: ";
    getline (cin, A);
    best = print_dict(letterCombinations(A));

    // if MAX_VOWEL is empty then
    // no such dictionary exists
    // else print the min string
    if(best.size() == 0){
         cout<< "Does Not Exist"<<endl;
    }
    else{
        cout<<"Best Match:"<<best[0]<<endl;
    }
    return 0;
}
