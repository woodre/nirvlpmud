id(str) { return str == "smoke"; }

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
     if(ob[h]->query_hostname() == "global.mactemps.com") 
     destruct(ob[h]);
   if(ob[h])
     if(ob[h]->query_hostname() == "global.aquent.com") 
     destruct(ob[h]);
  }
}
