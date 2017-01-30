inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(status arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A secluded mountain pool");
  set_long("You are within a small fold, almost a gouge, in the generally "+
           "uniform, wooded slope of the mountain.  The eastern end of the fold "+
           "is a bank of almost solid rock, with a small stream of water "+
           "flowing out from near the top and washing down the rocks into a small "+
           "pool below, and finally down the mountain to the south.  A "+
           "small path ends at the edge of the pool, at "+
           "what appears to be a set of rock steps, and leads back into the "+
           "trees to the west.  A full moon almost "+
           "directly overhead makes the stream of water look almost like "+
           "tumbling jewels, and also illuminates what appears to be mist "+
           "or steam hanging above the pool.");
  
  add_item("mountain","Yes, you're on a mountain slope.");
  add_item("fold","That's where you are now.");
  add_item("bank","A miniature cliff of white rock, with a small stream of "+
                  "water spilling down it.");
  add_item("rock","White rock, washed even whiter by the moonlight.");
  add_item("water","Clear, pure water.");
  add_item("stream","A cheerfully bubbling stream of water out of the rocks "+
                    "above, and down the mountain to the south.");
  add_item("mist","Faint water vapor caused by the cool mountain air trying to "+
                  "draw the heat out of the pool.");
  add_item("steam","Faint water vapor caused by the cool mountain air trying to "+
                  "draw the heat out of the pool.");
  add_item("pool","A small but fairly deep pool, shaped suspicously like a small "+
                  "hot tub.  Though the water pouring into it from above is cool, "+
                  "the pool itself seems warm, probably from a hot spring below.");
  add_item("steps","A set of rock steps someone has built to make getting in and "+
                   "out of the pool easier.");
  add_item("moon","An unusually large and bright full moon floods the pool and "+
                  "surrounding rocks with silver-white light.");
  add_item("trees","Trees surround the pool, giving it a private feel.");
  
  set_etime_const(90);
  set_etime_rand(60);
  add_room_emote("The stream of water bubbles cheerfully.");
  add_room_emote("A wisp of steam rises from the pool.");
  add_room_emote("It seems unusually warm and humid here...");
  add_room_emote("A breeze whispers through the trees above.");
  
  add_exit("west",HARTROOM+"mpath");
}
