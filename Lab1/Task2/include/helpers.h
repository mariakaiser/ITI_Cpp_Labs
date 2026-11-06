#include <string>
#include <unordered_map>
using namespace std;

extern const unordered_map<string,int> mapping_color_color_codes;

void PositionOnScreen(int row, int col);

void SetColor(int color_code);

void Write(int row, int col,string color, string sentence);

void ClearTerminal();