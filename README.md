# !!!Replace with your unique project name!!!

## Description

This program prompts the user for integer values to be used as RGB color combinations for three different colors. Since RGB values cannot be less than 0 or greater than 255 the program will repeat if invalid intergers are entered. Additionally, the program uses the weighted average method to produce the grayscale version of the three inputed colors. Then, the program saves the inputed RGB colors and the grayscale colors to a file of the users choice.

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

Integer variables were used to store the users inputted choices for RGB color values. Integer varaibles were the best choice because RGB values need to be whole numbers. 
A string variable was declared in order to store the users inputed filename of choice. A string was appropriate because the filename could contain multiple charcters and be of different lengths.
An fstream variable was declared in order to open and write to a file. 

### Input and Output

In order 

### Decisions

!!!Replace with a summary and examples of how multiple decision constructs have been used effectively and appropriately!!!

### Iteration

!!!Replace with a summary and examples of how iteration has been used effectively and appropriately!!!

### File Input and Output

!!!Replace with a summary and examples of how input and/or output of files have been used effectively and appropriately!!!