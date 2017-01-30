#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"=================           The corridor abruptly ends in a solid wall\n"+
"               ==           of shadow and incense haze.  The chanting\n"+
"               ==           is now a low whisper so deep that you feel\n"+
"=================           it vibrating dimly through you.\n";

items=({
 "temple","You are in the Temple of Arate",
 "shadows","The shadows almost seem like they are alive",
 "corridor","The corridor is filled with a haze of incense smoke",
 "incense","The incense is so sweet you begin to feel light headed",
 "chanting","You can't look at chanting",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate8.c","west",
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
