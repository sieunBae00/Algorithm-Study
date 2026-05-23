<h2><a href="https://leetcode.com/problems/two-sum">Two Sum</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Given an array of integers <code>nums</code>&nbsp;and an integer <code>target</code>, return <em>indices of the two numbers such that they add up to <code>target</code></em>.</p>

<p>You may assume that each input would have <strong><em>exactly</em> one solution</strong>, and you may not use the <em>same</em> element twice.</p>

<p>You can return the answer in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,7,11,15], target = 9
<strong>Output:</strong> [0,1]
<strong>Explanation:</strong> Because nums[0] + nums[1] == 9, we return [0, 1].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,4], target = 6
<strong>Output:</strong> [1,2]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,3], target = 6
<strong>Output:</strong> [0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= target &lt;= 10<sup>9</sup></code></li>
	<li><strong>Only one valid answer exists.</strong></li>
</ul>

<p>&nbsp;</p>
<strong>Follow-up:&nbsp;</strong>Can you come up with an algorithm that is less than <code>O(n<sup>2</sup>)</code><font face="monospace">&nbsp;</font>time complexity?

---

### Idea

가장 쉽게 생각한다면, 이중 반복문을 돌며 두 수의 합이 `target` 이 되는 순간의 인덱스를 반환하면 된다.  
    
- __Follow-Up:__ `O(n^2)` 보다 적은 시간 안에 해결하려면?
  탐색 시간이 `O(1)` 인 `unordered_set` 을 떠올려볼 수 있다.  
  그런데 이 문제에서는 단순히 존재 여부를 확인하는 것이 아니라, 그 인덱스를 알아야 하므로, `(key, value)` 쌍을 저장할 수 있는 `unordered_map` 을 사용한다.  
    
  `unordered_map` : 해시 테이블로 구현됨. 삽입/삭제/탐색 평균 `O(1)` 안에 가능. 중복 허용 x. (덮어씌워짐)  

  > ⭐ 입력 배열을 `unordered_map` 에 모두 넣고 시작하는 것이 아니다. !!  
  > 배열을 딱 한 번만 순회.   
  > map 에 내가 찾는 수(나와 더해서 target 이 되는 수)가 있는지 확인.  
  > 없다면 나를 map 에 넣고 전진(인덱스+1)  
</br>

- 🛑 `unordered_map`은 중복을 허용하지 않는데, 입력 배열에는 같은 원소가 존재할 수 있다. 이것이 풀이에 지장을 주지 않는가?   
  -> `target` 을 만드는 경우의 수는 단 하나만 존재한다.   
  즉, `[3,3,3]` 과 같이 같은 수가 세 번 나오거나, `[3,3,2]` 이고 `target=5` 인 경우는 입력으로 주어지지 않는다는 이야기.  
    
  그렇다면 애초에 `unordered_map` 에 중복되는 `key` 가 들어갈 일이 없거나, 들어간다 해도 그것은 정답과 관계 없는 수이므로 문제가 없다. 
