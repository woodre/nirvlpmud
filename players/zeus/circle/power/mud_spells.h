/*  damage based on gxp [with a couple level checks], 
    cost based on level [w/ gxp caps]    */


int ms_damage(){
  int dmg;
  if(guild_exp < 100000)
    dmg = random(20);
  else if(guild_exp < 200000)
    dmg = 1 + random(22);
  else if(guild_exp < 300000)
    dmg = 2 + random(24);
  else if(guild_exp < 400000)
    dmg = 3 + random(27);
  else if(guild_exp < 700000)
    dmg = 4 + random(30);
  else if(guild_exp < 1000000)
    dmg = 5 + random(33);
  else if(guild_exp < 1300000)
    dmg = 6 + random(33);
  else /* if(guild_exp < 1600000) */
    dmg = 8 + random(33);
  if(guild_exp < 2000000 && guild_exp > 1600000 && USER->query_level() > 15)
    dmg = 10 + random(33);
  else if(guild_exp >= 2000000 && USER->query_extra_level() >= 5)
    dmg = 12 + random(33);  /* sonic damage */
  return dmg;
}

int ms_cost(){
  int cost;
  if(USER->query_level() < 7 && guild_exp < 100000)
    cost = 5;
  else if(USER->query_level() < 10 && guild_exp < 200000)
    cost = 10;
  else if(USER->query_level() < 15 && guild_exp < 400000)
    cost = 15;
  else if(USER->query_extra_level() < 5 && guild_exp < 1500000)
    cost = 20;
  else
    cost = 25;
  return cost;
}

static mud_spell(str){
  object nmy, ogob;
  int dmg, cost, free, temp, sps;
  if(USER->query_ghost()) return 0;
  if(light_check()) return 1;
  if(USER->query_spell_dam()) return 1;
  if(str) nmy = present(str, environment(USER));
  if(!nmy) nmy = USER->query_attack();
  if(!nmy)
  {
    tell_object(USER,"What do you want to attack?\n");
    return 1;
  }
  if(!living(nmy))
  {
    tell_object(USER,"You can't attack "+str+"!\n");
    return 1;
  }
  else if(!present(nmy, environment(USER)))
  {
    tell_object(USER,"What do you want to attack?\n");
    return 1;
  }
  if(nmy->is_player() && !nmy->query_pl_k() && !nmy->check_fight_area())
  {
    tell_object(USER,"You can't attack "+str+"!\n");
    return 1;
  }
  if(!random(4)){  if(!spell_failure(1)) return 1; }
  if(casting_check()) return 1;
  temp = 0; 
  free = 0;
  sps = (int)USER->query_spell_point();
  dmg = ms_damage();
  cost = ms_cost();
  if(sps < cost)  /* temp sps given if not enough */
  {
    if(sps < 0)
      free = (-1 * sps) + cost;
    else if(sps > 0)
      free = cost;
    USER->add_spell_point(free);
    temp = 1;
  }
  if(USER->query_level() == 19)
    USER->add_hit_point(-2);
  else
    USER->add_hit_point(-1);
  dmg *= 90; dmg /= 100;
  USER->spell_object(nmy,"",dmg,0,msg1(nmy,dmg),"",msg2(nmy,dmg));
  USER->set_spell_dtype("other|dark");
  USER->add_spell_point(cost * -1);
  if(temp)       /*  temp sps taken away-  ouch */
  {
    USER->add_spell_point(-free);
    tell_object(USER,"\n");
  }
  if(nmy && nmy->is_player() && nmy->query_guild_name() == "fallen" &&
    random(2) && present(nmy, environment(USER)))
  {
    if(ogob = present("circle_object", nmy))
    {
      tell_room(environment(USER), BOLD+BLK+"\nShadows explode from "+
        USER->query_name()+" and "+nmy->query_name()+"!\n\n"+NORM);
      temp = 1 + guild_exp / 300000;
      USER->add_hit_point(-temp);
      endurance -= (max_endurance / 8);
      temp = 1 + (ogob->query_guild_exp() / 300000);
      nmy->add_hit_point(-temp);
      ogob->add_endurance(-(ogob->query_max_endurance() / 8));
    }
  }
  if(focus && 0 == random(4) && guild_exp < 2000000)
    add_focus(1,1);
  else if(focus && 0 == random(4))
    add_focus(random(3),0);
  add_endurance(-1);
  energy_check();
  return 1;
}

msg1(object nmy, int dmg){
  int y;
  string x, msg1;
  x = nmy->query_name();
  if(!random(4))
  {
    y = random(18);
    switch(y){
    case 0:
      msg1 = "Shadows swirl around you.\n";
      break;
    case 1:
      msg1 = "Shadows pour over you.\n";
      break;
    case 2:
      msg1 = "Shadows rise up from the ground.\n";
      break;
    case 3:
      msg1 = "Shadows encircle your body.\n";
      break;
    case 4:
      msg1 = "Beams of light cascade over your body.\n";
      break;
    case 5:
      msg1 = "Beams of light seem to twist over you.\n";
      break;
    case 6:
      msg1 = "Beams of light flow around you.\n";
      break;
    case 7:
      msg1 = "Swirls of darkness flow over you.\n";
      break;
    case 8:
      msg1 = "Swirls of darkness merge with the light.\n";
      break;
    case 9:
      msg1 = "Swirls of darkness dance across your body.\n";
      break;
    case 10:
      msg1 = "You bathe in the shadows.\n";
      break;
    case 11:
      msg1 = "You draw strength from the shadows.\n";
      break;
    case 12:
      msg1 = "You draw strength from the light and darkness.\n";
      break;
    case 13:
      msg1 = "You writhe in the power of the shadows.\n";
      break;
    case 14:
      msg1 = "You draw the shadows close to you.\n";
      break;
    case 15:
      msg1 = "You beckon the shadows to draw near.\n";
      break;
    case 16:
      msg1 = "You draw power from the shadows.\n";
      break;
    case 17:
      msg1 = "You feel one with the shadows.\n";
      break;
    }
  }
  if(dmg < 5 && msg1)
    msg1 += "You cast a shadow spell at "+x+".\n";
  else if(dmg < 5)
    msg1 = "You cast a shadow spell at "+x+".\n";
  else if(dmg < 7 && msg1)
    msg1 += "You lash shadows into "+x+".\n";
  else if(dmg < 7)
    msg1 = "You lash shadows into "+x+".\n";
  else if(dmg < 10 && msg1)
    msg1 += "You cast a bolt of shadow magic at "+x+".\n";
  else if(dmg < 10)
    msg1 = "You cast a bolt of shadow magic at "+x+".\n";
  else if(dmg < 13 && msg1)
    msg1 += "You summon the shadows against "+x+".\n";
  else if(dmg < 13)
    msg1 = "You summon the shadows against "+x+".\n";
  else if(dmg < 16 && msg1)
    msg1 += "You call the shadows to whip into "+x+".\n";
  else if(dmg < 16)
    msg1 = "You call the shadows to whip into "+x+".\n";
  else if(dmg < 18 && msg1)
    msg1 += "You channel the shadows into "+x+".\n";
  else if(dmg < 18)
    msg1 = "You channel the shadows into "+x+".\n";
  else if(dmg < 20 && msg1)
    msg1 += "You command the shadows to descend upon "+x+".\n";
  else if(dmg < 20)
    msg1 = "You command the shadows to descend upon "+x+".\n";
  else if(dmg < 22 && msg1)
    msg1 += "You summon shadows which rise up and weaken "+x+".\n";
  else if(dmg < 22)
    msg1 = "You summon shadows which rise up and weaken "+x+".\n";
  else if(dmg < 24 && msg1)
    msg1 += "You cause the shadows to rip through "+x+".\n";
  else if(dmg < 24)
    msg1 = "You cause the shadows to rip through "+x+".\n";
  else if(dmg < 26 && msg1)
    msg1 += "Shadows explode from your body, tearing into "+x+".\n";
  else if(dmg < 26)
    msg1 = "Shadows explode from your body, tearing into "+x+".\n";
  else if(dmg < 29 && msg1)
    msg1 += "You beckon the shadows to destroy "+x+".\n";
  else if(dmg < 29)
    msg1 = "You beckon the shadows to destroy "+x+".\n";
  else if(dmg < 33 && msg1)
    msg1 += "You call forth the shadows to obliterate "+x+"!\n";
  else if(dmg < 33)
    msg1 = "You call forth the shadows to obliterate "+x+"!\n";
  else if(dmg < 36 && msg1)
    msg1 += "You summon shadows which rip into "+x+"!\n";
  else if(dmg < 36)
    msg1 = "You summon shadows which rip into "+x+"!\n";
  else if(msg1)
    msg1 += x+" is torn apart by the shadows!\n";
  else
    msg1 = x+" is torn apart by the shadows!\n";
  if(dmg < 20)
    return msg1+NORM;
  else if(dmg >= 20 && dmg < 29)
    return HIW+msg1+NORM;
  else if(dmg >= 29)
    return BOLD+BLK+msg1+NORM;
}

msg2(object nmy, int dmg){
  string x, msg2, nm, nm2;
  x = nmy->query_name();
  nm2 = (string)NAME;
  nm = capitalize(nm2);
  if(dmg < 5)
    msg2 = nm+" casts a shadow spell at "+x+".\n";
  else if(dmg < 7)
    msg2 = nm+" lashes shadows into "+x+".\n";
  else if(dmg < 10)
    msg2 = nm+" casts a bolt of shadow magic at "+x+".\n";
  else if(dmg < 13)
    msg2 = nm+" summons the shadows against "+x+".\n";
  else if(dmg < 16)
    msg2 = nm+" calls the shadows to whip into "+x+".\n";
  else if(dmg < 18)
    msg2 = nm+" channels the shadows into "+x+".\n";
  else if(dmg < 20)
    msg2 = nm+" commands the shadows to descend upon "+x+".\n";
  else if(dmg < 22)
    msg2 = HIW+nm+" summons shadows which rise up and weaken "+x+".\n";
  else if(dmg < 24)
    msg2 = HIW+nm+" causes the shadows to rip through "+x+".\n";
  else if(dmg < 26)
    msg2 = HIW+"Shadows explode from "+nm+"'s body, tearing into "+x+".\n";
  else if(dmg < 29)
    msg2 = HIW+nm+" beckons the shadows to destroy "+x+".\n";
  else if(dmg < 33)
    msg2 = BOLD+BLK+nm+" calls forth the shadows to obliterate "+x+"!\n";
  else if(dmg < 36)
    msg2 = BOLD+BLK+nm+" summons shadows which rip into "+x+"!\n";
  else
    msg2 = BOLD+BLK+x+" is torn apart by the shadows!\n";
  return msg2+NORM;
}
