# Color blindness readability

## Description

This program prompts the user for integer values to be used as RGB color combinations for three different colors. Since RGB values cannot be less than 0 or greater than 255 the program will repeat if invalid intergers are entered. Additionally, the program uses the weighted average method to produce the grayscale version of the three inputed colors. Then, the program saves the inputed RGB colors and the grayscale colors to a file of the users choice. These conversion will be used at a later time to check for colorblindness readability.
# v0.2 Updates

Now, in addition to entering RGB values the user will have the option to enter a general color(s). In order to perform these tasks multiple times functionality has been added to the program. The functions that have been created are: a function to give the users the option to add a color or opt out, one to give the option to enter an RGB value or general color, one to enter RGB values, one to choose a general color, functions to display the RGB color(s) or general color(s), and a function to calcutlate the weighted grayscale RGB colors. Additionally, iteration and decisions have been added within the functions and in order to properly use the functions. #ADD ITERATION AND DECISION UPDATES
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
You will be prompted to pick the hue of red, green and blue for three different colors. The grayscale of these colors will then be calculated to check for colorblindness readability.
For your first color:
Please give a value between 0-255 for the intensity of red.
1
Please give a value between 0-255 for the intensity of green.
2
Please give a value between 0-255 for the intensity of blue.
3
For your second color:
Please give a value between 0-255 for the intensity of red.
4
Please give a value between 0-255 for the intensity of green.
5
Please give a value between 0-255 for the intensity of green.
6
For your third color:
Please give a value between 0-255 for the intensity of red.
7
Please give a value between 0-255 for the intensity of green.
8
Please give a value between 0-255 for the intensity of blue.
9
The first color is :rgb(1,0,3)
The second color is :rgb(4,5,6)
The third color is : rgb(7,8,9)
The first grayscale color is: rgb(0,0,0)
The second grayscale color is: rgb(4,4,4)
The third grayscale color is: rgb(7,7,7)
What file would you like to save these colors to?
text2.txt
Thank you for inputing colors. At a later time we will report the colorblindness viewability of the color combinations. 



## C++ Guide

### Variables and Data Types

Integer variables were used to store the users inputted choices for RGB color values. Integer varaibles were the best choice because RGB values need to be whole numbers. Additional integer variables were declared for the grayscale RGB values, due to the same reasoning as above.
A string variable was declared in order to store the users inputed filename of choice. A string was appropriate because the filename could contain multiple charcters and be of different lengths.
An fstream variable was declared in order to open and write to a file. 

### Input and Output

In order to prompt the user to enter the desired input a cout is used to do so. To capture this desired statement a cin statement is used. Cin is sufficient since the only input needed at this stage are integers. Hence we don't need to use getline() to ignore potential whitespace. Additional cout statements were used to print out the RGB and grayscale colors to the user. Cout was chosen because we wanted the user to see their choices while using the program. Cout statements were also used to prompt the user to enter a filename, and cin statements were used to capture the filename. Again, the filename is not expected to have whitespace, so cin is sufficient. 

### Decisions

If statements were used to indicate to the user they entered an invalid RGB value. Only one condition was desired to be tested, so we used an if statement. A follow up statement(s) was/were not used so there was no need for else if and/or else decisions. 

### Iteration

A do-while loop was used to repeat the request for RGB values if an invalid value was entered. A do while loop is the most desirable because the code inside the loop needs to be executed at least once.


### File Input and Output

In addition to couting the RGB and grayscale choices, the user chooses a file to write the choices too. Since we are writting to a file, the file is opened using ios::app. Append was chosen over ios:writte so we can continue to add to the file without writting over the previous entries.

### Arrays/Vectors
Vectors are used to store both the general colors and the RGB values. One vector is used for to store all the general colors. This appropriate because it allows the colors to all be stored in one place, and then they can all be called upon. Additionally a vector of integers is used to store the RGB values. This is appropriate because we want to store all the values together. An array could also be used in order to maintain a fixed size, since we will always only want three integer values per color. The functions that input the RGB values only allow for three inputs, so having a vector that has too many values is not a problem. Vectors are also used to store the grayscale RGB values, the use of these is the same as the RGB values. 

### Functions
The two functions for displaying the general colors and RGB values have the return type "void" because the purpose of the display functions is to print. The parameters needed are the general colors string vector and the RGB values vector, respectively. Nothing is going to be returned for use. These functions are needed because they are called upon multiple times. 
Another function which prompts the user with the option to add another color or quit returns the inputed character because this is used for decisions. The second function that returns a character gives the use the option to choose a general color or enter RGB values. The returned character is again used within the program for decisions. Again, this function is appropriate because it is called upon multiple times. Neither of these functions require parameters since there purpose is just to get and return user input. The function that is used to input the RGB values returns a vector, which is appropriate because the vector is used within the function. This function also does not require a parameter it just returns the vector to be stored in a vector declared in the program. Passing by reference would not be appropriate here because the program needs multiple to be used to create multiple vectors. The function that gets the general colors returns a string. This string is then added to the vector of general colors. Alternatively to this format the function could be void, and the vector of general colors could be passed by reference and the inputed string could be added to the vector. Both of the functions are appropriate because they are called upon multiple times. The function that is used to calculate the the grayscale vectors uses the return type void. This is appropriate because because it takes in the RGB vector then using pass by reference alters the grayscale vector.