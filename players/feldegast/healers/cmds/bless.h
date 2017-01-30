do_bless(str)
{
  object shad;
  object targ;
  string shrt;
  int wait;

  if(!str)
  {
    notify_fail("Bless what?\n");
    return 0;
  }

  if (this_object()->test_dark())
    return 1;

  if(TP->query_level() < 19 || TP->query_extra_level() < 5)
    return 0;

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  targ = present(str, TP);
  if(!targ) targ = present(str, environment(TP));

  if(!targ)
  {
    notify_fail("There is no "+str+" here.\n");
    return 0;
  }

  if(targ->is_armor())
    shad = clone_object(OBJPATH+"arm_bonus.c");
  else if(targ->weapon_class())
    shad = clone_object(OBJPATH+"wep_bonus.c");

  if(!shad)
  {
    notify_fail("You cannot bless that.\n");
    return 0;
  }

  if((int)TP->query_sp() < 80)
  {
    write("You do not have enough energy.\n");
    return 1;
  }

  if(MYOB->query_time() > time())
  {
    notify_fail("You can not cast this spell yet.\n");
    return 0;
  }

  shrt = targ->short();
  if(!shad->start_shadow(targ))
  {
    write("You can not bless that.\n");
    return 1;
  }

  write("You instill "+shrt+" with order.\n");
  say(TPN+" blesses "+shrt+".\n");
  TP->add_spell_point(-80);
  if(TP->query_extra_level() > 50)
    wait = 600;
  else if(TP->query_extra_level() > 10)
    wait = 1200;
  else if(TP->query_level() > 18)
    wait = 1800;
  else
    wait = 2400;

  MYOB->set_time(time()+wait);
  return 1;

    
}
