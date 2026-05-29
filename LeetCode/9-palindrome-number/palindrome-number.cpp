class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false; // 음수이면 무조건 false
        
        int tmp = x;
        long long backward = 0; // 거꾸로 입력될 숫자

        while(tmp > 0){
            // 순서 중요. 나머지를 먼저 떼어내야 함.
            int r = tmp % 10; 
            tmp = tmp / 10;

            backward = backward*10 + r;
            if(tmp < 10 && tmp != 0) { // tmp 가 한 자릿수라면
                backward = backward*10 + tmp; // tmp를 backward 의 마지막 자리에 추가하고 종료
                break;
            }
        }

        if(x == backward) return true;
        else return false;
    }
};