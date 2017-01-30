inherit "room/room";
 
reset(arg){

  if(!present("knight"))
    move_object(clone_object("/players/snow/cam/mon/violet"), this_object()); 

 if(!arg){
 
 set_light(1);
  short_desc="The arctic tundra";
 long_desc=
 "You are walking through the bleak arctic tundra. Occasionally you see or\n\
sense movements out the corner of your eyes but when you turn, nothing\n\
is to be seen. You feel very small and alone in this wide expanse of snow,\n\
ice, and grey rock. What seems to be an unscaleable glacier lies to the east.\n";
 
items=({
 "snow", "Hard greyish-white snow",
 "ice","Deadish-grey ice",
 "rock","Grey rock with occasional blooms of lichen",
 "lichen","A tough rust-red growth on the rock",
 "glacier","A huge expanse of ice. You are not skilled enough to climb it yet"
            });
 
  dest_dir=({
  "/players/snow/ROOMS/tundra/tundra2.c","south",
 "/players/snow/ROOMS/tundra/tundra4.c","west",
 "/players/snow/ROOMS/tundra/tundra_ice.c","north",
      });
  }   }
 
