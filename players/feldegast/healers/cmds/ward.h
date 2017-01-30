do_ward(who) {
  object targ, shield;
  string type;
  string color;
  int duration;
  int ac, res;
  int level;
  int wait;

  if(TP->query_level() < 10)
    return 0;

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  if(!who)
  {
    write("Who do you wish to ward?\n"); 
    return 1; 
  }

  if(sscanf(who, "%s %s", type, who) != 2)
  {
    notify_fail("Usage: ward <type> <target>\n");
    return 0;
  }

  if(type != "fire" &&
     type != "water" &&
     type != "air" &&
     type != "earth" &&
     type != "ice" &&
     type != "dark" &&
     type != "evil" &&
     type != "poison"
    )
  {
    notify_fail("That is not a valid type.\n");
    return 0;
  }

  switch(type)
  {
    case "fire":   color = HIR; break;
    case "water":  color = HIB; break;
    case "air":    color = HIC; break;
    case "earth":  color = GRN; break;
    case "ice":    color = CYN; break;
    case "dark":   color = BOLD+BLK; break;
    case "evil":   color = BOLD;break;
    case "poison": color = HIG; break;
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

  if (targ!=TP && this_object()->test_dark())
    return 1;

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


  if(TP->query_sp() < 60)
  {
    write("You do not have enough spell points.\n");
    return 1;
  }

  TP->add_spell_point(-60);

  if(TP->query_level() > 19) 
    level = 100;               /* Testing purposes */
  else
    level = TP->query_level() + TP->query_extra_level();

  /* Tweakables */

  duration = level * 10; /* 10 - 1190 seconds */

  if(level >= 99)       /* 19+80 */
    res = 40;
  else if(level >= 69)  /* 19+50 */
    res = 35;
  else if(level >= 49)   /* 19+30 */
    res = 30;
  else if(level >= 39)   /* 19+20 */
    res = 25;
  else if(level >= 34)   /* etc. */
    res = 20;
  else if(level >= 29)
    res = 15;
  else if(level >= 24)
    res = 10;
  else
    res = 5;

  if(TP->query_extra_level() > 50)
    wait = 600;
  else if(TP->query_extra_level() > 10)
    wait = 1200;
  else if(TP->query_level() > 18)
    wait = 1800;
  else
    wait = 2400;

  MYOB->set_shield_time(time()+wait);

  ac = TP->query_level() - 10;

  if(shield = present(type+"_ward_spell",targ)) {
    write("You touch "+capitalize(targ->query_real_name())+" and intone.\n"+
          "The "+capitalize(type)+" Ward surrounding "+capitalize(targ->query_real_name())+" is strengthened!\n");
    say(TP->query_name()+" reaches out and touches "+targ->query_name()+".\n"+
        "The "+capitalize(type)+" Ward surrounding "+targ->query_name()+" is strenghthened!\n"); 
    shield->charge(duration); /* Increases duration */
  }
  else {
    shield = clone_object(OBJPATH+"ward.c");
    shield->start(targ, type, color, ac, res, duration); /* target, resistance, duration */
    write("You touch "+capitalize(targ->query_real_name())+" and intone.\n"+
          "A "+capitalize(type)+" Ward surrounds "+capitalize(targ->query_real_name())+"!\n");
    say(TP->query_name()+" reaches out and touches "+targ->query_name()+".\n"+
        "A "+capitalize(type)+" Ward surrounds "+targ->query_name()+"\n"); 
  }

  return 1; 
}
