#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
if(!present("guard", this_object())){
move_object(clone_object("players/jaraxle/templar/mobs/high_templar"),this_object());
        }
        if(!present("bulletinboard", this_object())){
move_object(clone_object("players/jaraxle/templar/rooms/eboard"),this_object());
        }
  if(arg) return;
set_light(1);
short_desc = ""+HIR+"E"+HIW+"lite "+NORM+BOLD+"Command Post"+NORM+""+HIW+" ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
  "  The small, modest room of the Elite Guard is dimly lit by a torch\n"+
  "hung beside the stairwell. A small window, open to the air, has a\n"+
  "spectacular view of the forest that stretches for miles beyond the\n"+
  "outer walls of the fortress. A corner of the room has been cleared,\n"+
  "with racks to hold weapons, baskets for smaller items, and several\n"+
  "hooks to hold armors. A narrow stairwell leads down.\n";
items = ({
  "torch","An old eternal torch, flickering in the breeze",
  "stairwell","A stone stairwell that leads down from the top of the tower",
  "window","A square window, carved from the massive stone blocks of the wall",
  "forest","A lush, green forest thick with foliage",
  "racks","Strong, wooden racks mainly for use with weapons",
  "baskets","Numerous wicker baskets bleached white with age",
  "hooks","Metal hooks with scratches from prolonged use",
});

dest_dir = ({
"/players/jaraxle/templar/rooms/equipment.c","down",
});

}

 init(){
        ::init();
this_player()->set_fight_area();
}
exit(){    if(this_player()) this_player()->clear_fight_area();     }

