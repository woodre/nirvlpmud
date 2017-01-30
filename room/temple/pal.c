/* Recoded - was using some room inherit from Reflex dir that didn't exist
   -- Rumplemintz
*/

#include <ansi.h>
inherit "room/room";

void reset(status arg) {
  if (!present("book", this_object())) {
    move_object(clone_object("/players/guilds/warriors/OBJ/trainer_paladin"),
                this_object());
  }
  if (arg)
    return;
  set_light(1);
  set_no_clean(1);
  short_desc = BOLD + "Temple" + NORM;
  long_desc = BOLD +
"The Paladin Profession Training room.\n" + NORM +
"You are in an open circular room. Enclosed areas cover the circumference\n" +
"Many weapons are stored on the walls from simple wooden practice swords to\n" +
"large, heavy swords that require great mastery to use. In the center of the\n" +
"dirt area there is a giant symbol of a cross. On the far side of the dirt\n" +
"area within the enclosure there is a small pedestal with an inset of the area\n" +
"containing a book. The arch exist to the south.\n";
  items = ({
    "weapons", "Weapons of all types are secured to the walls of the enclosure such that\nthey cannot be removed",
    "practice swords", "Simple crude wooden practice swords secured to the walls",
    "swords", "Various swords are secured to the walls",
    "dirt", "A dry, dusty dirt covers the practice area",
    "symbol", "The symbol of a cross, is slightly covered with dust in the practice area",
    "pedestal", "This is a plain stone pedestal",
    "inset", "This is a small depression set slightly into the pedestal.  A book rests upon it",
    "enclosure", "The area around the practice area is covered protecting it from the weather",
  });
  dest_dir = ({ "/room/temple/pastgate", "south" });
}

int query_no_fight() { return 1; }
