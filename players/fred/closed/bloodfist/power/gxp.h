
gxp(str){
  int amt, free, cur, lvl, xlvl;
  lvl = User->query_level();
  xlvl = User->query_extra_level();
  cur = User->query_exp();

  return (notify_fail("This is not in use right now.\n"), 0);

  if(xlvl < 1 && lvl < 21)
    free = cur - call_other("room/adv_guild","get_next_exp", lvl - 1);
  else if(xlvl > 0 && lvl < 21)
    free = cur - call_other("room/exlv_guild","get_next_exp", xlvl - 1);
  else if(lvl >= 21)
    free = cur;  
  
  if(str == "all")
    amt = free;
  else if(!str || !sscanf(str, "%d", amt) == 1)
  {
    TOU "How much experience do you want to move into the guild?\n"+
      "You have "+free+" free experience and need "+
      PO->query_glevel_togo()+" for your next guild level.\n");
    return 1;
  }

  if(amt > free)
  {
    TOU "You don't have that much free experience to move into the guild.\n"+
      "That is "+(amt - free)+
      " more experience than you have free to move.\n");
    return 1;
  }

  if(amt < 0)
  {
    TOU "You can't move a a negative amount of experience into the guild.\n"+
      "You need "+PO->query_glevel_togo()+" for your next guild level.\n");
    return 1;
  }

  PO->add_gexp(amt);

  TOU "You move "+amt+" of your "+free+" free experience into the guild.\n"+
    "You now need "+PO->query_glevel_togo()+" for your next guild level.\n");

  User->add_exp(-amt);

  return 1;
}

