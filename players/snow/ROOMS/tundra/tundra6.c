inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="The arctic tundra";
 long_desc=
 "You are walking through the bleak arctic tundra. Occasionally you see or\n\
sense movements out the corner of your eyes but when you turn, nothing\n\
is to be seen. You feel very small and alone in this wide expanse of snow,\n\
ice, and grey rock. A huge glacier wraps around to your north, west, and\n\
east but there seems to be some sort of cave in the west glacier wall.\n";
 
items=({
 "snow", "Hard greyish-white snow",
 "ice","Deadish-grey ice",
 "rock","Grey rock with occasional blooms of lichen",
 "lichen","A tough rust-red growth on the rock",
 "glacier","A huge expanse of ice. You are not skilled enough to climb it yet",
 "cave","A dark cave. You feel as though something huge lives inside",
            });
 
  dest_dir=({
 "/players/snow/ROOMS/tundra/tundra4.c","south",
 "/players/snow/ROOMS/tundra/tundra_lair.c","cave",
      });
  }   }
 
