#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Scholars Way       (South)\n"+
 "*Avenue of Colors   (West/East)\n"+
 "You are walking along the Avenue of Colors.  To the north is some sort of\n"+
 "Gymnasium.  To the south along Scholars Way lie the massive marble pillars of\n"+
 "the Library of Ryllian.  To the east you see the Tower of the Hero rising up\n"+
 "against the city skyline.  To the west is The Torchlit Highway.  The road is\n"+
 "lit by blazing torches.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the west.\n"+
   "The Tower of Heros rises to the east",
 "library","The library lies to the south",
 "gymnasium","The grmnasium of Ryllian lies to the north",
 });

  dest_dir=({
 "/players/saber/ryllian/gym.c","north",
 "/players/saber/ryllian/ryll11.c","east",
 "/players/saber/ryllian/library.c","south",
 "/players/saber/ryllian/ryll6.c","west",
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
