#include <iostream>
#include <fstream>
#include <vector>
#include "colors.h"

using namespace std;
void displayGeneralColors(string);
char chooseRGBorGeneralorDefault();
vector <int> getUserRGB();
string getGeneralColors();
vector <int> getRGB();
void stringFileWriter(string);
void fileWriter(const vector <int> &, const vector <int> &);

int main()
{ 
  vector<int> inputRGB;
  vector <int> forUserGrayRGB;
  vector <int> GrayRGB;
  colors RGB1;
  string filename;
  bool validRGBCheck;
  fstream filewriter;
  char colorType;
  string generalColor;

  cout<< "You will be prompted to pick the hue of red, green and blue for any number of colors or pick a general color from a list.\n The grayscale of the colors chosen via RGB values will then be \n calculated to check for colorblindness readability."<<endl;
  
  // Allowing the user to choose to enter RGB values, default grayscale RGB color, or to choose a general color
  colorType = chooseRGBorGeneralorDefault();

  //If the user chooses to enter an RGB value
  if(colorType == 'r' || colorType == 'R')
  {
    /*Getting the user inputed RGB values and checking 
    if the inputs are valid*/

    do
    {
      inputRGB = getUserRGB();
      validRGBCheck = RGB1.isUserRGBValid(inputRGB);
    }while(validRGBCheck == false);
    RGB1.setRGB(inputRGB);
    RGB1.strongestColor();
    GrayRGB = RGB1.CalcGrayscaleRGB();
    RGB1.displayRGB();
 
  }

  /*If the user chooses to use a default RGB color, sets the RGB value to black */

  else if( colorType == 'd'|| colorType == 'D')
  {
    forUserGrayRGB = RGB1.givingDefaultRGB();
    RGB1.setRGB(forUserGrayRGB);
  }

  /* If the user chooses to enter a general color, allows the user to choose from a list of general colors*/

  else if (colorType == 'g'|| colorType == 'G')
  {
    generalColor = getGeneralColors();
    cout << "The general color is:"<<endl;
    displayGeneralColors(generalColor);
    stringFileWriter(generalColor);
}

  if(inputRGB.size()> 0)
  {
  fileWriter(inputRGB, GrayRGB);
  }
  cout<<"Thank you for inputing your color choices. At a later time we will report the colorblindness readability."<<endl;
  return 0;
}

// Function Definitions 

// To capture the users choice whether to enter RG values, general colors, or use a default grayscale RGB
char chooseRGBorGeneralorDefault()
{
  char colorType;
  do
  {
  cout<< "Would you like to enter (R)GB values, (g)eneral color, or use (d)efault grayscale RGB value?"<<endl;
  cin>> colorType;
  cin.ignore();
  }while(colorType != 'R' && colorType != 'r' && colorType != 'g' && colorType != 'G' && colorType != 'D' && colorType != 'd');
  return colorType;
}

// For displaying the string vector of general colors 
void displayGeneralColors(string generalColor)
{ 
  cout<< "The general color is:"<<generalColor<<endl;
 
}

// Getting RGB values from user
vector <int> getUserRGB()
{
  vector <int> RGB;
  int red;
  int green;
  int blue;
  cout<< "Please give a value between 0-255 for the intensity of red."<<endl;
  cin>>red;
  RGB.push_back(red);
  cout<< "Please give a value between 0-255 for the intensity of green."<<endl;
  cin>>green;
  RGB.push_back(green);
  cout<< "Please give a value between 0-255 for the intensity of blue."<<endl;
  cin>>blue;
  RGB.push_back(blue);
  return RGB;
}

// To get the users general color choice
string getGeneralColors()
{
  char colorchoice;
  do
  {
  cout<<"Please choose a general color: (r)ed, (g)reen, or (b)lue?"<< endl;
  cin>> colorchoice;
  }while(colorchoice != 'r' && colorchoice != 'R' && colorchoice != 'g' && colorchoice != 'G' && colorchoice != 'b' && colorchoice != 'B');
  if(colorchoice == 'r' || colorchoice == 'R')
  {
    string red = "red";
    return red;
  }
  else if(colorchoice == 'g' || colorchoice == 'G')
  {
    string green = "green";
    return green;
  }
  else
  {
    string blue = "blue";
    return blue;
  }
} 

// To capture the user's file choice and write the original and weighted grayscale RGB values to it
void fileWriter(const vector <int> & RGB, const vector <int> & Gray)
{
  string filename;
  fstream filewriter;
   do
  {
  
   cout<<"What file would you like to save these colors to?"<<endl;
   cin>>filename;
   filewriter.open(filename, ios::app);
   if( !filewriter.is_open())
    {
      cout<<"Error opening file.";
    }
  }while(!filewriter.is_open());

  if(RGB.size()> 0)
  {
    filewriter << "Your RGB color is: ("<< RGB[0] << ","<< RGB[1]<<","<< RGB[2]<<")"<<endl;
  }
  if(Gray.size()>0)
  {
    filewriter << "The weighted grayscale of this color is (" <<Gray[0] << ","<< Gray[1]<< ","<<Gray[2]<<")"<<endl;
  }

 filewriter.close();
}

// To capture the user's file choice and write the general color to it
void stringFileWriter(string generalColor)
{
  string filename;
  fstream filewriter;
  do
  {
  
   cout<<"What file would you like to save this color to?"<<endl;
   cin>>filename;
   filewriter.open(filename, ios::app);
   if( !filewriter.is_open())
    {
      cout<<"Error opening file.";
    }
  }while(!filewriter.is_open());

 
    filewriter << "The color chosen is"<<" "<< generalColor << endl;

 filewriter.close();
}