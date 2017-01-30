#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("tauros")) {
move_object(clone_object(ROOT+"mon/tauros.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"At the deepest point along the Arena Pathway, you have found a small niche\n"+
"between several of the larger crates. They are stacked along either side\n"+
"of the small area, making for makeshift wooden walls. Several of the\n"+
"crates have been smashed in and looted, leaving very little behind.\n";

    items=({
"pathway","Arena Pathway runs along the eastern edge of Qual'tor",
"niche","A small niche is here between the large crates",
"crates","The large crates were used for supplies to the arena",
"area","A small area is here between the large crates",
"walls","The large crates make up the makeshift walls",
    });

    dest_dir=({
  ROOT+"arena_way3.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("dar_south","south");
    }

    search(){
write("Small bits of broken wood are everywhere.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_south() {
if(present("tauros") && (this_player()->query_level() < 20)) {
write("Tauros the Minotaur grabs you and slams you up against one of the crates.\n"+
      "His hot, nasty breath is in your face as you tremble in fear.\n");
return 1; }
return 0;
}

