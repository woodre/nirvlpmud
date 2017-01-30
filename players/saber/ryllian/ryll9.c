#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("fem"))  {
move_object(clone_object("players/saber/closed/new_mini/agents/gothic.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Imperial Street    (North)\n"+
 "*Copper Lane        (South)\n"+
 "You stand where Imperial Street intersects with Copper Lane.  To the North you\n"+
 "see the Spirals of the Church of Larn and the dark shadow of the Mages Tower.\n"+
 "To the south you see the beginning of slums of Ryllian.  The street is dimly\n"+
 "lit by a few flickering torches.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the northwest.\n"+
   "The Tower of Heros rises to the east",
 "slums","The slums lie to the south",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll8.c","north",
 "/players/saber/ryllian/slums1.c","south",
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
