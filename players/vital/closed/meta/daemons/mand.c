/******************************************************************************
 *	File:			mand.c
 *	Function:		Daemon to handle requests for help/man files.
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2004 v-Dev Code Factory
 *					All Rights Reserved.
 *	Source:			3/17/04
 *	Notes:			The mand [man daemon] is set up to find help files in any
 *                  of the defined help directories. To use this file in other
 *                  places:
 *                      Add a #define DOCDIR that points to your help files.
 *                      Add any additional help directories that you would
 *                          like mand to be able to access to the DIRS define.
 *                      Populate your DOCDIR with text help files ending with
 *                          a .txt suffix.
 *	Change History: Began including error codes. They are all commented at the
 *                  end of the file. Eventually they will be included in the
 *                  actual help file for this daemon.
 *****************************************************************************/

#include "../inc/def.h"

#define HOWTO DOCDIR + "howto.txt"
#define HEADER "          -----=====*****[+]*****======-----         \n"
#define FOOTER "Thank you for reading with us. Come read again later.\n"

#define DIRS ({ "/doc/helpdir/", DOCDIR })

/* Mapping of all words that can be looked up and their directories*/
mapping GlobalWords;
/* Array of directories that can be searched */
string *GlobalDirs;

/* Function Prototypes */
void man_hash();
void help_help();
int get_help(string str);
status file_size(string word, string directory);
mapping query_help();

void
reset(status arg)
{
    if (!root()) destruct(this_object());
    if (arg) return;
    GlobalDirs =  ({ "/doc/helpdir/", DOCDIR });
    GlobalWords = ([ ]);
    man_hash();
}

void
help_help()
{
    string howto;
    if (file_size(HOWTO) > 0)
    {
        howto = read_file(HOWTO);
        cat(howto);
    }
    else write("The help file for this action is currently out-to-lunch.\n");
}

int
get_help(string str)
{
    string tempword, a01;
    tempword = str + ".help";
    a01 = GlobalWords[tempword];
    if (!str)
    {
        help_help();
        return 1;
    }
    if (file_size(tempword, a01))
    {
        write(HEADER);
        cat(GlobalWords[tempword] + tempword);
        write(FOOTER);
        return 1;
    }
    else
    {
        notify_fail(HEADER + "A record cannot be located for that information.\n" + FOOTER);
        return 0;
    }
    notify_fail("Manual Daemon Error Code \"Smarmy\"\n");
    return 0;
}

status
file_size(string word, string directory)
{
    if (directory == "/doc/helpdir/") word = implode(explode(word, ".help"),"");
    if (file_size(directory + word) > 0) return 1;
    else return 0;
}

void
man_hash()
{
    int x1, y1, x2, y2;
    string *words;
    
    GlobalWords = ([ ]);
    GlobalDirs  = ({ "/doc/helpdir/", DOCDIR });
    
    y1 = sizeof(GlobalDirs);
    
    for (x1 = 0; x1 < y1; x1++)
    {
        words = get_dir(GlobalDirs[x1] + "*");
        y2 = sizeof(words);
        for (x2 = 0; x2 < y2; x2++)
        {
            if (GlobalDirs[x1] == "/doc/helpdir/")
                words[x2] = words[x2] + ".help";
            GlobalWords[words[x2]] = GlobalDirs[x1];
        }
    }
}

mapping
query_help()
{
    return GlobalWords;
}

array
query_directories()
{
    return GlobalDirs;
}

debug_check()
{
    string words, *list;
    int x, y;
    
    man_hash();
    
    list = keys(GlobalWords);
    
    y = sizeof(list);
    
    for ( x = 0; x < y; x++ )
    {
        words += (list[x] + ", ";
    }
    return "Cmd Keys: " + words + "\n";
}

/******************************************************************************
 * Error Code Reference
 *
 * Smarmy:      function get_help(string str) errored by not accounting for
 *              all the possible arguments it was passed, or by a hacker
 *****************************************************************************/