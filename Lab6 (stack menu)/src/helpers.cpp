
#include "../include/helpers.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

// a map of codes to colors
const std::unordered_map<std::string, int> mapping_color_color_codes =
{
    {"Black",   30},
    {"Red",     31},
    {"Green",   32},
    {"Yellow",  33},
    {"Blue",    34},
    {"Magenta", 35},
    {"Cyan",    36},
    {"White",   37}
};

void PositionOnScreen(int row, int col)
{
    
    cout << "\033["+ to_string(row) + ";"+ to_string(col) + "H";
}

void SetColor(int color_code){
    printf("\033[%dm" , color_code);
}

void Write(int row, int col,string color, string sentence)
{
    if(mapping_color_color_codes.find(color) == mapping_color_color_codes.end())
    {
        cout<<"not a valid color"<<endl;
        return;
    }
    int color_code = mapping_color_color_codes.at(color);
    PositionOnScreen(row, col);
    SetColor(color_code);
    cout<<sentence<<'\n';
    cout << "\033[0m"; // Reset Color to terminal default
}

void ClearTerminal()
{
    cout << "\033[2J\033[H";
}

void ClearLine(int row)
{
    PositionOnScreen(row, 0);
    cout << "\033[2K";
}