#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){

  move_object(clone_object("/players/saber/closed/quest/arate/arateguard.c"),
  this_object());        

 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"======================       Large clouds of incense smoke fill the\n"+
"                             corridor.  The smoke seems to be oozing\n"+
"                             through cracks in the southern wall,\n"+
"======================       forming chaotic patterns in the air.\n";

items=({
 "temple","You are in the Temple of Arate",
 "cracks","There might be a secret door to the south",
 "wall","You think there might be a secret door to the south",
 "corridor","The corridor is filled with a haze of incense smoke.\n"+
            "The smoke is oozing through cracks in the southern wall",
 "incense","The incense is so sweet you begin to feel light headed",
 "patterns","Patterns shift before your eyes in a storm of chaotic images", 
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate14.c","east",
 "/players/saber/closed/quest/arate/arate12.c","west",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("south","south");
}

south()  {
  call_other(this_player(), "move_player",
       "through the tapestries#players/saber/closed/quest/arate/arate19.c");
  return 1;
         }

search() {
 write("You find cracks in the wall to the south.\n");
 say (tp +" searches the area\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
