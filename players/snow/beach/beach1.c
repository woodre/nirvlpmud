inherit "room/room";
 
reset(arg){
 
if(!present("arctic seal 3"))  {
move_object(clone_object("/players/snow/MONSTERS/arctic_seal"),this_object());
move_object(clone_object("/players/snow/MONSTERS/arctic_seal"),this_object());
move_object(clone_object("/players/snow/MONSTERS/arctic_seal"),this_object());  }
 
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
  "/players/snow/beach/surf1","surf",
  "/players/snow/beach/beach2","north",
  "/players/snow/beach/tundra1","east",
  "/players/snow/gate.c","vortex",
});
  }   }
 
