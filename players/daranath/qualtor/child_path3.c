#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("paladin")) {
move_object(clone_object(ROOT+"mon/paladin.c"),this_object());
}
if(!present("citymon")) {
int a, b; a=0; b = (random(3)+1);
while(a<b){
  int c; c = random(3);
if(c == 0) move_object(clone_object(ROOT+"mon/dwarf_bar.c"),this_object());
if(c == 1) move_object(clone_object(ROOT+"mon/elf_bar.c"),this_object());
if(c == 2) move_object(clone_object(ROOT+"mon/half_bar.c"),this_object());
  a++; }
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(City Ward)");
    long_desc=
"               "+BOLD+"Children's Pathway"+NORM+" (north, south)\n"+
"               "+BOLD+"Heroes Walk"+NORM+" (east)\n"+
"At the far northern end of City Ward, along the Children's pathway, a\n"+
"large wood and stone barricade has been built, in a vain attempt to \n"+
"keep the monsters in "+WHT+"Ghost Ward"+NORM+" at bay. A small street runs east\n"+
"from the barricade, while Children's Pathway heads back to the south.\n";

    items=({
"barricade","A large barricade blocks the undead from Ghost Ward that try to get into\n"+
     "City Ward. The barricade itself is usually guarded by Qual'tors Paladins\n"+
     "and other barricade fighters from the surrounding lands",
"pathway","Children's Pathway has been effectivly split in half, divided by both\n"+
     "city wards and the large stone barricade",
"stone","A variety of stone and wood make up the strong barricade",
"wood","A variety of stone and wood make up the strong barricade",
"street","Heroe's Walk heads east from here",
"monsters","Looking over the barricade, you don't seem to be able to see any of\n"+
     "the nasty residents of Ghost Ward",
    });

    dest_dir=({
      "/players/daranath/qualtor/child_path4.c","north",
      "/players/daranath/qualtor/child_path2.c","south",
      "/players/daranath/qualtor/hero_west.c","east",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("dar_north","north");
    }

    search(){
    write("You find nothing about the base of the fountain.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_north(){
write("You climb over the strong barricade and head into\n\n"+
      "              "+WHT+"GHOST WARD"+NORM+"\n\n"+
      "You shiver as you see the dark ash falling from the sky.\n\n");
return 0;
}

