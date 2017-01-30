inherit "room/room";
 
reset(arg) {
    while(!present("clerk 7"))
      move_object(clone_object("/players/trix/castle/town/monst/clerk"),this_object());
    if(arg) return;
    set_light(1);
    long_desc = 
"  You're in the western part of Trixtown Bank.  You can see Trixtown 1st\n"+
"street to the north, while there are other rooms to the east.\n";
    short_desc = "Trixtown Bank";
    dest_dir = ({ "/players/trix/castle/town/1str1s.c","north",
                  "/players/trix/castle/town/bank2.c","east"});
}
