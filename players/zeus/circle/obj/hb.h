
heart_beat(){

  if(!environment())
    return ;
  if(!USER->is_player())
    return ;

  if(!random(3)) environment_check();   /* Check environ for other fallen */

  endurance_check();           /* See if you are fighting or not mostly */

  if(USER->test_dark())        /*  Lose sps when there is no light */
    USER->add_spell_point(-1);

  else if(0 == random(3))      /*  Higher mana regen in light rooms */
    USER->add_spell_point(2+random(guild_exp / 1600000));

  beats++;   /*  guild age */

  if(old_exp < 1) old_exp = USER->query_exp();   /* Deal with xp gain */
  if((guild_exp < 8000000) && (old_exp < USER->query_exp()) && percent > 0)
  {
    int gexp, val;
    gexp = USER->query_exp() - old_exp;
    val = (percent * gexp / 100);
    guild_exp += val;
    USER->add_exp(val * -1);
  }
  else if(guild_exp >= 8000000 && percent != 0)
    percent = 0;
  old_exp = USER->query_exp();

  combat = USER->query_attack();
  if(combat && environment(USER))
  {
  if(!present(combat, environment(USER)))
    combat = 0;
  }

  if(dark_ass)  /* Dark assistance spell- call func if cast while in combat */
  {
    if(combat && !USER->query_ghost())
      dark_assistance_spell();
    else if(!random(8))
    {
      dark_ass = 0;
      tell_object(USER, "You feel a dark presence leave you...\n");
    }
  }

  if(!USER->query_weapon())  /* Make sure USER always has something wielded */
  {
    wielded_by = USER;
    call_other(USER, "wield", this_object(), 1);
    wielded = 1;
  }

  if(duration)   /* Focus / Duration */
  {
    if(!combat)
      duration -= 2;
    else
      duration--;
    if(random((int)USER->query_ac()) == 0)
      USER->add_spell_point(1);
    if(duration <= 0)
    {
      duration = 0;
      tell_object(USER, BOLD+BLK+
        "You lose focus of the shadows.\n"+NORM);
      tell_room(environment(USER), BOLD+BLK+USER->QN+
        " loses focus of the shadows.\n"+NORM, ({ USER }));
      focus = 0;
    }
  }

  if(shadow_shield)   /*  When the shield spell is active */
  {
    if(!combat)
      shadow_shield -= 2;
    else
      shadow_shield--;
    if(shadow_shield <= 0)
    {
      tell_object(USER,
        BOLD+BLK+"Your shield of shadows dissipates...\n"+NORM);
      shadow_shield = 0;
    }
  }

  if(shadowcloak)   /* Mana drain if cloaked */
  {
    if(guild_exp > 5200000 && (random(guild_exp / 2600000) == 0))
      USER->add_spell_point(-1);
    USER->set_invs_sp();
  }

  if(rage)      /* Limit rage spell to one per hb */
    rage = 0;

  if(vigor)
  {
    if(combat)
    {
      endurance -= (vigor_level + 1);
      USER->add_spell_point(-1 * (vigor_level + 2));
      vigor--;
    }
    else
      vigor -= 2;
    if(vigor <= 0)
    {
      tell_object(USER,
        BOLD+BLK+"You feel drained as your vigor subsides...\n"+NORM);
      vigor_bonus = 0;
      vigor = 0;
      if(endurance > 3)
        endurance -= 3;
    }
  }

  if(casting)
  {
    endurance -=3;
    casting--;

    if(siphon && combat)  /* siphon energy */
    {
      c = (int)USER->query_hp();
      d = (int)USER->query_mhp();
      e = (int)USER->query_spell_point();
      f = (int)USER->query_msp();
      tell_object(USER, RED+"Shadow tendrils siphon energy from "+
        combat->short()+NORM+RED+" to you!\n"+NORM);
      tell_room(environment(USER), RED+"Shadow tendrils siphon energy from "+
        combat->short()+"!\n"+NORM, ({ USER }));
      if(present("zeus_siphon_stone", USER))
      {
        if((int)combat->query_hp() > 26)
          combat->hit_player((15 +
            present("zeus_siphon_stone", USER)->qzj()), "other|shadow");
        if(d && f &&  (((c * 100) / d) > ((e * 100) / f)))
          USER->add_spell_point(16 +
            (present("zeus_siphon_stone", USER)->qzj() / 2));
        else
          USER->add_hit_point(16 +
            (present("zeus_siphon_stone", USER)->qzj() / 2));
        endurance += (7 +
          (present("zeus_siphon_stone", USER)->qzj() / 3));
      }
    }
    else {
      combat = 0;
      casting = 0;
    }
    if(!casting && siphon)
    {
      tell_object(USER, BOLD+BLK+"\nYour siphon tendrils dissipate.\n"+NORM);
      siphon = 0;
    }
  }

}
