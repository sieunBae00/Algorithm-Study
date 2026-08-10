class Solution {
public:
    string reverseVowels(string s) {
        char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left(0), right(s.size()-1);

        while(left < right){
            if(find(vowels, vowels+10, s[left]) != vowels+10 && find(vowels, vowels+10, s[right]) != vowels+10){ // 둘 다 모음일 경우
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if(find(vowels, vowels+10, s[left]) != vowels+10) right--;
            else if(find(vowels, vowels+10, s[right]) != vowels+10) left++;
            else{
                left++;
                right--;
            }
        }

        return s;
    }
};