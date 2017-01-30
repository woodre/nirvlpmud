#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Kingdom";
long_desc =
        "  This area of the tree tops is thick with foliage.  There is a\n"+
        "subtle flat amongst the branches.  Roped bridges connect to the\n"+
        "flat by small posts then slide into the dense forest.\n";
items = ({

"bridges","Long wooden bridges that disappear into the trees.\nThey cross north and east into the forest.\nThere is a short staircase leading to the west",
"staircase","A staircase further into the trees to the west",
  "tree tops","Thick with leaves and countless branches",
  "foliage","Trees, thick with leaves and branches",
 "flat","A platform in the trees made from branches tied together with rope",
  "rope","Rope made from dried out vines",
  "branches","Branches of ranging sizes grow from the trees in the forest",
  "posts","Thin tree trunks connected to the flat.\nRope is wrapped around the posts, holding bridges in place",
  "forest","The forest is full of foliage.\nShadows dance in and out of the leaved branches\nas the sunlight shimmers through open gaps in the leaves",
});


dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/roomw.c","descend",
});

}
init() {

::init();

add_action("north","north");
add_action("east","east");
add_action("west","west");
}

north() {
write("You cross the north bridge.\n");
this_player()->move_player("north#/players/jaraxle/3rd/warrior/rooms/treew2");
return 1; }

east() {
write("You cross the east bridge.\n");
this_player()->move_player("goes north#/players/jaraxle/3rd/warrior/rooms/tree");
return 1; }

west(){
write("You climb the stairs to the west.\n");
this_player()->move_player("goes west#/players/jaraxle/3rd/warrior/rooms/land_4_sale/land1");
return 1; }
