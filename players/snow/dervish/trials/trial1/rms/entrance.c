/* 
 * Forbin
 * Created:   2003.08.25
 * Last edit: 2003.09.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"
#define FIXED_MOSS 6
#define RANDOM_MOSS 8

int done;

reset(arg) {
  if(arg) return;
  short_desc = HIR+"A "+HIY+"S"+HIG+"t"+HIB+"r"+HIC+"a"+HIM+"n"+HIW+"g"+HIM+"e "+HIC+"P"+HIB+"l"+HIG+"a"+HIY+"c"+HIR+"e"+NORM;
  long_desc = "  Blackness envelopes almost everything, cold embraces your soul and\n"+  
              "here in this featureless void, darkness reigns.  A pinpoint of light\n"+
              "marks the way back out, and a purple haze boils forth from a cavernous\n"+
              "dark hole that swallows the ground.\n";
  add_item(({"light","pinpoint","pinpoint of light"}),
             "A pinpoint of light shines off in the distance, it is the way out");
  add_item(({"haze","purple haze","mist"}),"A purple mist floats about low to the ground");
  add_item("ground","A purple mist spews forth from a large hole in the ground");
  add_item("hole","A large gaping hole - it looks as if you could descend into it");
  add_listen("main", "You listen closely and hear your heart pounding.\n");
  set_chance(random(5));
    add_msg(HIM+"Purple mist rises up from out of the hole."+NORM);
  add_exit("/players/snow/dervish/hall/desert6.c","out");
  done = 0;
}

short() { return HIR+"A "+HIY+"S"+HIG+"t"+HIB+"r"+HIC+"a"+HIM+"n"+HIW+"g"+HIM+"e "+HIC+"P"+HIB+"l"+HIG+"a"+HIY+"c"+HIR+"e"+NORM; }

init() {
  ::init();
  add_action("cmd_descend","descend");
}

cmd_descend() {
  if(!done) initialize_moss();
  write("You gather your fortitude and descend into the hole.\n");
  say(this_player()->query_name()+" descends into a hole in the ground.\n");
  move_object(this_player(),ROOT+"rms/cave.c");
  command("look",this_player());
  say(this_player()->query_name()+" falls out a hole in the ceiling.\n");
    return 1; 
}

initialize_moss() {
  int mossnum;
  int x;
  mossnum = FIXED_MOSS + RANDOM_MOSS;
  for(x = 0; x < mossnum; x++) {
    int y;
    y = 1+random(6);
    if(x <= FIXED_MOSS) {
      if((int)ROOT+"rms/canopy0"+y+".c"->query_moss_fixed()) { 
        ROOT+"rms/canopy0"+y+".c"->set_moss_fixed(1);
      }
      else ROOT+"rms/canopy0"+y+".c"->add_moss_fixed(1);
    }
    if(x > FIXED_MOSS) {
      if((int)ROOT+"rms/canopy0"+y+".c"->query_moss_random()) { 
        ROOT+"rms/canopy0"+y+".c"->set_moss_random(1);
      }
      else ROOT+"rms/canopy0"+y+".c"->add_moss_random(1);
    }
  }
  done = 1;
}
