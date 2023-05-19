class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mp;
        
        mp[1] = "I";
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";
        
        string ans = "";
        
        mp[2] = "II";
        mp[3] = "III";
        mp[4] = "IV";
        mp[6] = "VI";
        mp[7] = "VII";
        mp[8] = "VIII";
        mp[9] = "IX";
        
        mp[20] = "XX";
        mp[30] = "XXX";
        mp[40] = "XL";
        mp[60] = "LX";
        mp[70] = "LXX";
        mp[80] = "LXXX";
        mp[90] = "XC";
        
        mp[200] = "CC";
        mp[300] = "CCC";
        mp[400] = "CD";
        mp[600] = "DC";
        mp[700] = "DCC";
        mp[800] = "DCCC";
        mp[900] = "CM";
        
        mp[2000] = "MM";
        mp[3000] = "MMM";
        
        vector<int> digits;
        
        while(num > 0){
            digits.push_back(num%10);
            num = num/10;
        }
        
        int x = pow(10,(digits.size()-1));
        
        for(int i=digits.size()-1;i>=0;i--){
            int n = digits[i]*x;
            ans += mp[n];
            x = x/10;
        }
 
       return ans;
        
    }
};