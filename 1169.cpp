class Solution {
public:
    // Time complexity is O(N^2)
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> ans;
        unordered_set<string> res;
        unordered_map<string,vector<vector<string>>> mp;
        unordered_map<string,int> inMap;
        for(string s:transactions){
            // If this ss is occur before no need to check then just push it into the result
            if(inMap.count(s)>0){
                ans.push_back(s);
                continue;
            }
            string ss = s;
            inMap[ss]++;
            int i = s.find(',');
            string name = s.substr(0,i);
            s = s.substr(i+1);
            i = s.find(',');
            string time = s.substr(0,i);
            s = s.substr(i+1);
            i = s.find(',');
            string amount = s.substr(0,i);
            string city = s.substr(i+1);
            if(stoi(amount) > 1000)
                res.insert(ss);
            // cannot be else if because ss may satisfy two valid condition at the same time
            // so if need to check is any other record that makes ss satisfy con2 and also add that record into result
            if(mp.count(name) > 0){
                for(int j=0;j<mp[name].size();j++){
                    if(abs(stoi(time) - stoi(mp[name][j][0])) <= 60 && city != mp[name][j][2]){
                        res.insert(ss);
                        string sss = name+","+mp[name][j][0]+","+mp[name][j][1]+","+mp[name][j][2];
                        res.insert(sss);
                    }
                }
            }            
            mp[name].push_back({time,amount,city});
        }
        for(string s:res)
            ans.push_back(s);
        return ans;
    }
};