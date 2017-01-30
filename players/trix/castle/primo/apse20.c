inherit "room/room";
 
reset(arg) {
  if(!present("sacristan"))
    move_object(clone_object("/players/trix/castle/primonst/sacristan.c"),this_object());
    if(arg) return;
    set_light(1);
   long_desc=
"  You are in the apse of the cathedral.  From here you can see the\n"+
"back part of the altar.  A strange and oblique light reaches you\n"+
"through the narrow windows just under the high ceiling.\n";
   short_desc = "The apse";
    dest_dir = ({ "/players/trix/castle/primo/laisle11.c", "southwest",
                  "/players/trix/castle/primo/raisle16.c", "southeast"});
}
