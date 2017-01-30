inherit "room/room";
#include <ansi.h>
#define PATH "/players/dreamspeakr/mesa/"


reset(arg) {
	if(!present("american indian")) {
	    move_object(clone_object("/players/dreamspeakr/mesa/NPC/shaman.c"), this_object());
      move_object(clone_object("/players/dreamspeakr/mesa/NPC/anasazi.c"), this_object());
      move_object(clone_object("/players/dreamspeakr/mesa/NPC/anasazi.c"), this_object());
  }
  if(arg) return;
     set_light(1);

     short_desc = HIG+"Cliff Palace Kiva"+NORM;
     long_desc =
         "\n"+
         "\tConstructed subsurface, this kiva spans approximately \n"+
         "600 feet wide in a complete circle.  Above, a vertical shaft \n"+
         "ventilates the room allowing fresh air to enter.  Smoke \n"+
         "from the fire in the center of the room billows out of the \n"+
         "overhead entry.  This room is the Sipapu, the spiritual \n"+
         "grounds for the Anasazi tribe.  \n"+
         "\n"
;

     items = ({
         "shaft","Hollowed out wood used to let in fresh air",
         "smoke","Theres a funny smell to it.  Your eyes burn as you \n"+
            "try to look at it",
         "fire","As it blazes in the center of the room, men gather \n"+
            "round telling stories and passing the peace pipe",
         "sipapu","(A spirit entrance) to the Four Worlds below, from \n"+
            "which the Anasazi people believe they arrived on the earth's\n"+
            "surface",
});

dest_dir = ({
    PATH+"mv6.c","leave",
});

}
