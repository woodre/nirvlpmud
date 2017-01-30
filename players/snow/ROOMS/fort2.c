inherit "room/room";
 
reset(arg){
 
  if(!present("knight"))
    move_object(clone_object("/players/snow/cam/mon/blue"), this_object()); 

 if(!arg){
 
 set_light(1);
  short_desc="West Wing";
 long_desc=
 "This is the west wing of the great fortress. Carvings in the walls shift\n\
continously between seemingly random images in the living crystals of ice.\n\
There is a stairway here leading up to the top of one of the many fortress\n\
towers. The crisp arctic wind blowing through the room strangely seems to\n\
be coming from the top of the tower, down the stairway toward you.\n";
 
items=({
 "carvings", "Images of great white bears and brilliant, snow-covered \n" +
                   "tundra meld on and off the ice",
 "stairway","Smooth steps curl up the tower to the top",
 "tower","One of the many towers in this ice fortress"
          });
 
  dest_dir=({
  "/players/snow/ROOMS/fortport2.c","up",
 "/players/snow/ROOMS/fort_hall.c","east",
      });
  }   }
 
 
init()  {
 ::init();
  add_action("smell_wind","smell");
        }
 
smell_wind() {
  write("A crisp, clear wind brings you no recognizable scents.\n");
  say (this_player()->query_name() +"sniffs the clean air. \n");
  return 1;  }
