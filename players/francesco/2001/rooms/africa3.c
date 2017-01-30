#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("lion")) {
  move_object(clone_object("/players/francesco/2001/mobs/lion.c"),
	this_object());  }
set_light(1);

short_desc = "African Drylands" ;
long_desc =
     "   AFRICA,  3,000,000 YEARS AGO\n"+
     "On the border of a dry african plain.  Some shrubs are scattered about\n"+
     "and the few leaves on the babano trees are dry and wilted and about to fall. \n"+
     "In the far distance one can barely see tall, dark, brown mountains.  \n"+
     "This desolated land appears to house much less animals than before.\n",

items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "shrubs","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon sight",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa15.c","north",
  "/players/francesco/2001/rooms/africa11.c","west",
});

}
