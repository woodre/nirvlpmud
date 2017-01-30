/*                                                                    *
 *    File:             /players/angel/area/stargate/room/hall2.c     *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2006 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           11/15/06                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"
 
#include <ansi.h>

#include "std.h"

inherit "room/room";

int lamp_is_lit;

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIY+"STARGATE"+NORM;
  items =
  ({
    "elevator",
    "There is a button on the wall next to the silver doors",
    "facility",
    "underground building",
    "room",
    "its solid concrete",
    "concrete",
    "man maid solid rock",
    "pipes",
    "various sizes and colors",
    "wires",
    "various sizes and color",
    "ceiling",
    "Its full of pipes and wires",
    "surface",
    "earth, what you walk on",
    "hallway",
    "a long corridor connecting rooms",
  });

  dest_dir =
  ({
	"/players/angel/area/stargate/room/hall8",   "south",
	"/players/angel/area/stargate/room/ir",      "east",
  });
}

init(){
    ::init();
    this_player()->set_fight_area();
    add_action("north", "north");
    add_action("open",  "open");
    add_action("push",  "push");
    add_action("push",  "press");
    add_action("close", "close");
    }

long(str)
{
    if (str == "door") {
        if (!call_other("/players/angel/area/stargate/room/elevator", "query_door", 0) &&
            call_other("/players/angel/area/stargate/room/elevator", "query_level", 0))
            write("The door is open.\n");
        else
            write("The door is closed.\n");
        return;
    }
    if (str == "button") {
        write("The button on the wall is somehow associated with the \n"+
            "elevator's operation. Maybe you can push it. \n");
            if (lamp_is_lit) write("The lamp beside the elevator is lit.\n");
        return;
    }
    write(""+HIC+" ~ HALL LEVEL 27 ~"+NORM+"\n");
    write(""+CYN+"This is a deep underground facility. All sides of the room are\n");
    write("made of three feet thick concrete. Many pipes and wires run along\n");
    write("the ceiling and air is pumped down from the surface. This facility\n");
    write("is well secured. The hallway leads to many rooms and an elevator."+NORM+"\n");
    write("There are three obvious exit: north, south, and east.\n");
    if (lamp_is_lit)
        write("The lamp beside the elevator is lit.\n");
}

id(str) {
    return str == "door" || str=="button";
}

    north() {
        if (call_other("/players/angel/area/stargate/room/elevator", "query_door", 0) ||
            call_other("/players/angel/area/stargate/room/elevator", "query_level", 0) != 27) {
            write("The door is closed.\n");
            return 1;
    }
    call_other(this_player(), "move_player", "north#/players/angel/area/stargate/room/elevator");
    return 1;
    }
    open(str)
    {
        if (str != "door")
            return 0;
        if (call_other("/players/angel/area/stargate/room/elevator", "query_level", 0) != 27) {
            write("You can't when the elevator isn't here.\n");
            return 1;
    }
    call_other("/players/angel/area/stargate/room/elevator", "open_door", "door");
    return 1;
    }
    close(str)
    {
        if (str != "door")
            return 0;
        call_other("/players/angel/area/stargate/room/elevator", "close_door", "door");
        return 1;
    }
    push(str)
    {
        if (!str || str != "button")
            return 0;
        if (call_other("/players/angel/area/stargate/room/elevator", "call_elevator", 27))
            lamp_is_lit = 1;
          write("You push the button.\n");
          return 1;
    }
    elevator_arrives()
    {
        say("The lamp on the button beside the elevator goes out.\n");
        lamp_is_lit = 0;
    }

    exit(){    if(this_player()) this_player()->clear_fight_area();     }