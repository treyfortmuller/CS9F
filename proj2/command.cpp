#include <cstdlib> // for the exit() function
#include <iostream> // standard input, output stream
#include <fstream> // file read and write stream
#include <sstream> // a stream associated with a string
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
    string line, lineInWord; // a line from cin, a word in the string stream
    // TODO: Declare other variables here.  

    while (getline(cmds, line)) // while we can get a line from the cin stream
    {
        istringstream lineIn(line); // intialize an input string stream called linIn bound to the line string
        
        // extracts the first word in the line from the string stream and checks that the stream is not empty
        if (!(lineIn >> lineInWord))
        {
            cerr << "No words were entered..." << endl; // Do something if there weren't any words.
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

void InterpretUpdate(istream& cmds)
{
    string errMsg = "Invalid entry - usage: update [word] [int]";
    string word;
    int number;
    string temp; // temporary string ot check there's nothing left on the steam

    if (cmds >> word >> number) {

        if (cmds >> temp) { // there's too many arguments
            cerr << errMsg << endl;
        } else {
            // we have a legal input
            cout << "update " << word << " " << number << endl;
        }
    } else {
        cerr << errMsg << endl;
    }
}

void InterpretList(istream& cmds)
{
    string errMsg =  "Invalid entry - usage: list \"names\" -or- \"quantities\"";
    string arg;
    string temp; // temporary string to check there's nothing left on the stream

    if (cmds >> arg) { // parse the argument to the command
        
        if (cmds >> temp) { // if there's more in the string stream
            cerr << errMsg << endl;
        } else {
            // we have a legal input
            if (arg == "quantities") {
                cout << "list " << arg << endl;
            } else if (arg == "names") {
                cout << "list " << arg << endl;
            } else {
                cerr << errMsg << endl;
            }
        }

    } else {
        cerr << errMsg << endl;
    }
}

void InterpretBatch(istream& cmds)
{
    string errMsg = "Invalid entry - usage: batch [filename]";
    string filename;
    string temp;

    ifstream fileInput; // initialize a new input file stream object called fileInput

    if (cmds >> filename) {
        if (cmds >> temp) { // we have too many arguments
            cerr << errMsg << endl;
        } else {
            // we have a legal input
            fileInput.open(filename.c_str());
            if (fileInput.fail()) {
                cout << "Failed to open text file." << endl;
            } else {
                // we can read the file, pass the file stream off
                InterpretCommands(fileInput);
            }
        }
    } else {
        // we didn't get any args
        cerr << errMsg << endl;
    }
}

void InterpretQuit(istream& cmds)
{
    exit(0); // exit successfully
}