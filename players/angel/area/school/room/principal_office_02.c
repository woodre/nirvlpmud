/*                                                                              *
 *      File:             /players/angel/area/school/room/principal_office_02.c *
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
    move_object(clone_object("/players/angel/area/school/npc/asst_principal_02.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Asst Principal's Office";
  long_desc =
"   This is Assistant Principal McArthur's Office. This room\n\
looks very professional. There is a solid mahogany desk with a\n\
leather covered reclining office chair. There are piles of paper\n\
next to the computer.\n";

  items =
  ({
    "office",
    "A nice size office, very professional",
    "desk",
    "The mahogany desk is an antique. They aren't built like this anymore",
    "chair",
    "This is a leather office chair and it is very comfortable",
    "leather",
    "A refined material from cows",
    "computer",
    "A laptop computer used for school work",
    "papers",
    "The principal has many reports on how to\n\
improve the school sitting on the desk",   
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/principal_office_01.c", "exit",
  });
}

init() {
  ::init();
    add_action("stop","exit",1);
    add_action("disallow","quit");
}

  stop() {
    if(present("principal", environment(this_player())))
      {write("Mrs. McArthur pins you to down on on her desk.\n");
      say(this_player()->query_name()+" is pinned to the desk while trying to escape.\n");
        return 1;
}}

  disallow() {
    if(present("principal", environment(this_player())))
      if(this_player()->query_ghost() == 1) { return 0; }
      else{
      write("You can't quit from here.\n");
        return 1; }
}

realm(){ return "NT"; }