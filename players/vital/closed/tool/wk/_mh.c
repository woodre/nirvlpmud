/******************************************************************************
 *  File:           _mh.c
 *  Function:       overide the /bin/wiz/home.c functionality for me
 *  Author(s):      Vital@Nirvana
 *  Copyright:      Copyright (c) 2004 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         25/1/04
 *  Notes:          
 *  Change History:
 *****************************************************************************/

#pragma strong_types
#pragma combine_strings

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"

int
main(string destination)
{
    object home;
    home = clone_object("/players/vital/workroom/workroom.c");
    if ( !destination )
    {
        notify_fail("You moron. What are you getting ready to work on.\n");
        return 0;
    }
    switch (destination)
    {
        case "base":
            TP->move_player("to The Tower#" + WORKROOM);
            TP->set_home(WORKROOM);
            WORKROOM->configure_long(destination);
            break;
        case "news":
            TP->move_player("to The Newsroom#" + WORKROOM);
            TP->set_home(WORKROOM);
            WORKROOM->configure_long(destination);
            break;
        case "class":
            TP->move_player("to The Classroom#" + WORKROOM);
            TP->set_home(WORKROOM);
            WORKROOM->configure_long(destination);
            break;
        case "guild":
            TP->move_player("to Recode a Guild#" + WORKROOM);
            TP->set_home(WORKROOM);
            WORKROOM->configure_long(destination);
            break;
        case "idle":
            TP->move_player("to Idle Away the Hours#" + WORKROOM);
            TP->set_home(WORKROOM);
            WORKROOM->configure_long(destination);
            break;
        case "area":
            TP->move_player("to Work on the Destinations#" + WORKROOM);
            TP->set_home(WORKROOM);
            WORKROOM->configure_long(destination);
            break;
        case "lib":
            TP->move_player("to Screw Up the Lib#" + WORKROOM);
            TP->set_home(WORKROOM);
            WORKROOM->configure_long(destination);
            break;
        case "board":
            TP->move_player("to The Board#/room/adv_inner.c");
            break;
        case "green":
            TP->move_player("to The Green#/room/vill_green.c");
            break;
        case "post":
            TP->move_player("to The Post#/room/post.c");
            break;
        case "port":
            TP->move_player(
                "to The Port#/players/vital/dest/spaceport/rooms/enter.c");
            break;
        case "church":
            TP->move_player("to The Church#/room/church.c");
            break;
        case "ranger":
            TP->move_player("to The Ranger Guild#/players/guilds/Rangers/CommandCenter/CommandCenter.c");
            break;
        default:
            TP->move_player("to The Tower#" + WORKROOM);
            TP->set_home(WORKROOM);
            WORKROOM->configure_long("base");
            break;
    }
    return 1;
}


string
get_help()
{
  string help;
  help = "Syntax: mh <base,news,class,guild,idle,board,green,post,church,ranger>";
  return help;
}
