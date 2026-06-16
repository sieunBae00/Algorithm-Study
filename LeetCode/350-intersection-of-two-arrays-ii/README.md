<h2><a href="https://leetcode.com/problems/intersection-of-two-arrays-ii">Intersection of Two Arrays II</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Given two integer arrays <code>nums1</code> and <code>nums2</code>, return <em>an array of their intersection</em>. Each element in the result must appear as many times as it shows in both arrays and you may return the result in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,2,1], nums2 = [2,2]
<strong>Output:</strong> [2,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [4,9,5], nums2 = [9,4,9,8,4]
<strong>Output:</strong> [4,9]
<strong>Explanation:</strong> [9,4] is also accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>0 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>What if the given array is already sorted? How would you optimize your algorithm?</li>
	<li>What if <code>nums1</code>&#39;s size is small compared to <code>nums2</code>&#39;s size? Which algorithm is better?</li>
	<li>What if elements of <code>nums2</code> are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?</li>
</ul>


---

### Idea

일단 생각나는 건 배열의 각 원소마다 다른 배열 전체 순회하며 교집합 원소를 찾는 것.  
<-- 시간복잡도 `O(n^2)`  
</br>

-> 두 배열 모두 정렬하고 시작하자.  
  
정렬만 하면 그 다음부터는 쉬워진다.   
두 배열에 각 하나씩 포인터를 두고, 더 작은 쪽의 포인터를 전진시키면 된다.   
그러다가 같은 값을 만나면 정답 배열에 추가.  
<-- 시간복잡도 `O(nlogn + mlogm)`  

