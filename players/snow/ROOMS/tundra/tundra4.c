inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="The arctic tundra";
 long_desc=
 "You are walking through the bleak arctic tundra. Occasionally you see or\n\
sense movements out the corner of your eyes but when you turn, nothing\n\
is to be seen. You feel very small and alone in this wide expanse of snow,\n\
ice, and grey rock.\n";
 
items=({
 "snow", "Hard greyish-white snow",
 "ice","Deadish-grey ice",
 "rock","Grey rock with occasional blooms of lichen",
 "lichen","A tough rust-red growth on the rock",
            });
 
  dest_dir=({
  "/players/snow/ROOMS/tundra/tundra1.c","south",
 "/players/snow/ROOMS/tundra/tundra5.c","east",
 "/players/snow/ROOMS/tundra/tundra7.c","west",
 "/players/snow/ROOMS/tundra/tundra6.c","north",
      });
  }   }
 
