#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ==       ==            Thick tapestries depicting grotesque scenes\n"+
"     ==       ==            of forbidden magiks cover the walls, muting\n"+
"     ==       ==            the nearby sounds of chanting.  The shadows\n"+
"     ==       ==            have again consolidated, forming themselves\n"+
"     ==       ==            into almost recognizable patters.\n";

items=({
 "shadows","The shadows almost seem like they are alive",
 "incense","The incense is so sweet you begin to feel light headed",
 "chanting","You can't see chanting",
 "tapestries","There seems to be room behind the tapestry to the west",
 "tapestry","There seems to be a room behind the tapestry to the west",
 "pattern","Patterns shift before your eyes in a storm of chaotic images", 
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate10.c","north",
 "/players/saber/closed/quest/arate/arate23.c","south",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("west","west");
}

west()  {
  call_other(this_player(), "move_player",
            "west#players/saber/closed/quest/arate/arate15.c");
  return 1;
         }
         
search() {
 write("You find nothing.\n");
 say (tp +" searches the area.\n");
 return 1;  }

realm()  { return "NT"; }
arate()  { return "YES"; }
