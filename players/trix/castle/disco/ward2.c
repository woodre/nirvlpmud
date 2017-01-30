inherit "room/room";
 
reset(arg) {
  if(!present("wardrober"))
    move_object(clone_object("/players/trix/castle/dismonst/wardrober.c"),this_object());
    if(arg) return;
    set_light(1);
   long_desc=
"  This is the wardrobe.  There are coats, jackets, and overcoats everywhere\n"+
"around you and you imagine there're a lot of people in the disco.  The\n"+
"temptation to get into the groove is great.\n";
   short_desc = "A wardrobe";
    dest_dir = ({ "/players/trix/castle/disco/hall3.c","east"});
}
