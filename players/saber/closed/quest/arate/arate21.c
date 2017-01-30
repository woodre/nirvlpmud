#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"=================           You stand in a partially concealed alcove,\n"+
"               ==           hidden behind thick tapestries.\n"+
"               == \n"+
"=================             - = YOU HAVE JUST SPRUNG A TRAP = -\n";

items=({
 "alcove","You are standing in an alcove",
 "tapestries","The tapestries depict scenes of forbidden magicks",
});

dest_dir=({
 "/players/saber/closed/quest/arate/arate20.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
