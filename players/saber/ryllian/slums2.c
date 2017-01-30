#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
"*Copper Lane        (North/South)\n"+
"*Cobblestone Lane   (East)\n"+
"You stand at the intersection of Copper and Cobblestone Lane.  To the south\n"+
"you can hear the faint roar of the ocean.  To the west is an evil looking\n"+
"structure, while to the north and the east the slums continue.  The\n"+
"intersection is lit by a single torch.\n";

items=({
 "torch","A magical torch of eternal fire\n"+
      "It is flickering in the sea breeze",
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","The Sea of Stars lies to the south",
 "structure","There is an evil looking structure to the west",
 "slums","You stand within the slums of Ryllian",
 });

  dest_dir=({
 "/players/saber/ryllian/slums1.c","north",
 "/players/saber/ryllian/slums3.c","south",
 "/players/saber/ryllian/slums4.c","east",
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

