/* ========================================================================== */
/*                                                                            */
/*   west1.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Kitchen in King Maxim's castle                                           */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(1);
  short_desc = "Kitchen in King Maxim's castle";
  long_desc =
"     You are standing in the kitchen of King Maxim's castle. There are\n"+
"pots hanging from the ceiling. There is an island counter that runs\n"+
"through the middle of the room. The room is spotless, as if nothing has\n"+
"been cooked in here in ages.\n";
  items = ({
    "kitchen", "It's your standard kitchen",
    "pots", "Various pots hang from hooks",
    "ceiling", "There are pots hanging from it",
    "counter", "It is spotless, almost unused looking",
    "room", "It is spotless, almost unused looking",
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/foyer", "east"
  });
}
