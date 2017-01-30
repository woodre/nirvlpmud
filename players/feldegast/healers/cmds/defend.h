do_defend(who) {
  object targ, shield;
  int amt;
  int wait;

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  if(MYOB->query_shield_time() > time())
  {
    notify_fail("You can not cast this spell yet.\n");
    return 0;
  }

  if(!who)
  {
    write("Who do you wish to defend?\n"); 
    return 1; 
  }

  if(!(targ=present(who,environment(TP)))) 
  {
    write("That person is not here!\n");
    return 1; 
  }

  if(!living(targ))
  {
    write("You may only cast upon something living.\n");
    return 1; 
  }

  if(!targ->is_player())
  {
    write("You may only cast this on players.\n");
    return 1;
  }

  if(targ->query_invis())
  {
    write("That person is not here!\n"); 
    return 1; 
  }

  if(targ->query_ghost())
  {
    write("You can not cast upon a ghost!\n"); 
    return 1; 
  }

  if (targ != TP && this_object()->test_dark())
    return 1;

  if(present("defend_spell", targ)) 
  {
    write("That person already has a defend spell!\n");
    return 1;
  }

  if(TP->query_sp() < 50)
  {
    write("You do not have enough energy to cast that spell.\n");
    return 1;
  }

  TP->add_spell_point(-50);

  if(TP->query_extra_level() > 50)
    wait = 20;
  else if(TP->query_extra_level() > 10)
    wait = 30;
  else if(TP->query_level() > 18)
    wait = 40;
  else
    wait = 60;

  MYOB->set_shield_time(time()+wait);

  if(TP->query_extra_level() > 50)
    amt = 4;
  else if(TP->query_extra_level() > 25)
    amt = 3;
  else if(TP->query_extra_level() > 5)
    amt = 2;
  else
    amt = 1;
  
  shield = clone_object(OBJPATH+"defend.c");
  shield->start(targ,amt);

  write("You touch "+targ->query_name()+" and concentrate.\n"+
        targ->query_name()+"'s armor class increases!\n");
  say(TP->query_name()+" reaches out and touches "+targ->query_name()+".\n"+
      "Light streams outward from "+TP->query_name()+"'s hand.\n"); 
  return 1; 
}

