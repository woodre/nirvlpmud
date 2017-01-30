/* ========================================================================== */
/*                                                                            */
/*   east1.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Maid's quarters in King Maxim's castle                                   */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(0);
  short_desc = "Maid quarters in King Maxim's castle";
  long_desc =
"     You are standing in the maid quarters.  There is a small bed on\n"+
"one side of the room, and an armoire on the other. There are no windows\n"+
"or lights. There is a broom and a mop leaning against one of the walls,\n"+
"and a bucket sitting on the floor.\n";
  items = ({
    "bed", "A small feather bed with some covers on top",
    "covers", "Neatly tucked in, they cover the bed",
    "armoire", "Likely where the maid keeps her clothes",
    "broom", "A normal broom, used to sweep floors",
    "mop"," A normal mop, it's used to clean floors",
    "bucket", "A mop bucket, it's empty"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/foyer", "west"
  });
}
