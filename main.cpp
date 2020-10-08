#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // given three rgb values to check for colorblindness viewability 
  int red1, red2, red3;
  int green1, green2, green3;
  int blue1, blue2, blue3;
  string filename;
  fstream filewriter;
  cout<< "You will be prompted to pick the hue of red, green and blue for three different colors. The grayscale of these colors will then be calculated to check for colorblindness readability."<<endl;
  cout<<"For your first color:"<<endl;
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of red."<<endl;
  cin>>red1;
  if(red1 < 0 | red1 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while (red1 < 0 | red1 > 255 );
  do
  { 
   cout<< "Please give a value between 0-255 for the intensity of green."<<endl;
  cin>>blue1;
  if( green1 < 0 | green1 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while(green1 < 0 | green1 >255);
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of blue."<<endl;
  cin>>blue1;
  if(blue1 < 0 | blue1 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while(blue1 < 0 | blue1 > 255);

cout<<"For your second color:"<<endl;
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of red."<<endl;
  cin>>red2;
  if(red2 < 0 | red2 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while (red2 < 0 | red2 > 255 );
  do
  { 
   cout<< "Please give a value between 0-255 for the intensity of green."<<endl;
  cin>>green2;
  if( green2 < 0 | green2 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while(green2 < 0 | green2 >255);
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of green."<<endl;
  cin>>blue2;
  if(blue2 < 0 | blue2 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while(blue2 < 0 | blue2 > 255);

  cout<<"For your third color:"<<endl;
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of red."<<endl;
  cin>>red3;
  if(red3 < 0 | red3 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while (red3 < 0 | red3 > 255 );
  do
  { 
   cout<< "Please give a value between 0-255 for the intensity of green."<<endl;
  cin>>green3;
  if( green3 < 0 | green3 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while(green3 < 0 | green3 >255);
  do
  {
  cout<< "Please give a value between 0-255 for the intensity of blue."<<endl;
  cin>>blue3;
  if(blue3 < 0 | blue3 > 255)
  {
    cout << "Invalid RGB value." <<endl;
  }
  } while(blue3 < 0 | blue3 > 255);
  
  cout<< "The first color is :rgb("<< red1<< "," <<green1 <<","<< blue1<< ")"<<endl;
  cout<< "The second color is :rgb("<< red2<< "," <<green2 <<","<< blue2<< ")"<<endl;
  cout<< "The third color is : rgb("<< red3<< "," <<green3 <<","<< blue3<< ")"<<endl;
  int gray1 = .3 *red1 + .59*green1 + .11*blue1;
  int gray2 = .3 *red2 + .59*green2 + .11*blue2;
  int gray3 = .3 *red3 + .59*green3 + .11*blue3;
  cout<<"The first grayscale color is: rgb("<<gray1<<","<<gray1<<","<<gray1<<")"<<endl;
  cout<<"The second grayscale color is: rgb("<<gray2<<","<<gray2<<","<<gray2<<")"<<endl;
  cout<<"The third grayscale color is: rgb("<<gray3<<","<< gray3<<","<<gray3<<")"<<endl;
  cout<<"What file would you like to save these colors to?"<<endl;
  do
  {
  cin>>filename;

  filewriter.open(filename, ios::app);

  if( !filewriter.is_open())
  {
    cout<<"Error opening file.";
  }
  }while(!filewriter.is_open());

  filewriter<<"The first color is :rgb("<< red1<< "," <<green1 <<","<< blue1<< ")"<<endl;
  filewriter<<"The second color is :rgb("<< red2<< "," <<green2 <<","<< blue2<< ")"<<endl;
  filewriter<< "The third color is :rgb("<< red3<< "," <<green3 <<","<< blue3<< ")"<<endl; 
   filewriter<<"The first grayscale color is: rgb("<<gray1<<","<<gray1<<","<<gray1<<")"<<endl;
  filewriter<<"The second grayscale color is: rgb("<<gray2<<","<<gray2<<","<<gray2<<")"<<endl;
  filewriter<<"The third grayscale color is: rgb("<<gray3<<","<< gray3<<","<<gray3<<")"<<endl;
 

  cout<< "Thank you for inputing your color choices. At a later time we will report the colorblindness readability.";
 
 filewriter.close();


   
  return 0;
}
