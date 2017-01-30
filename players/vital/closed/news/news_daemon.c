/******************************************************************************
 *	File:			baby.c
 *	Function:		
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2003 v-Dev Code Factory
 *					All Rights Reserved.
 *	Source:			9/23/03
 *	Notes:			
 *	Change History:
 *****************************************************************************/

#include "news.h"

#pragma combine_strings         /* please, please work... */
#pragma strong_types            /* I'm like that, pedantic */

static string *Global_Message_Files = ({ });
/* array of message numbers for headers */
mapping Global_Message_Headers = ([ ]);
/* map of number:header w/i a newsgroup */
string *Global_News_Groups = ({ });
/* array of newsgroups possible         */
string *Global_Protected_Groups = ({ });
/* array of undeletable newsgroups      */
int Global_Current_Index = 0;
/* number of the current newsgroup      */

/* function prototyping */
int load_headers();
varargs void set_index(int index);
int query_index();
int load_groups();
int add_group(string group);
void switch_group(string group);


/* Work in progress, not sure where to put what yet, but I am       */
/* scribbling down these ideas as I go. Maybe I can get the         */
/* pieces put together someday. I'm working on this as the news     */
/* daemon to be called from a smaller news object that will either  */
/* autoload or be stationary like the post object. Really, might be */
/* able to put the base news commands in something more permanent   */
/* /bin to create mudwide access to it. */

/* hey, what do we refer to this thing as? */
status
id(string hmm)
{
    return hmm == "printer"
        || hmm == "xerox"
        || hmm == "press"
        || hmm == "docucolor"
        || hmm == "xerox printer"
        || hmm == "news"
        || hmm == "printing press"
        || hmm == "news_reader"
        || hmm == "news_daemon"
        || hmm == "igen3"
        || hmm == "iGen3"
        || hmm == "baby";
}

/* all of this is fluff, mind you, utter fluff */
string
short()
{
    return "Xerox, DocuColor iGen3. Digital Production Press Printer";
}

/* someday I'll add in stuff for adminstrators to edit things */
/* and I'll document everything and I'll put a description in */
/* that reflects the editors abilities as well, for now-FLUFF */
void
long()
{
    string temp_long;
    temp_long = short() + "\n\
Welcome to the Xerox, DocuColor iGen3. Digital Production Press Printer.\n\
You have chosen wisely. The iGen3 can print 100 ppm in 4 color separation\n\
but we have retrofitted it to integrate within Nirvana and serve as our \n\
news-server daemon.\n\n\
There is a large, glowing, green button on the top front of the iGen3.\n\
It creates an urge to press it.\n";
    write(temp_long);
}

/* initialize arrays and mappings */
void 
reset(status x)
{
    if (x) return;
    if ( (!environment(this_object())) || (environment(this_object()) != ROOM) )
        move_object(this_object(), ROOM);
    Global_News_Groups = ({ });
    /* these base groups are those that should always be protected */
    Global_Protected_Groups = PROTECTED;
    Global_Message_Files = ({ });
    Global_Message_Headers = ([ ]);
    set_index();
    load_groups();
}

void
init()
{
    add_action("green_button","press");
}

int
press(string arg)
{
    if (!arg)
    {
        notify_fail("What are you trying to press.\n");
        return 0;
    }
    if (arg && (arg == "button" || arg == "green button" ||
        arg == "glowing green button") )
        move_object( clone_object(NEWS + "nob.c"), this_player() );
     return 1;
}

int
load_headers()
{
    string header_temp, one, two, three;
    int x;
    Global_Message_Headers = ([ ]);
    write("Unloading previous newsgroup's headers.\n");
    
    /* load the messages into an array */
    if ( !(Global_Message_Files = get_dir(NEWS +
        Global_News_Groups[Global_Current_Index] + "/*.news")) )
    {
        notify_fail("No messages found in \[" +
            Global_News_Groups[Global_Current_Index] + "\] newsgroup.\n");
        return 0;
    }
    write("Scanning \[" + Global_News_Groups[Global_Current_Index] + 
        "\] for messages.\n");
    /* cycle through each message in previous array */
    /* & scan for header information                */
    
    for(x=0; x < sizeof(Global_Message_Files); x++)
    {
        header_temp = read_file(NEWS + Global_News_Groups[Global_Current_Index]
            + "/" + Global_Message_Files[x] );
        if ( sscanf(header_temp,"%s#%d#%s",one,two,three) != 3)
        {
            notify_fail("The message file "+Global_Message_Files[x]+
" might be corrupt. \n\The header information is not properly formated.\n");
            return 0;
        }
            else
        {
            Global_Message_Headers = Global_Message_Headers + ([ two:one ]);
            write("Messages loaded.\n");
        }
    }
    return 1;
}

void
set_index(int index)
{
    if (!index || (index < sizeof(Global_News_Groups)) ) Global_Current_Index = 0;
    Global_Current_Index = index;
}

int
query_index() { return Global_Current_Index; }


int
load_groups()
{
    int x, y;
    y = sizeof(Global_Protected_Groups);
    if ( !sizeof(Global_News_Groups) )
    {
        for (x = 0; x < y; x++)
        {
            string temp;
            temp = Global_Protected_Groups[x];
            if ( !mkdir(temp) )
            {
                notify_fail("Unable to create news group: " +
                    temp + "\n");
                return 0;
            }
        }
/*         if ( !mkdir(NEWS+"inform") ) */
/*         { */
/*             notify_fail("Unable to create news group: inform\n"); */
/*             return 0; */
/*         } */
/*         if ( !mkdir(NEWS+"guild") ) */
/*         { */
/*             notify_fail("Unable to create news group: guild\n"); */
/*             return 0; */
/*         } */
/*         if ( !mkdir(NEWS+"misc") ) */
/*         { */
/*             notify_fail("Unable to create news group: misc\n"); */
/*             return 0; */
/*         } */
/*         if ( !mkdir(NEWS+"area") ) */
/*         { */
/*             notify_fail("Unable to create news group: area\n"); */
/*             return 0; */
/*         } */
    }
    Global_News_Groups = get_dir(NEWS + "*");
    return 1;
}

int
add_group(string group)
{
    if ( !group )
    {
        notify_fail("What group do you want to add?\n");
        return 0;
    }
    if ( !stringp(group) )
    {
        notify_fail("You must enter a string for a group name.\n");
        return 0;
    }
    group = implode(explode(group, " "), "_");
    if ( strlen(group) > 30 )
    {
        notify_fail(
"You only have 30 characters for a group name.\n\
Spaces are replaced with an underscore \'_\' .\n\
The use of spaces is deprecated in favor of a \n\
period \'.\' to designate group levels. For an\n\
example:\n\
    guild.knights\n\
    inform.urgent\n\
    area.");
        return 0;
    }
    if ( member(group,Global_News_Groups) )
    {
        notify_fail("That group already exists.\n");
        return 0;
    }
    if ( stringp(group) && (strlen(group) < 30) &&
        (!member(Global_News_Groups)) )
    {
        if ( !mkdir(NEWS + group) )
        {
            notify_fail("Error creating news group " + group + "\n");
            return 0;
        }
        write("Initializing newsgroup \[" + group + "\].\n");
        load_groups();
        set_index(member(group, Global_News_Groups)); 
    return 1;
    }
}

void
swtich_group(string group)
{
    int temp_index;
    temp_index = member(group, Global_News_Groups);
    if (!group)
    {
        notify_fail("Which group are you trying to select?\n");
        return 0;
    }
    if ( stringp(group) && temp_index == -1 )
    {
        notify_fail("Unable to select \[" + group + "\] as a newsgroup.\n");
        return 0;
    }
    if ( stringp(group) && (temp_index >= 0) ) Global_Current_Index = temp_index;
    load_headers();
}

int
remove_group(string group)
{
    int x, y;
    if (!group)
    {
        notify_fail("Which group are you trying to remove?\n");
        return 0;
    }
    if (stringp(group) && (member_array(group, Global_Protected_Groups) == -1) )
    {
        notify_fail("You may not remove that news group.\n");
        return 0;
    }
    if ( stringp(group) && (member_array(group, Global_News_Groups)) )
    {
        switch_group(group);
        if ( (y = sizeof(Global_Message_Files) > 0) )
        {
            write("Removing messages from newsgroup \[" +
                Global_News_Groups[Global_Current_Index] + "\]\n");
            for(x=0; x < y; x++)
                rm(NEWS + Global_News_Groups[Global_Current_Index] + "/" +
                    Global_Message_Files[x]);
        }
        write("Removing newsgroup directory: \["+ group +"\]\n");
        rmdir( NEWS + group);
        return 1;
    }
    write("Something failed here.\n");
    notify_fail("This error message was generated by a failure to select a valid newsgroup \nto remove or some other incredibly insane twist of fate.\n");
    return 0;
}
