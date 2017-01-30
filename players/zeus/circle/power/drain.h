
drain_spell(string str){
  int guild_bonus, val, gxp;
  object item;
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("drain")) return 0;
  if(PO->light_check()) return 1;
  if(!str) return 0;
  item = present(str, User);
  if(!item) return 0;
  if(item->drop())
  {
    TOU"You can't drain this item!\n");
    return 1;
  }
  if(item->query_weight() > 15)
  { 
    write("You can't drain this item!\n"); 
    return 1; 
  }
  if(item->id("nodrain"))
  {
    TOU"You can't drain this item!\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(!PO->spell_failure(4)) return 1;
  if(PO->casting_check()) return 1;
  gxp = (int)PO->query_guild_exp();
  if((string)item->query_info() == "csw")
  {
    int a,b;
    TOU
     "As you drain the energy from the "+str+" you are overcome with\n"+
     "power.  Shadows swirl over your body as you unleash the energy.\n"+
     "You absorb the power of your shadow weapon and feel much better.\n");
    TRU User->query_name()+" wraps the "+str+" in a shadow.\n"+
      "Shadows swirl all around "+User->query_name()+"!\n", ({User}));
    User->add_spell_point(500);
    a = PO->query_endurance();
    b = PO->query_max_endurance();
    PO->add_endurance(b-a);
    destruct(item);
    User->recalc_carry();
    return 1;
  }
  if(item->query_value() < (50+random(150)))
  {
    TOU "The "+str+" crumbles away in your hands.\n");
    destruct(item);
    User->recalc_carry();
    return 1;
  }
  if(item->query_value() >= 1000)
    val = item->query_value() / 30;
  else
    val = 0;
  if(val > 50)
    val = 50;
  if(PO->query_guild_exp() >= 8000000)
    guild_bonus = 40;
  else if(!PO->query_guild_exp() <= 0)
    guild_bonus = (int)PO->query_guild_exp() / 200000;
  else
      guild_bonus = 0;
  if(gxp < 650000)
    PO->add_endurance(3);
  else if(gxp < 1000000)
    PO->add_endurance(2);
  else if(gxp < 1500000)
    PO->add_endurance(1);
  PO->add_endurance(val / 5);
  TOU "You wrap the "+str+" in a shadow, draining its energy.\n");
  TRU User->query_name()+" wraps the "+str+" in a shadow.\n", ({User}));
  User->add_spell_point(random(val) + random(guild_bonus) + 5);
  destruct(item);
  User->recalc_carry();
  return 1;
}
