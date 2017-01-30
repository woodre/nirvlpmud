int do_cure(string str) {
  object target;
  object disease;
  int flag;

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  if(!str)
    target=this_player();
  else
    target=present(str,environment(TP));

  if(!target) 
  {
    write("Usage: cure <player>\n");
    return 1;
  }

  if (target != TP && (int)this_object()->test_dark())
    return 1;

  if(TP->query_sp() < 80) 
  {
    write("You don't have enough spell points.\n");
    return 1;
  }

  /* The wonderful world of short-circuited conditional statements... */

  while( (disease=present("poison", target)) || 
         (disease=present("scorptox",target)) ||
         (disease=present("toadtox", target)) ||
         (disease=present("hcl"   , target)) ||
         (disease=present("toxin" , target)) ||
         (disease=present("toxin2", target)) ||
         (disease=present("hcl", target   )) )
  {
    destruct(disease);
    flag = 1;
  }

  if(!flag)
  {
    write("If "+(string)target->query_name()+" is ill, you do not know how to cure "+(string)target->query_objective()+".\n");
    return 1;
  }

  MYOB->add_karma(40);
  TP->add_sp(-80);
  write("Sensing a malignant presence in "+
  (target==TP?"your":(target->query_name()+"'s"))+
  " body, you extend your\norder sense to expell any lingering toxins.\n");
  if(target != TP) tell_object(target, TPN+" cures you.\n");
  tell_room(environment(), TPN+" cures "+(string)target->query_name()+".\n", ({ TP, target }));
  return 1;
}
