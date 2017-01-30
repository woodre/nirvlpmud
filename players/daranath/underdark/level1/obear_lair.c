#define tp this_player()->query_name()
inherit "room/room";
#include <ansi.h>

reset(int arg){
 if(!present("owlbear")) {
    int a;
     a=0;
    while(a<3){
move_object(clone_object("/players/daranath/mons/owlbear.c"),this_object());
     a++;
   }
}

 if(!arg){

  set_light(-1);
  short_desc="OwlBear Lair";
  long_desc=
  "A small cave emerges from the darkness of the twisting tunnels, large\n"+
  "piles of rubbish lying about the far ends of it. The dirt covered floor\n"+
  "has large, clawed prints running across it, obviously something has\n"+
  "made this cave its lair.\n";

items=({
 "floor", "The floor is covered in a thick layer of loose dirt",
 "prints", "The large, clawed prints are made by a creature that is best\n"+
           "left alone",
 "rubbish", "The rubbish is made up of various items that are commonly\n"+
            "found about a dungeon complex and some that are not",
 "cave", "The small cave is about 15' or so in diameter and not very\n"+
         "friendly, you could not imagine living here",
 "tunnels", "The tunnels end here, dumping you in this small cave",
 "darkness", "The darkness leaves you wondering what might be hidden in"+
             "every corner",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/i,9.c","north",
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
