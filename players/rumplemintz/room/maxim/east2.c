/* ========================================================================== */
/*                                                                            */
/*   east2.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Armory of King Maxim's castle                                            */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(1);
  short_desc = "Armory of King Maxim's castle";
  long_desc =
"     You are in the armory of the castle. There are armors and weapons\n"+
"all over the place. There seems to be no order, and things are strewn \n"+
"about. The weapons all looked used and battle-worn. The armor is rusty\n"+
"and in a state of disrepair.\n";
  items = ({
    "armory", "Armors and weapons are kept here",
    "armors", "The armors don't look like they would be very protective",
    "weapons", "All of the weapons look well used and non repairable"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/foyer2", "west"
  });
}
