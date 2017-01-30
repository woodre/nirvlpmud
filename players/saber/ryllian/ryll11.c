#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("cat"))  {
move_object(clone_object("/players/saber/closed/new_mini/agents/feline.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Avenue of Colors   (West)\n"+
 "*Avenue of Valor    (South)\n"+
 "You stand at a three way intersection.  To the west runs the Avenue of Colors.\n"+
 "East is the dimly lit thieves alley.  To the south is an abandon looking\n"+
 "street that has for some reason been named the Avenue of Valor.  You see the\n"+
 "Tower of the Hero rising against the night sky to the southeast.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the west.\n"+
   "The Tower of Heros rises to the southeast",
 "library","The library lies to the southwest",
 "gymnasium","The grmnasium of Ryllian lies to the north",
 "alley","Thieves alley lies to the east.  You don't think that you should enter..",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll12.c","south",
 "/players/saber/ryllian/ryll7.c","west",
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
