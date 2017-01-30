/*                                                                              *
 *      File:             /players/angel/area/school/room/main_office_01.c      *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";
int x;

reset(arg)
{
  ::reset(arg);
  if( !present("teacher", this_object()) )
    move_object(clone_object("/players/angel/area/school/npc/teacher_06.c"), this_object());
  if( !present("worker", this_object()) )
  {
    for(x=0; x<3; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/office_workers_01.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "main office";
  long_desc =
"   This is the Main office at the elementary school. It is a\n\
pretty standard office with space for three desks. The office\n\
workers use this room to answer the phones, assisting parents\n\
and relaying information to principal. Visible to the north is\n\
a door.\n";

  items =
  ({
    "workers",
    "school office personnel",
    "phones",
    "The phones stay lit up and has many buttons",
    "parents",
    "regular students parents who need assistance",
    "principal",
    "His office is to the north. He is over 6 feet tall with a slender\n\
build. He looks like he is Italian.",
    "door",
    "As you look behind the desk you can see a door with Mr. Ray on it",
    "office",
    "A place to work, nothing fancy",
    "desk",
    "Where the office personnel work",
    "school",
    "It is a large brick building",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/principal_office_01", "north",
    "/players/angel/area/school/room/entrance", "southeast",
  });
}