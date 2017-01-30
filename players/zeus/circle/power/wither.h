
wither_spell(string str) {
  object corpse, corpse2;
  string xx;
  int bonus, a; 
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("wither corpse")) return 0;
  if(PO->light_check()) return 1;
  if(!str) return 0;
  if(str != "corpse") return 0;
  corpse = present("corpse", environment(User));
  corpse2 = present("corpse", environment(PO));  
  if(!corpse && !corpse2){
	TOU"There is no corpse present.\n");
    return 1;
  }
  if(!PO->spell_failure(4)) return 1;
  if(PO->casting_check()) return 1;
  a = random(3);
  TOU "You wave your hand...\n");
  switch(a)
  {
  case 0:
    TOU "Shadows rise from the ground, pouring into the corpse.\n"+
      "As it withers away the shadows fill you with power.\n");
    break;
  case 1:
    TOU "Shadows descend upon the corpse, wrapping around it.\n"+
      "As it withers away the shadows feed you its power.\n");
    break;
  case 2:
    TOU "Shadows feed upon the remaining power of the corpse.\n"+
      "As it withers away you are rejuvenated by the shadows.\n");
    break;
  }
  a = random(4);
  switch(a)
  {
  case 0:
    TRU User->QN+" waves a hand...\n"+
      "Shadows rise from the ground, pouring into the corpse.\n", ({User}));
    break;
  case 1:
    TRU User->QN+" beckons shadows to pour into the corpse.\n", ({User}));
    break;
  case 2:
    TRU User->QN+" causes shadows to engulf the corpse.\n", ({ User }));
    break;
  case 3:
    TRU User->QN+" summons shadows which wither the corpse away.\n",
      ({ User }));
    break;
  }
  if((int)PO->query_guild_exp() < 1000000)
    bonus = 4;
  else if((int)PO->query_guild_exp() < 2000000)
    bonus = 3;
  else if((int)PO->query_guild_exp() < 4000000)
    bonus = 2;
  else if((int)PO->query_guild_exp() < 6000000)
    bonus = 1;
  else
    bonus = 0; 
  if(!corpse2) 
  {
    if(sscanf(file_name(corpse),"obj/corpse%s", xx) != 1) return 1;
    User->add_spell_point((int)corpse->query_corpse_level() * 2 + bonus);
    destruct(corpse);
  }
  else
  {
    if(sscanf(file_name(corpse2),"obj/corpse%s", xx) != 1) return 1;
    User->add_spell_point((int)corpse2->query_corpse_level() * 2 + bonus);
    destruct(corpse2);
  }
  PO->add_endurance(-1);
  return 1;
}
