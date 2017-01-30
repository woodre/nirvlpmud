/*                                                                            *
 *      File:             /players/angel/area/mansion/mansion_01.c            *
 *      Function:         Heal shop                                           *
 *      Author(s):        Angel@Nirvana                                       *
 *      Copyright:        Copyright (c) 2007 Angel                            *
 *                                All Rights Reserved.                        *
 *      Source:           06/20/07                                            *
 *      Notes:            Entrance to Mansion                                 *
 *                                                                            *
 *                                                                            *
 *      Change History:                                                       *
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Bob Ray's Mansion";
  long_desc =
"    "+HIY+"Mansion"+NORM+"\n\
  This is the yard that leads to Mayor Bob Ray's mansion.\n\
Looking up there is a three story brick home. It appears\n\
to have brilliant workmanship. Some of the windows in the\n\
second floor are made of colored glass. A marvelous site.\n";

  items =
  ({
  
});
  dest_dir =
  ({
    "/players/angel/area/town/room/emain_04", "road",
/*    "/players/angel/area/mansion/room/entrance_10", "enter", */

  });
}

init(){ 
  ::init();
    this_player()->set_fight_area();
      }

exit(){    if(this_player()) this_player()->clear_fight_area();     }

realm(){ return "NT"; }