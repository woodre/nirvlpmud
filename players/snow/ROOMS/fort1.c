inherit "room/room";
 
reset(arg){

  if(!present("knight"))
    move_object(clone_object("/players/snow/cam/mon/green"), this_object()); 

 if(!arg){
 
 set_light(1);
  short_desc="East Wing";
 long_desc=
 "This is the east wing of the great fortress. Carvings in the walls shift \n\
continously between seemingly random images in the living crystals of ice.\n\
There is a stairway here leading up to the top of one of the many fortress\n\
towers. You feel a chill wind incongruously mixed with a sulpherous smell\n\
sweeping down the stairway toward you.\n";
items=({
 "carvings", "Images of volcanoes, demons, and giant marine monsters \n" +
                   "meld on and off the ice",
 "stairway","Smooth steps curl up the tower to the top",
 "tower","One of the many towers in this ice fortress"
          });
 
  dest_dir=({
  "/players/snow/ROOMS/fortport1.c","up",
 "/players/snow/ROOMS/fort_hall.c","west",
      });
  }   }
 
 
init()  {
 ::init();
  add_action("smell_wind","smell");
        }
 
smell_wind() {
  write("A foul-smelling wind brings scents of ash and sulpher assaulting \n"+
       "your nostrils.\n");
  say (this_player()->query_name() +"smells the foul wind polluting the room \n");
  return 1;  }
 
