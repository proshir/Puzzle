## Problem Description:

We aim to design a program that enables all users to create and solve 15x15 crossword puzzles. Initially, no puzzles exist. Users can create a new puzzle by entering the "make" command or solve an existing puzzle by entering the "solve" command.

Please refer to the provided image for column and row numbering:
![jadval](https://github.com/proshir/Puzzle/assets/19504971/fb83f98f-35e2-482a-84b4-81aad755b76f)

Throughout this program, the pattern "question number-h-row number" is used for horizontal questions, and "question number-v-column number" for vertical questions.

# Getting Started:

The program starts by displaying the message: "enter 'solve' to solve one of the available crossword puzzles or 'make' to create a new one!" Users must enter one of these two commands. If any other input is given, the program responds with "invalid input!"

Please note that the program is not case-sensitive regarding uppercase and lowercase letters in input. However, all outputs are displayed in lowercase. Additionally, the program does not print outputs for entering blank lines.

### Command: make

By entering this command, the program prompts the user to input coordinates for filled squares ("which squares are black?"). Users enter the coordinates for each filled square on separate lines and conclude with "***" to indicate the end of input. The coordinates for each square are in the format "column number-row number." For instance, to specify the third square from the left in the first row, use the pattern "1-3."

Next, the program asks users to input questions and answers ("enter questions and answers"). Input in this section begins with the program receiving the first question for the first vertical column ("1-v-1:") and continues as users provide questions and answers in consecutive lines. The program determines how many questions to ask for each column based on the filled square coordinates. After receiving the last question and answer for the 15th vertical column, the same process repeats for horizontal rows starting with "1-h-1." Upon receiving the last question and answer for the 15th horizontal row, the program prints "!the crossword puzzle made successfully."

All input in this section is validated for accuracy. The program ensures a maximum of five puzzles can be created.

### Command: solve

After entering this command, the program prompts the user to choose from available puzzles. For instance, if three puzzles have been created so far, the message "choose from [1,3]:" is displayed, and the user enters the desired number. If the entered number is outside the specified range or any other input is provided, the program asks the user to enter a valid number ("invalid input, please choose from [1, 3]"). If only one puzzle is available, the program does not ask for user input. If no puzzles have been created, it displays the message "there is no crossword puzzle to solve!"

After choosing a puzzle, the program displays it. Once the solving process begins, the user can only input commands to view questions (q), answer questions (a), request help (h), or finish (finish). Any other input results in "invalid input!"

### Command: View Questions (q)

To view a question, the user inputs, for example, "q 1-H-3" to view the third question in the first horizontal row. If the numbers to the right or left are invalid, the program responds with "invalid input!"

### Command: Answer Questions (a)

To answer questions, the user inputs, for example, "a 1-H-3 programming" to answer the third question in the first horizontal row with the answer "programming." If the numbers to the right or left are invalid or no answer is provided after the question number, the program responds with "invalid input!" If the answer is incorrect, the program prints "wrong answer!" If the answer is correct, the program makes necessary updates and displays the puzzle.

### Command: Finish

Entering this command in the "solve" mode ends the puzzle-solving process, and everything reverts to the initial state. The program prompts the user to enter either "solve" or "make." If any other input is given, the program responds with "invalid input!"

### Scoring System:

For the puzzle-solving process, the program provides a scoring mechanism. Users earn points by correctly guessing the letters in a word based on the number of letters. However, there is also a "help" command that, when used, deducts five points from the user's score. Users can only use the "help" command if their score is above or equal to 10. If all the letters in an answer are correctly guessed, the program prints "!you've completed this answer!" After solving or finishing, the program displays the user's score as a percentage (e.g., "rate: 75").
