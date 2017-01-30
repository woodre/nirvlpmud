#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(0);
short_desc="City of Ryllian";
long_desc=
 "*Corpse Alley      (West/East)\n"+
 "You stand in a very dark, very narrow alley.  To the\n"+
 "east is Copper Lane.  To the west is some sort of a shop.\n";

items=({
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "alley","You are in corpse alley",
 "shop","There is some sort of shop to the west",
 "slums","You stand within the slums of Ryllian",
 });

  dest_dir=({
 "/players/saber/ryllian/cshop.c","west",
 "/players/saber/ryllian/slums1.c","east",
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
