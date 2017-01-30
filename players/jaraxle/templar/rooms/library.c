#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(1);
short_desc = "Templar Library";
long_desc =
  "  A huge room with walls full of assorted books.  Each wall stands\n"+
  "about ten feet high, and is stocked full. Each section of the room\n"+
  "is divided among the different reading material.  In the center of\n"+
  "the room, there is a large oak table with wide chairs about it.  A\n"+
  "large chandelier of candles hangs quietly from the center of the room\n"+
  "giving it plenty of light. Long ladders lean against the stacks for\n"+
  "easier access to the books higher on the shelves. In each corner of\n"+
  "ceiling there is a triangular plaque with a Templar cross shining.\n";
items = ({
  "walls","Large walls with shelves.  The shelves are full of books",
  "section","There are sections about magic, combat, horseback riding, needlepoint, armory, faith, and misc reading",
  "table","A large, old table made of thick oak wood",
  "chandelier","A large iron chandelier with candles burning brightly on each arm",
  "chairs","Large wooden chairs, wide enough for two people each",
  "ladders","Wooden ladders which reach up to the ceiling",
  "plaque","A shining plaque of the Knights Templar Cross",
  "books","Books of different sizes and thickness",
});

MOCO("/players/jaraxle/templar/mon/chris.c"),TO);
dest_dir = ({
  "/players/jaraxle/templar/rooms/courtyard.c","out",
});

}

 init(){
        ::init();
this_player()->set_fight_area();
}
exit(){    if(this_player()) this_player()->clear_fight_area();     }
