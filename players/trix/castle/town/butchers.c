inherit "room/room";
 
reset(arg) {
  if(!present("butcher"))
    move_object(clone_object("/players/trix/castle/town/monst/butcher.c"),this_object());
  if(arg) return;
  set_light(1);
  long_desc = 
"  You are in the Trixtown butcher's shop.  There are bloodstains everywhere\n"+
"and pieces of meat spread all around the room.  You see 2nd street to the\n"+ 
"east.\n";
  short_desc = "Trixtown butcher's";
  dest_dir = ({ "/players/trix/castle/town/2str1n.c","east"});
}
