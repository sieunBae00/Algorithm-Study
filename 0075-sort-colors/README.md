<h2><a href="https://leetcode.com/problems/sort-colors">75. Sort Colors</a></h2><h3>Medium</h3><hr><p>Given an array <code>nums</code> with <code>n</code> objects colored red, white, or blue, sort them <strong><a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank">in-place</a> </strong>so that objects of the same color are adjacent, with the colors in the order red, white, and blue.</p>

<p>We will use the integers <code>0</code>, <code>1</code>, and <code>2</code> to represent the color red, white, and blue, respectively.</p>

<p>You must solve this problem without using the library&#39;s sort function.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,0,2,1,1,0]
<strong>Output:</strong> [0,0,1,1,2,2]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [2,0,1]
<strong>Output:</strong> [0,1,2]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == nums.length</code></li>
	<li><code>1 &lt;= n &lt;= 300</code></li>
	<li><code>nums[i]</code> is either <code>0</code>, <code>1</code>, or <code>2</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong>&nbsp;Could you come up with a one-pass algorithm using only&nbsp;constant extra space?</p>


---

### Idea

전에 풀었던 '짝수를 앞쪽으로 밀어넣는' 문제와 유사.  
  
다만 이 문제에서는 분류가 `0/1/2` 로 3개이므로, 경계를 가르는 포인터가 2개 필요.  
  
`left`: 0/1 사이 경계 포인터.   
`right`: 1/2 사이 경계 포인터.  
`curr`: 현재 숫자를 가리키는 포인터.  
  
``` text
0을 만난다면: left <-> curr 를 swap.   
0이 올바른 자리로 갔으니, left와 curr 를 한 칸 전진.  
  
2를 만난다면: right <-> curr 를 swap.   
2가 올바른 위치로 갔으니 right 를 한 칸 앞으로. (right--;). 
**주의: right 와 swap 한 수를 아직 확인하지 않았으므로, curr은 전진하지 x.  
  
1을 만난다면: 1은 0과 2 사이에 있어야 하므로 swap 이 필요 x.  
curr 만 한 칸 전진.  
```

- 🛑 처음에 for 문을 돌며 `i`를 배열의 끝까지 전진시키도록 했다.  
  그러나 `curr` 가 기준이 되어야 하므로, 정해진 수만큼만 반복 후 종료하도록 하면 문제가 발생한다.  
  (⭐ `nums[curr] == 2` 일 경우 `curr` 가 증가하지 않기 때문. !!)    
  
  >💡 while (curr <= right) 으로 코드를 수정한다.  
</br>

- ⭐ `nums[curr] == 0` 일 경우에는 왜 `curr` 를 전진시키는가? (`left` 와 `swap` 한 후의 `curr` 를 알 수 없으니 전진시키면 안 되지 않나?)   
  __`left` 와 `swap` 한다는 건:__ `left` 는 이미 "지나온" 숫자이다.   
  지나오는 과정에서 `2` 는 이미 `right` 와 `swap` 했을 것이고, `left` 이전까지가 모두 `0`일 것이므로,
  `left` 와 `swap` 하는 경우 `curr` 로 날아오는 수는 __무조건 `1`__ 이 된다.  

