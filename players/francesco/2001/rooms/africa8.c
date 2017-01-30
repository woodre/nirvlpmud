#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("tooth")) {
  move_object(clone_object("/players/francesco/2001/mobs/bigtooth.c"),
	this_object());  }

set_light(1);

short_desc = "African Drylands" ;
long_desc =
     "   AFRICA,  3,000,000 YEARS AGO\n"+
     "On the border of a dry african plain.  Some bushes are scattered about\n"+
     "and the few leaves on the baobab trees are dry and wilted and about to fall. \n"+
     "In the far distance one can barely see tall, dark, brown mountains.  \n"+
     "This wide area is often the scenario of battles between the opposite \n"+
     "tribes living the valley.\n",

items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "bushes","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon sight",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa25.c","east",
  "/players/francesco/2001/rooms/africa24.c","west",
  "/players/francesco/2001/rooms/africa21.c","south",
});

}

init(){
  ::init();
  add_action("listen","listen");
}

listen(){
   write("Now and then you hear the yellings of animals and \n"+
         "the sound of bones crushing.\n");
   return 1;
}

