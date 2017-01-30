#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/vale/"
inherit "room/room";

reset(int arg){
  if(!present("portal")) {
move_object(clone_object(ROOT+"obj/portal2.c"),this_object());
}
  if(!arg){
    
set_light(1);
short_desc= ("Entry into "+MAG+"Lotus Vale"+NORM);
long_desc=
"A towering wall of stone rises up to your left, the massive cliff bleached\n"+
"a bright white over time from the sun. A small pathway follows the wall to\n"+
"the north, while a lush forest vale seems to open up to the east of the\n"+
"pathway. Welcome to the Lotus Vale.\n";

items=({
"rock","The rocky outcroppings are quite sharp. You can easily hurt someone with one",
"area","The surrounding area is bleaky and dreary. Not a place to build a home",
"landscape","The landscape is harsh",
    });

    dest_dir=({
  ROOT+"sub_entry.c","north",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("Nothing about the Lotus Vale catches your curiousity during the search.\n"+
      "Nothing yet, anyhow...\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

