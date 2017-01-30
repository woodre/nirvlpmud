#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("monolith")) {
  move_object(clone_object("/players/francesco/2001/items/monolith.c"),
	this_object());  }

set_light(1);

short_desc = "African Drylands" ;
long_desc =
     "   AFRICA,  3,000,000 YEARS AGO\n"+
     "On the border of a dry african plain.  Some bushes are scattered about\n"+
     "and the few leaves on the tung trees are dry and wilted and about to fall. \n"+
     "In the far distance one can barely see tall, dark, brown mountains.\n",

items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "bushes","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon sight",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa25.c","west",
  "/players/francesco/2001/rooms/africa23.c","south",
});

}

init(){
      ::init();
      add_action("touch","touch");
      }

touch(str) 
  {
  if(!str) {write("Touch what?\n"); return 1;}
  if(str!="monolith") {write("Touch what?\n"); return 1; }
  write("All of a sudden a brilliant blast of light surrounds the room.\n"+
        "Your mind blows,  your eyes close, your body feels weightless.\n"+
        " ....... ......... ........... ........... ......... .......\n"+
        "   ...     .....     .......     .......     .....     ...\n"+
        "    .        .         ...         ...         .        .\n"+
        "                        .           . \n"+
        "             You are transported elsewhere.\n");
  this_player()->move_player("to another age#players/francesco/2001/rooms/space1.c");
  return 1;
  }

