<h2><a href="https://leetcode.com/problems/generate-parentheses">Generate Parentheses</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given <code>n</code> pairs of parentheses, write a function to <em>generate all combinations of well-formed parentheses</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> ["((()))","(()())","(())()","()(())","()()()"]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 1
<strong>Output:</strong> ["()"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 8</code></li>
</ul>

---

### Idea

'모든 가능한 문자열' 배열을 Return 해야 한다.  
  
`n` 이 주어진다 -> 여는 괄호(`(`) `n` 개, 닫는 괄호(`)`) `n` 개 사용.  
</br>

🛑 '모든 경우의 수' 를 찾아내려면?   
-> 매번 '여는 괄호' / '닫는 괄호' 의 갈림길이 생긴다. (다만 각 경우에 대하여 가능한 조건이 존재.)   
매 갈림길에 대하여 여는/닫는 괄호가 가능한지 검사한다.  
  
목표를 달성했거나(문자열 완성)/불가능한 경우라면 -> __바로 이전 갈림길로 되돌아가서__ 다른 경우를 검사. (마치 미로 탐색)  
-> __BackTracking__ 이라 한다.  
  
> 💡 재귀함수(Recursion) !!!  
> 재귀적으로 호출하다가, retrun 되면? __바로 이전 함수로 돌아간다.__ !!  
</br>

``` text
여는 괄호(`(`) 가 가능하려면: n개를 다 쓰지 않았으면 가능  
닫는 괄호(`)`) 가 가능하려면: 여는 괄호보다 적게 사용했을 경우 가능  
```
</br>

- 🛑 재귀 함수에서 '변수'를 다루는 방식  
  처음에 재귀 함수를 아래와 같이 구성했다가, 동일한 문자열이 여러 번 만들어지게 되었다.  

``` cpp
/* 잘못된 코드*/

void make_parentheses(string current_str, int open, int close){
        if(open == 0 && close == 0){ // 종결조건
            ans.push_back(current_str);
            return;
        }
        if(open > 0){
            current_str.push_back('('); // 변수의 값 직접 변경
            open--; // 변수의 값 직접 변경
            make_parentheses(current_str, open, close);
        }
        if(open < close){
            current_str.push_back(')'); // 변수의 값 직접 변경
            close--; // 변수의 값 직접 변경
            make_parentheses(current_str, open, close);
        }
        return;
    }
```

  이유는 변수의 값(상태)를 직접 수정하고 있기 때문이다.  
  재귀 함수에서 변수의 값을 직접 수정하는 형태를 사용할 수도 있지만,  
  그러려면 반드시 특정 갈림길로 갔다가 되돌아올 경우 __"원래 상태로 되돌려 놓아야 한다."__  
  결국 이 문제에서는 변수의 값을 직접 수정하지 않고 복사본을 넘기는 식
  (```cpp 
  make_parentheses(current_str + "(", open-1, close);```)
  으로 수정했다.  
</br>

- ⭐ __값 복사해서 넘기기 v.s. 값 직접 수정&원상복구 하기__  
  각 방식에는 장단점이 있다.  
  
  - __값 복사해서 넘기기:__ 복사본을 만들어 넘겨주는 것이므로 원본이 바뀌지 않음, 코드의 간결성. 단, 넘겨주는 데이터의 크기가 큰 경우 메모리 사용량에 주의.  

  - __값 직접 수정&원상복구 하기:__ 원본을 수정하는 것이므로 메모리가 새로 할당되지 않아 성능이 우수. 재귀함수 호출 후(step over)에 반드시 원본으로 복구할 것.  


