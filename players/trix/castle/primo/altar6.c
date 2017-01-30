inherit "room/room";
 
reset(arg) {
  if(!present("bishop"))
    move_object(clone_object("/players/trix/castle/primonst/bishop.c"),this_object());
    if(arg) return;
    set_light(1);
  long_desc=
"  You're on top of the huge altar of the cathedral.  Everything\n"+
"around you is made with gold or silver.  In front of you is placed an\n"+
"ancient and elegant tabernacle made of gold and adorned with gems.\n"+
"Above you, you notice a great cross hanging from the high ceiling.\n"+
"There are stairs going down to the floor to the east and to the west.\n";
    short_desc = "A huge altar";
   dest_dir = ({ "/players/trix/castle/primo/laisle11.c","west",
                 "/players/trix/castle/primo/raisle16.c","east"});
   items = ({ "cross", "A giant cross on which Jesus' eyes seem to follow every little movement of yours",
              "tabernacle", "A golden and very precious tabernacle , it is closed to unholy people , though" });
}
