#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("minotuar")) {
 move_object(clone_object(ROOT+"mon/mino_glad.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Arena Pathway"+NORM+" (northeast, south)\n"+
"Winding its way around the ruins of Qual'tors former Arena, the pathway \n"+
"turns to the northeast. The skeletal remains of a large tavern rest on the\n"+
"western edge of the pathway, is tavern sign partially buried under loose\n"+
"dirt and other debris.\n";

    items=({
"arena","Qual'tors former arena is now broken down and deserted",
"tavern","The tavern was burnt down long ago during the warfare that lead to Qual'tors\n"+
     "downfall. The only thing left was the tavern sign hanging outside",
"dirt","The dirt is partially covering the tavern sign",
"debris","The tavern sign is partially covered by dirt and debris",
"pathway","The dirt pathway leads northeast around the arena's ruins",
"sign","The tavern sign is buried under a good amount of earth and other debris\n"+
     "it seems to read: Blood, Sweat and Beers",
    });

    dest_dir=({
  "/players/daranath/qualtor/newstuff/arena_way3.c","northeast",
  "/players/daranath/qualtor/newstuff/arena_way1.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_ne","northeast");
    }

    search(){
    write("A quick search of the Arena Pathway reveals nothing.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_ne() {
if(present("minotaur")) {
write("The Minotaur pushes you to the ground and snorts:\n"+
      "     No Way!  If you can't get by me, how can you defeat him?\n");
return 1; }
return 0;
}

