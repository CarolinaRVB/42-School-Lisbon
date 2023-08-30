### 💡 Description of solution : (32 lines of code)
--------------------------------
<p> <b>1.</b> Code consists of a program to write the words "fizz", "buzz" or "fizzbuzz" if a number between 1 and 100 is multiple of 3, 5 or both. If not, the program should only write the number itself. Each output should be separated by a "newline (\n)" character. The program itself does not take any parameters, it should only give the output shown in the subject when compiled and run.</p>
<p> <b>2.</b> To do so, in my main i start a while loop that goes from 1 to 100 included.</p>
<p> <b>3.</b> For each number i check 3 conditions, the first checks if the number is multiple of both 3 and 5 (<b>NOTE:</b> it is important to write first this condition so that there is no repetition of words), of true the word fizzbuzz is written. Then i check if the number is multiple of just 3 (fizz) or just 5(buzz).</p>
<p> <b>4.</b> If none of the previous conditions is true, the program will call an auxiliary function called "write_num" to use the "write" function to write the characters of the number in the output.</p>
<p> <b>5.</b> After, the program will simply write a "newline  (\n)" character and iterate to the next number until it reaches the number 100.</p>
<p> <b>6.</b> Finally, the program terminates. </p>
