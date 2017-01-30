int do_gift(string str)
{
  object target;
  int amt;

  if(!str) {
    write("Usage: infuse <person>\n");
    return 1;
  }

  target=present(str,environment(TP));

  if((int)MYOB->query_casting())
  {
    write("You have not yet recovered from casting your previous spell.\n");
    return 1;
  }

  if(!target) {
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
  if(amt > 40) amt = 40;

  if(amt <= 0)
  {
    write((string)target->query_name()+" is not injured.\n");
    return 1;
  }

  if(!living(target) || present("prevent_healing", target))
  {
    write("That cannot be healed.\n");
  }

  if(TP->query_hp() < amt) 
  {
    write("You cannot give away life that you do not have.\n");
    return 1;
  }

  MYOB->set_casting(1);
  MYOB->add_karma(amt);

  if(target->is_player())
    target->add_hit_point(amt/2);
  else
    target->heal_self(amt/2);

  TP->add_hit_point(-amt);
  write("You give some of your own life and order to "+target->query_name()+".\n");
  say(TPN+" gives life to "+target->query_name()+".\n");
  call_out("gift_heal", 1+random(3), ({ target, amt }));
  return 1;
}

/* 
Arg0 = target 
Arg1 = amount
*/         
void gift_heal(mixed *args)
{
  if(args[0])
  {
    args[0]->add_hit_point(args[1]);
    tell_object(args[0], "You feel the life energy coursing through your veins.\n");
  }
}
