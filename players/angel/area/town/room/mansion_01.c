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
  According to the mailbox near the street, this is Mayor Bob Ray's\n\
mansion.  It is a three-story brick home.  It appears to have\n\
brilliant workmanship. Some of the windows in the second floor are\n\
made of colored glass. The house is a marvelous sight.\n";

  items =
  ({
  "mailbox",
  "A Decorative Whitehall Estate Mailbox",
  "home",
  "a three-story brick home",
  "window",
  "The window's look like something that you might find in Tiffany's",
  "glass",
  "The glass has many different colors",
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