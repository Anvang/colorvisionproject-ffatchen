#include "colors.h"
#include <string>
#include <iostream>

using namespace std;
using std::string;

// To get the users RGB values 
void colors::getRGB()
{
  vector <int> gettingRGB;
  int red;
  int green;
  int blue;
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of red."<<endl;
  cin>>red;
  if(red < 0 | red > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  }while(red < 0 | red > 255);
  RGB.push_back(red);
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of green."<<endl;
  cin>>green;
  if( green < 0 | green > 255)
  {
  cout << "Invalid RGB value." <<endl;
  }
  }while(green < 0 | green > 255);
  RGB.push_back(green);
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of blue."<<endl;
  cin>>blue;
  if(blue < 0 | blue > 255)
  {
    cout << "Invalid RGB value." <<endl;
  } 
  }while(blue < 0 | blue > 255);
  RGB.push_back(blue);
  RGB = gettingRGB;
}

//To calculate the weighted grayscale for user's RGB values
void colors::CalcGrayscaleRGB()
{
  int gray1 = .3 * RGB[0];
  GrayscaleRGB.push_back(gray1);
  int gray2 = .59 * RGB[1];
  GrayscaleRGB.push_back(gray2);
  int gray3 = .11 * RGB[2];
  GrayscaleRGB.push_back(gray3);
}

//Displaying RGB values and Grayscale values 
void colors::displayRGB()
{
if(RGB.size()> 0)
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