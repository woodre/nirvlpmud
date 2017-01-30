inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="The arctic tundra";
 long_desc=
 "You are in a valley, enclosed by glacier on all sides but one. To the north\n\
seems to lie the bleak arctic tundra. Occasionally you see or sense\n\
movements out of the very corner of your eyes but when you turn, nothing\n\
is to be seen. You feel very small and alone in this wide expanse of snow,\n\
ice, and grey rock. There is a blue portal floating here.\n";
 
items=({
 "snow", "Hard greyish-white snow",
 "ice","Deadish-grey ice",
 "rock","Grey rock with occasional blooms of lichen",
 "lichen","A tough rust-red growth on the rock",
 "portal","A glowing blue portal. You see a circular room with no windows on " +
             "the other side",
 "glacier","A huge glacier of ice. You are not skilled enough to climb it yet.",
            });
 
  dest_dir=({
  "/players/snow/ROOMS/tundra/tundra1.c","north",
 "/players/snow/ROOMS/fortport2.c","portal",
      });
  }   }
 
 
