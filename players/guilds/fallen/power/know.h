

chk(b,c){
  if(c == 0)
    return "Unknown";
  else if((b * 100 / c) > 80)
    return "Great";
  else if((b * 100 / c) > 60)
    return "Good";
  else if((b * 100 / c) > 40)
    return "Okay";
  else if((b * 100 / c) > 20)
    return "Bad";
  else if((b * 100 / c) <= 20)
    return "Awful";
}

know(str){
  object a, *area;
  int c,d,e,f;
  if(User->query_ghost()) return 0;
  if(!GOB->query_skills("know")) return 0;
  if(GOB->light_check()) return 1;
  if(!str) return 0;
  e = -1; /* players */
  f = 0; /* living creatures */
  a = find_player(str);
  if(!a)
  {
    TOU "There is no "+str+" logged on.\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(a->query_level() > 20 && a->query_invis()) return 0;
  if(a->query_level() > 20 && User->query_level() < 21)
  {
    TOU "You are unable to focus on "+a->query_name()+" for some reason.\n");
    return 1;
  }
  if(!GOB->spell_failure(1)) return 1;
  if(GOB->casting_check()) return 1;
  TOU
    "You close your eyes and focus on "+a->query_name()+"...\n\n"+
    pad("\tHealth: ", 15)+chk(a->query_hp(),a->query_mhp())+"\n"+
    pad("\tMana: ", 15)+chk(a->query_spell_point(),a->query_msp())+"\n");
  if(environment(a))
  {
    if(a->query_invis() && a->query_level() >= User->query_level())
      TOU pad("\tLocation: ", 15)+"Unknown\n");
    else
      TOU pad("\tLocation: ", 15)+environment(a)->short()+"\n");
  }
  if(a->query_attack())
	TOU pad("\tOpponent: ", 15)+a->query_attack()->query_name()+"\n");

  area = all_inventory(environment(a));
  d = sizeof(area);
  for(c = 0; c < d; c++)
  {
    if(area[c]->is_player())
      e++;
    else if((area[c]->is_npc() || area[c]->is_pet()) && !area[c]->is_player())
      f++;
  }

  if(e || f)
    TOU "\n");
  if(e)
  {
    if(e == 1)
      TOU "\tThere is "+e+" other player in the room.\n");
    else
      TOU "\tThere are "+e+" other players in the room.\n");
  }
  if(f)
  {
    if(f == 1)
      TOU "\tThere is "+f+" other living thing in the room.\n");
    else
      TOU "\tThere are "+f+" other living things in the room.\n");
  }
  TOU "\n");

  TRU User->QN+" closes "+User->query_possessive()+" eyes for a moment.\n",
    ({User}));

  User->add_spell_point(-15);
  User->add_hit_ppoint(-2);
  GOB->add_endurance(-(1+random(2)));
  GOB->energy_check();
  return 1;
}
