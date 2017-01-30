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
"*Cobblestone Lane   (West/East)\n"+
"You stand amidst the slums of Ryllian.  To the west you see the decaying\n"+
"remains of many once grand and spacious buildings.  To the east you see an\n"+
"intersection of The Torchlit Highway, leading back to the market square.\n";

items=({
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","The Sea of Stars lies to the south",
 "buildings","There are the remains of many decaying buildings to the west",
 "slums","You stand within the slums of Ryllian",
 });

  dest_dir=({
 "/players/saber/ryllian/slums2.c","west",
 "/players/saber/ryllian/ryll10.c","east",
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

