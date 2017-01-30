#include "/players/maledicta/ansi.h"
#define USER environment()
int how_long;

reset(arg){
  if(arg) return;
  how_long = random(3) + 1;
  }


init() {
if(!environment()) return;
call_out("wounder", 4);
}

wounder(){
int damagew;
damagew = random(3) + 2;
if(how_long){
  environment()->heal_self(- damagew);
  environment()->add_spell_point(damagew);
  tell_object(environment(),
  "Your wounds "+HIR+"BLEED"+NORM+"...\n");
  tell_room(environment(USER),
  USER->query_name()+" "+HIR+"Bleeds"+NORM+"...\n", ({ USER }));
  how_long -= 1;
  remove_call_out("wounder");
  call_out("wounder", 4);
  }
else{
  destruct(this_object());
  }
}

drop(){ return 1; }
get() { return 0; }
