inherit "players/illarion/room";
#include "/players/illarion/dfns.h"
void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_short("The end of an alley");
  set_long("An alleyway between two buildings comes to a blind end at "+
           "another building.  Strewn all around are boxes and other trash, "+
           "including an old, apparently abandoned dumpster.  Faceless, "+
           "dark buildings surround the alleyway's broken pavement on all "+
           "sides but the north.");

  add_item("buildings","Faceless masses of stone and concrete, rising into "+
                       "the dark above your head.  There are no windows "+
                       "near the ground.");
  add_item("windows","There aren't any, pay attention.");
  add_item("boxes","Cardboard boxes, and wooden crates, perhaps the "+
                   "remnants of a business that used to operate here, "+
                   "but now smashed in and mixed with less savory trash.");
  add_item("trash","You really don't want to know.");
  add_item("pavement","The remnants of an asphault paving job, now so "+
                      "ruined and broken it looks like the place was mined.");
  add_item("dumpster","An old metal dumpster, with the lids missing. "+
                      "Despite all the other trash on the ground, though, "+
                      "the dumpster doesn't seem to be full, leading you "+
                      "to wonder what you'd find if you "+BLD("check")+
                      "ed it.");
                      
  add_exit("north",HROOM2+"alley");
  
}
void init() {
  ::init();
  add_action("cmd_check","check");
}
int cmd_check(string str) {
  if(!str || str != "dumpster") FAIL("Check what?\n");
  write("You look down into the dumpster and discover a fresh, horrifying\n"+
        "corpse with a gaping chest wound and the head severed and a foot\n"+
        "away from the neck!  You look away in disgust at such savagery.\n");
  say(TPN+" looks into the dumpster, and quickly looks away.\n");
  return 1;
}
