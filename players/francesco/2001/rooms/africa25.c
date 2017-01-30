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
     "On the border of a dry african plain.  Some bushes are scattered around,\n"+
     "the leaves on the trees are about to fall down.  In the far distance\n"+
     "tall mountains appear with a dark brown color.  A certain noise can \n"+
     "be heard, maybe coming from east.\n",

items = ({
   "plain","It is wide, flat and dark. It was created when a volcano was estinguished",
   "bushes","They are low and brown, widely spreading out in the plain",
   "leaves", "Once upon a time they were food for the jurassic animals",
   "trees","They look naked almost of all of their leaves",
   "mountains","The mountains are tall, wide and close the whole horizon sight",
});

dest_dir = ({
  "/players/francesco/2001/rooms/africa8.c","west",
  "/players/francesco/2001/rooms/africa9.c","east",
  "/players/francesco/2001/rooms/africa22.c","south",
});

}

init(){
  ::init();
  add_action("listen","listen");
}

listen(){
   write("What you hear is not exactly a noise, but rather a very light whistle.\n");
   return 1;
}