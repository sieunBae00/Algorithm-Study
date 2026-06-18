class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string temp;
        vector<string> st;

        while(getline(ss, temp, '/')){ // temp에 '/' 로 구별된 문자열이 들어감 
            if(temp == ".") continue;
            else if(temp == ".."){
                if(st.size() != 0) st.pop_back();
            }
            else if(temp == "") continue;
            else st.push_back(temp);
        }
        if(st.size() == 0) return "/";

        stringstream ans;
        for(int i=0; i<st.size(); i++){
            ans << "/" << st[i];
        }
        return ans.str();

    }
};