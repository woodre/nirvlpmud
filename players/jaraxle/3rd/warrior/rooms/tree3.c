#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Bridge";
long_desc =
        "  This is the center of a long wooden bridge between a stretch\n"+
        "of tree trunks.  The bridge is tied off onto some of the trees\n"+
        "by rope.  Leaves trickle down onto the walkway of the bridge,\n"+
        "carpeting it in brown and green.\n";

items = ({
  "trees","Tall, vibrant trees with a touch of aged bark",
  "bark","Bark that has seen many, many years",
  "rope","Rope made from dried vines, tie the bridge off in evenly spaced\nlocations to hold up the bridge",
  "tree trunks","Trunks enormous in girth surrounding the bridge",
  "trunks","Trunks enormous in girth surrounding the bridge",
  "leaves","Brown and green leaves which have fallen from the tree tops",
  "tree tops","The trees grow high above, covering the bridge in a sheet of green and brown",
"bridge","A long wooden bridge that disappears into the trees from east and west.\nLeaves of brown and green cover the bridge.\nThe bridge is tied to several trees with rope.\nThere is a small landing on the bridge that lets you "+HIW+"look over"+NORM+" the "+HIW+"bridge"+NORM+" from",
  "walkway","A long wooden bridge that disappears into the trees from east and west",
});

MOCO("/players/jaraxle/3rd/warrior/mon/maiden.c"),TO);

}
init() {

::init();

add_action("east","east");
add_action("west","west");
add_action("lok","look");
}

west() {
write("You go west over the bridge.\n");
this_player()->move_player("west#/players/jaraxle/3rd/warrior/rooms/treew3");
return 1; }

east() {
write("You move over the bridge to the east.\n");
this_player()->move_player("east#/players/jaraxle/3rd/warrior/rooms/treee3");
return 1; }

lok(arg){
if(arg == "over bridge"){
write("You look over the bridge . . .\n\n");
      move_object(this_player(), "/players/jaraxle/3rd/warrior/rooms/room3.c");
      command("look", TP);
  move_object(this_player(), this_object());
return 1; }
}


