<h2><a href="https://leetcode.com/problems/find-peak-element">162. Find Peak Element</a></h2><h3>Medium</h3><hr><p>A peak element is an element that is strictly greater than its neighbors.</p>

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, find a peak element, and return its index. If the array contains multiple peaks, return the index to <strong>any of the peaks</strong>.</p>

<p>You may imagine that <code>nums[-1] = nums[n] = -&infin;</code>. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.</p>

<p>You must write an algorithm that runs in <code>O(log n)</code> time.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 3 is a peak element and your function should return the index number 2.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,3,5,6,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>nums[i] != nums[i + 1]</code> for all valid <code>i</code>.</li>
</ul>


---

### Idea

처음 생각)    
배열에서 중복된 원소가 가능하지만, '바로 옆' 과 같은 경우는 없다.    
peak 이 아니면 -> 적어도 하나의 원소가 나보다 크다. -> 해당 원소는 자신보다 작은 이웃 하나를 확보한 것이므로 peak 의 가능성이 있음. -> 확인.     
*시작은 어디부터? -> 가운데부터 시작하면 오히려 힘들 수도.. (왼/오 모두 클 때 어떻게 해야할지?) -> 왼쪽 끝(인덱스0) 부터 시작. <- 방향 명확.    
    
🛑 그러나 위와 같은 아이디어는 `O(n)` 의 시간복잡도를 갖는다.  
우리는 `O(logn)` 으로 알고리즘을 구성해야 하며, 이를 위해서는 '이분 탐색'이 필수적이다.    
</br>  

문제의 핵심: 높은 쪽으로 계속 올라가다 보면, 반드시 `peak` 를 만난다.    
💡 __*되돌아올 일 없음. !!__    
    
따라서, 이분 탐색을 적용하여 높은 쪽으로 향하더라도, 그 길이 잘못되었을 리는 없다. (양쪽 다 높다면 -> 양쪽 모두에 `peak` 가 존재함이 보장된다.)    
    
*이분탐색의 종결조건 주의;    
종결조건을 `left <= right` 로 설정하면 무한루프에 빠질 수 있음.    
