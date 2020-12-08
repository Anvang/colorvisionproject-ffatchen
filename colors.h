#ifndef COLORS_H
#define COLORS_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class colors
{
private:
  vector <int> RGB;
  vector <int> GrayscaleRGB;
  vector <int> defaultRGBColor;
public:

  // Constructor for RGB vectors
  colors();

  vector<int> givingDefaultRGB();
  
  vector <int> getRGB();
  
  void setRGB(const vector <int> &); 

  void strongestColor();

  vector <int> CalcGrayscaleRGB();

  void setGrayScaleRGB(const vector <int> &);

  void displayRGB();
};

#endif