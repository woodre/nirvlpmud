inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Drow Fighter School";
  long_desc = "This room is filled with all kinds of stuff.  The walls are filled with\n"+
              "all kinds of different weapons and armor.  There are pictures of the best\n"+
              "drow fighters that have graduated from this school and probally moved up\n"+
              "to become weapon masters of a house.  The floor is stained with blood.\n"+
              "This is no ordinary school.  You MUST learn to fight or die.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under28","east",
               });
           }
if(!present("trainer"))
move_object(clone_object("/players/mouzar/castle/under/mon/tdrow"),this_object());
} 
