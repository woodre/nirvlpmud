inherit "room/room";
 
reset(arg) {
  if(!present("player"))
    move_object(clone_object("/players/trix/castle/primonst/orgplayer.c"),this_object());
    if(arg) return;
    set_light(1);
    long_desc=
"  You're in a small room with a high ceiling.  As soon as you walk\n"+
"in you see an imposing metallic organ that stands next to the eastern\n"+
"wall and almost reaches the ceiling.  You imagine the mighty sound\n"+
"that could come out of it.\n";
    short_desc = "The organ room";
    dest_dir = ({ "/players/trix/castle/primo/raisle12.c", "west"});

}
