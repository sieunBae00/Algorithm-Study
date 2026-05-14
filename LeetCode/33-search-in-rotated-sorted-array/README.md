<h2><a href="https://leetcode.com/problems/search-in-rotated-sorted-array">Search in Rotated Sorted Array</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>There is an integer array <code>nums</code> sorted in ascending order (with <strong>distinct</strong> values).</p>

<p>Prior to being passed to your function, <code>nums</code> is <strong>possibly left rotated</strong> at an unknown index <code>k</code> (<code>1 &lt;= k &lt; nums.length</code>) such that the resulting array is <code>[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]</code> (<strong>0-indexed</strong>). For example, <code>[0,1,2,4,5,6,7]</code> might be left rotated by&nbsp;<code>3</code>&nbsp;indices and become <code>[4,5,6,7,0,1,2]</code>.</p>

<p>Given the array <code>nums</code> <strong>after</strong> the possible rotation and an integer <code>target</code>, return <em>the index of </em><code>target</code><em> if it is in </em><code>nums</code><em>, or </em><code>-1</code><em> if it is not in </em><code>nums</code>.</p>

<p>You must write an algorithm with <code>O(log n)</code> runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 0
<strong>Output:</strong> 4
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [4,5,6,7,0,1,2], target = 3
<strong>Output:</strong> -1
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> nums = [1], target = 0
<strong>Output:</strong> -1
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 5000</code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li>All values of <code>nums</code> are <strong>unique</strong>.</li>
	<li><code>nums</code> is an ascending array that is possibly rotated.</li>
	<li><code>-10<sup>4</sup> &lt;= target &lt;= 10<sup>4</sup></code></li>
</ul>

---

### Idea

결국 주어진 배열에서 target 을 찾으라는 것.  
다만 __O(logn)__ 이하의 시간복잡도를 가져야 하고, 원래 정렬되어 있던 배열이 shift 된 상황임을 활용할 것.  
  
🛑 `i` 가 `i-1` 보다 큰 순간을 찾아내서 원래 배열로 만들 수 있을까?  
-> ' `i` 가 `i-1` 보다 큰 순간' 을 찾아낸다 = __n 개 순회; O(n)__ = 너무 느리다.  
-> '이진 탐색' 이용.  
  
> 💡 절반으로 쪼개면, 한 쪽은 무조건 '정상' (정렬된 상태)  

``` text
만약 target 이 '정상' 부분에 속한다면 -> 해당 부분에서 이분탐색하여 target 의 인덱스 찾는다.  
만약 target 이 '비정상' 부분에 속한다면 -> 해당 부분을 다시 둘로 나누어 범위를 좁힌다.
```

__-> 결국 L/R 중 어느 쪽에 속하는지 판별해 범위를 절반으로 줄이는 것.  
*그 '판별' 에 shift 된 상황을 활용.__
</br>

- ⭐ 예외 케이스: 범위에 속한 숫자가 하나뿐일 경우
  `nums = [3, 1], target = 3` 인 테스트 케이스에서 `-1(찾을 수 없음)` 이라는 틀린 답이 나왔다.  
  이는 처음에 '왼쪽이 정렬된 경우' 의 로직을 `nums[left] < nums[mid]` 로 설정했기 때문.  
  `(left == mid)` 일 경우, 즉 (왼쪽) 범위에 속한 숫자가 하나인 경우에는 (당연하게도) `nums[left] == nums[right]` 이 된다.  
  이처럼 같은 경우를 포함시키지 않으면 어느 곳에도 속하지 못해 `-1` 이라는 결과가 나오게 되는 것.  


