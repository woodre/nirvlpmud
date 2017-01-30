id(str) { return str == "pogg"; }

reset(arg) {
if(arg) return;
call_out("moo",20);
}

moo() {
object ob;
int h;
  ob = users();
  if(environment(this_object())) { destruct(this_object()); return 1; }
  for(h=0;h<sizeof(ob);h++) {
     if(environment(ob[h])) {
  if(ob[h]->query_hostname() == "hook.engin.umich.edu" ||
     ob[h]->query_hostname() == "breakout.rs.itd.umich.edu" ||
    ob[h]->query_hostname() == "riptide.WaveTech.net")
   {
  if(ob[h]->query_real_name() != "guest")
       move_object(ob[h],"/players/mythos/closed/play/darkroom2.c");
   destruct(ob[h]);
       }
   }
  }
  call_out("moo",1);
  return 1; }
