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
     "and the few leaves on the tung trees are dry and wilted and about to fall. \n"+
     "In the far distance one can barely see tall, dark, brown mountains.  \n"+
     "A member of the Moonwatcher tribe slowly wanders across the bare, flat\n"+
     "country-side, foraging for roots and occasional berries.  He moves\n"+
     "cautiously.  He is aware that if a lion appears, he would be defenceless\n"+
     "and with nowhere to hide.\n",

items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "bushes","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon from sight",
   "member","He is quite similar to a monkey, 3 feet tall",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa1.c","south",
  "/players/francesco/2001/rooms/africa13.c","east",
  "/players/francesco/2001/rooms/africa4.c","north",
});

}

init(){
  ::init();
  add_action("listen","listen");
}

listen(){
   write("You hear the desperate yells of an animal.\n");
   return 1;
}