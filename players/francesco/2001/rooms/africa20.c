#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("herbivore")) {
  move_object(clone_object("/players/francesco/2001/mobs/herbivore.c"),
	this_object());  }

set_light(1);

short_desc = "African Drylands" ;
long_desc =
     "   AFRICA,  3,000,000 YEARS AGO\n"+
     "In the middle of a dry african plain.  Some bushes are scattered about\n"+
     "and the few leaves on the babano trees are dry and wilted and about to \n"+
     "fall.  In the far distance one can barely see tall, dark, brown mountains.  \n"+
     "Tons of meat of the herbivores are visible in the far distance over \n"+
     "the parched savannah.  They are slowly starving to death in the midst\n"+
     "of plenty.\n",


items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "bushes","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon sight",
   "herbivores","Monstrous brontosaurus, about 30 feet tall and 60 feet long",
   "savanna","it is a wide and dry area with low bushes and dried grass",

});

dest_dir = ({
  "/players/francesco/2001/rooms/africa24.c","north",
  "/players/francesco/2001/rooms/africa16.c","south",
  "/players/francesco/2001/rooms/africa21.c","east",
  "/players/francesco/2001/rooms/africa19.c","west",
});

}
