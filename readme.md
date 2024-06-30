# COP 1334 Assignment - Introduction to C++

## Chapter 7 Challenge 10 (Variant)

## Title: Exam Grading

### Exercise Description:

This is a modification of the program challenge in the book.

Driver’s License Exam The local Driver’s License Office has asked you to write a program that grades the written portion of the driver’s license exam.

The exam has 20 multiple-choice questions. Here are the correct answers:

|           |           |            |            |
|-----------|-----------|------------|------------|
| **1.  A** | **6. B**  | **11.  A** | **16.  C** |
| **2.  D** | **7. A**  | **12.  C** | **17.  C** |
| **3.  B** | **8. B**  | **13.  D** | **18.  A** |
| **4.  B** | **9. C**  | **14.  B** | **19.  D** |
| **5.  C** | **10. D** | **15.  D** | **20.  B** |

Your program should store the correct answers shown above in an vector. Create a char vector called vCorrectAnswers and initialize with the correct answers

It should ask the user to enter the student’s answers for each of the 20 questions, and the answers should be stored in another another vector<char>

After the student’s answers have been entered, the program should display a message indicating whether the student passed or failed the exam. (A student must correctly answer 15 of the 20 questions to pass the exam.)

It should then display the total number of correctly answered questions, the total number of incorrectly answered questions, and a list showing the question numbers of the incorrectly answered questions. Input Validation:

Only accept the letters A, B, C, or D as answers.

Use the following functions:

vCorrectAnwers = loadCorrect()

vDriverAnswers = getDriverAnswers

getDriversAnswers call bool validateAnswer(char) which returns true if the answer is A, B, C, or D.

numCorrect = gradeExam(const vector<char>&,const vector<char>&, vector<char>&); which returns the number of correct answers

create a vector<char> vIncorrectAnsers in main that stores all of the incorrect answers. Pass vCorrectAnswers, vDriverAnswers, vIncorrectAnswers);

gradeExam will compare exam answers with correct answers that will do the following:

If the answer is correct update numCorrect else as the index + 1 to  vIncorrectAnswers. Note the first two are passed as a constant and vIncorrectAnswers is passed by reference so it can be changed

bool passExam returns true is numCorrect  is 15 or more. Remember to use a constant to determine numbers of questions correct needed to pass.

Write a function displayResults(int, vector<char>);

The function will receive the numCorrect and a vIncorrect.

It will display the number correct, where or not the user passed, and the incorrect answers question number(the index + 1)

Program must be fully commented. All variables initialized and commented

All functions must be fully commented.

You may use chatGPT to provide comments but you may not use it to write any of your code.

Include a statement at the top that states the following:

//I did not use chatGPT or any outside source to assist me with the code.

I will go over this next class but I recommend starting on it behand so you can ask questions.



## Execution from the Terminal (Alternative way without an IDE):

We must provide to the Compiler the same switches that we usually do in the IDE:

```terminal
g++ -Wall -std=c++17 main.cpp
```

That will create a file named 'a.out' if you are working in MacOS or a .exe file if you are on Windows. That's the default executable file's name when we don't provide a name.

But we can also specify the name of the resulting executable file:

```terminal
g++ -Wall -std=c++17 main.cpp -o your_prefered_executable_file_name
```

And in order to run that a.out file, we must execute on the terminal:

```terminal
 % ./a.out
```

## Result of Execution on the Terminal (MacOS example):

```terminal
reinier@reinier % ./your_prefered_executable_file_name

Welcome to Exam Grader Pro.

Please type the answer for the 1st question (A, B, C, or D): a
Please type the answer for the 2nd question (A, B, C, or D): d
Please type the answer for the 3rd question (A, B, C, or D): b
Please type the answer for the 4th question (A, B, C, or D): as
That's not a single character. Try again.
Please type the answer for the 4th question (A, B, C, or D): 3
Invalid input. Please try again.
Please type the answer for the 4th question (A, B, C, or D): a
Please type the answer for the 5th question (A, B, C, or D): a
Please type the answer for the 6th question (A, B, C, or D): a
Please type the answer for the 7th question (A, B, C, or D): a
Please type the answer for the 8th question (A, B, C, or D): b
Please type the answer for the 9th question (A, B, C, or D): c
Please type the answer for the 10th question (A, B, C, or D): d
Please type the answer for the 11th question (A, B, C, or D): a
Please type the answer for the 12th question (A, B, C, or D): c
Please type the answer for the 13rd question (A, B, C, or D): d
Please type the answer for the 14th question (A, B, C, or D): b
Please type the answer for the 15th question (A, B, C, or D): d
Please type the answer for the 16th question (A, B, C, or D): c
Please type the answer for the 17th question (A, B, C, or D): c
Please type the answer for the 18th question (A, B, C, or D): a
Please type the answer for the 19th question (A, B, C, or D): d
Please type the answer for the 20th question (A, B, C, or D): b

Driver License Exam Official Results
Final Score: 17/20 points.
As a result: Congratulations! You passed the Driver License Exam.

Detailed Results: 
-----------------------------------------------------
| Question # | Your answer | Correct Answer | Score |
-----------------------------------------------------
|      1     |      A      |        A       |   1   |
-----------------------------------------------------
|      2     |      D      |        D       |   1   |
-----------------------------------------------------
|      3     |      B      |        B       |   1   |
-----------------------------------------------------
|      4     |      A      |        B       |   0   |
-----------------------------------------------------
|      5     |      A      |        C       |   0   |
-----------------------------------------------------
|      6     |      A      |        B       |   0   |
-----------------------------------------------------
|      7     |      A      |        A       |   1   |
-----------------------------------------------------
|      8     |      B      |        B       |   1   |
-----------------------------------------------------
|      9     |      C      |        C       |   1   |
-----------------------------------------------------
|     10     |      D      |        D       |   1   |
-----------------------------------------------------
|     11     |      A      |        A       |   1   |
-----------------------------------------------------
|     12     |      C      |        C       |   1   |
-----------------------------------------------------
|     13     |      D      |        D       |   1   |
-----------------------------------------------------
|     14     |      B      |        B       |   1   |
-----------------------------------------------------
|     15     |      D      |        D       |   1   |
-----------------------------------------------------
|     16     |      C      |        C       |   1   |
-----------------------------------------------------
|     17     |      C      |        C       |   1   |
-----------------------------------------------------
|     18     |      A      |        A       |   1   |
-----------------------------------------------------
|     19     |      D      |        D       |   1   |
-----------------------------------------------------
|     20     |      B      |        B       |   1   |
-----------------------------------------------------
| Final Amount of Points:                   |  17   |
-----------------------------------------------------
Thank you for using our services. Goodbye!
  
Process finished with exit code 0
reinier@reinier % 
```

### Author

**Reinier Garcia**

* [Github](https://github.com/reymillenium)
* [Twitter](https://twitter.com/ReinierGarciaR)
* [Linkedin](https://www.linkedin.com/in/reiniergarcia/)
* [Website](https://www.reiniergarcia.dev/)
* [Stack Overflow](https://stackoverflow.com/users/9616949/reinier-garcia)

### License

Copyright © 2024, [Reinier Garcia](https://github.com/reymillenium).


