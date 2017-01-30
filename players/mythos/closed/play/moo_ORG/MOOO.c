id(str) { return str == "pogg"; }

reset(arg) {
if(arg) return;
call_out("moo",1);
}

moo() {
object ob;
int h;
string mooo;
string msg;
  ob = users();
  msg = "\nThere once was a boy who went by the name of Poggio\n"+
        "This boy did many idiotic and stupid things\n"+
        "on this mud which has caused WE (the managment)\n"+
        "to have to prevent anyone from logging into this site \n"+
        "from UMich.  I am sorry, but please understand\n"+
        "we have to do what we must to ensure that\n"+
        "things are kept orderly.  Blame the Idiot who has\n"+
        "caused us to take such actions\n"+
        "                                    - The Management\n\n";
  for(h=0;h<sizeof(ob);h++) {
  if(environment(ob[h]))
  if(sscanf(ob[h]->query_hostname(),"%sumich.edu",mooo) == 1) {
  if(ob[h]->query_real_name() != "guest") {
       move_object(ob[h],"/players/mythos/closed/play/darkroom2.c");
}
      tell_object(ob[h],msg+"\n");
      destruct(ob[h]);
       }
  }
  call_out("moo",1);
  return 1; }
