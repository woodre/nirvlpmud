/*                                                                    *
 *    File:             /players/angel/closed/hell.c                  *
 *    Function:         room                                          *
 *    Author(s):        Angel@Nirvana                                 *
 *    Copyright:        Copyright (c) 2009 Angel                      *
 *                              All Rights Reserved.                  *
 *    Source:           06/22/09                                      *
 *    Notes:                                                          *
 *                                                                    *
 *                                                                    *
 *    Change History:                                                 *
 */

#include "/sys/lib.h"

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
   if( !present("lucifer", this_object()) )
    move_object(clone_object("/players/angel/closed/lucifer.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = RED+"HELL"+NORM;
  long_desc =
  ""+RED+"   <<<<<<<<<<<<<<<<<<<<<<<<<< HELL >>>>>>>>>>>>>>>>>>>>>>>>>>\n"+
  "This is a place of suffering and punishment for the wrong doings\n"+
  "agianst Angel.  Lucifer stands before you with plans to make you\n"+
  "relive all of the pain, guilt, and suffering that occured to you\n"+
  "on your prior plan of extience.  This realm is 1025 degrees\n"+
  "pharenheit.  You can feel you skin dripping off your body."+NORM+"\n";
}

void init()
{
  ::init();
  add_action("pray","pray");
  add_action("stop","out",1);
  add_action("disallow","quit");
}

int pray(string str)
{
  if(!str)
  {
    write("Who would you like to pray to?\n");
    return 1;
  }
  if(str == "to God")
  {
    write("You pray to God and with his mercy you are released from Hell!\n");
    call_other(this_player(),"move_player","in#players/angel/area/stargate/room/sg1.c");
    return 1;
  }
}

  stop() {
    if(present("lucifer", environment(this_player())))
      {write("Lucifer slams you in the Fiery Pit as you try to escape.\n");
      say(this_player()->query_name()+" is slammed in the Fiery Pit as they try to escape.\n");
        return 1;
}}

  disallow() {
    if(present("lucifer", environment(this_player())))
      if(this_player()->query_ghost() == 1) { return 0; }
      else{
      write("You are in HELL for all Eternity.\n");
        return 1; }
}

realm() {return "NT";}