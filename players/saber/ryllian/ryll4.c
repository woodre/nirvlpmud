#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Avenue of Colors      (West/East)\n"+
 "You walk along the Avenue of Colors.  Overhead the moon shines brightly down\n"+
 "upon you, illuminating the streets with its pale illumination.  To the west\n"+
 "the Mages tower rises up high into the air, competing with the spirals of the\n"+
 "Church of Larn to reach the heavens.  To the east lies the Torchlit Highway.\n";

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
 "house","The Embassy House lies to the west",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll3.c","east",
 "/players/saber/ryllian/ryll5.c","west",
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
