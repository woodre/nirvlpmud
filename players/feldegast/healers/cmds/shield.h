do_shield(who) {
  object targ, shield;
  int duration;
  int protection;
  int wait;

  if(TP->query_level() < 19)
    return 0;

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  if(!who)
  {
    write("Who do you wish to shield?\n"); 
    return 1; 
  }

  if(MYOB->query_shield_time() > time())
  {
    notify_fail("You can not cast this spell yet.\n");
    return 0;
  }


  if(!(targ=present(who,environment(TP))))
  {
    write("That person is not here!\n");
    return 1; 
  }

  if(!living(targ)) 
  {
    write("You may only cast this upon something living.\n"); 
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

  if (targ!=TP && this_object()->test_dark())
    return 1;
  
  if(TP->query_sp() < 50)
  {
    write("You do not have enough spell points.\n");
    return 1;
  }

  TP->add_spell_point(-50);

  if(TP->query_extra_level() > 50)
    wait = 180;
  else if(TP->query_extra_level() > 10)
    wait = 240;
  else if(TP->query_level() > 18)
    wait = 300;
  else
    wait = 360;

  MYOB->set_shield_time(time()+wait);

  duration = 2 * TP->query_level() + ( TP->query_extra_level() / 2 );
  protection = TP->query_attrib("wil") / 4 + 1;     /* Adjust this as needed. */

  if(shield = present("shield_spell",targ)) {
    write("You touch "+capitalize(targ->query_real_name())+" and concentrate.\n"+
          "The Shield of Light surrounding "+capitalize(targ->query_real_name())+" is strengthened!\n");
    say(TP->query_name()+" reaches out and touches "+targ->query_name()+".\n"+
        "The Shield of Light surrounding "+targ->query_name()+" is strengthened!\n"); 
    shield->charge(duration); /* Increases duration */
  }
  else {
    shield = clone_object(OBJPATH+"shield.c");
    shield->start(targ, protection, duration); /* target, resistance, duration */
    write("You touch "+capitalize(targ->query_real_name())+" and intone.\n"+
          "A Shield of Light surrounds "+capitalize(targ->query_real_name())+"!\n");
    say(TP->query_name()+" reaches out and touches "+targ->query_name()+".\n"+
        "A Shield of Light surrounds "+targ->query_name()+"\n"); 
  }

  return 1; 
}
