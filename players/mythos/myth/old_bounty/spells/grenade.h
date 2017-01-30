grenade(int n) {
string msg,msg2;
object ob;
int lev;
  if(!n) { write("Usage: grenade <setting>\n"+
                 "setting:  1 - 10 [1 = minimum, 10 = maximum] or\n"+
                 "          69 for poison\n");
             return 1; }
  lev = n;
  if(n != 69) {
  lev = bb->query_level() * lev / 10;
  if(tsp < 2*lev) { write("You do not have that much sp.\n"); return 1; } }
  else if(tsp < 50) { write("You do not have that much sp.\n"); return 1; }
  if(formtype == "tech") { 
    msg = "\n";
    msg2 = "\n";
  }
  else {
    msg = "\n";
    msg2 = "\n";
  }
  ob = clone_object("/players/mythos/bounty/spells/grenade.c");
  ob->set_form(formtype);
  ob->set_level(lev);  /* 1 - 20 or 69 for poison*/
  tp->add_weight(ob->query_weight());
  move_object(ob,tp);
  write(msg);
  say(msg2);
  tp->add_spell_point(-2*lev);
return 1; }
