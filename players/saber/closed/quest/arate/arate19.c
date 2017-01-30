#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ============           Huge volumes of incense choke you as you\n"+
"     ==        ==           enter the concealed alcove.  Though you\n"+
"     ==        ==           can not locate its source, it seems that\n"+
"     ============           this is the origin of the temple’s incense.\n";

items=({
 "temple","You are in the Temple of Arate",
 "incense","The incense is so sweet you begin to feel light headed.\n"+
           "You spot several incense 'burners' near the floor",
 });

dest_dir=({
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("north","north");
  add_action("east","east");
}

east()  {
  call_other(this_player(), "move_player", 
       "through the incense haze#players/saber/closed/quest/arate/arate20.c");
  return 1;
         }

north()  {
  call_other(this_player(), "move_player",
       "through the incense haze#players/saber/closed/quest/arate/arate13.c");
  return 1;
         }

search() {
 write("You find several incense 'burners' near the floor.\n");
 say (tp +" searches the area\.n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
