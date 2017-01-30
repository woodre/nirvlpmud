#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Imperial Street   (North/South)\n"+
 "You stand on Imperial street.  To the northwest you see that Embassy House,\n"+
 "and the black shadow of the Mages tower rising up high into the air in\n"+
 "competition with the spirals of the Church of Larn.  The street is lit by\n"+
 "flickering torches.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the northwest.\n"+
   "The Tower of Heros rises to the east",
  "church","The Church of Larn lies to the northwest",
 "house","The Embassy House lies to the west",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll5.c","north",
 "/players/saber/ryllian/ryll9.c","south",
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
