### 💡 Description of solution : (9 lines of code)
--------------------------------
<p> <b>1.</b> Code consists of a function that mimics the "strcpy" function. The objective of this function is to copy the string "s2" into the string "s1" and return a pointer to the "s1" string.</p>
<div align="center"><i>
  <p><b>MAN STRCPY</b></p>
  DESCRIPTION
       The  strcpy() function copies the string pointed to by src, including the terminating null byte ('\0'), to the
       buffer pointed to by dest.  The strings may not overlap, and the destination string dest must be large  enough
       to receive the copy.  Beware of buffer overruns!
</i></div>
<br>
<p> <b>2.</b> To do so i have a while loop that iterates throught the source string "s2", until it finds null byte ('\0'). </p>
<p> <b>3.</b> In each iteration, it copies the current character into the destination "s1" string. </p>
<p> <b>6.</b> Finally, after the loop it add the null byte, therefore terminating correctly the destination "s1" string, and returns a pointer to it. </p>
