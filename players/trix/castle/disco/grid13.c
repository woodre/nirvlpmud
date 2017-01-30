inherit "room/room";
reset(arg) {
  if(!present("dj"))
    move_object(clone_object("/players/trix/castle/dismonst/dj.c"),this_object());
    if(arg) return;
    set_light(1);
   long_desc=
"  This is the room where the DJ works for you.  You can see records\n"+
"everywhere and all kinds of sophisticated instruments.  You wonder if\n"+
"the DJ is a machine too.\n";
    short_desc = "EclYpsE";
    dest_dir = ({ "/players/trix/castle/disco/grid8.c","north",
                  "/players/trix/castle/disco/grid18.c","south"});
}
