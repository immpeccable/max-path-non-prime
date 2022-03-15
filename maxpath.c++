#include <bits/stdc++.h>
#include <string.h>
using namespace std;

//  Function for finding maximum sum

void printDp(vector<vector<int>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[i].size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPrime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

int maxPathSum(vector<vector<int>> input, int n, vector<vector<int>> &dp)
{

    for (int j = 0; j < n; j++)
    {
        if(isPrime(input[n-1][j])) continue;
        dp[n - 1][j] = input[n - 1][j];
    }
    //cout<<"n: "<<n<<endl;

    for (int i = n - 2; i >= 0; i--)
    {
        //cout<<"how many"<<endl;
        bool flag = false;
        for (int j = i; j >= 0; j--)
        {
            //cout<<input[i][j]<<endl;
            if(isPrime(input[i][j])){
                //cout<<input[i][j]<<endl;
                continue;
            }
            //cout<<"input: "<<input[i][j]<<endl;
            flag = true;
            dp[i][j] = input[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }

    }

    return dp[0][0];
}

int main()
{
    vector<vector<int>> input;
    string inputStr;
    std::ifstream infile("input2");
    while (getline(infile, inputStr))
    {
        vector<string> values = split(inputStr, " ");
        vector<int> valueInt;
        for (int i = 0; i < values.size(); i++)
        {
            int val = stoi(values[i]);
            valueInt.push_back(val);
        }
        input.push_back(valueInt);
    }
    int n = input.size();
    //cout << "n: " << n << endl;

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            input[i].push_back(0);
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    cout <<"result: "<<maxPathSum(input, n, dp)<<endl;
    return 0;
}