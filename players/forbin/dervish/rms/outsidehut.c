/* 
 * Forbin
 * Created:   2003.09.02
 * Last edit: 2003.10.28 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

reset(arg) {
  if(arg) return;
  short_desc = "A "+GRN+"Grassy"+NORM+" Clearning";
  long_desc = 
    "  Low growing grass runs through an open area that's been cleared\n"+ 
    "of the nearby trees.  Around the clearing, the surrounding forest\n"+
    "towers high forming a protective boundary, while a great mountain\n"+
    "dominates the northwest sky.  Dirt shows through the patchy grass,\n"+ 
    "and several bushes and little trees have been planted.  A small\n"+
    "hut rests in the center of the clearing; the building is worn and\n"+
    "weathered, and looks as old as the surround forest itself.\n";
  add_item("mountain",
    "Snow capped and cloaked in a foggy haze, it towers loomingly over\n"+
    "the northwestern forest");
  add_item(({"hut","building"}),
    "A small hut with a thatched room.  A large round door is set\n"+
    "between two round windows that look out towards the northwest.\n"+
    "Smoke floats out a hole in the roof.");
  add_item("smoke",
    "A sweet smelling smoke rises out of the hut's roof");
  add_item("grass",
    "Wide blade grass grows about the area in patches");
  add_item(({"area","clearing"}),
    "The forest has been cleared off and a small homestead built\n");
  add_item("forest",
    "The forest grows up around the clearing, protecting it");
  add_item(({"tree","trees","bush","bushes"}),
    "The area has been landscaped with round bushes and small trees");
  add_item("dirt",
    "The dark brown dirt shows through the grass in places");
  add_item("door",
    "A large round door is centered in the northwest wall of the hut.\n"+
    "It is built from vertical boards, strapped together with wide\n"+
    "metal bands at the top, middle, and bottom.  The door is closed");
  add_item(({"window","windows"}),
    "Two round windows flank a large door, one on each side");
  add_smell("main",
    "An odd smelling smoke rises from out a hole in the roof of a hut.\n");
  set_chance(random(5));
    add_msg("A strange smell floats through the air.");
  set_light(1);
  add_exit(ROOT+"rms/paradise05.c","jungle");
  add_exit_msg("jungle", "You head off into the jungle.\n",
		                 "heads off into the jungle.\n");
}

short() { return "A "+GRN+"Grassy"+NORM+" Clearning"; }

init() {
  ::init();
  add_action("cmd_enter","enter");
}

cmd_track(string str) {
  if(!str || (str != "hut" && str != "cabin" && str != "building")) { 
    notify_fail("Enter what?\n"); 
      return 0; 
  }
  write("You faintly knock, and checking the knob, you turn it and enter the hut.\n");
  say(this_player()->query_name()+" knocks lightly on the door, then enters the hut.\n");
  move_object(this_player(),ROOT+"rms/hut.c");
  command("look",this_player());
  say(this_player()->query_name()+" arrives.\n");
    return 1; 
}
