#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
/*
if(!present("bulletinboard", this_object())){
move_object(clone_object("/players/jaraxle/hope/board.c"), this_object());
}
*/
if(!present("high_guard", this_object())){
move_object(clone_object("/players/jaraxle/hope/mobs/high_templar2.c"), this_object());
move_object(clone_object("/players/jaraxle/hope/mobs/high_templar2.c"), this_object());
}
  if(arg) return;
set_light(1);
short_desc = "Inner Hall "+BOLD+"["+HIY+"Tower of Hope"+NORM+BOLD+"]"+NORM;
long_desc = 
"  This is the inner hall of the Tower of Hope.  Here the\n"+
"allies and knights meet to discuss the protection of the\n"+
"realm of Nirvana. To the north is the portal chamber, and\n"+
"to the south is the main hall. A stairway leads up to the\n"+
"magical viewing chamber.\n";  

items = ({
"walls",
"The walls are made from a beautiful white stone, bound by a glittering\n"+
"mortar.  Numerous holy symbols adorn each stone, binding and protecting\n"+
"the tower from harm",
"stone",
"A beautiful white stone",
"symbols",
"Small holy symbols etched into the stone",
"archway",
"A stone archway leading to the main hall",
"stairway",
"A stone stairway leading up to the viewing chamber"
});


dest_dir = ({
  "/players/jaraxle/hope/rooms/hportal.c", "north",
  "/players/jaraxle/hope/rooms/hmain.c","south",
  "/players/jaraxle/hope/rooms/hviewer.c","up",
});

}

init(){
::init();
add_action("secret_in","west");
}

secret_in(){
if(!present("KnightTemplar", this_player())) return 0;
if(!present("KnightTemplar", this_player())->query_elite()) return 0;
write("You move to within the confines of the Inner Sanctum of the Elite Guard.\n");
move_object(this_player(), "/players/jaraxle/hope/rooms/hsanctum.c");
return 1;
}
no_hunter(){ return 1; }
