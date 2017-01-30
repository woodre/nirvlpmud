#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "a mountain trail";
long_desc =
"  You are on the southern side of the great mountain range. A\n"+
"winding path leads down to a crowded grouping of tall hills or\n"+
"north to a crest at the top of the mountain's ridge. Small\n"+
"patches of trees dot the landscape at the base of the mountain.\n";  

items = ({
  "range",
  "A long mountain range that extends from east to west",
  "path",
  "A narrow path that leads up the mountain to the crest or\n"+
  "down into the hilly valley below",
  "crest",
  "The lowest portion of the mountain range",
  "valley",
  "A large valley of hills and trees",
  "trees",
  "Medium sized trees that grow along the hills of the valley",
  "mountain", 
  "A large mountain that is part of the range moving from east\n"+
  "to west",
  "ridge",
  "The lowest part of the mountain you are on",
  "hills",
  "large and steep hills that are located at the base of the\n"+
  "mountain",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r2.c","north",
  "/players/maledicta/path/rooms/r4.c", "down",
});

}


