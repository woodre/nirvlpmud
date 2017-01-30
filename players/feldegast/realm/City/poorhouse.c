/*
File: poorhouse.c
Author: Feldegast
Date: 11/02/98
Revised: 03/23/02
Description:
  A poorhouse with a box for donations.
*/

#include "defs.h"

inherit ROOM;

reset(arg) 
{
  if(!present("box")) {
    move_object(clone_object("/players/feldegast/obj/dbox"));
  }
  if (arg) return;
  set_light(1);
  short_desc="The Poorhouse";
  long_desc=
"  This decrepit building is the only home for many of\n"+
"the poorer residents of Calador.  In back are a row of cots\n"+
"with threadbare blankets on them.  Cracked mortar and bits\n"+
"of ceiling are sprinkled across the floor.\n";
  items=({
    "residents","The poorhouse is mostly empty right now due to a booming\n"+
                "economy and a favorable economic climate",
    "cots",     "Simple wooden cots with threadbare blankets on them",
    "mortar",   "You get the feeling this building isn't well maintained",
    "ceiling",  "It probably leaks when it rains"
  });
  dest_dir=({
    PATH+"copper1","east"
  });
}   
