#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2){
        int s1 = num1.size();
        int s2 = num2.size();
        if(num1 == "0" || num2 == "0") return "0";
        int k = s1 + s2 - 2;
        if(k <= 0) return "";
        vector<int> v(s1+s2, 0);
        for(int i = 0; i < s1; i++){
            for(int j = 0; j < s2; j++){
                v[k-i-j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int carry = 0;
        for(int i = 0; i < s1 + s2; i++){
            v[i] += carry;
            carry = v[i]/10;
            v[i] = v[i] % 10;
        }
        reverse(v.begin(), v.end());
        int u = 0;
        while(v[u] == 0) u++;
        string res = "";
        for(int i = u; i < v.size(); i++)
            res+=v[i]+'0';
        return res;
    }

    string plus(string a, string b) {
        string str1 = a;
        string str2 = b;
        int len = max(str1.size(), str2.size());
        string result;
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        int carry = 0;
        for (int i = 0; i < len; ++i) {
            int str1_i = i < str1.size() ? str1[i] - '0' : 0;
            int str2_i = i < str2.size() ? str2[i] - '0' : 0;
            int val = (str1_i + str2_i + carry) % 10;
            carry = (str1_i + str2_i + carry) / 10;
            result.insert(result.begin(), val + '0');
        }
        if (carry == 1) result.insert(result.begin(), '1');
        if (result[0] == '0') result[0] = ' ';
        return result;
    }

    string subtraction(string num1, string num2){
        string s1 = num1;
        string s2 = num2;
        if(s1==s2) {
            return "0";
        }
        string s3;
        bool flag=false;
        if(s1.length()<s2.length() || (s1.length()==s2.length() && s1<s2)) {
            std::string s=s1;
            s1=s2;
            s2=s;
            flag=true;
        } else {
            s3="";
        }
        while(s2.length()<s1.length()) {
            s2="0" + s2;
        }
        int k,down=0;
        for(int i=s1.length()-1; i>=0; i--) {
            k=s1[i] -s2[i] +down;
            if(k<0) {
                down=-1;
                k=10+k;
            } else {
                down=0;
            }
            s3=(char)('0' + k) + s3;
        }
        k=0;
        while(s3[k]=='0' ) {
            k++;
        }
        s3=s3.substr(k);
        if(flag)
            s3="-"+s3;
        return s3;
    }
};

int main() {
    Solution ojb;
//    string n1 = "6607231979617165052588803597880259566126991854418003456709172319062888021175159823406078234169218536510561442502580138201931774342510214570237380148767999";
//    string n2 = "6279842302850704939361248084003880351836382867485577813034830070108471249174447832309638959891547203343854880720276306946036752573467655038196781151389331";

    string n1 = "35978";
    string n2 = "8805922";

    string ret = ojb.multiply(n1, n2);

    int lenth = ret.length();
    int prev = lenth % 3;
    for(int i = 0; i < prev; i++){
        std::cout << ret[i];
    }
    for(int i = prev; i < ret.length(); i+=3){
        std::cout << ',' << ret[i] << ret[i+1] << ret[i+2];
    }

}