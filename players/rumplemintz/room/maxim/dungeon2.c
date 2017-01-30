/* ========================================================================== */
/*                                                                            */
/*   dungeon2.c                                                               */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Hallway in front of Cell 1 in King Maxim's castle.                       */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types
#include "/obj/door.h"

inherit "/room/room.c";
object obj_1, obj_2;

void reset(status arg){
  if(arg) return;
  set_light(0);
  short_desc = "Dungeon hallway in King Maxim's castle";
  long_desc =
"     You are in a dark hallway that leads down inmate row. The prison\n"+
"cells are located to the north of the hallway, and the hallway runs\n"+
"east-west. Iron bars make up the cell doors that serve as the protection\n"+
"between the citizens of Maxim's kingdom, and the accused and to often\n"+
"guilty. The stench of body fluids and stale blood permeates the air.\n";
  items = ({
    "inmate row", "The cells are on the north, the hall is on the south",
    "row", "The cells are on the north, the hall is on the south",
    "cells", "They are dark, cold, and dirty",
    "hall", "It runs east-west along the cells",
    "bars", "Iron bars make up the cell doors",
    "iron bars", "Iron bars make up the cell doors",
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/dungeon1", "east",
    "/players/rumplemintz/room/maxim/dungeon3", "west",
    "/players/rumplemintz/room/maxim/cell1", "north"
  });
  MAKE_DOORS(
    "/players/rumplemintz/room/maxim/dungeon2", "north",
    "/players/rumplemintz/room/maxim/cell1", "south",
    "silver",
    "m_prison",
    "An iron cell door\n",
    1,
    1,
    1
  );
}

