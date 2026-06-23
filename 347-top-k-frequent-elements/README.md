<h2><a href="https://leetcode.com/problems/top-k-frequent-elements">Top K Frequent Elements</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k</code> <em>most frequent elements</em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1,2,2,3], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,2]</span></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1], k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">[1]</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,1,2,1,2,3,1,3,2], k = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,2]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>k</code> is in the range <code>[1, the number of unique elements in the array]</code>.</li>
	<li>It is <strong>guaranteed</strong> that the answer is <strong>unique</strong>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Your algorithm&#39;s time complexity must be better than <code>O(n log n)</code>, where n is the array&#39;s size.</p>

---

### Idea

`priority_queue` + `unordered_map` 을 이용한다.  

1. 숫자별 등장 횟수 세기 (숫자, 등장 횟수)  
  `unordered_map<int, int>` 이용. 탐색 시간이 평균 O(1) 이므로 등장 횟수를 증가시킬 때에도 유리함. !!  
  ⭐ `map[n]++;` 으로 하고자 하는 모든 동작이 가능.  
    map 에 n 이 존재하지 않으면 -> (n, 0) 을 만들고, +1. 즉 (n, 1) 이 추가됨.  
    map 에 n 이 이미 존재하면 -> 원래 있던-n 에 대응하는-값에 +1.  
</br>

2. 우선순위 큐에 넣어서 자동으로 정렬하기 (등장 횟수, 숫자)  
   map 에 있던 쌍들을 전부 우선순위 큐에 넣은 후, 등장 횟수 기준으로 내림차순 정렬.  
   k개 만큼 pop() 해서 배열에 넣기(숫자)  
