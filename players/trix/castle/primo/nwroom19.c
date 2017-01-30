inherit "room/room";
 
reset(arg) {
  if(!present("priest"))
    move_object(clone_object("/players/trix/castle/primonst/priest.c"),this_object());
    if(arg) return;
    set_light(1);
  long_desc=
"  This is the western service room.  It's where priests put their\n"+
"habits and ceremonial items.  You can see that the walls are badly\n"+
"painted and everything smells like mould.\n";
"and everything smells like mould.\n";
   short_desc = "A room";
    dest_dir = ({ "/players/trix/castle/primo/laisle11.c", "east"});
}
