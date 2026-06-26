class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for(int i=0; i<expression.length(); i++){
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){ // 현재 문자가 연산자라면
                string leftStr = expression.substr(0, i);
                string rightStr = expression.substr(i+1);

                vector<int> leftRes = diffWaysToCompute(leftStr); // 왼쪽 범위 재귀
                vector<int> rightRes = diffWaysToCompute(rightStr); // 오른쪽 범위 재귀

                // 양쪽 계산 결과들끼리 매치, 연산자로 계산
                for(int j=0; j<leftRes.size(); j++){
                    for(int k=0; k<rightRes.size(); k++){
                        // 연산자에 따른 계산 결과 정답 배열에 저장
                        if(expression[i] == '+') ans.push_back(leftRes[j] + rightRes[k]);
                        else if(expression[i] == '-') ans.push_back(leftRes[j] - rightRes[k]);
                        else if(expression[i] == '*') ans.push_back(leftRes[j] * rightRes[k]);
                    }
                }
            }
        }

        //문자열 끝까지 순회했는데 연산자가 없을 경우 = 그냥 숫자 (재귀의 Base Case)
        if(ans.empty()) ans.push_back(stoi(expression));

        return ans;
    }
};