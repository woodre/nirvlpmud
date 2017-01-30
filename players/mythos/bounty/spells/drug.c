#define ep environment(this_object())
#define DO destruct(this_object())
int time,level,mtime;
string type,msg;

id(str) { return str == "drug" || str == "mbdrug" || str == type ||
                 str == type+" mbdrug"; }

query_save_flag() { return 1; }
drop() { return 1; }
get() { return 0; }

set_level(n) { level = n; }
add_time(n) { time += n; }
set_time(n) { time = n; mtime = time; }
query_time() { return time; }
query_mtime() { return mtime; }
set_type(str) { if(str != "lsd" && str != &&) type = "lsd";
                else type = str; }
query_type() { return type; }

reset(arg) {
  if(!arg) return;
  time = 666;
  mtime = 666;
  type = "lsd";
  msg = allocate(3);
  call_out("drug_beat",5);
}

init() {
  if(!living(ep)) DO;
  if(interactive(ep)) DO;
}

drug_beat() {
object ob;
int h;
if(!ep) { DO; return 1; }
if(!environment(ep)) { DO; return 1; }
if(time == 666) { time = 6+random(level); mtime = time; }
  ob = all_inventory(ep);
  for(h=0;h<sizeof(ob);h++) {
    if(ob[h] != this_object() && ob[h]->id(type+" mbdrug")) {
      ob[h]->add_time(time);
      DO;
    return 1; }
  }
  if(time < 1) { DO; return 1; }
  drug_effect();
  call_out("poison_beat",5);
return 1; }

drug_effect() {
if(!msg[0]) drug_msg();
tell_object(environment(ep),msg[random(3)]+"\n");
}

drug_msg() {
switch(type) {
  case "lsd": msg[0] = ;
              msg[1] = ;
              msg[2] = ;
              break;
}}