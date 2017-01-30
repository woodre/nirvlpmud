#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";
int a, b;

reset(int arg){
if(!present("citymon")) {
move_object(clone_object(ROOT+"mon/paladin.c"),this_object());
a = 0;
b = (random(3) + 1);
 while(a<b) {
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
"               "+BOLD+"Old Road"+NORM+" (north, south)\n"+
"               "+BOLD+"Heroes Walk"+NORM+" (east, west)\n"+
"Old road continues throughout the city, running north out from City Ward and\n"+
"into the heart of "+WHT+"Ghost Ward"+NORM+". Another large stone barricade has been\n"+
"built here, trying to keep the citizens of City Ward safe while they rebuild\n"+
"thier city and also thier lives.\n";

    items=({
"road","Old road runs north, deep into Ghost Ward",
"barricade","The barricade has been built of stone and wood, primarily pulled from\n"+
     "the many ruined building that used to reside in City Ward",
"stone","Lots of stone was available for building the barricade",
"wood","Broken timbers and other burnt logs are abundant within the barricade",
"city","The city of Qual'tor is all around you",
    });

    dest_dir=({
      "/players/daranath/qualtor/gateway.c","north",
      "/players/daranath/qualtor/old_road1.c","south",
      "/players/daranath/qualtor/hero_walk1.c","east",
      "/players/daranath/qualtor/hero_west.c","west",
    });

    }
  }

    init(){
      ::init();
add_action("search","search");
add_action("dar_north","north");
    }

    search(){
    write("You find nothing about the ruins of the statue.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_north(){
write("You climb over the strong barricade and head into\n\n"+
      "              "+WHT+"GHOST WARD"+NORM+"\n\n"+
      "You shiver as you see the dark ash falling from the sky.\n\n");
return 0;
}

