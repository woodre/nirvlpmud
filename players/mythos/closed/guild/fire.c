#include "/players/mythos/closed/guild/def.h"
id(str) { return str == "fire" || str =="pillar" || str == "flame"; }

get() { return 0; }
drop() { return 1; }

short() { return HIR+"A Great Pillar of Fire"+NORM; }

reset(arg) {
  if(arg) return;
  set_light(8);
  call_out("burn",10);
}

long() {
  write("Before you is an awesome sight.\n"+
        "A raging tower of spiraling flame roars upward.\n");
  if(present("instrument",tp)) 
  write("You shiver despite the heat as you ponder upon what could\n"+
        "have brought this horrendous symbol of destruction.\n"+
        "As you turn away from the painful fire you hear a whisper\n"+
        "reverberate within your soul: As long as the knowledge lives\n"+
        "all is not lost, knowledge can be found where lore has been preserved.\n");
  else if(present(fear,tp)) 
  write("");
  else write("You can only tremble at the thought of what could have\n"+
             "brought about THIS.");
}

burn() {
object he;
int h;
if(!ep) { destruct(this_object()); return 1; }
he = 0;
he = all_inventory(ep);
if(he)
for(h=0;h<sizeof(he);h++) {
  if(living(he[h])) {
     he[h]->heal_self(-2);
     tell_object(he[h],"The searing heat burns you....\n");
   }
}
call_out("burn",8);
return 1; }

init() {
  add_action("open_gate","open");
}

open(str) {
  if(!str) return 0;
  if(str == "portal") {
    write("A great force pulls at you and you fall into the flame......\n");
    move_object(tp,"/players/mythos/closed/guild/talisman.c");
  }
}
