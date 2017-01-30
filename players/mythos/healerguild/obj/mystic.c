#include "/players/mythos/healerguild/def.h"
string spl;
int lev, pie;

id(str) { return str == "light" || str == "globe"; }

short() { return "Globe of Light"; }

long() { 
         write("This is a globe containing the spell "+spl+".\n"+
               "To cast type "+spl+" <variables needed>\n");
       }
       
set_level(a) { lev = a; }
set_piety(a) { pie = a; }
set_spell(str) { spl = str; }

drop() { return 1; }
get() { return 0; }

init() {
  if(tp == ep) {
    add_action("cast",spl);
    call_out("fade",lev);
    set_light(1);
  }
}

cast(str) {
  if(!tp->query_ghost()) call_other(POWER,spl,lev,pie,str);
  write("The globe disappears. Spell: "+spl+"\n");
  destruct(TO);
return 1;}

fade() {
if(!ep) return 1;
  tell_object(ep,"The globe disappears. Spell: "+spl+"\n");
  destruct(TO);
return 1; }

query_save_flag() { return 1; }
