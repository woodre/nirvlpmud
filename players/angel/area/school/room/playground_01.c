/*                                                                              *
 *      File:             /players/angel/area/school/room/playground_01.c       *
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
  if( !present("student", this_object()) )
  {
    for(x=0; x<5; x++)
    {
    move_object(clone_object("/players/angel/area/school/npc/playground_student_01.c"), this_object());
    }
}
  if(arg) return;
  set_light(1);
  short_desc = "Playground";
  long_desc =
"  This is the school playground. There is a new inventive system\n\
made of plastic. The playground equipment is all connected together\n\
freeing up space for students to play more traditional games like\n\
tag, kickball and dodgeball. Students use this area to play dodgeball.\n\
The teachers hide under the shade of the trees during play time.\n";
 
  items =
  ({
    "playground",
    "A place for students to play",
    "plastic",
    "plastic, you'v seen it!",
    "tag",
    "A game of touch your it",
    "kick ball",
    "like baseball, but kick a ball instead",
    "equipment",
    "It is brand new",
    "dodge ball",
    "The object is not to throw the ball hard, but accurately in order\n\
to catch someone trying to dodge the ball",
    "games",
    "Something done for fun",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/school_hall_04", "northeast",
  });
}