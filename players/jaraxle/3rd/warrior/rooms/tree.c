#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Tree-Top Bridge";
long_desc =
        "  This is the center of a long wooden bridge.  The trees grow\n"+
        "wildly about you as the branches, full of plush leaves, encase\n"+
        "the bridge like a tunnel.\n";

items = ({
  "trees","Exciting trees that grow untamed in the forest",
 "bridge","A long bridge that disappears into the trees to the west and east.\nThe bridge is made of small wooden planks tied together with vine.\nThere is a rope railing on both sides to grab hold of.\nYou can also "+HIW+"look over"+NORM+" the"+HIW+" bridge"+NORM+"",
  "branches","Branches reach out from all of the trees, closing\nthe bridge into a shadowed tunnel",
  "leaves","The leaves cover the forest in a haze of dark and bright greens and brown tones",
  "railing","Two long, thick stretches of vine holding the bridge in place",
});


}
init() {

::init();

add_action("west","west");
add_action("east","east");
add_action("lok","look");
}

west() {
write("You go back west.\n");
this_player()->move_player("west#/players/jaraxle/3rd/warrior/rooms/treew");
return 1; }

east() {
write("You continue eastward on the bridge.\n");
this_player()->move_player("east#/players/jaraxle/3rd/warrior/rooms/treee");
return 1; }
lok(arg){
if(arg == "over bridge"){
write("You look over the bridge . . .\n\n");
      move_object(this_player(), "/players/jaraxle/3rd/warrior/rooms/entrance.c");
      command("look", TP);
  move_object(this_player(), this_object());
return 1; }
}

