/*                                                                              *
 *      File:             /players/angel/area/school/room/principal_office_01.c *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel                              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("principal", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/principal_01.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Principal's Office";
  long_desc =
"   This is Principal Ray's Office. This room looks very\n\
professional. There is a solid mahogany desk with a leather\n\
covered reclining office chair. The room's walls are covered\n\
with fancy bookcases as if it were a library. There are many\n\
plants and trees in the room that liven it up.\n";

  items =
  ({
    "office",
    "A nice size office, very professional with two solid doors",
    "doors",
    "The two doors are possible exits. One goes to the main office\n\
and the other 'enter's into the assistant principal's office",
    "desk",
    "They aren't built any better than this and it has a fancy wood trash\n\
can next to it",
    "chair",
    "This is a leather office chair and it is very comfortable",
    "book case",
    "The book case is made of solid wood. The color of the book case is magnificent",
    "trees",
    "There are trees in every direction. They are bright green and look well watered",
    "plants",
    "There are several green hanging plants around the room",
    "floor",
    "Hardwood floor",
    "trash can",
    "A fancy wood trash can",
    "trash",
    "Trash and garbage, what are you look in here for?",
    "garbage",
    "GARBAGE - you know GARBAGE!",
    "leather",
    "A refined material from cows",
    "cows",
    "Animals raised to butcher",  
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/main_office_01.c", "south",
  });
}

init() {
  ::init();
    add_action("enter","enter");
}

enter(str) {
	say(capitalize(this_player()->query_name())+
    "walks into the assistant principal's office\n");
    this_player()->move_player(
    "walked into the assistant principal's office#/players/angel/area/school/room/principal_office_02.c");
    say(capitalize(this_player()->query_name())+" arrives.\n");
    return 1;
}
