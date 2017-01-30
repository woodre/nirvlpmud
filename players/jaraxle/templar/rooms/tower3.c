#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = "East Tower";
long_desc =
  "   The stairway ends abruptly here.  A large opening can\n"+
  "be seen at the top of the stairway. Light shines through\n"+
  "the opening, casting odd shadows over the stairway. Back\n"+
  "down the stairway curves away into the darkness.\n";
items = ({
  "tower","Made of solid stone, the tower rises high above the castle",
  "shadows","Flickering shadows from the light that shines through the opening",
  "light","Glowing sunlight dancing through the opening",
  "darkness","It is dark",
  "stairway","A thick wooden stairway.  Splinters of wood reach from the outside\nof the the tower walls to the center of the tower.  The stairway\nleads down to the castle and ends upward at an opening",
  "opening","A large opening into the top of the tower",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/tower4.c","up",
  "/players/jaraxle/templar/rooms/tower2.c","down",
});

}


 init(){
        ::init();
this_player()->set_fight_area();
}
exit(){    if(this_player()) this_player()->clear_fight_area();     }
