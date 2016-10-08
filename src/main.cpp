/**
 * small program to check a simple text for simple spelling mistakes
 * see latedev.wordpress.com/2012/04/29/writing-a-real-c-program-index/
 *
 * Word: sequence of characters enclosed in spaces
 *
 * Tasks:
 *      Dictionary   - takes wordlist and adds words to set
 *      Checker      - goes through text and compare each word to dictionary
 *      Reports      - compiles a report about the text, highlighting
 *                     every mistake
 *      Command-Line - options to add dictionaries and only show error
 *                     count
 */

#include <iostream>
#include <string>

#include "inc/error.h"
#include "inc/dictionary.h"

using namespace std;

int main ( int argc, char *argv[] )
{
    try
    {
        cout << "scheck version 0.2" << endl;

        Dictionary d ( "../data/wordlist" );
        string word ( "dog" );

        while ( getline ( cin, word ) )
        {
        if ( d.Check( word ) )
        {
            cout << word << " is OK\n";
        }
        else
        {
            cout << word << " is misspelt\n";
        }
        }
    }
    catch ( const Error & e )
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    catch ( ... )
    {
        cout << "Unknown exeption" << endl;
        return 2;
    }

    return 0;
}
