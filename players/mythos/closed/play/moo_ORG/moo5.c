id(str) { return str == "pogg"; }

reset(arg) {
if(arg) return;
call_out("moo",1);
}

moo() {
object ob;
int h;
  ob = users();
  for(h=0;h<sizeof(ob);h++) {
   if(ob[h]->query_hostname() == "qbert.rs.itd.umich.edu") {
       move_object(ob[h],"/players/mythos/closed/play/darkroom2.c");
       }
  }
  call_out("moo",1);
  return 1; }
