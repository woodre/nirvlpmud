/*                                                                      *
 *    File:             /players/angel/area/lowthar/room/tirga_mor.c    *
 *    Function:         room                                            *
 *    Author(s):        Angel@Nirvana                                   *
 *    Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)        *
 *                              All Rights Reserved.                    *
 *    Source:           11/15/06                                        *
 *    Notes:                                                            *
 *                                                                      *
 *                                                                      *
 *    Change History:                                                   *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIY+"Tirga Mor"+NORM;
  long_desc =
"    "+HIY+"~ Tirga Mor Castle ~"+NORM+"\n\
"+HIC+"\n\
                              /\\ \n\
                             /  \\ \n\
                         ^  _|..|_  ^ \n\
                       _|I|  |I.|  |.|_ \n\
                      \\II||--| |--||  / \n\
                       -\\-|-------|-/- \n\
                         \\|II I ..|/ \n\
                     /\\   |II.    |     /\\ \n\
                    /  \\ _|III .  |_   /  \\ \n\
                    |--| /(|I.I I  |)\\ |--| \n\
                  _ /(I | +-----------+ |. )\\_ \n\
                 \\------/____---____\\------/ \n\
                   |I.III|  /(===)\\ |  .. | \n\
                   /--------_________------\\ \n\
                  `##########!\\-#####%!!!!!| |\\ \n\
                  /###########!!\\---_##%!!!\\_/| \n\
                \\##############!!!!!/---_%!!!!\\ \n\
                (-)#################!!!!!/----\\_ \n\
\n\
This is the entrance to Tirga Mor Castle."+NORM+"\n";

  items =
  ({
  });

  dest_dir =
  ({
	"/players/angel/area/lowthar/room/pen_02",   "north",
  });
}

init(){
  ::init();
    this_player()->set_fight_area();
   }

exit(){    if(this_player()) this_player()->clear_fight_area();     }