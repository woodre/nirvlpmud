inherit "room/room";
 
reset(arg){
 
if(!present("arctic wolf 2"))  {
move_object(clone_object("/players/snow/MONSTERS/arctic_wolf"),this_object());  }
if(!present("arctic wolf 4")) {
move_object(clone_object("/players/snow/MONSTERS/arctic_wolf"),this_object()); }
 
 if(!arg){
 
 set_light(1);
  short_desc="Coastal tundra";
 long_desc=
"Rolling, wild, windswept hills define this bleak area. The arctic tundra\n"+
"appears to be a harsh land.\n";
 
items=({
 "sun", "The sun is bright but doesn't seem to warm you much",
 "hills","Wind whips through the small crests and valleys of these mounds of earth",
 "wind","A fierce wind blowing toward the beach",
  });
 
  dest_dir=({
  "/players/snow/beach/beach1","west",
  "/players/snow/beach/tundra2","north",
});
  }   }
