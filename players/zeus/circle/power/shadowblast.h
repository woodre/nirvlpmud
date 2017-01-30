
shadowblast(str){
  object target, ogob;
  int damage, cost, lvl, dmgx, temp, free, sps, stats;
  string msg1, msg2, msg3, wn, his, him;

  if(!PO->query_skills("blast")) return 0;
  if(User->query_ghost()) return 0;
  if(PO->light_check()) return 1;
  if(!str && User->query_attack())
    target = User->query_attack();
  else if(str)
    target = present(str, environment(User));
  else if(!str && !User->query_attack())
    return 0;
  if(!target){
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(!living(target)){
    TOU"You cannot attack "+str+"!\n");
    return 1;
  }
  else if(!present(target, environment(User)))
  {
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(target->is_player() && !target->query_pl_k() && 
    !target->check_fight_area())
  {
    TOU"You cannot attack "+str+"!\n");
    return 1;
  }
  if(!random(3)){  if(!PO->spell_failure(2)) return 1; }
  if(PO->casting_check()) return 1;

  if(User->query_spell_dam()){
    if(!random(6))
      TOU"Shadows dance across your body.\n");
    else if(!random(5))
      TOU"Shadows flit around you.\n");
    else if(!random(4))
      TOU"Shadows play around your body.\n");
    else if(!random(3))
      TOU"Dark shadows flow over you.\n");
    else if(!random(2))
      TOU"Dark shadows swirl around you.\n");
    else
      TOU"Dark shadows rise up around you.\n");
    return 1;
  }

  his = (string)User->query_possessive();
  him = (string)User->query_objective();
  wn = (string)User->query_weapon()->query_type();
  if(!wn)
    wn = (string)User->query_weapon()->query_name();

  lvl = ((int)User->query_level() / 2);
  dmgx = (int)PO->query_guild_exp() / 250000;
  temp = 0;
  sps = (int)User->query_spell_point();
  stats = (int)User->query_attrib("int")
        + (int)User->query_attrib("pie")
        + (int)User->query_attrib("wil");

  if(target->is_player() && dmgx > 14)  dmgx = 14;
  else if(dmgx > 32)     dmgx = 30;
  if(lvl > 9)            lvl = 9;
  if(stats > 60)         stats = 60;
  damage = lvl + 6 + random((stats / 5) + 4 + dmgx);
  if(damage > 56)        damage = 56;
  if(damage <= 20)       cost = 10;
  else if(damage <= 25)  cost = 15;
  else if(damage <= 30)  cost = 20;
  else if(damage <= 35)  cost = 25;
  else                   cost = 30;
  if(!random(8))         cost += random(6);

  if(sps < cost){  /* temp sps given if not enough */
    if(sps < 0)
      free = (-1 * sps) + cost;
    else if(sps > 0)
      free = cost;
    User->add_spell_point(free);
    temp = 1;
  }

  if(damage < 8){
    msg1 = "You blast "+target->QN+" with shadows...\n";
/*    msg2 = "A shadow blast hits you.\n"; */
    msg3 = User->QN+" casts a shadow blast at "+target->QN+".\n";
  }
  else if(damage < 16){
    msg1 = "You summon shadows to blast "+target->QN+"...\n";
/*    msg2 = "A shadow blast hits you.\n"; */
    msg3 = User->QN+" casts a shadow blast at "+target->QN+".\n";
  }
  else if(damage < 24){
    if(PO == User->query_weapon())
    {
      msg1 = BOLD+WHT+"You summon the shadows around you...\n"+NORM+
        "\tYou shoot a shadow blast at "+target->QN+"...\n";
      msg3 = BOLD+WHT+User->QN+" summons the shadows around "+him+"...\n"+
        NORM+"\t"+User->QN+" casts a shadow blast at "+target->QN+".\n";
    }
    else
    {
      msg1 = BOLD+WHT+"You summon the shadows around you...\n"+NORM+
        "    You channel the shadows through your "+wn+"...\n"+
        "\tYou shoot a shadow blast at "+target->QN+"...\n";
      msg3 = BOLD+WHT+User->QN+" summons the shadows around "+him+"...\n"+
        NORM+
        "    "+User->QN+" channels the shadows through "+his+" "+wn+"...\n"+
        "\t"+User->QN+" casts a shadow blast at "+target->QN+".\n";
    }
/*    msg2 = "A shadow blast hits you.\n"; */
  }
  else if(damage < 27){
    if(PO == User->query_weapon())
    {
      msg1 = BOLD+WHT+"Shadows swirl around your fists...\n"+NORM+
        "\tYou pummel "+target->QN+" with the shadows...\n";
      msg3 = BOLD+WHT+"Shadows swirl around "+User->QN+"...\n"+NORM+
        "\t"+User->QN+" casts a shadow blast at "+target->QN+".\n";
    }
    else
    {
      msg1 = BOLD+WHT+"Shadows swirl around your "+wn+"...\n"+NORM+
        "    You channel the shadows through your "+wn+"...\n"+
        "\tYou pummel "+target->QN+" with the shadows...\n";
      msg3 = BOLD+WHT+"Shadows swirl around "+User->QN+"...\n"+NORM+
        "    "+User->QN+" channels the shadows through "+his+" "+wn+"...\n"+
        "\t"+User->QN+" casts a shadow blast at "+target->QN+".\n";
    }
/*    msg2 = "A shadow blast hits you.\n"; */
  }
  else if(damage < 30){
    if(PO == User->query_weapon())
    {
      msg1 = BOLD+WHT+"You summon the shadows around you...\n"+NORM+
        "\tYou unleash a violent shadow blast into "+target->QN+"...\n";
      msg3 = BOLD+WHT+User->QN+" summons the shadows around "+him+"...\n"+
        NORM+"\t"+User->QN+" casts a shadow blast at "+target->QN+".\n";
    }
    else
    {
      msg1 =  BOLD+WHT+"You summon the shadows around you...\n"+NORM+
        "    You channel the shadows through your "+wn+"...\n"+
        "\tYou unleash a violent shadow blast into "+target->QN+"...\n";
      msg3 = BOLD+WHT+User->QN+" summons the shadows around "+him+"...\n"+
        NORM+"    "+User->QN+" channels the shadows through "+his+" "+wn+
        "...\n"+
        "\t"+User->QN+" casts a shadow blast at "+target->QN+".\n";
    }
/*    msg2 = "A shadow blast hits you.\n"; */
  }
  else if(damage < 34){
    if(PO == User->query_weapon())
    {
      msg1 = BOLD+BLK+"The dark energy surges around you...\n"+NORM+
        "\tYou fire a blast of dark energy at "+target->QN+"...\n";
      msg3 = BOLD+BLK+"The dark energy surges around "+User->QN+"...\n"+NORM+
        "\t"+User->QN+" casts a blast of dark energy at "+target->QN+".\n";
    }
    else
    {
      msg1 = BOLD+BLK+"The dark energy surges around you...\n"+NORM+
        "    You channel the dark energy through your "+wn+"...\n"+
        "\tYou fire a blast of dark energy at "+target->QN+"...\n";
      msg3 = BOLD+BLK+"The dark energy surges around "+User->QN+"...\n"+NORM+
        "    "+User->QN+" channels the dark energy through "+his+" "+wn+
        "...\n"+
        "\t"+User->QN+" casts a blast of dark energy at "+target->QN+".\n";
    }
/*    msg2 = "A blast of dark energy hits you.\n"; */
  }
  else if(damage < 38){
    if(PO == User->query_weapon())
    {
      msg1 = BOLD+BLK+"Dark energy ripples over your body...\n"+NORM+
        "\tA funnel of dark energy flies out and strikes "+target->QN+"...\n";
      msg3 = BOLD+BLK+"Dark energy ripples over "+User->QN+"'s body...\n"+
        NORM+
        "\t"+User->QN+" casts a blast of dark energy at "+target->QN+".\n";
    }
    else
    {
      msg1 = BOLD+BLK+"Dark energy ripples over your body...\n"+NORM+
        "    You channel the dark energy through your "+wn+"...\n"+
        "\tA funnel of dark energy flies out and strikes "+target->QN+"...\n";
      msg3 = BOLD+BLK+"Dark energy ripples over "+User->QN+"'s body...\n"+
        NORM+"    "+User->QN+" channels the dark energy through "+his+" "+wn+
        "...\n"+
        "\t"+User->QN+" casts a blast of dark energy at "+target->QN+".\n";
    }
/*    msg2 = "A blast of dark energy hits you.\n"; */
  }
  else if(damage < 43){
    if(PO == User->query_weapon())
    {
      msg1 = BOLD+BLK+"You writhe in a cloud of dark energy...\n"+NORM+
        "\tA blast of dark energy surges from you into "+target->QN+"...\n";
      msg3 = BOLD+BLK+User->QN+" writhes in a cloud of dark energy...\n"+NORM+
        "\t"+User->QN+" casts a blast of dark energy at "+target->QN+".\n";
    }
    else
    {
      msg1 = BOLD+BLK+"You writhe in a cloud of dark energy...\n"+NORM+
        "    You channel the dark energy through your "+wn+"...\n"+
        "\tA blast of dark energy surges into "+target->QN+"...\n";
      msg3 = BOLD+BLK+User->QN+" writhes in a cloud of dark energy...\n"+NORM+
        "    "+User->QN+" channels the dark energy through "+his+" "+wn+
        "...\n"+
        "\t"+User->QN+" casts a blast of dark energy at "+target->QN+".\n";
    }
/*    msg2 = "A blast of dark energy hits you.\n"; */
  }
  else if(damage <= 47){
    if(PO == User->query_weapon())
    {
      msg1 = BOLD+BLK+"The dark energy pulses as it flows over you...\n"+NORM+
        "\tYou unleash a blast of dark energy at "+target->QN+"...\n";
      msg3 = BOLD+BLK+"The dark energy pulses as it flows over "+User->QN+
        "...\n"+NORM+
        "\t"+User->QN+" casts a blast of dark energy at "+target->QN+".\n";
    }
    else
    {
      msg1 = BOLD+BLK+"The dark energy pulses as it flows over you...\n"+NORM+
        "    You channel the dark energy through your "+wn+"...\n"+
        "\tYou unleash a blast of dark energy at "+target->QN+"...\n";
      msg3 = BOLD+BLK+"The dark energy pulses as it flows over "+User->QN+
        "...\n"+NORM+"    "+User->QN+" channels the dark energy through "+
        his+" "+wn+"...\n\t"+
        User->QN+" casts a blast of dark energy at "+target->QN+".\n";
    }
/*    msg2 = "A blast of dark energy hits you.\n"; */
  }
  else if(damage > 47){
    int q;
    q = random(4);
    switch(q)
    {
    case 0:
      if(PO == User->query_weapon())
      {
        msg1 = RED+"Flames of darkness dance across your body...\n"+NORM+
          "\tYou fire a blast of flaming darkness at "+target->QN+"...\n";
        msg3 = RED+"Flames of darkness dance across "+User->QN+"'s body...\n"+
          "\t"+NORM+User->QN+
          " casts a blast of dark flames at "+target->QN+".\n";
      }
      else
      {
        msg1 = RED+"Flames of darkness dance across your body...\n"+NORM+
          "    You channel the flames through your "+wn+"...\n"+
          "\tYou fire a blast of flaming darkness at "+target->QN+"...\n";
        msg3 = RED+"Flames of darkness dance across "+User->QN+"'s body...\n"+
          NORM+"    "+User->QN+" channels the flames through "+
          his+" "+wn+"...\n\t"+User->QN+
          " casts a blast of dark flames at "+target->QN+".\n";
      }
/*      msg2 = "A blast of dark flames engulfs you.\n"; */
      break;
    case 1:
      if(PO == User->query_weapon())
      {
        msg1 = RED+"Flames of darkness explode from your hands...\n"+NORM+
          "\tYou unleash a blast of flaming darkness at "+target->QN+"...\n";
        msg3 = RED+"Flames of darkness explode from "+User->QN+
          "'s hands...\n\t"+NORM+
          User->QN+" casts a blast of dark flames at "+target->QN+".\n";
      }
      else
      {
        msg1 = RED+"Flames of darkness explode from your hands...\n"+NORM+
          "    You channel the flames through your "+wn+"...\n"+
          "\tYou unleash a blast of flaming darkness at "+target->QN+"...\n";
        msg3 = RED+"Flames of darkness explode from "+User->QN+
          "'s hands...\n"+NORM+"    "+User->QN+
          " channels the flames through "+his+" "+wn+"...\n\t"+
          User->QN+" casts a blast of dark flames at "+target->QN+".\n";
      }
/*      msg2 = "A blast of dark flames hits you.\n"; */
      break;
    case 2:
      if(PO == User->query_weapon())
      {
        msg1 = RED+"You beckon as dark flames engulf you...\n"+NORM+
          "\tYou unleash a torrent of flames into "+target->QN+"...\n";
        msg3 = RED+User->QN+" beckons as dark flames engulf "+him+"...\n"+
          NORM+"\t"+
          User->QN+" casts a blast of dark flames at "+target->QN+".\n";
      }
      else
      {
        msg1 = RED+"You beckon as dark flames engulf you...\n"+NORM+
          "    You channel the flames through your "+wn+"...\n"+
          "\tYou unleash a torrent of flames into "+target->QN+"...\n";
        msg3 = RED+User->QN+" beckons as dark flames engulf "+him+"...\n"+
          NORM+"    "+User->QN+
          " channels the flames through "+his+" "+wn+"...\n\t"+
          User->QN+" casts a blast of dark flames at "+target->QN+".\n";
      }
/*      msg2 = "A blast of dark flames hits you.\n"; */
      break;
    case 3:
      if(PO == User->query_weapon())
      {
        msg1 = RED+"You focus your strength as flames swirl around you...\n"+
          NORM+"\tA gigantic blast of dark flames erupts around "+target->QN+
          "...\n";
        msg3 = RED+User->QN+" focuses "+his+
          " strength as flames swirl around "+him+"...\n\t"+NORM+
          User->QN+" engulfs "+target->QN+" in dark flames.\n";
      }
      else
      {
        msg1 = RED+"You focus your strength as flames swirl around you...\n"+
          NORM+"    You channel the flames through your "+wn+"...\n"+
          "\tA gigantic blast of dark flames erupts around "+target->QN+
          "...\n";
        msg3 = RED+User->QN+" focuses "+his+
          " strength as flames swirl around "+him+"...\n"+NORM+
          "    "+User->QN+
          " channels the flames through "+his+" "+wn+"...\n\t"+
          User->QN+" engulfs "+target->QN+" in dark flames.\n";
      }
/*      msg2 = "A blast of dark flames engulfs you.\n"; */
    break;
    }
  }
        
  damage *= 90; damage /= 100;
  User->spell_object(target, "blast", damage, 0, msg1, "", msg3);
  User->set_spell_dtype("other|dark");

  sps = (int)target->query_hp();  /*  finisher */
  if(sps < (target->query_mhp() / 15) && (sps < 50) && !random(2) &&
    PO->query_guild_exp() > 4000000 && !target->is_player())
  {
    User->add_spell_point(-10-random(6));    /* 10 to 15 sps */
    User->add_hit_point((sps / 2) * -1);     /* half enemy hp */
    target->hit_player(sps * 2);
  }
  User->add_spell_point(-cost);
  if(temp){  /*  temp sps taken away-  ouch */
    User->add_spell_point(-free);
    TOU"\n");
  }
  if(target && target->is_player() && target->query_guild_name() == "fallen"
    && random(2) && present(target, environment(User)))
  {
    if(ogob = present("circle_object", target))
    {
      tell_room(environment(User), BOLD+BLK+"\nShadows explode from "+
        User->query_name()+" and "+target->query_name()+"!\n\n"+NORM);
      temp = 1 + (PO->query_gxp() / 300000);
      User->add_hit_point(-temp);
      User->add_endurance(-(PO->query_max_endurance() / 8));
      temp = 1+ (ogob->query_guild_exp() / 300000);
      target->add_hit_point(-temp);
      ogob->add_endurance(-(ogob->query_max_endurance() / 8));
    }
  }
  if(PO->query_focus() && 0 == random(4))
    PO->add_focus(random(3),0);
  if(User->query_level() == 19)
    User->add_hit_point(-2);
  else
    User->add_hit_point(-1);
  PO->add_endurance(-(1+random(2)));
  PO->energy_check();
  return 1;
}
