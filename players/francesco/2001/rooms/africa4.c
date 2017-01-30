#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "African Drylands" ;
long_desc =
     "   AFRICA,  3,000,000 YEARS AGO\n"+
     "On the border of a dry african plain.  Some bushes are scattered about\n"+
     "and the few leaves on the trees are dry and wilted and about to fall. \n"+
     "In the far distance one can barely see tall, dark, brown mountains.  \n"+
     "A huge rock leans against a hillside.  A little tree grows nearby.\n",

items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "bushes","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon sight",
   "rock","It had been levigated by the continuous action of the wind,\n"+
          "which made it round and smooth. It is big enough that the \n"+
          "Moonwatcher can hide the entrance of his cave with it",
   "cave","Only the entrance of the cave can be seen, it is dark inside.\n"+
          "It might be 'enter'ed",
   "tree","A dead tree, in its stump a hive of bees can be found.\n"+
          "Lucky is the Moonwatcher when he finds them for his food",
   "hillside","The whole hill is only about twenty feet tall and about a hundred wide",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa19.c","north",
  "/players/francesco/2001/rooms/africa16.c","east",
  "/players/francesco/2001/rooms/africa12.c","south",
});

}
