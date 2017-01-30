inherit "room/room";
 
reset(arg) {
  if(!present("keeper"))
    move_object(clone_object("/players/trix/castle/town/monst/keeper"),this_object());
  if(!present("assistant"))
    move_object(clone_object("/players/trix/castle/town/monst/assistant"),this_object());
  if(arg) return;
  set_light(1);
  long_desc = 
"  This is Trixtown drugstore, a generic shop in which are sold all kinds of\n"+
"stuff.  There's a lot of dust on the floor that makes you think people don't\n"+
"come here very often.\n";
  short_desc = "Trixtown drugstore";
  dest_dir = ({ "/players/trix/castle/town/1str1n.c","west"});
}
