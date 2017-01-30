/* 
 * Forbin
 * Created:   2003.09.08
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

int mfixed, mrandom;

reset(arg) {
  if(arg) return;
  short_desc = "A Forest Canopy";
  long_desc = GRN+HBGRN+
    "  You stand upon a wooden platform that encircles a massive tree.\n"+
    "Darkened wood has been fashioned into a railing that runs around \n"+
    "the circumference of the platform and provides protection from   \n"+
    "falling.  A vine runs down through an opening in the platform.   \n"+ 
    "    No obvious exits.                                            \n"+NORM;
  add_item(({"platform","wooden platform"}),
    "The wooden platform, built from dark wood, has been built around\n"+
    "a large tree");
  add_item("tree",
    "The tree, almost 10 meters in diameter, grows tall.  It has a\n"+
    "large saddle where a limb meets the trunk");
  add_item("saddle",
    "A deep saddle is formed at the joint of the trunk and a limb");
  add_item(({"rail","railing"}),
    "A railing of weathered wood has been erected to keep people from\n"+
    "falling over the edge of the platform");
  add_item("opening",
    "A 2 meter hole cut into the platform, through which a knotted\n"+
    "vine runs down");
  add_item("canopy",
    "The forest is alive around you, abuzz with motion and sound");
  add_item(({"vine","vines"}),
    "The vines grown thick in the trees, yet do not seem to choke the\n"+
    "trees like most vines.  A hearty vine with knots tied in it runs\n"+
    "through a hole in the platform.  You could climb down it");
  set_chance(random(5));
    add_msg("Crickets chirp.");
    add_msg("Birds chatter in the treetops.");
    add_msg("An unfamiliar animal screeches somewhere off in the distance.");
  add_property("NT");
  set_light(1);
  no_exit_display = 1;
  add_exit(ROOT+"rms/canopy05.c","down");
}

short() { if(random(2)) return GRN+"A Forest Canopy"+NORM;
          else return HIG+"A Forest Canopy"+NORM; }

init() {
  ::init();
  add_action("cmd_climb","climb");
  add_action("cmd_block","down");
}

cmd_climb(string str) {
  if(!str || (str != "down" && str != "down vine") { 
    notify_fail("Climb which way?\n"); 
      return 0; 
  }
  write("You climb down out of the canopy.\n");
  say(this_player()->query_name()+" climbs down out of the canopy.\n");
  move_object(this_player(),ROOT+"rms/canopy05.c");
  command("look",this_player());
  say(this_player()->query_name()+" comes climbing down a vine.\n");
    return 1;
 
}

cmd_block() { write("What?\n"); return 1; }
