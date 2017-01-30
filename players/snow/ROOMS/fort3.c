inherit "room/room";
 
reset(arg){

  if(!present("knight"))
    move_object(clone_object("/players/snow/cam/mon/indigo"), this_object()); 

 if(!arg){
 
 set_light(1);
  short_desc="North Wing";
 long_desc=
 "This is the north wing of the great fortress. Carvings in the walls shift\n\
continously between seemingly random images in the living crystals of ice.\n\
There is a stairway here leading up to the top of one of the many fortress\n\
towers. The clear, cool breeze blowing through the room seemingly\n\
originates from the top of the tower. As you look around the stairway\n\
you can see a smaller staircase down.\n";
 
items=({
 "carvings", "Images of a great white dragon and sunlight reflecting from \n" +
                   "a mountain summit and shimmering fortress",
 "stairway","Smooth steps curl up the tower to the top",
 "tower","One of the many towers in this ice fortress"
          });
 
  dest_dir=({
  "/players/snow/ROOMS/fortport3.c","up",
 "/players/snow/ROOMS/fort_hall.c","south",
 "/players/snow/ROOMS/fort4.c","down",
      });
  }   }
 
 
init()  {
 ::init();
  add_action("smell_wind","smell");
        }
 
smell_wind() {
  write("The cool breeze clears your head and brings harmony to your \n" +
           "thoughts.\n");
  say (this_player()->query_name() +"breaths in the cool breeze and smiles. \n");
  return 1;  }
 
