inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Wizard Tower";
  long_desc = "This tower is very gloomy.  It is hard to make out things that are\n"+
              "on the various shelves.  There are books, potions, and spell components.\n"+
              "As you look closer you can see some of the components are still moving.\n"+
              "There are some gross looking creatures locked up in cages.  Probally some\n"+
              "experment gone wrong.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under26","west",
               });
           }
if(!present("drow"))
move_object(clone_object("/players/mouzar/castle/under/mon/wdrow"),this_object());
} 
