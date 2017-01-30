inherit "room/room";
 
reset(arg) {
  if(!present("president"))
    move_object(clone_object("/players/trix/castle/town/monst/president.c"),this_object());
  if(arg) return;
  set_light(1);
  long_desc = 
"  You're in the central part of Trixtown Bank.  There are exits to the west\n"+
"and to the east.\n";
  short_desc = "Trixtown Bank";
  dest_dir = ({ "/players/trix/castle/town/bank1.c","west",
                  "/players/trix/castle/town/bank3.c","east"});
}

