/*  User can't drop below 15 sps, will auto move hp to sp  
*/
energy_check(){
  int ouch, sps;
  object test;
  if((string)environment(USER)->realm() == "NM") return;
  if(USER->query_sp() < 15-random(18) && !USER->query_ghost() && 
    USER->query_level() < 21)
  {
    if(random((int)USER->query_attrib("luc")) < 18)
    {
      tell_object(USER,
        BOLD+BLK+"\n\tShadows explode from your drained body...\n"+
        NORM+RED+"\tStrength is sacrificed for Power!\n\n"+NORM);
      tell_room(environment(USER), BOLD+BLK+
        "\n\tShadows explode from "+USER->QN+"!\n\n"+NORM, ({USER}));
      if(endurance <= 0)
        USER->add_spell_point(-5);
      sps = (int)USER->query_spell_point();
      if(sps >= 0)
        ouch = 15 - sps;
      else if(sps < 0)
        ouch = (sps * -1) + 15;
      if(((int)USER->query_hp() - (ouch * 5)) < 0)
      {
        command("upistrfrsfdpfor", USER);
        test = clone_object("/obj/monster.c");
        test->set_name(BOLD+BLK+"The Shadows"+NORM);
        USER->stop_fight();
        USER->stop_fight();
        USER->attacked_by(test);
        USER->add_hit_point(-350);
        USER->hit_player(666);
        USER->add_spell_point(ouch);
        return;
      }
      else
      {
        USER->add_hit_point(-(ouch * 5));
        USER->add_spell_point(ouch);
      }
    }
  }
  else if(USER->query_level() >= 21)
    USER->heal_self(1000);
  else if(endurance <= 0)
    USER->add_spell_point(-5);  /* spells cost more when no endurance */
}

upistrfrsf(){
  if(USER->query_level() > 21)
    return 0;
  write_file("/players/zeus/circle/log/death1",
  ctime(time())+" - "+USER->QN+"  "+USER->query_level()+
  "+"+USER->query_extra_level()+" "+guild_exp+" ["+
  USER->query_hp()+" "+USER->query_spell_point()+
  "] "+beats+"\n");
/*
  USER->add_hit_point(-350);
commented out for concern of abuse.  stupid wizards (kazer?) can't fucking mind their own business */
  return 1;
}

