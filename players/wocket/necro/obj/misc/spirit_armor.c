#include "../../defs.h"
inherit "/obj/armor.c";

id(str){ return (str == "spirits" || str == "spirit_armor"); }
get(){ return 0; }
drop(){ return 1; }
query_type(){ return "spirit_armor"; }

extra_look(){
  write(BOLD+"Spirits fly and wail around "+environment()->query_name()+OFF);
}

call_armor_special(){
object necro;
string msg;
  necro = environment(to);
  switch(random(10)){
    case 0:  msg = "Spirits from the dead rise up to help catch the attack from your enemy.\n"; break;
    case 1:  msg = "spirit block.\n"; break;
    case 2:  msg = "spirit block.\n"; break;
    case 3:  msg = "spirit block.\n"; break;
    case 4..7: msg = "blocked by spirits.\n"; break;
    case 8..9: msg = ""; break;
    default: msg = ""; break;
  } 
  tell_room(environment(necro),msg);
  return (necro->query_guild_rank()+random(necro->query_guild_rank()));
}

init() {
  ::init();
  if(ep)
  if(tp == ep) {
     command("wear spirits",ep);
	call_out("wipe",1000);
  return 1;
  } 
}

wipe() {
  if(!ep) return 1; 
tell_object(ep,"\nWraithform runs its course and you return to your solid form.\n\n");
  command(ep,"remove spirits");
  destruct(this_object());
return 1; }

