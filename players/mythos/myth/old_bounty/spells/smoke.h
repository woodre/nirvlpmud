smoke() {
string msg,msg2;
object ob;
  if(tsp < 25) { write("You do not have enough sp.\n"); return 1; }
  if(formtype == "tech") { 
    msg = "\n";
    msg2 = "\n";
  }
  else {
    msg = "\n";
    msg2 = "\n";
  }
  ob = clone_object("/players/mythos/bounty/spells/smoke.c");
  tp->add_weight(ob->query_weight());
  move_object(ob,tp);
  write(msg);
  say(msg2);
  tp->add_spell_point(-25);
return 1; }
