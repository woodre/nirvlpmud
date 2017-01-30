inherit "room/room";
 
reset(arg) {
  object barber;
  if(!present("barber"))
    move_object(clone_object("/players/trix/castle/town/monst/barber.c"),this_object());
  if(arg) return;
  set_light(1);
  long_desc = 
"  You are in the Trixtown barber's shop, a tidy and shining shop filled with\n"+
"every sort of lotion.  You can smell an agreeable perfume in the air.\n";
  short_desc = "Trixtown barber's";
  dest_dir = ({ "/players/trix/castle/town/1str1n.c","east"});
}

