<h2><a href="https://leetcode.com/problems/maximum-average-subarray-i">643. Maximum Average Subarray I</a></h2><h3>Easy</h3><hr><p>You are given an integer array <code>nums</code> consisting of <code>n</code> elements, and an integer <code>k</code>.</p>

<p>Find a contiguous subarray whose <strong>length is equal to</strong> <code>k</code> that has the maximum average value and return <em>this value</em>. Any answer with a calculation error less than <code>10<sup>-5</sup></code> will be accepted.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,12,-5,-6,50,3], k = 4
<strong>Output:</strong> 12.75000
<strong>Explanation:</strong> Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5], k = 1
<strong>Output:</strong> 5.00000
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= k &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

---

### Idea

배열을 순회하며, "연속된 k 개 원소의 합" 이 가장 클 때를 저장. -> 평군이 가장 큰 순간.  
  
**처음에 현재의 합&최대 합을 하나의 변수로 처리해서 틀린 답이 나왔다.  
  (당연히도, 이전 위치의 최대 합과 현재 위치의 최대 합을 구성하는 원소가 다를 것이므로, 그중 일부만 계산하게 되면 의도치 않은 결과가 나오게 된다.). 
  -> "현재의 합(`curr_sum`)" 과 "최대 합(`max`)" 을 __분리__ 해야 한다. !!  
  
