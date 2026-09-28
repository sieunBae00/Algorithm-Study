class Solution {
public:
    int compress(vector<char>& chars) {
        int read(0), write(0);
        int cnt;
        
        while(read < chars.size()){
            cnt = 1;
            while(read < chars.size()-1 && chars[read] == chars[read+1]){
                read++;
                cnt++;
            }
            chars[write++] = chars[read]; // 쓰고 난 후 write++;
            
            if(cnt > 1){
                string s = to_string(cnt);
                for(char c : s) chars[write++] = c;
            }
            read++;
        }
        
        return write;
    }
};