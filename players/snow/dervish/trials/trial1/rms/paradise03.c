/* 
 * Forbin
 * Created:   2003.08.28
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"

reset(arg) {
  if(arg) return;
  short_desc = "A cool pool of water";
  long_desc = 
    "  Standing in waist-deep water, ripples undulate outward from    \n"+
    "you.  To the west is a towering waterfall that pours over a cliff\n"+
    "high above.  The water is very cold, and smooth as glass it      \n"+
    "glides to a sandy bank that surrounds the waterfalls with the    \n"+
    "u-shaped shore.  A lofty rainforest rises up a short distance    \n"+
    "beyond the shoreline.                                            \n"+
    "    There is one obvious exit: shore                             \n"+NORM;
  add_item("water",
    "The water is smooth as glass and crystal clear.  You can make out\n"+
    "the bottom of the pool and can even see your feet under water");
  add_item(({"ripple","ripples"}),
    "You disturb the water, and watch ripples circle outward");
  add_item(({"waterfall","towering waterfall"}),
    "A striking waterfall thunders over cliffs high above and splashes\n"+
    "into the pool.  A dark shadow is behind the falls of the pool");
  add_item("shadow",
    "A dark outline beyond the waterfall.  It almost looks like a cave\n"+
    "One could pass through the waterfall to get a better look");
  add_item("cliff",
    "High above, a smooth cliff dumps water over toward the pool");
  add_item(({"bank","sandy bank","shore","shoreline"}),
    "A sandy u-shaped bank that looks very inviting");
  add_item(({"forest","rainforest"}),
    "All around the pool and shore, dark forest grows tall");
  add_listen("main", 
    "Water splashes noisily as the waterfall meets the shallow pool.\n");
  add_listen("forest", 
    "You hear the noise of a living forest.\n");
  set_light(1);
  no_exit_display = 1;
  add_exit(ROOT+"rms/paradise04.c","shore");
  add_exit_msg("shore", "You wade out of the pool and onto the sandy shore.\n",
                        "wades out of the pool towards the shore.\n");
}

short() { return GRN+"A "+HIG+"Trop"+NORM+GRN+"ical "+HIG+"Para"+NORM+GRN+"dise"+NORM; }

init() {
  ::init();
  add_action("cmd_pass","pass");
}

cmd_pass(string str) {
  object wetme;
  if(!str || (str != "water" && str != "waterfall" && 
    str != "through water" && str != "through waterfall")) { 
    notify_fail("Pass through what?\n"); 
      return 0; 
  }
  write("You walk into the waterfall and out the other side - SOAKED!\n");
  say(this_player()->query_name()+" walks into the falling water.\n");
  move_object(this_player(),ROOT+"rms/paradise02.c");
  command("look",this_player());
  say(this_player()->query_name()+" emerges from the waterfall.\n");
  if(!present("waterfall_wet_object",this_player())) {
    wetme = clone_object(ROOT+"obj/allwet.c"); 
    move_object(wetme,this_player());
  }
  else { 
    destruct(present("waterfall_wet_object",this_player()));
    wetme = clone_object(ROOT+"obj/allwet.c"); 
    move_object(wetme,this_player());
  }
    return 1; 
}

