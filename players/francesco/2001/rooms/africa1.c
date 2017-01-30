#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("narrator")) {
  move_object(clone_object("/players/francesco/2001/mobs/narrator1.c"),
	this_object());  }
set_light(1);

short_desc = "African Drylands" ;
long_desc =
     "   AFRICA,  3,000,000 YEARS AGO\n"+
     "On the border of a dry african plain.  Some bushes are scattered about\n"+
     "and the few leaves on the gum trees are dry and wilted and about to fall.  \n"+
     "In the far distance one can barely sees tall and dark brown mountains. \n"+
     "Over the valley a full moon rises, and a cold wind blows down from the \n"+
     "distant mountains. It would be very cold tonight, but cold, like hunger, \n"+
     "is not a matter for any real concern.  It is merely part of the background \n"+
     "of life.\n",

items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "bushes","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon from sight",
   "moon","It is like a Little Sun, yet it only shines at night and gives no warmth.\n"+
          "When it is there, Moonwatcher crawls out of the cave, clambers \n"+
          "on to a large boulder besides the entrance, and squats there \n"+
          "where he can survey the valley. If any hunting beast approached, \n"+
          "he would have time to get back to the relative safety of the cave",
   "valley","It is several miles wide, spanning as far as the eyes can see",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa12.c","north",
  "/players/francesco/2001/rooms/africa10.c","east",
});

}

init(){
  ::init();
  add_action("listen","listen");
}

listen(){
   write("You hear the far soft blows of the wind.\n");
   return 1;
}
query_no_fight() {return 1;}
