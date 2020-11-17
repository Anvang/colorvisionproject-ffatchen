#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void displayRGB( const vector <int> &);
void displayGeneralColors(const vector <string> & colors);
char chooseRGBorGeneral();
vector <int> getRGB();
string getGeneralColors();
void fileWriter(const vector <int> &, const vector <int> &);
void CalcGrayscaleRGB(vector <int>, vector <int> &);
int main()
{ 
  string filename;
  fstream filewriter;
  char colorType;
  vector <int> RGB1;
  vector <int> Gray1;
  vector <string> generalColors1;
  cout<< "You will be prompted to pick the hue of red, green and blue for any number of colors or pick a general color from a list.\n The grayscale of the colors chosen via RGB values will then be \n calculated to check for colorblindness readability."<<endl;
  // Allowing the user to choose to enter RGB values or choose a general color
  colorType = chooseRGBorGeneral();
  if(colorType == 'r' || colorType == 'R')
  {
   RGB1 = getRGB();
  }
  else
  {
   generalColors1.push_back(getGeneralColors());
  }
  
  //Calculating grayscale RGB values if the user chose to enter RGB values
  if(RGB1.size()>0)
  {
  CalcGrayscaleRGB(RGB1,Gray1);
  }
  {
  if(RGB1.size()>0)
  {
  displayRGB(RGB1);
  }
  if(Gray1.size()> 0)
  {
  cout<< "For the weighted grayscale"<<endl;
  displayRGB(Gray1);
  }
  if(generalColors1.size()>0)
  {
    cout << "The general color(s) is/ are:"<<endl;
    displayGeneralColors(generalColors1);
  }
  fileWriter(RGB1,Gray1);
  return 0;
}
}
// Function Definitions 
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
// For displaying the integer vector of RGB values
void displayRGB( const vector <int> & RGB)
{
  cout<<"The RGB values are:"<<endl;
   for(int i = 0; i < RGB.size(); i++)
    {
    cout<< RGB[i]<< ",";
    }
    cout<<endl;
}
//For capturing the users choice to enter RGB values or choose a general color
char chooseRGBorGeneral()
{
  char colorType;
  do
  {
  cout<< "Would you like to enter (R)GB values or a (g)eneral color?"<<endl;
  cin>> colorType;
  cin.ignore();
  }while(colorType != 'R' && colorType != 'r' && colorType != 'g' && colorType != 'G');
  return colorType;
}
// To get the users RGB values 
vector <int> getRGB()
{
  vector <int> RGB;
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
//To calculate the weighted grayscale for user's RGB values
void CalcGrayscaleRGB(vector <int> RGB, vector <int>& grayscale)
{
  int gray1 = .3 * RGB[0];
  grayscale.push_back(gray1);
  int gray2 = .59 * RGB[1];
  grayscale.push_back(gray2);
  int gray3 = .11 * RGB[2];
  grayscale.push_back(gray3);
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
  filewriter << "The first RGB color is: ("<< RGB[0] << ","<< RGB[1]<<","<< RGB[2]<<")"<<endl;
  }
  if(Gray.size()>0)
  {
    filewriter << "The first grayscale RGB value is: ("<< Gray[0] << ","<< Gray[1]<<","<< Gray[2]<<")"<<endl;
  }
   cout<< "Thank you for inputing your color choices. At a later time we will report the colorblindness readability.";
 
 filewriter.close();
}