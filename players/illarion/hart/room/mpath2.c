inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

object waypine;

void reset(status arg) {
  if(!waypine) {
    waypine=clone_object(HARTROOM+"waypine");
    waypine->add_exit("out",HARTROOM+"mpath2");
  }
  if(arg) return;
  
  
  set_light(1);
  set_short("A moonlight mountain trail");
  set_long("A trail of beaten earth climbs up and along the slope of the "+
           "mountain, winding between trees and rocks.  Unusually bright "+
           "light from the moon overhead illuminates the path well enough "+
           "for it to be safe, though some sections are almost entirely in "+
           "shifting shadows cast by breeze-caught trees.  "+
           "The trail continues upward to the north, and down the slope to "+
           "the southwest.  An unusually large pine right beside the path "+
           "has fallen over and is growing almost horizontally.");
  
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
  add_item("pine","Also known as a wayward pine, a tree like this provides "+
                  "for travellers with no tents to shelter.  You should be "+
                  "able to "+BLD("enter")+" the pine.");
                    
  set_etime_const(90);
  set_etime_rand(60);
  add_room_emote("A faint breeze rustles leaves and makes the shadows move.");
  add_room_emote("Somewhere off in the forest, an owl hoots loudly.");
  add_room_emote("A cloud darkens the moon briefly, but passes swiftly.");
  
  add_exit("north",HARTROOM+"mpath");

}
void init() {
  ::init();
  add_action("cmd_enter","enter");
  add_action("cmd_collect","collect");
}
status cmd_enter(string str) {
  if(!str || str!="pine") FAIL("Enter what?\n");
  
  TP->move_player("into the pine#"+file_name(waypine));
  return 1;
} 
status cmd_collect(string str) {
  if(!str || (str!="wood" && str !="firewood")) FAIL("Collect what?\n");
  
  write(format("You look among the trees beside the path, and in no "+
               "time you have a small pile of firewood stacked up at "+
               "your feet."));
  say(TPN+" collects a small pile of firewood.");
  move_object(clone_object(HARTOBJ+"firewood"),this_object());
  return 1;
}
