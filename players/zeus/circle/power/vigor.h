
vigor(string str){
  int level;
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("vigor")) return 0;
  if(PO->light_check()) return 1;
  if(!str)
    level = 2;  /* defaults to medium */
  else if(str == "high" || str == "h")
    level = 3;
  else if(str == "medium" || str == "m")
    level = 2;
  else if(str == "low" || str == "l")
    level = 1;
  else return 0;

  if(!PO->spell_failure(2)) return 1;
  if(PO->casting_check()) return 1;

  if(PO->query_vigor())
    TOU HIW+"You beckon the shadows to reinvigorate you!\n"+NORM);
  else
  {
    TOU "You beckon the shadows to fill your body...\n"+
      HIW+"The shadows drive you to fight harder!\n"+NORM);
  }

  if(level == 3)
  {
    PO->set_vigor_level(3);  /* level of spell (3,2,1) */
    PO->set_vigor(8);        /* duration of spell in hbs */
    PO->set_vigor_bonus(26); /* weapon_class bonus each hb */
    PO->add_endurance(3);    /* initial endurance bonus - 36*/
  }
  else if(level == 2)
  {
    PO->set_vigor_level(2);  /* level of spell (3,2,1) */
    PO->set_vigor(14);       /* duration of spell in hbs */
    PO->set_vigor_bonus(18); /* weapon_class bonus each hb */
    PO->add_endurance(18);   /* initial endurance bonus - 27 */
  }
  else if(level == 1)
  {
    PO->set_vigor_level(1);  /* level of spell (3,2,1) */
    PO->set_vigor(20);       /* duration of spell in hbs */
    PO->set_vigor_bonus(14); /* weapon_class bonus each hb */
    PO->add_endurance(25);   /* initial endurance bonus - 18 */
  }

  TRU User->QN+" whispers a soft incantation.\n", ({User}));
  User->add_spell_point(-1 * (level * 20)); /* 60,40,20 */
  User->add_hit_point(-1 * (level * 10));   /* 30,20,10 */
  PO->energy_check();
  return 1;
}
