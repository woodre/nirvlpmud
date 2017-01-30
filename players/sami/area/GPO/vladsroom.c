/*                      /                                             *
 *    File:             /players/sami/area/GPO/hih1.c   *
 *    Function:         room                                          *
 *    Author(s):        Sami@Nirvana                                  *
 *    Copyright:        Copyright (c) 2014 Sami                       *
 *                              All Rights Reserved.                  *
 *    Source:                   10/4                                  *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */
inherit "/players/vertebraker/closed/std/room.c";
#include <ansi.h>
#include "define.h"

int door_open, door_locked;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Lower Deck");
  long_desc =
" O-==========================================================================-O\n"+
" |         |  The heavily infested hallway comes to an abrupt end.  The\n"+
" |         |  hallway appears to have kept going but has since been collapsed\n"+
" |         |  in.  There is too much debris blocking the way to the wast.\n"+
" |    "+HIR+"*"+NORM+"--- |  However, to the north what looks like a door can be seen through\n"+
" |         |  some of the rubble and debris.  Perhaps if one could find a key\n"+
" |         |  they would be able to open it.\n"+
" |         |\n"+
" O-==========================================================================-O\n";
dest_dir = ({
                "/players/sami/area/GPO/vladsroom.c", "north",
                "/players/sami/area/GPO/hih4.c", "east"});
}

init() {
        ::init();
        add_action("open_door","open");
        add_action("close_door", "close");
        add_action("unlock_door", "unlock");
        add_action("cmd_south","south");
        add_action("door_look","look");
        add_action("door_look","l");
        add_action("door_look","examine");
        add_action("door_look","exa");
}
/*complements to dragnar*/
door_look( string str ) {
  if( str == "door" ) {
    write("An office door. It appears to be "+(door_open ? "open" : "shut")+" and "+
           (door_locked ? "locked" : "unlocked")+".\n");
    if( door_locked )
      write("Perhaps there is a key nearby that would unlock the door?\n");
    return 1;
  } 
}
/*Door function complements of Oberon*/
unlock_door(arg) {
        if(arg != "door") return;
        if(!door_locked)
                write("The door is already unlocked.\n");
        else {
                if(present("samikey", this_player())) {
                        write("You unlock the door.\n");
                        set_door(2);
                        call_other("/players/sami/area/GPO/hih5", "set_door", 2);
                }
                else
                        write("You need a key to unlock this door!\n");
        }
        return 1;
}

open_door(arg) {
        if(arg != "door") return;
        if(door_open)
                write("The door is already open.\n");
        else if(door_locked)
                write("The door is locked and shut.\n");
        else {
                write("You open the door.\n");
                set_door(1);
                call_other("/players/sami/area/GPO/hih5", "set_door", 1);
        }
        return 1;
}

close_door(arg) {
        if(arg != "door") return;
        if(!door_open)
                write("The door is alraedy closed.\n");
        else {
                write("You close the door.\nYou hear a loud click as it closes.\n");
                set_door(3);
                call_other("/players/sami/area/GPO/hih5", "set_door", 3);
        }
        return 1;
}

cmd_south() {
        if(!door_open) {
                write("The door is closed.\n");
                return 1;
        }
}

set_door(value) {
        if(!value) return;
        switch(value) {
                case 1: door_open=1; door_locked=0; break;
                case 2: door_open=0; door_locked=0; break;
                case 3: door_open=0; door_locked=1; break;
                default: break;
        }
        return 1;
}
