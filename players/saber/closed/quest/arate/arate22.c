#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ===========            You are in a small alcove, deep within\n"+
"     ==        =======      the temple of Arate.  The air is heavy\n"+
"     ==                     with incense and smoke, and echoes with\n"+
"     ==                     the sound of chanting.  To the east you\n"+
"     ==        =======      catch glimpses of an altar.  You think\n"+
"     ===========            you could <peek east>.\n";

items=({
 "temple","You are in the Temple of Arate",
 "alcove","You are within a small alcove, deep within the Temple of Arate",
 "incense","The smokey incense is so sweet you begin to feel light headed",
 "smoke","The smokey incense is so sweet you begin to feel light headed",
 "chanting","You source of the chanting is to the east",
 "altar","The altar appears to be of the kind used for ritual sacrifice",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate23.c","east",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("peek_east","peek");
}

search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
