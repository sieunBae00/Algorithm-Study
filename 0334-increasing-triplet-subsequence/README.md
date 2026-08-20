<h2><a href="https://leetcode.com/problems/increasing-triplet-subsequence">334. Increasing Triplet Subsequence</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code>, return <code>true</code><em> if there exists a triple of indices </em><code>(i, j, k)</code><em> such that </em><code>i &lt; j &lt; k</code><em> and </em><code>nums[i] &lt; nums[j] &lt; nums[k]</code>. If no such indices exists, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,4,5]
<strong>Output:</strong> true
<strong>Explanation:</strong> Any triplet where i &lt; j &lt; k is valid.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,4,3,2,1]
<strong>Output:</strong> false
<strong>Explanation:</strong> No triplet exists.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,1,5,0,4,6]
<strong>Output:</strong> true
<strong>Explanation:</strong> One of the valid triplet is (1, 4, 5), because nums[1] == 1 &lt; nums[4] == 4 &lt; nums[5] == 6.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5 * 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you implement a solution that runs in <code>O(n)</code> time complexity and <code>O(1)</code> space complexity?

---

### Idea

처음 생각) 더 작은 게 있으면.. 바꾸는 게 이롭다. 대체 조건은?    
    
한 쌍씩 생각하면 '뒤쪽에 나보다 큰 원소가 하나는 있어야 해' 이다. 그걸 두 번..     
-> `O(n^2)` 라... 처음 방법으로 가자.     
    
생각보다 코드로 옮기면 복잡하지 않다.    

``` text
*배열을 순회하며 마주치는 원소는 first/second/third 모두의 후보가 된다. 셋 모두를 검사.    
** first, second 를 매우 큰 수(INT_MAX) 로 놓고 시작한다.   
    
- first 보다 작으면 first 를 대체한다.    
- first 보다 크고 second 보다 작으면 second 를 대체한다.   
- second 보다 크면 third 이다. -> true 반환하고 끝.   
   
모두 순회한 후에도 true 가 반환되지 않았다면 false 반환.   
```
