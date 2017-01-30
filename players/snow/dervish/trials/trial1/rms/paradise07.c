/* 
 * Forbin
 * Created:   2003.08.29
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

reset(arg) {
  if(arg) return;
  short_desc = GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM;
  long_desc = 
    "  The forest thins here, slowly melding with a lush grassland of\n"+
    "ferns and bushes.  The ground gently slopes north before sharply\n"+
    "rising up into a high mountain.  A swirling gray fog hugs the\n"+
    "upper crags of the mountain, yet every now and then a glimpse of\n"+
    "the peaks, capped in white, shows through.\n";
  add_item("forest",
    "The forest gives way to a wonderful grassland");
  add_item(({"grassland","grass","fern","ferns","bush","bushes"}),
    "Tall grass, wide-leaved ferns and squat bushes grow abundantly here");
  add_item("ground",
    "The ground slopes gently before giving birth to the mountain");
  add_item("mountain",
    "A large mountain towers to the north.  Both Beautiful and\n"+
    "majestic, you could attempt to climb to its peak");
  add_item(({"crag","crags","peak","snow","white"}),
    "Beautiful white snow dots the upper mountainscape");
  add_item("fog",
    "A dark fog swirls about the mountain");
  set_light(1);
  add_exit(ROOT+"rms/paradise05.c","west");
  add_exit_msg("west", "You head off into the jungle.\n",
		               "heads off into the jungle.\n");
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_climb","climb");
}

cmd_climb(string str) {
  object cgear;
  if(!str || (str != "mountain" && str != "the mountain")) { 
    notify_fail("Climb what?\n"); 
      return 0; 
  }
  cgear = present("dervish_quest_climbing_gear", this_player());
  if(!cgear) {
    write("You realize it will be impossible to climb the mountain without the\n"+
          "proper kind of climbing gear.\n");
    say(this_player()->query_name()+" studies the mountain hopelessly.\n");
      return 1;
  }
  write("You carefully climb up the mountain.\n");
  say(this_player()->query_name()+" climbs up the mountain.\n");
  move_object(this_player(),ROOT+"rms/mountain01.c");
  command("look",this_player());
  say(this_player()->query_name()+" comes climbing up the mountain.\n");
    return 1; 
}

