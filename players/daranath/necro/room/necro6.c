#include "../defs.h"
inherit ROOM;

reset(int arg){
  if(!arg){
    is_pk = 1;
    set_light(1);
    short_desc= "Necromancer Donation";
    long_desc="  "+
   "A small chamber white the same white marble walls as the rest of the\n"+
   "Necromancer Stronghold, this room is primarily used as a donation\n"+
   "area. Necromancers can leave unused or extra equipment for their\n"+
   "brothers and sisters.\n";

    items=({
     "room","The room has the same white marble walls as the guild",
     "walls","The white marble is covered with blood stains",
     "wall","The white marble is covered with blood stains",
     "marble","Expensive white marble makes up the guild hall",
    });

    dest_dir=({
      PATH+"/room/necro3.c","north",
      PATH+"/room/necro1.c","west",
    });

    }
}

init(){
  ::init();
  add_action("search","search");
}

search(){
  write("Bits of bone and areas of dried blood are all about the room.\n");
  say(tpn +" searches the area.\n");
  return 1;
}

