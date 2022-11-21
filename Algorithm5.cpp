#include <iostream>
#include <string.h>
using namespace std;
 
string LCString(char* str1, char* str2, int x, int y){
    string strings[x];
    int i = 0, j = 0, num = 0;
    string str;
    while (num < x){
        while (i < x){
            while (j < y){
                if (str1[i] == str2[j]){
                    str+=str1[i];
                    j++;
                    break;
                }
                j++;
            }
            i++;
        }
        strings[num] = str;
        str = "";
        j = 0;
        num++;
        i = num;
    }
    int max = 0;
    string longestString;
    for (int i = 0; i < x; i++){
        if (strings[i].length() > max){
            max = strings[i].length();
            longestString = strings[i];
        }
    }
    return longestString;
}

int LCSubStr(char* X, char* Y, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int result = 0; 
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else{
                LCSuff[i][j] = 0;
            }
        }
    }
    cout << "The lookup table is given below:\n";
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << LCSuff[i][j] << " ";
        }
        cout << endl;   
    } 
    cout << "The longest substring is " << LCString(X, Y, m, n)<< " and its length is: ";
    return result;
}

int main()
{
    char X[] = "CABABA";
    char Y[] = "XABABA";
 
    int m = strlen(X);
    int n = strlen(Y);
    
    cout << "First string is: " << X <<endl;
    cout << "Second string is: " << Y <<endl;
    cout << LCSubStr(X, Y, m, n);
    return 0;
}
