class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        int i=0;
        while(i<s.length()){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                q.push(s[i]);
            }else{

                if(q.empty())
                    return false;

                char ch = q.top();
                q.pop();
                if ((s[i] == ')' && ch != '(') ||
                    (s[i] == '}' && ch != '{') ||
                    (s[i] == ']' && ch != '[')){
                    return false;
                }
            }
            i++;
        }
        return q.empty();
    }
};