#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("golden_plates", this_object())){
move_object(clone_object("/players/jaraxle/templar/plate.c"), this_object());
}
  if(arg) return;
set_light(1);
short_desc = "Hall of Dedications "+BOLD+"["+HIY+"Tower of Hope"+NORM+BOLD+"]"+NORM;
long_desc = 
"  This is the Hall of Dedications. Here the spirit of the warrior\n"+
"of good, whether living or dead, is honored for its deeds in the\n"+
"realm. On the wall are several golden plates decorated with the\n"+
"names of these people.  An archway leads west to the main entry\n"+
"hall.\n";  

items = ({
"walls",
"The walls are made from a beautiful white stone, bound by a glittering\n"+
"mortar.  Numerous holy symbols adorn each stone, binding and protecting\n"+
"the tower from harm. Several large golden plates decorate them",
"wall",
"The wall is made from a beautiful white stone, bound by a glittering\n"+
"mortar. Holy symbols adorn each stone, binding and protecting the\n"+
"tower from harm",
"stone",
"A beautiful white stone",
"symbols",
"Small holy symbols etched into the stone",
"archway",
"A stone archway leading to the main hall"
});


dest_dir = ({
  "/players/jaraxle/hope/rooms/hmain.c","west"
});

}

no_hunter(){ return 1; }
