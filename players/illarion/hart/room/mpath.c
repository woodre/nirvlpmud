inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(status arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A moonlight mountain trail");
  set_long("A trail of beaten earth climbs up and along the slope of the "+
           "mountain, winding between trees and rocks.  Unusually bright "+
           "light from the moon overhead illuminates the path well enough "+
           "for it to be safe, though some sections are almost entirely in "+
           "shifting shadows cast by breeze-caught trees.  "+
           "The trail continues upward to the north, where the overhanging "+
           "trees seem to thin, and down "+
           "the mountain slope to the south, and an almost unnoticable side-trail "+
           "branches off to the east.");
  
  add_item("trail","Packed earth and the occasional well-placed rock to keep "+
                   "it from washing away.");
  add_item("mountain","You are on the slope of a large mountain, which is "+
                      "heavily wooded in this area.");
  add_item("trees","Trees of nearly all sizes and kinds, eerily beautiful "+
                   "in the moonlight.");
  add_item("rocks","This mountain appears to be made almost exclusively of "+
                   "some kind of white rock, that the moonlight makes even "+
                   "whiter.");
  add_item("moon","Even for a full moon, it seems unusually large and "+
                  "bright, casting almost as much light as a summer sun, "+
                  "though not nearly as much warmth.");
  add_item("side-trail","A faint, almost invisible trail that leads into a "+
                        "small fold in the mountain's slope to the east.");
  
  set_etime_const(90);
  set_etime_rand(60);
  add_room_emote("A faint breeze rustles leaves and makes the shadows move.");
  add_room_emote("The sound of moving water drifts on a breeze from the east.");
  add_room_emote("Somewhere off in the forest, an owl hoots loudly.");
  add_room_emote("A cloud darkens the moon briefly, but passes swiftly.");
  
  add_exit("north",HARTROOM+"meadow");
  add_exit("east",HARTROOM+"mspring");
  add_exit("south",HARTROOM+"mpath2");
}
