/* ========================================================================== */
/*                                                                            */
/*   lower1.c                                                                 */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Lower landing in King Maxim's castle                                     */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(1);
  short_desc = "Entry to dungeon in King Maxim's castle";
  long_desc =
"     You are standing at the bottom of the staircase. The area is dimly\n"+
"lit by a single torch attached to the wall. Mold has collected on the\n"+
"damp stone. Up above you can see the glow of the main level. The damp\n"+
"stone is marred by scrapes and scars of many years of neglect.\n";
  items = ({
    "staircase", "It leads up to the main level",
    "torch", "It is attached to the stone, and dimly lights this area",
    "mold", "The dampness of the dungeon stone makes a great home for mold",
    "stone", "It is cold, damp and dirty",
    "scrapes", "Gouges in the stone made by the dragging of iron",
    "scars", "Gouges in the stone made by the dragging of iron"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/foyer2", "up",
    "/players/rumplemintz/room/maxim/dungeon1", "south"
  });
}
