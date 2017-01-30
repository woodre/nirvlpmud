#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
int coins;
int searched;

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "the pond";
long_desc =
"  The hills here extend in all directions as you reach\n"+
"an open area.  A large pool of water spreads out before\n"+
"you with several shrubs and green grass growing around\n"+
"it. A single large tree stands in the center of the pool\n"+
"on a small island.  The path winds around the water\n"+
"and continues to the south or to the north and towards\n"+
"the mountains.\n";  

items = ({
  "hills",
  "Here the hills extend outward sweeping up in all directions\n"+
  "with a path leading to the north and south through them",
  "path",
  "A path leading north to south",
  "pool",
  "A large pool of water that is crystal clear and clean. A\n"+
  "large tree stands in the center of it on a small island",
  "water",
  "Crystal clear water that looks refreshing",
  "shrubs",
  "Small shrubs that surround the pool of water",
  "grass",
  "Beautiful green grass that has gathered around the pool of\n"+
  "water",
  "island",
  "A very small patch of ground that allows a tree to grow on\n"+
  "its surface",
  "tree",
  "A huge oak tree that stands on the island in the pool",
  "mountains",
  "A mountain range far to the north",
  });

dest_dir = ({
  "/players/maledicta/path/rooms/r6.c","north",
  "/players/maledicta/path/rooms/r8.c", "south",
});

}

init(){ 
  ::init();
  add_action("search", "search");
  }

search(){  
 
 if(!present("rescued_elf_dood_mal", this_player())){ return 0; }
 else{
  if(searched){ write("You search but find nothing.\n"); return 1; }
  destruct(present("rescued_elf_dood_mal", this_player()));
  write("You search carefully and uncover a small treasure trove...\n");
  move_object(clone_object("/players/maledicta/cont/rdragon/elven_rapier.c"), this_object());
  coins = clone_object("obj/money");
  coins->set_money(random(3000));
  move_object(coins, this_object()); 
  say(this_player()->query_name()+" uncovers something...\n");
  searched = 1;
  return 1;
  }
 return 1;
 }
  

