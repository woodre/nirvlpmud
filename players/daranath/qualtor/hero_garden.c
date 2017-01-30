#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
/*
move_object(clone_object("/players/daranath/qualtor/obj/fountain.c"),this_object());
*/
move_object(clone_object("/players/daranath/qualtor/mon/katt.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Garden of Heroes)");
    long_desc=
"               "+BOLD+"Garden of Heroes"+NORM+" (south)\n"+
     "The Garden of Heroes sits just to the north of Heroes Walk. A\n"+
     "large stone fountain the main feature of the garden, while many\n"+
     "plants and small animals live in the garden itself. This is\n"+
     "a tranquil place, protected by a magical force that not many\n"+
     "within the city could identify. Heroes walk lies to the\n"+
     "south from here.\n";

    items=({
     "plants","A variety of plants and trees are planted within the garden,\n"+
              "blocking the devestation of the city all about you",
     "animals","Small animals scurry about the area, living off the plants here",
     "animal","A chipmonk or sqirrel runs about the area",
    });

    dest_dir=({
      "/players/daranath/qualtor/hero_walk2.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing about the Garden of Heroes.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

