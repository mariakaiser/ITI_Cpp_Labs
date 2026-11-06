#include<iostream>
#include <cstdio>
#include "../include/magic_box_helpers.h"
#include "../include/helpers.h"

#include <thread>
#include <chrono>

void DrawMagicBox(int dim)
{

    if(dim%2==0){
        std::cout<<"input is not an odd integer" << endl;
        return;
    }
    if(dim < 3){
        std::cout<<"input is not a positive odd number"<<endl;
        return;
    }

    //starting from row 1 col 1 end in row dim col dim

    int n2 = dim*dim;

    int middle_col = dim/2 + 1;

    int row =1;
    int col = middle_col;

    Write(row, col * 4,"Magenta", "1");

    for(int i = 2;i<=n2;i++)
    {
        if(i % dim == 1)
        {
            row = (row % dim) + 1;
        }
        else 
        {
            row--;
            if(row == 0)
                row = dim;
            col = (col % dim) + 1;
        }
    
        // printf("\033[%d;%dH" , row ,col *4);
        Write(row,col * 4,"Yellow",to_string(i));
        
        // std::cout<< i;
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));

    }

    std::cout<< '\n';
}

void MagicBox()
{
    int dim =0;

    cout<<"Enter number for magic box"<<endl;
    cin>>dim;

    if (cin.fail()) 
    {
        cout << "Invalid integer" << endl;
        return;
    }

    ClearTerminal();
    DrawMagicBox(dim);

}