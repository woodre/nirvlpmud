#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Imperial Street   (South)\n"+
 "*Avenue of Colors  (East)\n"+
 "You stand on the intersection between the Avenue of Colors and Imperial\n"+
 "Street.  To the north is a large shrine.  To the northwest the black shadow of\n"+
 "the Mages tower rises up high into the air, competing with the spirals of the\n"+
 "Church of Larn to reach the heavens.  The Church lies to the west, and the\n"+
 "Embassy House lies to the southwest.  The street is lit by flickering torches.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the west.\n"+
   "The Tower of Heros rises to the east",
  "church","The Church of Larn lies to the west",
 "house","The Embassy House lies to the southwest",
 "shrine","A shrine lies to the north",
 });

  dest_dir=({
 "/players/saber/ryllian/shrine.c","north",
 "/players/saber/ryllian/ryll4.c","east",
 "/players/saber/ryllian/ryll8.c","south",
 "/players/saber/closed/quest/larn/enter.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
