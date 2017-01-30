/* 
 * Forbin
 * Created:   2003.09.02
 * Last edit: 2003.10.24 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

reset(arg) {
  if(arg) return;
  short_desc = "A "+HIW+"Snowy"+NORM+" Mountain Route";
  long_desc = 
    "  A snowy blanket covers everything here, and every way you look\n"+
    "appears the same, except for the small sign of a long untravelled\n"+
    "route up the mountain.  Halfway up the slope rests a large rock,\n"+
    "to which some gruesome creature is chained - blocking the path.\n";
  add_item(({"snow","blanket","snowy blanket"}),
    "Bright, white snow covers everything in sight");
  add_item(({"sign","route","untravelled route","path"}),
   "A seldom used path traces a route up the mountainside");
  add_item(({"mountain","slope"}),
    "You stand upon the mountain, which rises above you and falls back\n"+
    "toward the ground below to your back");
  add_item("rock","A rock stands next to the trail midway up the slope");
  set_light(1);
  add_exit(ROOT+"rms/mountainpeak.c","up");
  add_exit(ROOT+"rms/paradise07.c","down");
  add_exit_msg("up","You climb up towards the mountain peak.\n",
                    "climbs up towards the mountain peak.\n");
  add_exit_msg("down", "You climb back down towards the jungle.\n",
		               "climbs back down towards the jungle.\n");
  add_object(ROOT+"npc/yeti.c");
}

short() { return "A "+HIW+"Snowy"+NORM+" Mountain Route"; }

init() {
  ::init();
  add_action("cmd_up","up");
}

cmd_up() {
  object snowmonster;
  snowmonster = present("yeti", environment(this_object()));
  if(snowmonster) {
    write("Snarling loudly, the Yeti swings a clawed paw at you, barely missing\n"+
          "your head.  Unless you do something, it will prevent your ascent.\n");
    return 1;
  }
}