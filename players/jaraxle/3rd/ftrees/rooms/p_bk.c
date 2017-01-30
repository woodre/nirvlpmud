#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/ftrees/defs/fish.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Third Earth";
long_desc = 
    "You are floating over a large river.  You see glints of fish in the water\n";
items = ({
  "forest","A growth of trees to the north.\nThere is a small path between two trees you can "+HIW+"walk"+NORM+"",
  "trees","Thick trees abundant with great leaves grow to the north\ncreating a barrier of sorts",
  "path","A small dirt path you can "+HIW+"walk"+NORM+" on",
  "branches","Large branches which grow low to the ground",
  "ground","The ground is dry and extremely hard",
  "grass","The grass is dry and cracks under your heavy feet",
  "haze","A wave of reddish haze makeing phantom reflections in the air",
  "reflections","The haze makes reflections off the ground",
  "clearing","A large open plain of dry grass.\nA forest looms to the north while the clearling leads on in all other directions",
  "fish","Some fish",
});

dest_dir = ({
  "/players/jaraxle/3rd/warrior/rooms/plain2.c","south",
});

}

long(str){ if(str == "fish") view_fish(); else ::long(str); }
init(){
  ::init();

add_action("enter","walk");
}

enter(arg){
if(arg == "path"){
write("You gradually walk the path into the forest.\n");
TP->move_player("into the forest#/players/jaraxle/3rd/warrior/rooms/room3.c");
return 1; }
notify_fail("Walk what?\n"); return 0; }

