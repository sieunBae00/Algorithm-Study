/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low(1), high(n);
        if(low == high) return n;

        int curr = low + (high-low)/2;
        int hint = guess(curr);

        while(1){
            if(hint == 0) return curr;
            else if(hint == -1) high = curr-1;
            else if(hint == 1) low = curr+1;

            curr = low + (high-low)/2;
            hint = guess(curr);
        }
    }
};