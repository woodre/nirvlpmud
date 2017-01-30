#define TO this_object()
#define ep environment(TO)
#define MAX 10

int time;
int rate;
object caster;

id(str) { return str == "heal_reg"; }

drop() { return 1; }
get() { return 0; }

reset(arg) {
  if(arg) return;
  rate = 0;
  time = 15;
  set_heart_beat(1);
}

set_base(int a) {  if(rate < MAX) { time = time + a; rate += a/6; } 
                   else { rate = MAX; time = time + a; } }
set_caster(ob) { caster = ob; }

clear() {
 set_heart_beat(0);
 if(ep) tell_object(ep,"You stop regenerating\n");
 destruct(this_object());
return 1; }

heart_beat() {
  if(!ep) { set_heart_beat(0); return 1; }
  if(ep->query_ghost()) { clear(); return 1; }
  if(rate > MAX) rate = MAX;
  ep->heal_self(rate);
  if(ep->query_hp() < ep->query_mhp()) {
    if(time) time = time - 1;
    else clear(); 
  } else clear();
}

query_save_flag() { return 1; }
