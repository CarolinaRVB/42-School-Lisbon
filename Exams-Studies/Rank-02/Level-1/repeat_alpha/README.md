### 💡 Description of solution : (41 lines of code)
--------------------------------
<p> <b>1.</b> Code consists of a program that takes a string as an argument, and writes each alphabetical character of the string "x" times according to it's alphabetical index.</p>
<p> <b>2.</b> To do so, first i check if the number of arguments passed to the program are valid (the program and the string), and if the string is not empty. If true, the program should write a newline character and terminate. </p>
<p> <b>3.</b> If not true, i create two array variables to store the alphabetical characters in order: one in capital and one in small case. This will allow the program to obtain the correct index associated to each character (a = 1, b = 2, c = 3 etc ...).</p>
<p> <b>4.</b> I begin my loop that will continue until the character from the string passed as a parameter is the null character. Inside this loop check if the string character is not an alphabetical character. If not i just write that character. Then i have another loop that will iterate through each character in the two arrays that contain the alphabetical characters.</p>
<p> <b>5.</b> Inside this second loop, i will check the condition if the current character in the string is equal to the first character of one of the two arrays. If not i will increment the character in the array to the next character.</p>
<p> <b>6.</b> If the current character in the string is equal to the character of the array. Then i initiate another loop limited by the value of that index, and i call the "write" function "x" number of times until the value of that index reached zero.</p>
<p> <b>7.</b> After i reset the index variable used in the arrays, to zero, and i increment the variable in my string.</p>
<p> <b>8.</b> Finally i write a newline character and terminate the program.</p>

<br>
<p><b>NOTE:</b> I should optimise this program, right now the if the character is a number, the program will enter correctly the first "if" condition to write the number, however it will also enter the second loop afterwards, which is searching for a match between the character and one character from the arrays. However this step is not necessary.</p>
