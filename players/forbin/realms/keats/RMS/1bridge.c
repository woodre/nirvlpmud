/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Function:     City of Keats
 *  Create Date:  2004.06.13
 *  Last Edit:    2004.06.18 -Forbin
 *  Notable Changes:
 */

#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/realms/keats/room.c";

string Location;

reset(arg) 
{
  if(arg) return;
  short_desc = KEATS;
  Location = "The Bridge of Advention";
  long_desc = 
    "\n                   "+HIW+"The Bridge of Advention"+NORM+"\n"+
    "  A fairly wondrous construction, this long, massive suspension bridge\n"+
    "stretches across a fog cloaked chasm.  To the north and south are huge\n"+
    "gates that serve to sever outside travel into the city when times\n"+
    "require it.  A cool, misty fog shrouds everything else from view.\n";
  add_item(({"construction","bridge","suspension bridge"}),
    "Masterfully built of wood and stone, the bridge is in fine shape");
  add_item("chasm",
    "You peer off the bridge and see nothing but fog and mist far below.\n"+
    "With a sly grin, you wonder what would happen if you jumped off");
  add_item(({"fog","mist","misty fog"}),
    "The thick misty fog hides everything but the gates and the bridge\n"+
    "itself from your sight");
  add_item(({"gate","gates","gateway","gateways"}),
    "Large stone gateways tower over each end of the bridge.  Perched\n"+
    "directly on the edge of an unfathomable chasm, they stretch over\n"+
    "eight men high and at least 30 men wide.  They seem to have been\n"+
    "carved from single pieces of stone.  A pair of large doors, closed\n"+
    "in times of danger, are swung open at each gate");
  add_item(({"door","doors"}),
    "Each pair of doors are made of a dark, weathered wood.  Several iron\n"+
    "bands run horizontally across each door.  Currently, they are open");
  add_item("stone",
    "Each gateway is made of a dark gray stone that is marbled with light\n"+
    "streaks of bright blue");
  set_chance(random(5));
    add_msg("A chill wind blows across the bridge...");
  add_listen("main", 
    "You hear the sound of rushing water far below.\n");
  add_exit(RMS+"1word02.c", "keats");
  add_exit("/players/forbin/realms/flame_forest/RMS/ff06_02.c", "forest");
  set_light(1);
}

init() 
{
  ::init();
  add_action("cmd_jump","jump");
}

cmd_jump() 
{
  tell_object(this_player(),
    "Are you crazy?!?\n");
  return 1; 
}
