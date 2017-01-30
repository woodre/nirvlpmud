/* ========================================================================== */
/*                                                                            */
/*   dungeon1.c                                                               */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Entry room into the dungeon area of King Maxim's castle                  */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(0);
  short_desc = "Dungeon entry of King Maxim's castle";
  long_desc =
"     You are at what appears to be an entryway. In the darkness, you\n"+
"can make out a hallway that leads west. The cold air and moist\n"+
"surroundings seem to create fog and darkness. There is dried blood\n"+
"on the walls and floors, and the stench of a prison is overwhelming.\n";
  items = ({
    "entryway", "A gate stands open to the west",
    "gate", "It is stuck in the open position",
    "hallway", "It appears to dissolve in the darkness",
    "surroundings", "Everything is moist with humidity",
    "blood", "No doubt the blood of past inmates",
    "walls", "Clearly they have been neglected, as they are in disrepair",
    "floors", "There is blood splattered all over the floor"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/lower1", "north",
    "/players/rumplemintz/room/maxim/dungeon2", "west"
  });
}
