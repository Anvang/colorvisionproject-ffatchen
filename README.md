# Color blindness readability

## Description

This program prompts the user for integer values to be used as RGB color combinations for three different colors. The choice for three colors was chosen since the goal of this program is to create colorblind friendly graphs for those trying to visualize data. Since RGB values cannot be less than 0 or greater than 255 the program will repeat if invalid intergers are entered. Additionally, the program uses the weighted average method to produce the grayscale version of the three inputed colors. Then, the program saves the inputed RGB colors and the grayscale colors to a file of the users choice. These conversion will be used at a later time to check for colorblindness readability. In addition to RGB colors, the user has the option to choose general colors. At a later time shades of these general colors will be given to check for colorblindness readability.
# v0.2 Updates

Now, in addition to entering RGB values the user will have the option to enter a general color(s). In order to perform these tasks multiple times functionality has been added to the program. The functions that have been created are: a function to give the users the option to add a color or opt out, one to give the option to enter an RGB value or general color, one to enter RGB values, one to choose a general color, functions to display the RGB color(s) or general color(s), and a function to calculate the weighted grayscale RGB colors. Additionally,
a function was created in order to write to a file. Currently it is only used once, but it could be helpful to call upon in different sections of the program in future drafts.
## Developer

Faith Fatchen

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:
 g++ -std=c++11 main.cpp -o cvp; ./cvp
You will be prompted to pick the hue of red, green and blue for any number of colors or pick a general color from a list.
 The grayscale of the colors chosen via RGB values will then be 
 calculated to check for colorblindness readability.
Would you like to enter (R)GB values or a (g)eneral color?
r
Please give a value between 0-255 for the intensity of red.
7
Please give a value between 0-255 for the intensity of green.
8
Please give a value between 0-255 for the intensity of blue.
9
Please enter (a) to add another color or (q) to quit
a
Would you like to enter (R)GB values or a (g)eneral color?
g
Please choose a general color: (r)ed, (g)reen, or (b)lue?
r
You have one more option to add another color.
Please enter (a) to add another color or (q) to quit
q
7,8,9,
red,
The RGB color(s) chosen is/are:
7,8,9,
The grayscale RGB color(s) is/are:
2,4,0,
The general color(s) is/ are:
red,
What file would you like to save these colors to?
text.txt
Thank you for inputing your color choices. At a later time we will report the colorblindness readability.

## C++ Guide

### Variables and Data Types

Characters were used to store decisions returned from functions that give users different options. Vectors of integers were utilized to store the integer RGB values for the original color and grayscale color. Previously, individual integers were used to store each intensisty of the RGB colors. The vectors allow the program to store each RGB color in one place. Integers are the necessary datatype for the variables since RGB values must be whole numbers. Alternatively to a vector, an array of three components could have been declared, but the functionality of vectors such as adding to the vector was useful in the function that obtains the values for the vectors. Additionally, a vector of strings was used to store the general color choices. A vector was chosen instead of an array because in the future the program may allow for users to choose more options. Hence,the size of would need to be adjustable.

### Input and Output

In order to prompt the users decisions whether to enter a RGB or general color and whether or not to add an additional color or general color a cout statement was used, and cin is used to capture the users response. Cin is appropriate because ignore white space should not be necessary. Within the function that prompts the user to enter the desired RGB value or general color a cout is used to do so. To capture this desired statement a cin statement is used. Cin is sufficient since the only input needed at this stage is an integers or character. Hence we don't need to use getline() to ignore potential whitespace. Additional cout statements were used to print out the RGB, grayscale, and general colors to the user. Cout was chosen because we wanted the user to see their choices while using the program. Cout statements were also used to prompt the user to enter a filename, and cin statements were used to capture the filename. Again, the filename is not expected to have whitespace, so cin is sufficient. 

### Decisions

In order to use the users decisions whether to enter and RGB color or general color if and else if were used. Else if was used instead of else in order to better understand the program. With the else if statement the condition explicitly shows what the program is directed to do for the decision of the user. If and else if statements were also used to direct the program based on the users input from the function that allows them to add or quit. The if and else if statements were chosen for the same reasons as above. Additionally, if statements were used to check the size of vectors before calling upon the display functions. If statements were used for each vector instead of else if since we wanted to check each condition. Within the function capturing the users general color choices, if, else if, and else statements were used for the color choice. Else if and else statements are appropriate since there will only be one color chosen, so if one statement is true we do not need to check the others. Else is sufficient for the last condition since the loop used in the function will only break when one of the three choices is entered. Hence, it is not a concern that the else statement would be invoked for an invalid choice.

### Iteration
A for loop was used within the display functions to print out the vectors. A for loop is the appropriate choice since we want the program to run through the loop a certain amount of times, in this case for the length of the vectors. Do- while loops were used within the functions capturing the users choices (whether to input a RGB or general color) in order to repeat the prompt for the choices while an invalid character was entered. Again, a do-while loop was used to repeat the request for RGB value and the general color character if an invalid value was entered. Do while loops are the most desirable because the code inside the loop needs to be executed at least once.


### File Input and Output

In addition to couting the RGB and grayscale choices, the user chooses a file to write the choices too. Since we are writting to a file, the file is opened using ios::app. Append was chosen over ios:writte so we can continue to add to the file without writting over the previous entries.

### Arrays/Vectors
Vectors are used to store both the general colors and the RGB values. One vector is used for to store all the general colors. This appropriate because it allows the colors to all be stored in one place, and then they can all be called upon. Also, the push_back function is used to continue adding upon the vector of general colors. Depending on feedback from the stakeholder, the program may eventually give the option to add more colors, so the varying size of the vector would be necessary. Additionally a vector of integers is used to store the RGB values. This is appropriate because we want to store all the values together. An array could also be used in order to maintain a fixed size, since we will always only want three integer values per color. The functions that input the RGB values only allow for three inputs, so having a vector that has too many values is not a problem. The functions assign the RGB values in the correct order beginning with the red value at place [0] and ending with the blue value at place [2]. Vectors are also used to store the grayscale RGB values, the use of these is the same as the original RGB vectors.

### Functions
The two functions for displaying the general colors and RGB values have the return type "void" because the purpose of the display functions is to print. The parameters needed are the general colors string vector and the RGB values vector, respectively. Nothing is going to be returned for use. These functions are needed because they are called upon multiple times. Another function which prompts the user with the option to add another color or quit returns the inputed character because this is used for decisions. The second function that returns a character gives the use the option to choose a general color or enter RGB values. The returned character is again used within the program for decisions. Again, this function is appropriate because it is called upon multiple times. Neither of these functions require parameters since their purpose is just to get and return user input. The function that is used to input the RGB values returns a vector, which is appropriate because the vector is used within the function. This function also does not require a parameter it just returns the vector to be stored in a vector declared in the program. Passing by reference would not be appropriate here because the program needs multiple to be used to create multiple vectors. The function that gets the general colors returns a string. This string is then added to the vector of general colors. Alternatively to this format the function could be void, and the vector of general colors could be passed by reference and the inputed string could be added to the vector. Both of the functions are appropriate because they are called upon multiple times. The function that is used to calculate the the grayscale vectors uses the return type void. This is appropriate because because it takes in the RGB vector then using pass by reference alters the grayscale vector.