#include "/obj/ansi.h"
#define ROOM    "/players/reflex/lib/std/random/room"

inherit ROOM;

    query_no_fight(){ return 1; }
void create() {
if(!present("monk_book", this_object())){
  move_object(clone_object("/players/guilds/warriors/OBJ/trainer_paladin"), this_object());

   }

::create();
    set_short(BOLD+"Temple"+NORM);
    set_long(BOLD+
        "The Paladin Profession Training  room.\n"+NORM+
	"You are in an open circular room. Enclosed areas cover the circumferance\n"+ 
        "Many eapons are stored on the walls from simple wooden practice swords to\n"+
        "large, heavy swords that require great mastery to use. In the center of the\n"+ 
        "dirt ares there is a giant symbol of a cross. On the far side of the dirt\n"+
        "area within the enclosure there is a small pedestal with an  inset at the\n"+ 
        "containing a book.The arch exits to the south.\n");
    set_items(([
        "weapons" :
        "Weapons of all types are secured to the walls of the enclosure such that.\n"+
        "they cannot be removed.\n", 
        "practice swords" :
        "Simple, crude wooden practice swords secured to the walls. \n",
        "swords" :
        "Various swords are secured to the walls.\n",
        "dirt" :
        "A dry, dusty dirt covers the practice area.\n",
        "symbol" :
        "The symbol of a cross, is slightly covered with dust in the practice area.\n",
        "pedestal" :
        "This is a plain stone pedestal.\n",
        "inset" :
        "This is a small depression set slightly into the pedestal.  A book rests upon it.\n",
	"enclosure" :
	"The area around the practice area is covered protecting it from the weather.\n",
        ]));
    set_sounds(([
	"default" :
	"While empty here, weapons clashing can be heard to the west.\n",
	]));
    set_exits(([
        "south" : "/room/temple/pastgate.c",
        ]));
    set_light(1);
}