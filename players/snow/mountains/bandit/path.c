inherit "room/room";
 
reset(arg){ 
 if(!arg){
 
 set_light(1);
  short_desc="A twisty path";
 long_desc=
 "The path you are traversing lies between two cliffs and winds with\n\
the convoluting flow of the mountains.\n";
 
items=({
 "cliffs", "Unscaleable cliffs rise steeply on both sides of the path",
 "mountains","Huge mountains rise all around you",
});
 
  dest_dir=({
  "/players/snow/mountains/bandit/entrance.c","west",
  "/players/snow/ROOMS/path2","east",
});
  }   }
 
