#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     =================      You stand in a concealed alcove, hidden\n"+
"     ==                     behind the thick tapestries which line\n"+
"     ==                     the walls of the outer corridor.  From\n"+
"     =================      somewhere nearby you hear chanting.\n";

items=({
 "temple","You are in the Temple of Arate",
 "alcove","You are in a concealed alcove",
 "corridor","The corridor is filled with a haze of incense smoke",
 "chanting","You can't look at chanting",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate16.c","east",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing.\n");
 say (tp +" searches the area\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
