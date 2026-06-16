<h2><a href="https://leetcode.com/problems/remove-element">Remove Element</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Given an integer array <code>nums</code> and an integer <code>val</code>, remove all occurrences of <code>val</code> in <code>nums</code> <a href="https://en.wikipedia.org/wiki/In-place_algorithm" target="_blank"><strong>in-place</strong></a>. The order of the elements may be changed. Then return <em>the number of elements in </em><code>nums</code><em> which are not equal to </em><code>val</code>.</p>

<p>Consider the number of elements in <code>nums</code> which are not equal to <code>val</code> be <code>k</code>, to get accepted, you need to do the following things:</p>

<ul>
	<li>Change the array <code>nums</code> such that the first <code>k</code> elements of <code>nums</code> contain the elements which are not equal to <code>val</code>. The remaining elements of <code>nums</code> are not important as well as the size of <code>nums</code>.</li>
	<li>Return <code>k</code>.</li>
</ul>

<p><strong>Custom Judge:</strong></p>

<p>The judge will test your solution with the following code:</p>

<pre>
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i &lt; actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
</pre>

<p>If all assertions pass, then your solution will be <strong>accepted</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [3,2,2,3], val = 3
<strong>Output:</strong> 2, nums = [2,2,_,_]
<strong>Explanation:</strong> Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [0,1,2,2,3,0,4,2], val = 2
<strong>Output:</strong> 5, nums = [0,1,4,0,3,_,_,_]
<strong>Explanation:</strong> Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 50</code></li>
	<li><code>0 &lt;= val &lt;= 100</code></li>
</ul>


---

### Idea

`val` 을 찾아 모두 지우고, `val`이 아닌 숫자(`k`개) 를 배열의 앞쪽에 몰아 넣어야 한다.  
주어진 배열 내에서(in-place) 해결해야 한다.  
배열의 앞쪽 `k`개의 원소만을 검사하므로, 뒤쪽 요소의 값은 신경쓰지 않아도 된다.
</br>

처음엔 투포인터를, 하나는 배열의 시작 / 다른 하나는 배열의 끝 에서 출발하려고 했다.    
그런데 여러 케이스에 대해서 예외처리가 복잡해 코드가 지저분해졌다...
</br>

'''text  
-> 투포인터는 유지하되, 두 개의 포인터 모두를 `0`번 인덱스에서 출발하도록 한다.  
배열을 순회하는 포인터(`fast`)와, 다음 유효한 숫자를 덮어쓸 위치를 가리키는 포인터(`slow`) 로 역할을 구분한다.  
💡 `fast` 가 배열을 순회하다가 유효한 숫자(=`val` 이 아닌 숫자) 를 만나면, `slow` 위치에 그 숫자를 덮어쓴다. 그 후 `slow` 를 하나 전진시킨다.  
'''
    
⭐ __**오해해서는 안되는 포인트:__ `slow` 가 `val` 인 위치에만 멈추는 것이 아니다. `slow` 는 __"매 칸에" 멈춘다.__  
다만 `fast` 는 "`val` 을 만났을 때" 무시하고 지나간다. `fast` 가 유효한 숫자에서만 멈추어 그 숫자를 `slow` 위치에 덮어쓴다.  
  
--> 결론적으로 "유효한 숫자의 수만큼" `fast` 가 `slow` 를 덮어쓰게 된다. = 유효한 숫자들이 배열의 앞부분에 위치하게 된다.   
마지막으로, (`slow` 가 전진한 횟수) = (유효한 숫자의 수) 이므로 `slow` 를 `return` 하면 된다.  
