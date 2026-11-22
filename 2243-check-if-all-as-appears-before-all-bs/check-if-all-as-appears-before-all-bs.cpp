class Solution {
public:
    bool checkString(string s) {
        int firstbcount = -1;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == 'b'){
                firstbcount = i;
                break;
            }
        }

        if(firstbcount == -1) return true;
        
        for(int i=firstbcount; i<n; i++){
            if(s[i] == 'a') return false;
        }

        return true;
    }
};