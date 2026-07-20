class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> sFreq;
        unordered_map<char,int> guessFreq;
        int bull = 0;
        int cow = 0;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]){
                bull++;
            }
            else{
                sFreq[secret[i]]++;
                guessFreq[guess[i]]++;
            }
        }
        for(auto it : sFreq){
            cow += min(it.second, guessFreq[it.first]);
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};