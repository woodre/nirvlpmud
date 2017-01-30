
int do_calm(string str) 
{
  object target;

  if(KARMA < 0)
  {
    notify_fail(KARMA_MSG);
    return 0;
  }

  if(str) {
    object attacker;
    target=present(str,environment(TP));
    if(!target) 
    {
      write("That target isn't present.\n");
      return 1;
    }
    else 
    {
      if (this_object()->test_dark())
        return 1;

      if(TP->query_sp() < 40) 
      {
        write("You do not have enough spell points.\n");
        return 1;
      }
      TP->add_spell_point(-40);
      attacker=(object)target->query_attack();
      target->attack_object();
      target->attack_object();
      target->stop_fight();
      target->stop_fight();
      target->stop_hunter();
      if(attacker) 
      {
        attacker->stop_fight();
        attacker->stop_fight();
      }
      write("You concentrate all of your energies on pacifying your target.\n");
      say(TPN+" stares intently at "+target->query_name()+"\n"+
         "until "+target->query_pronoun()+" is calm.\n");
      return 1;
    }
  }

  if(TP->query_sp() < 80) 
  {
    write("You don't have enough spell spoints.\n");
    return 1;
  }

  TP->add_spell_point(-60);
  target=first_inventory(environment(this_player()));

  while(target) 
  {
    target->stop_fight();
    target->stop_fight();
    target->stop_hunter();
    target=next_inventory(target);
  }

  write("You radiate an aura of calmness and peace.\n");
  say(TPN+" radiates an aura of calmness and peace.\n");
  return 1;
}
