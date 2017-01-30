#include "/players/mythos/myth/healer/def.h"
int percent;
string type;
int amount;
id(str) { return str == "regen_ob" || str == "mregen" || str == "reg_"+type; }

query_weight() { return 0; }
drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  type = "both";
  percent = 60;
  amount = 0;
  set_heart_beat(1);
}

set_percent(int n) { percent = n; }
set_type(str) { type = str; }
set_amount(int n) { if(n<1)  n = 1; amount = n; }
query_amount() { return amount; }

clear() {
 set_heart_beat(0);
 if(ep) tell_object(ep,"Regeneration is complete.\n");
 destruct(this_object());
return 1; }

heart_beat() {
int ehp,esp,mhp,msp;
int psp,php,ok;
  if(!ep) { set_heart_beat(0); return 1; }
  if(ep->query_ghost()) { clear(); return 1; }
  ehp = esp = mhp = msp = ok = 0;
  php = psp = 100;
  if(type == "both" || type == "hp") { 
     ehp = ep->query_hp(); mhp = ep->query_mhp(); php = ehp*100/mhp;
  } 
  if(type == "both" || type == "sp") {
     esp = ep->query_sp(); msp = ep->query_msp(); psp = esp*100/msp;
  }
  if(percent > php) { ep->add_hit_point(amount); ok = 1; }
  if(percent > psp) { ep->add_spell_point(amount); ok = 1; }
  if(!ok) clear();
  else if(!random(2)) tell_object(ep,"You feel a little better.\n");
}