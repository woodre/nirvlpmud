#include "/players/feldegast/defines.h"

inherit ROOM;

reset(arg) {
  if(arg) return;
  set_short("Traproom");
  set_long("Jagged spikes protroud from the walls of this room, and odd holes\n"+
           "in a grid pattern dot the floor and ceiling.\n");
  set_light(1);
  dest_dir=({
    "/players/feldegast/closed/tower/towersub1.c","west",
  });
}
init() {
  ::init();
  call_out("call_trap",3,this_player());
}
void call_trap(object targ) {
  if(environment(targ)!=this_object()) return 0;
  tell_object(targ,random(2)?"A gout of flame rises up out of the floor, singing you.\n"
                                   :"A rusty spike shoots out of the ceiling and gores you viciously.\n");
  targ->do_damage(({ random(20)+1 }), ({ "other|fire" }));
  call_out("call_trap",5+random(5),targ);
}
