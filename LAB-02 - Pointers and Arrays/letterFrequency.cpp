#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int* letterFrequency(const string& str)
{
    int* freq = new int[26]{0};

    for (char c : str) {
        if (isalpha(c)) {
            freq[tolower(c) - 'a']++;
        }
    }
    return freq;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    int* freq = letterFrequency(input);

    cout << "\nLetter Frequency\n";
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << char('a' + i) << "\t" << freq[i] << endl;
        }
    }

    delete[] freq;
    return 0;
}