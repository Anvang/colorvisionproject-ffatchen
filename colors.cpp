#include "colors.h"
#include <string>
#include <iostream>

using namespace std;
using std::string;

// Constructor for RGB vectors
colors::colors()
{
  RGB.push_back(0);
  GrayscaleRGB.push_back(0);
  defaultRGBColor.push_back(0);
  defaultRGBColor.push_back(0);
  defaultRGBColor.push_back(0);
}

//For access to default RGB
vector<int> colors::givingDefaultRGB()
{
  vector <int> defaultRGB;
  defaultRGB = defaultRGBColor;
  return defaultRGB;
}
bool colors::isUserRGBValid(vector <int> input)
{
  bool isValid;
  if(input[0]>= 0 && input[0]<= 255)
  {
    cout << "The first RGB value is valid"<<endl;
    isValid = true;
  }
  if(input[1]>= 0 && input[1]<= 255)
  {
    cout<< "The second RGB value is valid"<<endl;
    isValid = true;
  }
  if(input[2]>= 0 && input[2]<= 255)
  {
    cout<< "The third RGB value is valid"<<endl;
    isValid = true;
  }
  if(input[0]< 0 || input[0]>255 || input[1] < 0 || input[1] > 255 || input[2]< 0 || input[2]> 255)
  {
    cout<< "At least one RGB entry is invalid"<<endl;
    isValid = false;
  }
  return isValid;
}
//Setting the class RGB vector as the user's input
void colors::setRGB(const vector <int> & input)
{
  RGB = input;
}

// Checking to see if the rgb color is gray or if itis primarily red, blue, or green
void colors::strongestColor()
{
  // declaring integers for each intensity of red, blue, and green from the RGB vector
  int R = RGB[0];
  int B = RGB[1];
  int G = RGB[2]; 

  if(R == B && R == G)
  {
    cout<<"Your color is gray!"<< endl;
  }
  else if( R > B && R > G)
  {
    cout<< "Your color is primarily red"<<endl;
  }
  else if(B > R && B > G)
  {
    cout << "Your color is primarily blue"<< endl;
  }
  else if(G > R && G > B)
  {
    cout<<"Your color is primarily green"<<endl;
  }
}

//To calculate the weighted grayscale for user's RGB values
vector <int> colors::CalcGrayscaleRGB()
{
  GrayscaleRGB.pop_back();
  vector <int> GrayscaleToReturn;
  int gray1 = .3 * RGB[0];
  GrayscaleRGB.push_back(gray1);
  int gray2 = .59 * RGB[1];
  GrayscaleRGB.push_back(gray2);
  int gray3 = .11 * RGB[2];
  GrayscaleRGB.push_back(gray3);
  return GrayscaleRGB;
}

//Displaying RGB values and Grayscale values 
void colors::displayRGB()
{
if(RGB.size()> 1)
{
  cout<<"The RGB values are:"<<endl;
   for(int i = 0; i < RGB.size(); i++)
    {
    cout<< RGB[i]<< ",";
    }
  cout<<endl;
  cout<< " The grayscale RGB values are:"<<endl;
  for(int i = 0; i<GrayscaleRGB.size();i++ )
  {
    cout<<GrayscaleRGB[i]<<",";
  }
  cout<<endl;
}
}

