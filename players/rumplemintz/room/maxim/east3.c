/* ========================================================================== */
/*                                                                            */
/*   east3.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Eastern stairway in King Maxim's castle                                  */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(0);
  short_desc = "Eastern stairway in King Maxim's castle";
  long_desc =
"     You are standing at the bottom of a spiral staircase leading up.\n"+
"This corner of the castle is dark and gloomy. There are no windows or\n"+
"sconces to light the area.\n";
  items = ({
    "staircase", "It leads up",
    "spiral staircase", "It leads up"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/upeast1", "up",
    "/players/rumplemintz/room/maxim/foyer3", "west"
  });
}
