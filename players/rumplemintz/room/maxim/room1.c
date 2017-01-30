/* ========================================================================== */
/*                                                                            */
/*   room1.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Landing for King Maxim's castle                                          */
/*                                                                            */
/* ========================================================================== */


#pragma strict_types

inherit "/room/room.c";

void reset(status arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Entrance to King Maxim's castle";
  long_desc =
"     You are standing at the entrance to King Maxim's castle. There\n"+
"is a moat surrounding the large grey stones. Moss and other fungi\n"+
"appear to be growing out of control. The outward appearance is not\n"+
"a welcoming one.\n";
  items = ({
    "moat", "Your standard moat. It's water that runs around the outside of the castle",
    "stones", "Large grey stones make up the building blocks for the castle",
    "moss", "It appears the castle does not have a groundskeeper",
    "fungi", "It appears the castle does not have a groundskeeper"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/foyer", "north",
    "/players/rumplemintz/workroom", "work"
  });
}
