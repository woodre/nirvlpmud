/******************************************************************************
 *  File:           hall2.c
 *  Author(s):      Vital@Nirvana from source by Rich@Nirvana
 *  Copyright:      Copyright (c) 2005 v-Dev Code Factory
 *                  All Rights Reserved.
 *  Source:         9/22/05
 *  Notes:          
 *  Change History: 
 *****************************************************************************/

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  set_short("Main Corridor");
  set_long("\
  This is a long corridor that connects several different rooms\n\
along the way and extends to the north, west and the south. To the\n\
east is a sliding portal that lead to the Visitors\' Lounge in the\n\
ship.\n");
  add_item("portal","This is a sliding door that gives access to another room");
  add_exit("players/rich/area/room/hall3.c", "north");
  add_exit("players/rich/area/room1.c", "west");
  add_exit("players/rich/area/room/kling1.c", "east");
  add_exit("players/rich/area/room/hall1.c", "south");
}
