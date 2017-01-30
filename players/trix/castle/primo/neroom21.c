inherit "room/room";
 
reset(arg) {
  if(!present("priest"))
    move_object(clone_object("/players/trix/castle/primonst/priest.c"),this_object());
    if(arg) return;
    set_light(1);
  long_desc=
"  This is the eastern service room.  You can see a lot of untidily\n"+
"heaped up stuff.  There's dust everywhere and spiderwebs cover the\n"+
"corners and most of the furniture in the room.\n";
   short_desc = "A room";
    dest_dir = ({ "/players/trix/castle/primo/raisle16.c", "west"});
}
