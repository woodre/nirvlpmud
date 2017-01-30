#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
if(!present("Andru", this_object())){
move_object(clone_object("players/jaraxle/templar/mon/shopkeep"),this_object());
}

  if(arg) return;
set_light(1);
short_desc = HIW+"Templar Exchange ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
long_desc =
"  The shop is a spacious room with items for sale set upon the many\n"+
"shelves that are mounted on the stone walls. A long, wooden counter\n"+
"spans the width of the room, blocking access to the supply room\n"+
"beyond. A small fireplace warms the room, and a sign hangs on the\n"+
"wall behind the counter.\n";
items = ({
"sign","Commands are: 'buy item', 'sell item', 'sell all', 'list'\n"+
"'list weapons','list armors' and 'value item'",
});

dest_dir = ({
"/players/jaraxle/templar/rooms/hallway1.c","west",
});

}

 init(){
        ::init();
this_player()->set_fight_area();
}
exit(){    if(this_player()) this_player()->clear_fight_area();     }

