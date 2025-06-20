/*
In this problem, you will be given one or more integers in English. Your task is to translate these
numbers into their integer representation. The numbers can range from negative 999,999,999 to positive
999,999,999. The following is an exhaustive list of English words that your program must account for:
negative, zero, one, two, three, four, five, six, seven, eight, nine, ten,
eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen,
twenty, thirty, forty, fifty, sixty, seventy, eighty, ninety, hundred,
thousand, million
Input
The input file contains multiple descriptions of integers in English, one per line, in conformity with the
following requirements:
1. Negative numbers will be preceded by the word ‘negative’.
2. The word ‘hundred’ is not used when ‘thousand’ could be. For example, 1500 is written “one
thousand five hundred”, not “fifteen hundred”.
Output
For each input line, write the corresponding number. Answers are expected to be on separate lines
with a newline after each.
Sample Input
six
negative seven hundred twenty nine
one million one hundr
*/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int main()
{
unordered_map<string,int>number_map;



number_map["zero"] = 0;
number_map["one"]=1;
number_map["two"] = 2;
number_map["three"] = 3;
number_map["four"] = 4;
number_map["five"] = 5;
number_map["six"] = 6;
number_map["seven"] = 7;
number_map["eight"] = 8;
number_map["nine"] = 9;
number_map["ten"] = 10;
number_map["eleven"] = 11;
number_map["twelve"] = 12;
number_map["thirteen"] = 13;
number_map["fourteen"] = 14;
number_map["fifteen"] = 15;
number_map["sixteen"] = 16;
number_map["seventeen"] = 17;
number_map["eighteen"] = 18;
number_map["nineteen"] = 19;

number_map["twenty"] = 20;
number_map["thirty"] = 30;
number_map["forty"] = 40;
number_map["fifty"] = 50;
number_map["sixty"] = 60;
number_map["seventy"] = 70;
number_map["eighty"] = 80;
number_map["ninety"] = 90;

number_map["hundred"] = 100;
number_map["thousand"] = 1000;
number_map["million"] = 1000000;


string line;
while (getline(cin, line)) {
    
stringstream ss(line);
string word;
long long total = 0;
bool   isNegative=false;
long long current_chunk = 0;



while (ss >> word) {
    if (word == "negative") {
        isNegative = true;
    } else if (word == "million") {
        total += current_chunk * 1000000;
        current_chunk = 0;
    } else if (word == "thousand") {
        total += current_chunk * 1000;
        current_chunk = 0;
    } else if (word == "hundred") {
        current_chunk *= 100;
    } else {
        current_chunk += number_map[word];
    }
}
total += current_chunk; // Add the remaining chunk
if (isNegative) total *= -1;
cout << total << endl;


}



    return 0;
}