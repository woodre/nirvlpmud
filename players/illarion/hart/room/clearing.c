#include "/players/illarion/dfns.h"
inherit "/players/illarion/room";
#define BOAT HARTROOM+"boat.c"

status boat_here;

void reset(status arg) {
  if(arg) return;
  
  set_light(1);
  boat_here=1;
  
  set_short("A moonlit forest clearing");
  set_long(
"A wide, perflectly oval clearing interrupts the forest here.  The eastern "+
"half of the clearing is covered by thick, soft grass, and the western half "+
"by still, shining water.  A tiny creek runs from the pond through the "+
"grassy part of the clearing, filling the air with the sound of water over "+
"rocks.  Just beside the creek, a tiny dock extends out over the pond.  "+
"A thin path of beaten dirt follows the creek from the dock out of the "+
"clearing.  The whole clearing is bathed in impossibly bright moonlight "+
"out of the perfectly clear, starry sky above.  $&boat_string$&");

  add_item("forest","A thick mass of trees and undergrowth that ends in "+
                    "an almost abrubt line at the edge of the clearing.");
  add_item("grass","Thick, soft, grass, that's almost a carpet over the "+
                   "ground.");
  add_item("clearing","The break in the forest you are currently in.");
  add_item("pond","A small but seemingly deep body of water that covers "+
                  "the western half of the clearing.  The moonlight is "+
                  "bright enough to show that despite the overhanging "+
                  "branches the water is clear and clean.");
  add_item("creek","Barely more than a trickle of water across the clearing,"+
                   " with a soft but cheerful sound.");
  add_item("water","The water in both the pond and the creek looks clear, "+
                   "but cold.");
  add_item("dock","Little more than a few boards that extend out over the "+
                  "water, the dock is clearly intended as a very small "+
                  "craft.");
  add_item("path","A narrow but well-maintained dirt path between the dock "+
                  "and the forest.");
  add_item("boat","$&boat_desc$&");
  add_item("sky","The perfectly clear sky overhead allows the light from "+
                 "the countless twinkling stars and full moon to flood "+
                 "the clearing, far brighter than should be possible.");
  
  set_etime_const(120);
  set_etime_rand(60);
  add_room_emote("A light breeze makes ripples in the pond and grass.");
  add_room_emote("A tiny light dances across your field of vision, "+
                 "immediately followed by a delicate tinkle of laughter.");
  add_room_emote("An owl hoots somewhere in the forest.");
  add_room_emote("The moonlight glimmers off the pond.");
  add_room_emote("The pond laps gently at its banks.");
}

string boat_string() {
  if(boat_here)
    return "A small boat floats beside the dock.";
  else
    return "A small boat floats out near the center of the pond.";
}

string boat_desc() {
  if(boat_here)
    return "Floating beside the dock is a two-person wooden boat.  The "+
           "bow and stern are built up around a comfortable looking "+
           "seat nestled in each.  Oddly, there is no sign of any "+
           "paddles.  It is possible to \"board\" the boat.";
  else
    return "A smallish boat floats out in the pond, too far away for you "+
           "to make out any details.";
}

void set_boat_here(status x) {
  boat_here=x;
}

void init() {
  ::init();
  add_action("cmd_board","board");
}

status cmd_board(string str) {
  if(!str || str != "boat")
    FAIL("Board what?\n");
  if(!boat_here)
    FAIL("It's much too far away.\n");
  write("You step on board the boat.\n");
  TP->move_player("onto the boat#"+BOAT);
  return 1;
}
