/* ========================================================================== */
/*                                                                            */
/*   upwest1.c                                                                */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Top of western stairway in King Maxim's caslte                           */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(0);
  short_desc = "Western stairway in King Maxim's castle";
  long_desc =
"     You are at the top of the western staircase of the castle. The\n"+
"ambient light is still to dark to be of much use. The sconces on the\n"+
"walls are all broken and incapable of holding anything. The cobwebs\n"+
"are so thick here, it makes passage sticky. There appears to be an\n"+
"opening to the south.\n";
  items = ({
    "staircase", "It winds down to the first level",
    "cobwebs", "They are really thick here, some of them appear fresh",
    "sconces", "They are old and unused. All of them are broken",
    "opening", "It appears to lead south into another room"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/west3", "down",
    "/players/rumplemintz/room/maxim/upwest2", "south"
  });
}
