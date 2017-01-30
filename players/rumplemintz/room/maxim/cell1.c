/* ========================================================================== */
/*                                                                            */
/*   cell1.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Prison cell 1 inside King Maxim's castle.                                */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(0);
  short_desc = "A prison cell in King Maxim's castle";
  long_desc =
"     You are in a dark, dirty, cold, moist, and stinky prison cell. The\n"+
"stench of excrement is almost unbearable. The walls have various markings\n"+
"on them. The walls are covered in blood, and other fluids. In the corner\n"+
"there is a small pile of straw and a metal cup.\n";
  items = ({
    "walls", "Scratched into the wall is a message",
    "message", "Rumplemintz was here!!!!",
    "markings", "There is a message scracthed into the wall",
    "blood", "It is dried in random splatter patterns",
    "straw", "It appears someone used it for a pillow",
    "cup", "A drinking cup that is chained to the wall",
    "cell", "It's a typical prison cell"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/dungeon2", "south"
  });
}
