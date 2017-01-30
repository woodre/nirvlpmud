/* ========================================================================== */
/*                                                                            */
/*   upeast1.c                                                                */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Top of eastern stairway in King Maxim's castle                           */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(0);
  short_desc = "Eastern stairway in King Maxim's castle";
  long_desc =
"     You are at the top of the eastern stairway of the castle. There\n"+
"seems to be some light coming from the south. The stairway winds \n"+
"down to the main level. There are cobwebs covering everything.\n";
  items = ({
    "stairway", "It winds down to the main level",
    "light", "It is coming from the south",
    "cobwebs", "They are covering everything"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/east3", "down",
    "/players/rumplemintz/room/maxim/upeast2", "south"
  });
}
