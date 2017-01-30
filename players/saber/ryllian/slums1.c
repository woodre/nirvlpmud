#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("begger"))  {
move_object(clone_object("/players/saber/monsters/begger.c"),this_object());
        }
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
 "*Copper Lane        (North/South)\n"+
 "*Corpse Alley       (West)\n"+
 "You stand in the slums of Ryllian on Copper Lane.  To the distant North you\n"+
 "see Imperial Street, overshadowed by the spirals of the Church of Larn and the\n"+
 "dark shadow of the Mages Tower.  To the south the slums continue, while to the\n"+
 "east is the beginning of Corpse Alley.  To the southwest is an evil looking\n"+
 "structure.  The street is dimly lit by a few flickering torches.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","You cannot see that from here",
 "tower","The Mages tower rises to the northwest.\n"+
   "The Tower of Heros rises to the east",
 "slums","You stand within the slums of Ryllian",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll9.c","north",
 "/players/saber/ryllian/slums2.c","south",
 "/players/saber/ryllian/slums5.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("southwest","southwest");
  add_action("southwest","sw");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

southwest()  {
call_other(this_player(), "move_player", "southwest#/players/saber/closed/quest/arate/arate.c");
  return 1;
        }
