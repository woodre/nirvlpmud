#include "def.h"
inherit "obj/treasure";

reset(arg) {
  set_id("table");
  set_alias("map");
  set_short(BLK+BOLD+"A stone table"+NORM);
  set_weight(100);
  set_value(10000);
}
long(str) {
  if(str=="map") {
    write(
"The map is divided into a 3x3 grid like this:\n\n"+
"|--------------------------------------------------------|\n"+ 
"|   Mountains   |       Chasm        |      Plateau      |\n"+
"|---------------|--------------------|-------------------|\n"+
"|     Hills     |       Ruins        |      Forest       |\n"+
"|---------------|--------------------|-------------------|\n"+
"|     Swamp     |     Grassland      |        Shop       |\n"+
"|--------------------------------------------------------|\n"
    );
  } else
  write(
"A massive rectangular stone table dominates the center of the\n\
room.  In the center of the table is a magnificently detailed\n\
miniaturized map that you can 'view'.  It appears so realistic\n\
that you can practically see figures moving around on it...\n\
You may also type 'obit' for an obituary.\n"

  );
}
init() {
  add_action("cmd_view","view");
  add_action("cmd_obit","obit");
}

cmd_view() {
  object world;
  object it;
  int i;
  write(
"Player          Health   Opponent        Health   Location\n"
  );
  world=users();
  if(it=find_living("lupus")) world+=({ it });
  for(i=0;i<sizeof(world);i++) {
    object room;
    object enemy;
    int stats;
    room=environment(world[i]);
    enemy=world[i]->query_attack();
    if(room && room->query_grand_arena() && !world[i]->query_ghost() &&
       !room->is_arena_central()) {
      write(pad(world[i]->query_name(),15));
      stats=(world[i]->query_hp()*100)/world[i]->query_mhp();
      write(pad(" ("+stats+"\%)",10));
      if(enemy) {
      write(pad(enemy->query_name(),15));
      stats=(enemy->query_hp()*100)/enemy->query_mhp();
      write(pad(" ("+stats+"\%)",8));
      }
      else write(pad(" ",23));
      write("  ");
      write(room->short());
      write("\n");
    }
  }
  return 1;
}
cmd_obit() {
  tail("/log/DEATHS");
  return 1;
}
