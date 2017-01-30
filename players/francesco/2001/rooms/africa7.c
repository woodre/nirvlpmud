#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("moonwatcher")) {
  move_object(clone_object("/players/francesco/2001/mobs/moonwatcher.c"),
	this_object());  }

set_light(1);

short_desc = "African Drylands" ;
long_desc =
     "   AFRICA,  3,000,000 YEARS AGO\n"+
     "On the border of a dry african plain.  Some bushes are scattered about\n"+
     "and the few leaves on the trees are dry and wilted and about to fall. \n"+
     "In the far distance one can barely see tall, dark, brown mountains.  \n"+
     "A stream of water moves very slowly, almost disappearing into the ground\n"+
     "and looking rather like a swamp.  The tribe of the Moonwatcher can come \n"+
     "here in the hope of getting some relief to their thirsty.\n",

items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "bushes","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon sight",
   "stream","The dark water moves very slowly",
   "swamp","Stagnant water, with some dark leaves floating over it",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa24.c","east",
  "/players/francesco/2001/rooms/africa19.c","south",
});

}
