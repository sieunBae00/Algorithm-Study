<h2><a href="https://leetcode.com/problems/find-the-difference-of-two-arrays">1392. Find the Difference of Two Arrays</a></h2><h3>Easy</h3><hr><p>Given two <strong>0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code>, return <em>a list</em> <code>answer</code> <em>of size</em> <code>2</code> <em>where:</em></p>

<ul>
	<li><code>answer[0]</code> <em>is a list of all <strong>distinct</strong> integers in</em> <code>nums1</code> <em>which are <strong>not</strong> present in</em> <code>nums2</code><em>.</em></li>
	<li><code>answer[1]</code> <em>is a list of all <strong>distinct</strong> integers in</em> <code>nums2</code> <em>which are <strong>not</strong> present in</em> <code>nums1</code>.</li>
</ul>

<p><strong>Note</strong> that the integers in the lists may be returned in <strong>any</strong> order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,3], nums2 = [2,4,6]
<strong>Output:</strong> [[1,3],[4,6]]
<strong>Explanation:
</strong>For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums1. Therefore, answer[1] = [4,6].</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums1 = [1,2,3,3], nums2 = [1,1,2,2]
<strong>Output:</strong> [[3],[]]
<strong>Explanation:
</strong>For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 1000</code></li>
	<li><code>-1000 &lt;= nums1[i], nums2[i] &lt;= 1000</code></li>
</ul>


---

### Idea

처음 생각) 다른 한 배열에 있는지/없는지를 판단해야 한다. 원소 개수의 영향을 받지 않으므로 `unordered_set` 을 사용한다.   
</br>

- 🛑 처음에 `nums1[]`, `nums2[]` 를 각각 순회하면서 `set2`, `set1` 에 있는지를 검사했는데, 문제가 생겼다.    
  -> `nums1[]`, `nums2[]` 는 중복 제거가 안 된 상태이므로 같은 숫자에 대해 여러 번 검사하고, 그에 따라 원소를 여러 번 추가하게 되는 경우가 있기 때문이다.    
  그러나 문제에서는 원소의 개수는 상관 없이 해당 원소가 다른 배열에 있는지/없는지만 판단하면 된다.    
  => __`nums1[]`, `nums2[]` 가 아닌 `set1`, `set2` 를 순회__ 하며 각 원소가 다른 하나의 `set(set2/set1)` 에 있는지를 검사한다.   
  
- ⭐ unordered_set 을 순회하는 방법    
  `unordered_set` 은 인덱스로 접근이 불가능하다. `iterator` 를 사용하여 순회한다. 다음과 같이 코드를 활용할 수 있다.
  ``` cpp
  for(auto it = set.begin(); it != set.end(); ++it){ // iterator 자료형이 복잡하므로 auto 사용
     cout << *it << endl; // '*it' 으로 요소의 값에 접근
  }
  ```
