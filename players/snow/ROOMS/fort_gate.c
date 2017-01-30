inherit "room/room";
 
reset(arg){
 
if(!present("structure"))  {
move_object(clone_object("/players/snow/MONSTERS/iceoct.c"),this_object());  }
 
 if(!arg){
 
 set_light(1);
  short_desc="The Ice Fortress entrance";
 long_desc=
 "You see before you the great gates of Snow's Ice fortress. As always, the\n\
gates are flung wide open to visitors foolish enough to brave the great\n\
mountain and its secrets.\n";
 
items=({
 "gates",
"Huge gates made of blue-grey ice. It would take a battering ram several\n"+
"days to make any sort of progress with one of these goliaths. You are lucky\n"+
"they are open",
 "fortress","A huge shimmering fortress seemingly made of living ice crystals",
          });
 
  dest_dir=({
  "/players/snow/ROOMS/fort_hall.c","fortress",
 "/players/snow/ROOMS/path3.c","down",
      });
  }   }
 
 
