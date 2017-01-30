#define tp this_player()->query_name()
inherit "room/room";
#include <ansi.h>

reset(int arg){
 if(!present("beetle")) {
    int a;
     a=0;
    while(a<5){
move_object(clone_object("/players/daranath/mons/beetle_fire.c"),this_object());
     a++;
   }
}

 if(!arg){

  set_light(1);
  short_desc="Softly Glowing Chamber";
  long_desc=
  "The soft glow originates from this chamber, as several rock surfaces\n"+
  "have a residue that is casting the radiance. The chamber itself is\n"+
  "a small cave, with rock outcroppings about the chamber. A tunnel\n"+
  "runs to the west from here.\n";

items=({
 "floor", "The floor is covered in a thick layer of loose dirt",
 "cave", "The small cave is about 15' or so in diameter and not very\n"+
         "friendly, you could not imagine living here",
 "tunnels", "The tunnels end here, dumping you in this small cave",
 "darkness", "The darkness leaves you wondering what might be hidden in"+
             "every corner",
 "glow", "The soft glow is chemical in nature and a soft red color",
 "residue", "Looks like a chemical resdue that a creature might\n"+
            "have left here",
 "rock", "The rock outcroppings are sticking straight out from the\n"+
         "ground, as if something has pushed them out",
 });

  dest_dir=({
 "/players/daranath/underdark/level1/e,8.c","west",
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
