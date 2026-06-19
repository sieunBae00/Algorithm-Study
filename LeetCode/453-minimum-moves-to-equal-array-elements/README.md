<h2><a href="https://leetcode.com/problems/minimum-moves-to-equal-array-elements">Minimum Moves to Equal Array Elements</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given an integer array <code>nums</code> of size <code>n</code>, return <em>the minimum number of moves required to make all array elements equal</em>.</p>

<p>In one move, you can increment <code>n - 1</code> elements of the array by <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Only three moves are needed (remember each move increments two elements):
[1,2,3]  =&gt;  [2,3,3]  =&gt;  [3,4,3]  =&gt;  [4,4,4]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,1,1]
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li>The answer is guaranteed to fit in a <strong>32-bit</strong> integer.</li>
</ul>


---

### Idea

#### 문제 설명  

`n`개 원소로 구성된 배열이 주어졌을 때, 한 번당 `n-1` 개의 원소를 `1`만큼 증가시킬 수 있다. (즉 원소 하나만 제외하고 모두 증가)  
모든 원소의 값이 같아지려면 최소 몇 번 수행해야 하는가?  
</br>

가장 작은 원소 `n-1` 개를 `1` 증가시킨다고 생각하면... = __제일 큰 원소 하나만 빼고 모두 `1`씩 증가.__  
-> 우선순위큐? 는 안됨. `n-1` 개씩 뺴고 다시 넣고 할 수가 없음..
</br>

정렬을 한번 하긴 해야 할 것 같은데...  
정렬 후 -> 가장 작은/큰 원소 차이 비교. ?  

__"제일 큰 원소를 `1` 감소시킨다"__ 는 관점으로 접근하면...  
-> 모두 같아졌다는 건 어떻게 확인?   
   
확인 필요 없이 바로 횟수 계산 가능.  
`[1,2,3]` 배열이 주어지면 -> 제일 큰 원소를 `1` 감소시킨다 -> 최종 배열 `[1,1,1]`  

> 💡 가장 작은 원소와 나머지 원소들 간의 차이만 누적해서 더하면 됨.  

