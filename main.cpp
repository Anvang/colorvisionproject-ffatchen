#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
void displayRGB( const vector <int> &);
void displayGeneralColors(const vector <string> & colors);
char addColor();
char chooseRGBorGeneral();
vector <int> getRGB();
string getGeneralColors();
void CalcGrayscaleRGB(vector <int>, vector <int> &);
int main()
{ 
  string filename;
  fstream filewriter;
  char choice;
  char choice2;
  char colorType;
  char colorType1;
  char colorType2;
  vector <int> RGB1;
  vector <int> Gray1;
  vector <int> RGB2;
  vector <int> Gray2;
  vector <int> RGB3;
  vector <int> Gray3;
  vector <string> generalColors1;
  cout<< "You will be prompted to pick the hue of red, green and blue for any number of colors or pick a general color from a list.\n The grayscale of the colors chosen via RGB values will then be \n calculated to check for colorblindness readability."<<endl;
  colorType = chooseRGBorGeneral();
  if(colorType == 'r' || colorType == 'R')
  {
   RGB1 = getRGB();
  }
  else
  {
   generalColors1.push_back(getGeneralColors());
  }
  choice = addColor();
  if(choice == 'a' | choice == 'A')
  {
    colorType1 = chooseRGBorGeneral();
  }
  else if(choice == 'q' | choice == 'Q')
  {
    if(RGB1.size() >0)
    {
    displayRGB(RGB1);
    }
  }
  if(colorType1 == 'r' | colorType1 =='R')
  {
    RGB2 = getRGB();
  }
  else if(colorType1 == 'g' | colorType1 == 'G')
  {
    generalColors1.push_back(getGeneralColors());
  }
  cout<< "You have one more option to add another color."<<endl;
  choice2 = addColor();
  if(choice2 == 'a'| choice2 == 'A')
  {
    colorType2 = chooseRGBorGeneral();
  }
  else if ( choice2 == 'q'| choice2 == 'Q')
  {
  if(RGB1.size()>0)
  {
  displayRGB(RGB1);
  }
  if(RGB2.size()>0)
  {
  displayRGB(RGB2);
  }
  if(generalColors1.size()>0)
  {
  displayGeneralColors(generalColors1);
  }
  }
  if(colorType2 == 'r' | colorType2 == 'R')
  {
    RGB3 = getRGB();
  }
  else if(colorType2 == 'g' | colorType2 == 'G')
  {
    generalColors1.push_back(getGeneralColors());
  }
  //calc grayscale 
  if(RGB1.size()>0)
  {
  CalcGrayscaleRGB(RGB1,Gray1);
  }
  if(RGB2.size()>0)
  {
  CalcGrayscaleRGB( RGB2, Gray2);
  }
  if(RGB3.size()>0)
  {
  CalcGrayscaleRGB(RGB3, Gray3);
  }
  if(RGB1.size()> 0 | RGB2.size()>0 | RGB3.size()>0)
  {
  cout<< "The RGB color(s) chosen is/are:"<<endl;
  }
  {
  if(RGB1.size()>0)
  {
  displayRGB(RGB1);
  }
  if(RGB2.size()>0)
  {
  displayRGB(RGB2);
  }
  if(Gray1.size()> 0 | Gray2.size()>0 | Gray3.size()>0)
  {
  cout<< "The grayscale RGB color(s) is/are:"<<endl;
  }
  if(Gray1.size()> 0)
  {
  displayRGB(Gray1);
  }
  if(Gray2.size()>0)
  {
  displayRGB(Gray2);
  }
  if(Gray3.size()>0)
  {
    displayRGB(Gray3);
  }
  if(generalColors1.size()>0)
  {
    cout << "The general color(s) is/ are:"<<endl;
    displayGeneralColors(generalColors1);
  }
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
  if(RGB1.size()> 0)
  {
  filewriter << "The first RGB color is: ("<< RGB1[0] << ","<< RGB1[1]<<","<< RGB1[2]<<")"<<endl;
  }
  if(RGB2.size()> 0)
  {
  filewriter << "The second RGB color is (" << RGB2[0]<< ","<< RGB2[1] <<"," << RGB2[2]<<")"<<endl;
  }
  if(RGB3.size()>0)
  {
  filewriter<< "The third RGB color is (" << RGB3[0] << ","<< RGB3[1] << "," << RGB3[2]<<")"<<endl;
  }
   cout<< "Thank you for inputing your color choices. At a later time we will report the colorblindness readability.";
 
 filewriter.close();
  return 0;
}
}
void displayGeneralColors(const vector <string> &colors)
{
  for(int i = 0; i < colors.size(); i++)
  {
    cout<< colors[i]<< ",";
  }
  cout<< endl;
}
void displayRGB( const vector <int> & RGB)
{
   for(int i = 0; i < RGB.size(); i++)
    {
    cout<< RGB[i]<< ",";
    }
    cout<<endl;
}

char addColor()
{ 
  char choice;
  do
  {
  cout<< "Please enter (a) to add another color or (q) to quit" <<endl; 
  cin>>choice; 
  }while(choice != 'q' && choice != 'q' && choice != 'a' && choice != 'A');
  return choice;
}
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
//function to calc grayscale for RGB
void CalcGrayscaleRGB(vector <int> RGB, vector <int>& grayscale)
{
  int gray1 = .3 * RGB[0];
  grayscale.push_back(gray1);
  int gray2 = .59 * RGB[1];
  grayscale.push_back(gray2);
  int gray3 = .11 * RGB[2];
  grayscale.push_back(gray3);
}