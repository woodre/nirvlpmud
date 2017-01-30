inherit "room/room";
 
reset(arg){
 
if(!present("arctic seal 2"))  {
move_object(clone_object("/players/snow/MONSTERS/arctic_seal"),this_object());  }
if(!present("seal pup 5")) {
move_object(clone_object("/players/snow/MONSTERS/seal_pup"),this_object());
move_object(clone_object("/players/snow/MONSTERS/seal_pup"),this_object());
move_object(clone_object("/players/snow/MONSTERS/seal_pup"),this_object());
move_object(clone_object("/players/snow/MONSTERS/seal_pup"),this_object()); }

if(!present("knight"))
  move_object(clone_object("/players/snow/cam/mon/white"), this_object());

 if(!arg){
 
 set_light(1);
  short_desc="An arctic beach";
 long_desc=
 "Bright sun shines off sparkling rocks and snow. The surf periodically smashes\n"+
"close to where you stand.\n";
 
items=({
 "sun", "The sun is bright but doesn't seem to warm you much",
 "rocks","Jagged rocks beaten by the surf",
 "surf","Waves crash upon the shore",
  });
 
  dest_dir=({
  "/players/snow/beach/surf2","surf",
  "/players/snow/beach/beach1","south",
  "/players/snow/beach/tundra2","east",
});
  }   }
 
