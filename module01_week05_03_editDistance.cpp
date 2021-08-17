#include <iostream>
#include <string>

using std::string;
using namespace std;

int edit_distance(const string &str1, const string &str2);


int main() {
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
}


int edit_distance(const string &str1, const string &str2){
    //write your code here
    int strlen1 = str1.length();
    int strlen2 = str2.length();

    int levenst_arr[strlen1 + 1][strlen2 + 1];
    levenst_arr[0][0] = 0;
    for (int i = 1; i <= strlen1; i++) levenst_arr[i][0] = i;
    for (int j = 1; j <= strlen2; j++) levenst_arr[0][j] = j;

    int insrt, deltn, match, xmtch;

    for (int i = 1; i <= strlen1; i++){
        for (int j = 1; j <= strlen2; j++){
            insrt = levenst_arr[i][j - 1] + 1;
            deltn = levenst_arr[i - 1][j] + 1;
            match = levenst_arr[i - 1][j - 1];
            xmtch = match + 1;

            //std::cout << "str1[" << i - 1 << "] = " << str1[i - 1] << "; str2[" << j - 1 << "] = " << str2[j - 1] << endl; 

            if (str1[i - 1] == str2[j - 1]) levenst_arr[i][j] = min(insrt, min(deltn, match));
            else levenst_arr[i][j] = min(insrt, min(deltn, xmtch));
        }
    }
    /*
    for (int i = 0; i <= strlen1; i++){
        for (int j = 0; j <= strlen2; j++){
            std::cout << levenst_arr[i][j] << " ";
        }
        std::cout << endl;
    }*/
    return levenst_arr[strlen1][strlen2];
}



