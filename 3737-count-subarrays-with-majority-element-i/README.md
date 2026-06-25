<h2><a href="https://leetcode.com/problems/count-subarrays-with-majority-element-i">4074. Count Subarrays With Majority Element I</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>nums</code> and an integer <code>target</code>.</p>

<p>Return the number of <strong><span data-keyword="subarray-nonempty">subarrays</span></strong> of <code>nums</code> in which <code>target</code> is the <strong>majority element</strong>.</p>

<p>The <strong>majority element</strong> of a subarray is the element that appears <strong>strictly</strong> <strong>more than half</strong> of the times in that subarray.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,2,3], target = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<p>Valid subarrays with <code>target = 2</code> as the majority element:</p>

<ul>
	<li><code>nums[1..1] = [2]</code></li>
	<li><code>nums[2..2] = [2]</code></li>
	<li><code>nums[1..2] = [2,2]</code></li>
	<li><code>nums[0..2] = [1,2,2]</code></li>
	<li><code>nums[1..3] = [2,2,3]</code></li>
</ul>

<p>So there are 5 such subarrays.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1,1], target = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation: </strong></p>

<p><strong>​​​​​​​</strong>All 10 subarrays have 1 as the majority element.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3], target = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p><code>target = 4</code> does not appear in <code>nums</code> at all. Therefore, there cannot be any subarray where 4 is the majority element. Hence the answer is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>​​​​​​​9</sup></code></li>
	<li><code>1 &lt;= target &lt;= 10<sup>9</sup></code></li>
</ul>

---

### Idea

처음엔 풀이가 떠오르지 않아 당황했지만, `burte-force` 로 해결 가능한 문제이다.  

``` cpp
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;

        // 모든 subarray 순회하기
        for(int i=0; i<nums.size(); i++){
            for(int j=i; j<nums.size(); j++){
                // subarray 에서 count() 함수로 특정 숫자의 개수 세기
                if(2 * count(nums.begin()+i, nums.begin()+j+1, target) > j-i+1){
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

처음엔 위와 같이 {이중 for 문 + count()} 를 썼는데, 시간복잡도가 `O(n^3)` 이 되어 TLE 에 걸렸다..  
  
__-> 💡 "누적해서 센다."__ `count()` 로 셀 필요 없이, `j` 가 한 칸씩 전진할 때마다 `target` 인지 확인 후 넘어간다.  

> `i` 가 한 칸씩 전진할 때마다 `cnt` 변수를 초기화,   
> `j` 가 한 칸씩 전진할 때마다 `target` 인지 확인 후 `cnt++;` / __그때까지 누적된__ `cnt` 수가 배열 크기의 절반을 넘으면 `ans++;`    
