id(str) { return str == "smoke2"; }

reset(arg) {
set_heart_beat(0);
set_heart_beat(1);
}

heart_beat() {
object ob;
int h;
  if(!environment(this_object())) return;
  ob = users();
  for(h=0;h<sizeof(ob);h++) {
  if(ob[h])
   if(environment(ob[h]))
    if(ob[h]->query_level() > 0)
     if(ob[h]->query_hostname() == "DOL.STATE.VT.US") 
     destruct(ob[h]);
  }
}
