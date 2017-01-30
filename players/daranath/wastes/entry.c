#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!present("portal")) {
move_object(clone_object(ROOT+"obj/portal2.c"),this_object());
}
  if(!arg){
    
set_light(1);
short_desc= ("Entry into the "+BLK+BOLD+"Gundar Wastes"+NORM);
long_desc=
"The surrounding area is nothing but a vast, broken landscape. Rocky outcroppings\n"+
"jut from the ground in a seemingly random fashion, making you wonder how safe\n"+
"the area truely is. A small pathway leads north from here, all other directions\n"+
"blocked by stone and shadow.\n";

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
write("The rocky surroundings obscures tracks and footprints, making the area devoid\n"+
      "of anything interesting.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

