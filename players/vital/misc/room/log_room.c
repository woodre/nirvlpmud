/******************************************************************************
 *	File:			log_room.c
 *	Function:		A room to test logging
 *	Author(s):		Vital@Nirvana
 *	Copyright:		Copyright (c) 2004 v-Dev Code Factory
 *					All Rights Reserved.
 *	Source:			9/2/04
 *	Notes:			
 *	Change History:
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

inherit "room/room";

string *GlobalVisitors;

void
reset(status arg) {
    if(!arg)
    { 
        set_light(1);
        short_desc = "Test Room";
        long_desc =  "This is room to test logging";

        items =
        ({
            "log",
            "A log of who has been in this room"
        });
        dest_dir =
        ({
        });
        GlobalVisitors = ({ });
    }
}

void
check_visitor()
{
    object player_object;
    string player_name;
    int test_value;
    
    if (this_player())
    {
        player_object = this_player();
        player_name = (string)this_player()->query_real_name();
        
        write(player_name);
        
        test_value = member_array(GlobalVisitors, player_name);
    
        if ( test_value != -1)
        {
            write(" has visited this room previously.\n");
            return;
        }
        GlobalVisitors += ({ player_name });
        write(" has been added to the room's guest list.\n");
        save_object("/players/vital/misc/room/room");
    }
    return;
}

int
visitor_list()
{
    int x, y;
    string message;
    
    if (!GlobalVisitors)
    {
        notify_fail("No visitors to this room.\n");
        return 0;
    }
    
    x = sizeof(GlobalVisitors);
    message = short_desc + " has been visited by:\n";
    
    for (y = 0; y < x; y++ ) message += capitalize(GlobalVisitors[y]) + ", ";
    
    write(message + "\n");
    return 1;
}

int
reset_list()
{
    GlobalVisitors = ({ });
    save_object("/players/vital/misc/room/room");
    return 1;
}

init() {
    ::init();
    save_object("/players/vital/misc/room/room");
    if (restore_object("/players/vital/misc/room/room")) write("woot");
    check_visitor();
    add_action("visitor_list","vlist");
    add_action("reset_list","rlist");
}
