#define ep environment(this_object())
#define DO destruct(this_object())
int time,level,mtime;

id(str) { return str == "poison" || str == "mbpoison"; }

query_save_flag() { return 1; }
drop() { return 1; }
get() { return 0; }

set_level(n) { level = n; }
add_time(n) { time += n; }
set_time(n) { time = n; mtime = time; }
query_time() { return time; }
query_mtime() { return mtime; }

reset(arg) {
  if(!arg) return;
  time = 666;
  mtime = 666;
  call_out("poison_beat",5);
}

init() {
  if(!living(ep)) DO;
  if(interactive(ep)) DO;
}

poison_beat() {
object ob;
int h;
if(!ep) { DO; return 1; }
if(!environment(ep)) { DO; return 1; }
if(time == 666) { time = 6+random(level); mtime = time; }
  ob = all_inventory(ep);
  for(h=0;h<sizeof(ob);h++) {
    if(ob[h] != this_object() && ob[h]->id("mbpoison")) {
      ob[h]->add_time(time);
      DO;
    return 1; }
  }
  if(time < 1) { DO; return 1; }
  tell_object(environment(ep),
    ep->query_name()+"'s face contorts in agony as poison spreads through "+
    ep->query_possessive()+" body.\n");
  ep->heal_self(-1 - random(level));
  time = time - 1;
  call_out("poison_beat",5);
return 1; }