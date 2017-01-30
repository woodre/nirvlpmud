#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
  if(!present("merchant")) {
move_object(clone_object(ROOT+"mon/merchant.c"),this_object());
}
  if(!present("shop")) {
move_object(clone_object(ROOT+"obj/mer_shop.c"),this_object());
}
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Rocky Opening"+NORM);
long_desc=
"The rocky, desolate land gives way here, allowing a small clearing to form\n"+
"within. A large amount of sand covers the area, making for an excellent\n"+
"place to set up camp.\n"+
"A small wagon has been left here, its horses somewhere else.\n";

items=({
"land","Land around here is extremly rocky and harsh",
"sand","The sand is a light brown in color",
"clearing","The rocky wastes have given way to a small clearing, allowing anyone\n"+
     "to use this area",
"camp","A merchant has set up a small campsite here to purchase items",
"rock","Sharp, deadly rocks are a trademark of the Gundar Wastes",
"horses","There are no horses present",
"horse","There are no horses present",
"wagon","A small dusty, covered wagon is here within the clearing. It looks\n"+
     "to have travelled a great distance to get here",
    });

    dest_dir=({
  ROOT+"sub_entry.c","east",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
add_action("ask_habib","ask");
}

search(){
write("The rocky surroundings obscures tracks and footprints, making the area devoid\n"+
      "of anything interesting.\n");
  say(tp +" searches the area.\n");
 return 1;
}

ask_habib(){
  if(!present("habib")) {
write("Habib doesn't seem to be present at the moment.\n");
return 1; }
write("Habib says: You can do the following things here with me:\n\n"+
      "     "+HIR+"sell"+NORM+" any objects that you want\n"+
      "     "+HIR+"value"+NORM+" any objects to sell the sale price\n"+
      "\nIs there anything that you would like to sell?\n");
return 1; 
}

realm() {return "NT"; }
