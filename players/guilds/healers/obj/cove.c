#define TO this_object()
#define ep environment(TO)
#define MAX 10

int time;
int rate;
object caster;

id(str) { return str == "cove_reg"; }

query_weight() { return 0; }
drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  rate = 0;
  time = 30;
  set_heart_beat(1);
}

set_base(int a) { if(rate < MAX) rate = MAX; else rate += a/6;
                   time = time + a;  }
set_caster(ob) { caster = ob; }

clear() {
 set_heart_beat(0);
 if(ep) tell_room(ep,"This room no longer increases healing rates.\n");
 destruct(this_object());
return 1; }

heart_beat() {
object who;
int h;
  if(!ep) { set_heart_beat(0); return 1; }
  if(rate > MAX) rate = MAX;
  who = all_inventory(ep);
  for(h=0;h<sizeof(who);h++) {
    if(query_ip_name(who[h])) { 
      if(who[h]->query_mhp() > who[h]->query_hp()  && who[h]->query_real_name() != "guest") {
        who[h]->heal_self(rate); 
        if(caster) { 
          if(who[h] != caster) caster->add_xp(rate*2); 
        } 
      }
    }
  }
  if(time) time = time - 1;
  else clear();
}

query_save_flag() { return 1; }
