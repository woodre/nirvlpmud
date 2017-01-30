
emergency(){
  string q;
  object x;
  int a;
  if(!environment(environment(previous_object()))) return 0;
  q = "I'm in trouble and could use some help!\n    ";
  q += CHAN_DAEMON->print(environment(previous_object()), "mon", 4);
  q += "\n    - I'm at "+environment(environment(previous_object()))->short();
  if(x = environment(previous_object())->query_attack())
  {
    a = (x->query_hp() * 10) / x->query_mhp();
    q += " fighting "+x->short()+" ["+a+"/10].";
  }
  else q += ".";
  CHAN_DAEMON->print(environment(previous_object()), q, 1);
  return 1;
}
