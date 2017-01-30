#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"=================           You stand in a prison cell, deep within the\n"+
"               ==           temple of Arate.  The walls have shackles\n"+
"               ==           fixed into them.  The air smells a mixture\n"+
"=================           of heavy incense and human refuse.\n";

items=({
 "temple","You are in the Temple of Arate",
 "cell","You are within a prison cell",
 "wall","The walls have shackles fixed into them",
 "walls","The walls have shackles fixed into them",
 "incense","The incense is so sweet you begin to feel light headed",
 "shackles","You could <free captive> with a key",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate24.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("free_captive","free");
}

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
