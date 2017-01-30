#include "/players/mythos/myth/healer/def.h"
object alt_at,main_at;
int time;
int percent;
string type;
id(str) { return str == "shielding" || str == "field"; }

short() { return "A glowing field of force"; }

query_weight() { return 0; }
drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  alt_at = main_at = 0;
  type = "all";
  percent = -1;
  time = 100;
  set_heart_beat(1);
}

set_type(str) { type = str; }
set_time(int n) { time = n; }
set_percent(int n) { percent = -n; }

clear() {
 set_heart_beat(0);
 if(ep) tell_object(ep,"The field vanishes.\n");
 destruct(this_object());
return 1; }

heart_beat() {
  if(!ep) { set_heart_beat(0); return 1; }
  if(ep->query_ghost()) { clear(); return 1; }
  if(att) main_at = att; 
  if(ep->query_alt_attacker()) alt_at = ep->query_alt_attacker();
  if(main_at) if(type != "all" && !main_at->id(type)) main_at = 0;
  if(alt_at) if(type != "all" && !alt_at->id(type)) alt_at = 0;
  if(main_at) {
    main_at->set_spell_dam(main_at->query_wc() * percent/10);
    main_at->spell_object(ep,"",main_at->query_wc() * percent/10,0,
            "The field absorbs some of your blow.\n",
            "The field absorbs some of the blow.\n",
            "There is a brilliant flash as the blow is deflected.\n");
    main_at = 0;
  }
  if(alt_at) {
    alt_at->set_spell_dam(alt_at->query_wc() * percent/10);
    alt_at->spell_object(ep,"",alt_at->query_wc() * percent/10,0,
            "The field absorbs some of your blow.\n",
            "The field absorbs some of the blow.\n",
            "There is a brilliant flash as the blow is deflected.\n");
    alt_at = 0;
  } 
  if(time) time = time - 1;
  else clear();
}