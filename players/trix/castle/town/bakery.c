inherit "room/room";
 
reset(arg) {
  if(!present("baker"))
    move_object(clone_object("/players/trix/castle/town/monst/baker"),this_object());

  if(arg) return;
  set_light(1);
  long_desc = 
"  This is the bakery of Trixtown, a nice and well lit shop full of every sort\n"+
"of bread.  The exit to Trixtown Main Road is to the north.\n";
  short_desc = "Trixtown bakery";
  dest_dir = ({ "/players/trix/castle/town/mainroad2.c","north"});
}
