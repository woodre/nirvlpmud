#define tp this_player()->query_name()
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "room/room";

reset(int arg){
if(!present("halfling")) {
move_object(clone_object(ROOT+"mon/half_scared.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Arena Ward)");
    long_desc=
"               "+BOLD+"Arena Pathway"+NORM+" (southwest, east)\n"+
"Just west of the old arena entrance, the pathway running along the eastern\n"+
"edge of Qual'tor ends here, doubling back southwest torwards the city\n"+
"again. Piles of wooden crates and broken chests line the northern edge\n"+
"of the area, while a large stone archway sits just to the east.\n";

    items=({
"pathway","The dirt and stone pathway ends here",
"arena","The Qual'tor arena is long since ruined",
"entrance","The entrance to the arena sits just to the east",
"crates","Wooden crates and chests line the northern edge of this area",
"chests","The wooden chests and crates are long since looted",
"archway","The old stone entrance of the arena was marked with a large archway",
    });

    dest_dir=({
  ROOT+"arena_way4.c","north",
  ROOT+"arena_entry.c","east",
  ROOT+"arena_way2.c","southwest",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
write("Bloody trails cover the pathway, heading north between the crates.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

