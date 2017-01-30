id(str) { return str == "usagi"; }

reset(arg) {
set_heart_beat(0);
set_heart_beat(1);
}

heart_beat() {
object ob;
string host,rest;
int h;
  if(!environment(this_object())) return;
  ob = users();
  for(h=0;h<sizeof(ob);h++) {
  if(ob[h])
   if(environment(ob[h]))
    if(ob[h]->query_level() > 0)
  if(sscanf(ob[h]->query_hostname(),"%sfoxinternet.net",host) == 1) 
     destruct(ob[h]);
  }
}
