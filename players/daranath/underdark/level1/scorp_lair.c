#define tp this_player()->query_name()
inherit "room/room";
#include <ansi.h>

reset(int arg){
 if(!present("scorpion")) {
    int a;
     a=0;
    while(a<4){
move_object(clone_object("/players/daranath/mons/scorp_giant.c"),this_object());
     a++;
   }
}

 if(!arg){

  set_light(-1);
  short_desc="Scorpion Lair";
  long_desc=
  "A small cave emerges from the darkness of the twisting tunnels, large\n"+
  "piles of detrement stacked in the corners of the area. Various sizes and\n"+
  "shapes of shells are about, scattered from wall to wall. Bits and pieces\n"+
  "of armor and weapons also lie about, reminders of brave souls who lost\n"+
  "thier life within this cave.\n";

items=({
 "floor", "The floor is covered in a thick layer of loose dirt",
 "shells", "The shells are lying about in a random fashion",
 "armor", "The armor of fallen heroes is scattered about the cave, rents\n"+
           "and tears in the armor a testament to the dead",
 "weapons", "Useless and rusted, the weapons in this area match that of the\n"+
             "armor, broken and scattered",
 "corners", "The corners hide shadows which run deep",
 "cave", "The small cave is about 15' or so in diameter and not very\n"+
         "friendly, you could not imagine living here",
 "tunnels", "The tunnels end here, dumping you in this small cave",
 "darkness", "The darkness leaves you wondering what might be hidden in"+
             "every corner",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/c,9.c","north",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You find nothing amongst the dirt.\n");
say (tp +" searches the area\n");
 return 1;  }

arate() { return "YES"; }
