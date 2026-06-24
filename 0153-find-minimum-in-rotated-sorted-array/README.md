<h2><a href="https://leetcode.com/problems/find-minimum-in-rotated-sorted-array">153. Find Minimum in Rotated Sorted Array</a></h2><h3>Medium</h3><hr><p>Suppose an array of length <code>n</code> sorted in ascending order is <strong>rotated</strong> between <code>1</code> and <code>n</code> times. For example, the array <code>nums = [0,1,2,4,5,6,7]</code> might become:</p>

<ul>
	<li><code>[4,5,6,7,0,1,2]</code> if it was rotated <code>4</code> times.</li>
	<li><code>[0,1,2,4,5,6,7]</code> if it was rotated <code>7</code> times.</li>
</ul>

<p>Notice that <strong>rotating</strong> an array <code>[a[0], a[1], a[2], ..., a[n-1]]</code> 1 time results in the array <code>[a[n-1], a[0], a[1], a[2], ..., a[n-2]]</code>.</p>

<p>Given the sorted rotated array <code>nums</code> of <strong>unique</strong> elements, return <em>the minimum element of this array</em>.</p>

<p>You must write an algorithm that runs in&nbsp;<code>O(log n) time</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,4,5,1,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The original array was [1,2,3,4,5] rotated 3 times.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [4,5,6,7,0,1,2]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [11,13,15,17]
<strong>Output:</strong> 11
<strong>Explanation:</strong> The original array was [11,13,15,17] and it was rotated 4 times. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 5000</code></li>
	<li><code>-5000 &lt;= nums[i] &lt;= 5000</code></li>
	<li>All the integers of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is sorted and rotated between <code>1</code> and <code>n</code> times.</li>
</ul>


---

### Idea

문제에서 `O(logn)` 의 시간복잡도를 요구 -> 반으로 나눠서 범위 좁히기(이분탐색)   
  
- 🛑 범위를 좁힐 때,
  `min = mid;` 와 `max = mid;` 를 썼을 때 // `min = mid+1;` 과 `max = mid-1;` 를 썼을 때 모두에서 문제가 생겼다.  
  
-> 무지성으로 짝지어서 둘 중 하나로 쓰지 말 것.  
💡 __"확실하게 쓰레기통에 버릴 수 있는가?"__ 를 생각.  
 
> __`nums[mid] > nums[max]` 의 경우:__ mid 위치의 값이 우리가 찾는 최솟값일 확률은 없음. -> 버려도 됨. -> `min = mid + 1;`  
> __`else` 의 경우(`nums[mid] <= nums[max]`):__ mid 위치의 값이 우리가 찾는 그 '최솟값'일 가능성이 있음. !! -> 버리면 안 됨. -> `max = mid;`  
</br>

- 🛑 while 문의 종결조건: `while(min <= max)` OR `while(min < max)` ??  
  `while(min <= max)` 을 쓰면 -> `min == max` 가 될 경우 무한 루프에 빠짐. (`min`/`max` 업데이트해도 같은 값)  
  따라서 `while(min < max)` 조건을 쓰는 것이 알맞음.  
  -> while 문 끝난 후에는 `nums[min]` 혹은 `nums[max]` 반환하기. (`nums[mid]` 는 `mid` 가 업데이트되지 않았을 가능성 있어서 위험)  
