class Solution {
public:
    // token up smallest tokens to gain score
    // then using score to down largest token 
    //
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0;
        int score = 0;
        sort(tokens.begin(),tokens.end());
        int up = 0, down = tokens.size()-1;
        while(up<=down && (power>=tokens[up] || score)){
            // Because wanna largest score so here is using while not if to gain score as much as possible
            while(up<=down && power>=tokens[up]){
                score++;
                power -= tokens[up];
                up++;
            }
            ans = max(ans,score);
            // Because wanna largest score so here is not while but use if
            if(up<=down && score>0){
                score--;
                power += tokens[down];
                down--;
            }
        }
        return ans;
    }
};