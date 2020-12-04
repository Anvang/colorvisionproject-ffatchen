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
public:
void getRGB();
void CalcGrayscaleRGB();
void displayRGB();
};

#endif