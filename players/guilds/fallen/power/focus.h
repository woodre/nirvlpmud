
focus(){
  int gxp, val, dur, cost, f;
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("focus")) return 0;
  if(GOB->light_check()) return 1;
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
/*
  if(User->query_weapon())
  {
    if(User->query_weapon() != PO)
    {
      TOU"You may not focus the shadows while using a weapon.\n");
      return 1;
    }
  }
*/
  if(!GOB->spell_failure(1)) return 1;
  if(GOB->casting_check()) return 1;
  f = GOB->query_focus();
  if(f)
  {
    TOU BOLD+BLK+"You strengthen your focus of the shadows.\n"+NORM);
    TRU BOLD+BLK+User->QN+" strengthens "+User->POS+
      " focus of the shadows.\n"+NORM, ({User}));
  }
  else
  {
    TOU BOLD+BLK+"You focus the shadows around you.\n"+NORM);
    TRU BOLD+BLK+User->QN+" focuses the shadows around "+User->OBJ+".\n"+
  	  NORM, ({User}));
  }
  gxp = GOB->query_guild_exp();
  if(gxp < 200000)
  {
    if(User->query_level() < 14)
      cost = User->query_level() * -1;
    else
      cost = -14;
  }
  else if(gxp < 500000)
    cost = -15-random(6);
  else if(gxp < 2000000)
    cost = -15-random(10);
  else
    cost = -15-random(16);
  if(gxp < 800000)
    val = 7 + random(6);
  else
    val = 8 + (gxp / 800000);
  if(gxp < 1000000)
    dur = 5 + random(2);
  else
    dur = 5 + (gxp / 1000000);
  if(val > 18)
    val = 18;
  if(f)  /* if already focused */
  {
    if(0 == random(7) && gxp < 2000000)
      dur += 2;
    else if(0 == random(4))
      val += 2;
    else if(0 == random(8))
      User->add_spell_point(2);
    else if(0 == random(3) && gxp < 500000)
      GOB->add_endurance(3);
  }
  User->add_spell_point(cost);
  if(gxp < 500000)
    User->add_hit_point(-1);
  else if(gxp < 1500000)
    User->add_hit_point(val * -1 / 2);
  else
    User->add_hit_point(val * -1);

  if(gxp < 2000000 && User->query_attack())
  {
    if(User->query_attack()->query_attack() == User)
      val += 4;
  }

  GOB->set_focus(val,dur);
  GOB->energy_check();
  GOB->add_endurance(-1);
  return 1;
}
