id(str) { return str == "pogg"; }

reset(arg) {
if(arg) return;
call_out("moo",1);
}

moo() {
object ob;
int h;
string mooo;
  ob = users();
  for(h=0;h<sizeof(ob);h++) {
    if(sscanf(ob[h]->query_hostname(),"%sengin.umich.edu",mooo) == 1) {
       move_object(ob[h],"/players/mythos/closed/play/darkroom2.c");
      ob[h]->save_me();
      destruct(ob[h]);
       }
  }
  call_out("moo",1);
  return 1; }
