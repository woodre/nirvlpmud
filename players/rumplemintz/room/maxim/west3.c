/* ========================================================================== */
/*                                                                            */
/*   west3.c                                                                  */
/*   (c) 2005  Rumplemintz                                                    */
/*                                                                            */
/*   Western stairway in King Maxim's castle                                  */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(0);
  short_desc = "Western stairway in King Maxim's castle";
  long_desc =
"     You are standing at the bottom of a stairwell. The sconces on the\n"+
"wall have been extinguished. The floor is wet and the air is cold. There\n"+
"are cobwebs covering the stairs.\n";
  items = ({
    "stairwell", "It is covered in cobwebs, it looks unused",
    "sconces", "They appear like they are too old to light",
    "cobwebs", "They are everywhere"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/upwest1", "up",
    "/players/rumplemintz/room/maxim/foyer3", "east"
  });
}
