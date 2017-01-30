inherit "players/earwax/housing/land";
#include "/players/illarion/dfns.h"

void reset(status arg) {
  set_cost(5000000);
  set_realm_name("The Mountain Meadow");
  set_lot_size("3");

  ::reset(arg);
  if(arg) return;

  set_light(1);
  short_desc=("A moonlit mountain meadow");
  long_desc=("Perched here partway up the mountain slope is a small but "+
           "beautiful meadow.  White rocks washed even whiter by moonlight "+
           "poke up here and there through a carpet of green grass.  Above "+
           "the meadow to the north the mountain slopes up again into "+
           "stark, rocky slopes, with a rare pocket of trees, finally ending "+
           "against the starry night sky.  To the south, the bright moon "+
           "illuminates a wide forest cut through by a river.  A small "+
           "footpath cuts through the meadow, from north to south.");
  items=({"meadow","You're there now.",
  "rocks","Weathered white rocks that poke up out of the grass "+
                   "of the meadow.  While most tend toward being tall and "+
                   "thin, a few are suitable for sitting on.",
  "grass","The grass is as thick and soft as a carpet, completely "+
                   "covering the meadow except for the rocks and footpath.",
  "slopes","The rocky slopes above you are much less welcoming "+
                    "than the meadow, but have their own beauty, especially "+
                    "washed even whiter by the moonlight.",
  "trees","The trees on the upper slopes are only visible as "+
                   "darker patches against the rocky slops of the mountain.",
  "sky","High and mostly clear, the sky is filled with stars "+
                 "that shine very bright and clear despite the full moon.  "+
                 "Every so often, a shooting star streaks overhead.",
  "moon","Even for a full moon, it seems impossibly bright and "+
                  "bright and large, lighting the meadow almost as well as "+
                  "sunlight would, though far more softly.",
  "forest","A wide, dark mass of trees, whose scent is just "+
                    "barely perceptible at this height.",
  "footpath","A simple path of foot-beaten dirt that winds "+
                      "through the meadow from north to south.",
  "river","A ribbon of faintly reflected moonlight winding through "+
                   "the forest.",
                 });
/*  
  set_etime_const(90);
  set_etime_rand(60);
  add_room_emote("A cool breeze wafts across the meadow.");
  add_room_emote("A cloud dims the moonlight briefly, but swiftly passes.");
  add_room_emote("An owl's hoot can be faintly heard on the wind.");
  add_room_emote("A shooting star draws a blazing path across the sky.");
  add_exit("south",HARTROOM+"mpath");
*/
}
