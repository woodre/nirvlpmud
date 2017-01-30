/* 
 * Forbin
 * Created:   2003.08.28
 * Last edit: 2003.09.25 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/room.c";
#define ROOT "/players/forbin/dervish/"

reset(arg) {
  if(arg) return;
  short_desc = GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM;
  long_desc = 
    "  A sandy shoreline stretches around a quiet pool of water in a\n"+
    "semi-circle, almost closing in on itself before running into a\n"+
    "smooth rock wall.  A beautiful waterfall cascades down the wall,\n"+
    "splashing loudly into the pool and bubbling foam and froth about.\n"+
    "Thick jungle rises up all around, cutting this idilic place off\n"+
    "from the world almost completely.  The only breaks in the wall of\n"+
    "forest are a wide trail  leading east, and a stream feeding out\n"+
    "of the pool into the woods.\n";
  add_item(({"shore","shoreline"}),
    "The fine sand is so soft, you sink slightly into it");
  add_item(({"wall","rock","rock wall"}),
    "A sheer rock wall, topped with cliffs, grows high into the sky");
  add_item(({"fall","falls","waterfall"}),
    "Water magnificently falls from the cliff above, crashing loudly\n"+
    "into the pool");
  add_item(({"pool","water"}),
    "The water of the pool is silky smooth save for the area near the\n"+
    "falls, where the waterfall splashes and sprays water all about");
  add_item(({"foam","froth"}),
    "A white foam and froth marks where the falls meet the pool");
  add_item(({"jungle","forest","woods"}),
    "All around, a thick jungle rises up");
  add_item("trail",
    "A wide path leads eastward into the jungle");
  add_item("stream",
    "A small stream flows out of the pool and into the jungle.  Trees\n"+
    "and vines hang low above it, but one might be able to follow it");
  add_listen("main", 
    "Birds and animals chirp and growl noisily in the jungle.\n");
  set_light(1);
  add_exit(ROOT+"rms/paradise05.c","east");
  add_exit(ROOT+"rms/paradise03.c","pool");
  add_exit_msg("east", "You head off into the jungle.\n",
		               "heads off into the jungle.\n");
  add_exit_msg("pool", "You wade out into the pool of water.\n",
                       "wades out into the pool of water.\n");
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_follow","follow");
}

cmd_follow(string str) {
  object wetme;
  if(!str || (str != "stream" && str != "the stream")) { 
    notify_fail("Follow what?\n"); 
      return 0; 
  }
  write("You head off into the jungle following the stream.\n");
  say(this_player()->query_name()+" heads off into the jungle.\n");
  move_object(this_player(),ROOT+"rms/paradise08.c");
  command("look",this_player());
  say(this_player()->query_name()+" arrives.\n");
    return 1; 
}

