int do_vita(string str)
{
  object target;
  int amt;
  int cost;
  if(!str) target=TP;
  else target=present(str, environment(TP));

  if((int)MYOB->query_casting())
  {
    write("You have not yet recovered from casting your previous spell.\n");
    return 1;
  }

  if(!target)
  {
    notify_fail("That person isn't here.\n");
    return 0;
  }

  if(target->query_invis())
  {
    write("That person is not here!\n"); 
    return 1; 
  }

  if(target->query_ghost())
  {
    write("You can not cast upon a ghost!\n"); 
    return 1; 
  }

  amt = (int)target->query_mhp() - (int)target->query_hp();
  if(amt > 50) amt = 50;

  if(amt <= 0)
  {
    write((string)target->query_name()+" is not injured.\n");
    return 1;
  }

  cost = 3*amt/4;

  if(!living(target) || present("prevent_healing", target))
  {
    write("That cannot be healed.\n");
  }

  if((int)TP->query_sp() < cost)
  {
    write("You do not have enough energy to cast that spell.\n");
    return 1;
  }

  MYOB->set_casting(1);
  MYOB->add_karma(amt);

  if(target->is_player())
    target->add_hit_point(amt/2);
  else
    target->heal_self(amt/2);

  write("You reach out with your order-sense and try to remove the chaotic\n"+
        "lines from "+target->query_name()+"'s body.\n");
  if(target!=TP) tell_object(target, TPN+" touches you with healing hands.\n");
  say(TPN+" heals "+(string)target->query_name()+".\n", ({ TP, target }));
  call_out("vita_heal", 1+random(3), ({ target, amt }) );

  return 1;
}

/*
Arg0 = target
Arg1 = amount
*/

void vita_heal(mixed *args)
{
  if(args[0])
  {
    args[0]->add_hit_point(args[1]);
    tell_object(args[0], "Your injuries start to knit together.  You feel much better.\n");
  }
}


