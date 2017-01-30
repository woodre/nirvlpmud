spell_failure(int x){
  int level, sts, val;
  if(guild_exp >= 8000000) return 1;
  return 1;  /* Changed on 6.19.02 at Maledicta's recommendation - no more. */
  if(USER->query_attack() && USER->query_attack()->is_player()) return 1;

  if(guild_exp < 2000000)
    level = 4;
  else if(guild_exp < 4000000)
    level = 3;
  else if(guild_exp < 6000000)
    level = 2;
  else if(guild_exp < 8000000)
    level = 1;

  if(!x)
    x = 1;

  sts = (int)USER->query_attrib("pie") +
        (int)USER->query_attrib("wil") +
        (int)USER->query_attrib("int") + 20;

  if(sts < 45) /* Below this things can get nasty */
    sts = 45;

  if(random((int)USER->query_attrib("luc")) > 18)
    sts += 2;

  if(level >= random(sts))
  {
    write(RED+"\n\t\tYour spell fails!\n\n"+NORM);
    if(x == 1)
    {
      USER->add_hit_point(-5-random(30));
      USER->add_spell_point(-15-random(30));
    }
    else if(x == 2)
    {
      USER->add_hit_point(-15-random(35));
      USER->add_spell_point(-20-random(35));
    }
    else if(x == 3)
    {
      USER->add_hit_point(-15-random(50));
      USER->add_spell_point(-35-random(-60));
    }
    else if(x == 4)
      return 0;
    energy_check();
    return 0;
  }
  return 1;
}

