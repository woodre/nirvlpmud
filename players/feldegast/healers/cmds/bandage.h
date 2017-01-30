int do_bandage(string str)
{
  object target;
  int amt;
  int cost;
  if(!str) target=TP;
  else target=present(str,environment(TP));

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
  if(amt > 20) amt = 20;

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
    target->add_hit_point(amt);
  else
    target->heal_self(amt);

  if(target!=TP) {
    write("You bandage "+target->query_name()+"'s wounds and add a subtle\n"+
          "touch of order.\n");
    say(TPN+" bandages "+target->query_name()+"'s wounds.\n");
  }
  else {
    write("You bandage your wounds and add a touch of order.\n");
    say(TPN+" bandages "+TP->query_possessive()+" own wounds.\n");
  }
  return 1;
}
         
