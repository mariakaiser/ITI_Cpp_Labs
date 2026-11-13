#include <iostream>   // Standard input/output library
#include <cstdio>     // C standard I/O functions such as printf

#ifdef _WIN32
    #include <conio.h>
#else // Linux specific libs ========
    #include <unistd.h> // Provides Unix functions such as read
    #include <termios.h>  // Used to control terminal settings
#endif

#ifndef _WIN32 // Linux func =======
// Alternative implementation of getch() for Linux systems
char getch_linux() {
    char buf = 0; // Variable to store the input character

    struct termios old = {0}; // Structure to save current terminal settings

    // Save the current terminal settings
    tcgetattr(0, &old);

    // Disable Canonical Mode (do not wait for Enter key)
    old.c_lflag &= ~ICANON;

    // Disable Echo so typed characters are not displayed
    old.c_lflag &= ~ECHO;

    // Require at least one character to be read
    old.c_cc[VMIN] = 1;

    // No timeout while waiting for input
    old.c_cc[VTIME] = 0;

    // Apply the modified settings immediately
    tcsetattr(0, TCSANOW, &old);

    // Read a single character immediately from the keyboard
    read(0, &buf, 1);

    // Re-enable Canonical Mode
    old.c_lflag |= ICANON;

    // Re-enable Echo
    old.c_lflag |= ECHO;

    // Restore the terminal to its original settings
    tcsetattr(0, TCSADRAIN, &old);

    // Return the character that was read
    return buf;
}
#endif

// 1 -> up arrow
// 2 -> down arrow
// 3 -> enter
// 4 -> home
// 5 -> other key
// 6 -> end

int DetermineArrow()
{
    #ifdef _WIN32
    int c = _getch();

    if (c == '\r') return 3;      // Enter
    if (c == 27)   return 7;      // Esc

    if (c == 0 || c == 0xE0) {    // special-key prefix
        switch (_getch()) {
            case 72: return 1;    // Up
            case 80: return 2;    // Down
            case 71: return 4;    // Home
            case 79: return 6;    // End
            default: return 5;
        }
    }
    return -1;
    #else
    //std::printf("Press the arrow keys to test the program (press 'q' to quit):\n");
    char byte1='q';
    char byte2='q';
    char byte3='q';
  
    // Read a key from the user
    byte1= getch_linux();
        //std::cout<<"Byte 1 :: "<<byte1<<std::endl;

    if(byte1 == '\n')
    {
        //std::cout<<"enter"<<std::endl;
        return 3;
    }

    // If the key is the beginning of an arrow-key escape sequence
    if (byte1 == '\033') {
        // Skip the second character '['
        byte2=getch_linux();
        //std::cout<<"Byte 2 :: "<<byte2<<std::endl;
        byte3=getch_linux();
        // The third character determines the arrow direction
        //std::cout<<"Byte 3 :: "<<byte3<<std::endl;
        switch (byte3) {
            case 'A': // up
                return 1;
            case 'B': // down
                return 2;
            case 'H': // home
                return 4;
            case 'F': //end
                return 6;
            default: // else -> ignore
                return 5;
        }
    }

    //std::cout<<"================================="<<std::endl;

    return -1;
    #endif
}

// int main() {
//     // Display instructions for the user
//     std::printf("Press the arrow keys to test the program (press 'q' to quit):\n");
//     char byte1='q';
//     char byte2='q';
//     char byte3='q';

//     // Infinite loop that runs until the user chooses to quit
//     do{
//         // Read a key from the user
//         byte1= getch_linux();
//          //std::cout<<"Byte 1 :: "<<byte1<<std::endl;
//         // If the key is the beginning of an arrow-key escape sequence
//         if (byte1 == '\033') {
//             // Skip the second character '['
//             byte2=getch_linux();
//             //std::cout<<"Byte 2 :: "<<byte2<<std::endl;
//             byte3=getch_linux();
//             // The third character determines the arrow direction
//             //std::cout<<"Byte 3 :: "<<byte3<<std::endl;
//             switch (byte3) {
//                 case 'A':
//                     std::printf("↑ Up Arrow\n");
//                     break;

//                 case 'B':
//                     std::printf("↓ Down Arrow\n");
//                     break;

//                 case 'C':
//                     std::printf("→ Right Arrow\n");
//                     break;

//                 case 'D':
//                     std::printf("← Left Arrow\n");
//                     break;
//                 case 'H':
//                     std::printf("← Home Button \n");
//                     break;
//                 case 'F':
//                     std::printf("End Button\n");
//                     break;
//             }
//         }

//         std::cout<<"================================="<<std::endl;
//     }while(byte1 != 'q' || byte1 != 'Q');        // Exit the program if the user presses Q or q
//     // Exit the program successfully
//     return 0;
// }
