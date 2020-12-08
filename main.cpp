#include <iostream>
#include <fstream>
#include <vector>
#include "colors.h"

using namespace std;
void displayGeneralColors(const vector <string> & colors);
char chooseRGBorGeneralorDefault();
string getGeneralColors();
vector <int> getRGB();
void fileWriter(const vector <int> &, const vector <int> &);

int main()
{ 
  vector<int> inputRGB;
  vector <int> forUserGrayRGB;
  vector <int> GrayRGB;
  colors RGB1;
  string filename;
  fstream filewriter;
  char colorType;
  vector <string> generalColors;

  cout<< "You will be prompted to pick the hue of red, green and blue for any number of colors or pick a general color from a list.\n The grayscale of the colors chosen via RGB values will then be \n calculated to check for colorblindness readability."<<endl;
  
  // Allowing the user to choose to enter RGB values, default grayscale RGB color, or to choose a general color
  colorType = chooseRGBorGeneralorDefault();
  if(colorType == 'r' || colorType == 'R')
  {
  inputRGB = RGB1.getRGB();
  RGB1.setRGB(inputRGB);
  RGB1.strongestColor();
  GrayRGB = RGB1.CalcGrayscaleRGB();
 
  }
  else if( colorType == 'd'|| colorType == 'D')
  {
    forUserGrayRGB = RGB1.givingDefaultRGB();
    RGB1.setRGB(forUserGrayRGB);
  }
  else
  {
   generalColors.push_back(getGeneralColors());
  }

  RGB1.displayRGB();

  if(generalColors.size()>0)
  {
    cout << "The general color(s) is/ are:"<<endl;
    displayGeneralColors(generalColors);
  }
  fileWriter(inputRGB, GrayRGB);
  
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
void displayGeneralColors(const vector <string> &colors)
{ 
  cout<< "The general colors are:"<<endl;
  for(int i = 0; i < colors.size(); i++)
  {
    cout<< colors[i]<< ",";
  }
  cout<< endl;
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