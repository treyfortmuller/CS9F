#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Function Prototypes

void InterpretCommands(istream&);

void InterpretUpdate(istream&);

void InterpretList(istream&);

void InterpretBatch(istream&);

void InterpretQuit(istream&);

/**
 * Driver Function
 */
int main()
{
    InterpretCommands(cin);
    return 0;
}

/**
 * TODO: Write your function description here.
 */
void InterpretCommands(istream& cmds)
{
    string line, lineInWord;
    // TODO: Declare other variables here.

    while (________) // TODO: Get a line.
    {
        istringstream lineIn(line);

        if (________) // TODO: Get the line's first word.
        {
            ________; // TODO: Do something if there weren't any words.
        }
        else if (lineInWord == "update")
        {
            InterpretUpdate(lineIn);
        }
        else if (lineInWord == "list")
        {
            InterpretList(lineIn);
        }
        else if (lineInWord == "batch")
        {
            InterpretBatch(lineIn);
        }
        else if (lineInWord == "quit")
        {
            InterpretQuit(lineIn);
        }
        else
        {
            cerr << "Unrecognizable command word." << endl;
        }
    }
}
