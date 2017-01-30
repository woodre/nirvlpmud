#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Avenue of Colors      (West/East)\n"+
 "You stand in the city of Ryllian.  To the west the Avenue of Colors runs\n"+
 "towards the Mages tower, the Church of Larn and the Embassy House.  To the\n"+
 "east the Avenue of Colors runs to the Library and the Tower of Heros.  The\n"+
 "street is lit by flickering torches.  There is an alley to the ne.\n";

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
 "library","The library lies to the east",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll7.c","east",
 "/players/saber/ryllian/ryll3.c","west",
 "/players/saber/ryllian/gym.c","northeast",
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
