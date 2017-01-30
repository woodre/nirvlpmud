/*
*      File:            /players/lacar/area/park/rooms/unicornpark5.c
*      Function:         room
*      Author(s):        Lacar@nirvana
*      Copyright:        Copyright (c) 2006 Lacar(Carla Merrill)
*                                All Rights Reserved
*      Source:           11/22/06
*      Notes:            area
*      Change History:
*/

#include <ansi.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("statue", this_object()))
  move_object(clone_object("/players/lacar/area/park/obj/ststue_ex.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = "Unicorn Park 5";
  long_desc = 
"  This is a clearing which only holds a Unicorn statue. The air seems\n\
very still, yet you can hear the birds off in the distance. It is a\n\
very calming place. The grass seems to invite one to relax and the\n\
whole area gives off a warm inviting feeling.\n";

  items =
  ({
	"statue",
	"A majestic Unicorn statue with a plaque on it",   
	"plaque",
	"A piece of gold with words on it that can be read",
	"grass",
	"Nice green lush grass",
	"unicorn",
	"A majestic statue with a plaque on it",
	"birds",
	"Birds that can be heard but not seen",
	"clearing",
	"A lush grassy area with a Unicorn statue in the center",
});
dest_dir =
({
"/players/lacar/area/park/rooms/unicornpark4","south",
"/players/lacar/area/park/rooms/unicornpark6","east",
"/players/lacar/area/park/rooms/unicornpark10","north",
});
}