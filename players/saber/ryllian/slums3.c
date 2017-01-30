#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("dog"))  {
move_object(clone_object("/players/saber/closed/new_mini/agents/canine.c"),this_object());
        }
 if(!arg){
  set_light(1);
short_desc="City of Ryllian";
long_desc=
"*Copper Lane       (North)\n"+
"You stand at the end of copper lane.  To the north are the slums of Ryllian,\n"+
"while the waterfront district lies to the east.  To the south and west stretch\n"+
"the Sea of Stars, gleaming softly in the moonlight.\n";

items=({
 "street","The streets are made from dark stone",
  "city","The city of Ryllian",
 "streets","The city streets are made from dark stone",
 "ocean","The Sea of Stars streatches out to the horizon",
 "structure","There is an evil looking structure to the west",
 "moonlight","The moonlight is especially beautiful tonight",
 "slums","The slums lie to the north",
 });

  dest_dir=({
 "/players/saber/ryllian/slums2.c","north",
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

