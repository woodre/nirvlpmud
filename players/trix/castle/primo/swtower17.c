inherit "room/room";
 
reset(arg) {
   if(!present("ringer"))
     move_object(clone_object("/players/trix/castle/primonst/ringer.c"),this_object());
    if(arg) return;
    set_light(1);
    long_desc=
"  This is the base of the bell tower.  A long rope hangs from the\n"+
"darkness that reigns in the upper tower.  The walls are circular and\n"+
"You can see there aren't any other exits besides the one you used to\n"+
"get here.\n";
    short_desc = "The base of a bell tower";
    dest_dir = ({ "/players/trix/castle/primo/laisle7.c", "east"});

}
