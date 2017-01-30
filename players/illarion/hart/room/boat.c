/*   boat.c - a specialized room associated with clearing.c
 */

inherit "/players/illarion/room";
#include "/players/illarion/dfns.h"
#define CLEAR "/players/illarion/hart/room/clearing.c"


status at_dock;

void reset(status arg) {
  if(arg) return;
  
  set_light(1);
  at_dock=1;

  set_short("A small wooden boat");
  set_long(
"This smallish but ornate boat floats gently in the water of a small, "+
"half-circle shaped pond, surrounded by trees on the rounded side, and "+
"an open clearing to the east.  A large, comfortable-looking seat is "+
"built into both the bow and stern of the boat, with perhaps three paces "+
"distance between them.  There is no sign of paddles or any other way "+
"to move the boat, except a small note tacked to the deck.  "+
"$&location_string$&");
  add_item("boat","That's right, you're in a boat.  Mind you don't "+
                  "fall out.");
  add_item("seats","Each seat consists of a seat and back cushion, "+
                  "embroidered with a variety of water scenes, which "+
                  "despite their old-fashioned appearance reform themselves "+
                  "to cradle their occupants.");
  add_item("seat","Each seat consists of a seat and back cushion, "+
                  "embroidered with a variety of water scenes, which "+
                  "despite their old-fashioned appearance reform themselves "+
                  "to cradle their occupants.");
  add_item("bow","The bow of the boat is carved into the form of a mermaid, "+
                 "facing forward.");
  add_item("stern","The stern of the boat is carved in the shape of a "+
                   "large fish's tail, sticking up from the water.");
  add_item("note","A handwritten note in a strong, clear hand, that reads, "+
                  "\"To "+BLD("propel")+" the boat requires only a strong "+
                  "thought.  It will carry you into the pond, and back to "+
                  "the dock.\"\n");
  add_item("pond","The water shines in the moonlight, almost as brightly "+
                  "as the moon itself, and ripples ever so slightly under "+
                  "the influence of a gentle breeze.");
  add_item("shore","The pond seems to simply end at banks barely an inch "+
                   "above its surface, and on the sides facing the forest "+
                   "a maze of tree roots twists down into the water.");
  add_item("trees","Trees of all kinds overhang the pond around its more "+
                   "rounded side, casting their reflections into the clear "+
                   "water below.");
  add_item("water","The clear, cool water around the boat shines in the "+
                   "moonlight.");
  add_item("sky","A full moon and an impossibly thick dusting of stars "+
                 "fill the night sky overhead.");
  add_item("stars","Countless bright stars, twinkling and brighter than "+
                   "stars have any right to be.");
  add_item("moon","The full moon shines down on the clearing almost as "+
                  "brightly as the sun.");
  add_item("dock","A simple wooden dock extending out from the grassy "+
                  "part of the clearing.");
  add_item("clearing","The pond you are currently on makes up the western "+
                      "half of a forest clearing.");
  
  set_etime_const(120);
  set_etime_rand(60);
  add_room_emote("The boat bobs up and down gently.");
  add_room_emote("A light breeze skids across the pond.");
  add_room_emote("A fairy darts over the water, leaving a bright reflection "+
                 "and a faint wake.");
  add_room_emote("The moonlight glimmers off the pond.");
  
  
  add_exit("disembark",HARTROOM+"clearing");
}

string location_string() {
  if(at_dock)
    return "A small dock connecting to the clearing is an easy step from "+
           "the boat's deck.";
  else
    return "The boat drifts, seemingly of its own volition, in a gentle "+
           "circle around the center of the pond.";
}

void init() {
  ::init();
  add_action("cmd_propel","propel");
  add_action("disembark_hook","disembark");
}

status cmd_propel() {
  at_dock=!at_dock;
  CLEAR->set_boat_here(at_dock);
  write("You hear a soft chime inside your head.\n");
  if(at_dock) {
    tell_room(this_object(),
"The boat turns and heads back to shore, moving so smoothly you can\n"+
"barely feel it, but in no time the boat has bumped against the dock\n"+
"and is still.\n");
    tell_room(CLEAR,
"With a soft thump, the boat bumps into the dock and stays beside it.\n");
   } else {
     tell_room(this_object(),
"Though you feel next to no motion, and no sound but water against\n"+
"wood, the boat slowly turns under its own power, and moves out into the\n"+
"center of the pond.\n");
     tell_room(CLEAR,
"The boat drifts gently away from the dock and to the center of the\n"+
"pond, as if by magic.");
  }
  return 1;
}

status disembark_hook() {
  if(!at_dock) {
    write("You try to climb out of the boat into the water, but you find\n"+
          "your muscles simply refuse to obey that command.\n");
    return 1;
  }
  return 0;
}
