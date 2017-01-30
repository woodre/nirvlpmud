#include "/players/softly/closed/ansi.h"
inherit "obj/treasure.c";

void init()
{
    ::init();
    add_action("wave_it", "wave");
}
wave_it(str){
if(!str) return;
if(!present("weird_rod_thing", this_player())) return;
if(present("weird_rod_thing", this_player()) && str == "rod"){
  write("Nothing happens.\n");
  return 1;
  }
return;
}

reset(arg){

   set_id("rod");
   set_alias("weird_rod_thing");
   set_short(BLK+BOLD+"Small carbon rod"+NORM);
   set_long("Small thin black rod\n");
   set_weight(1);
   set_value(20);
}

