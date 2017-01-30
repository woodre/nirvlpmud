/* dmg 5 - 125.   cost 90-140  */

shadowrage(str)
{
  object nmy, comp;
  int x,y,z,intel, pie, wil, ste;
  if(User->query_ghost()) return 0;
  if(!PO->query_skills("rage")) return 0;
  if(PO->light_check()) return 1;
  if(!str && User->query_attack())
    nmy = User->query_attack();
  else if(str)
    nmy = present(str, environment(User));
  else if(!str && !User->query_attack())
    return 0;
  if(!nmy)
  {
    TOU"You don't see "+str+" here.\n");
    return 1;
  }
  if(!living(nmy))
  {
    TOU"You cannot attack "+str+"!\n");
    return 1;
  }
  if(!nmy->is_npc())
  {
    TOU"You cannot attack "+str+"!\n");
    return 1;
  }
  if(environment(User)->realm() == "NM")
  {
    TOU"Your power is being drained here.\n");
    return 1;
  }
  if(PO->query_rage()) return 1;
  comp = present("guild_comp_pouch", environment(previous_object()));
  if(!comp)
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!comp->query_liquid())
  {
    TOU"You lack the spell component to cast this spell.\n");
    return 1;
  }
  if(!PO->spell_failure(3)) return 1;
  if(PO->casting_check()) return 1;

  intel = (int)User->query_attrib("int") / 20;
  pie = (int)User->query_attrib("pie") / 20;
  wil = (int)User->query_attrib("wil") / 20;
  ste = (int)User->query_attrib("ste") / 10;
  
/*
// [2005.12.09] Forbin
//   -Changed the following so the spell isn't so random
//   -As it stood, the player was just better off casting shadowblast
//    and saving the component/spell point/endurance cost from this
//
//  x = 1+random(intel+pie+wil+ste);
//
*/
  
  switch(random(10))
  {
    case 0:    x = 1+intel+pie+wil+ste;	  	  
    case 1..2: x = 1+intel+pie+wil+random(ste);	  
    case 3..4: x = 1+intel+pie+random(wil+ste);	  
    case 5..6: x = 1+intel+random(pie+wil+ste);	  
    case 7..9: x = 1+random(intel+pie+wil+ste);	  
  }
  
  TOU"You smear the black liquid on your hands...\n"+
    "Shadows pour around your hands as you RAGE!\n\n");
  for(y=0; y<x; y++)
  {
    z = random(11);
    switch(z)
    {
    case 0:
      TOU BOLD+BLK+"\tYou pummel "+nmy->QN+" with shadows!\n"+NORM);
      break;
    case 1:
      TOU BOLD+BLK+"\tShadows explode from you into "+nmy->QN+"!\n"+NORM);
      break;
    case 2:
      TOU BOLD+BLK+"\tYou pound "+nmy->QN+" as the shadows flare!\n"+NORM);
      break;
    case 3:
      TOU BOLD+BLK+"\tShadows lash into "+nmy->QN+"!\n"+NORM);
      break;
    case 4:
      TOU BOLD+BLK+
        "\tShadows encircle "+nmy->QN+", choking "+nmy->OBJ+"!\n"+NORM);
      break;
    case 5:
      TOU BOLD+BLK+"\t"+nmy->QN+" struggles against the shadows!\n"+NORM);
      break;
    case 6:
      TOU BOLD+BLK+"\tYour hands explode with shadows!\n"+NORM);
      break;
    case 7:
      TOU BOLD+BLK+"\tYou whip the shadows into "+nmy->QN+"!\n"+NORM);
      break;
    case 8:
      TOU BOLD+BLK+"\tYou strike "+nmy->QN+" with fists of shadows!\n"+NORM);
      break;
    case 9:
      TOU BOLD+BLK+"\tYou burn with shadow energy!\n"+NORM);
      break;
    case 10:
      TOU BOLD+BLK+"\t"+nmy->QN+" is obliterated by the shadows!\n"+NORM);
      break;
    }
  }
  TOU"\n");
  TRU BOLD+BLK+"\nAs shadows encircle "+User->QN+"'s fists, "+User->PRO+
    " RAGES on "+nmy->QN+"!\n\n"+NORM, ({User}));
  nmy->heal_self(-random(x * 25)-(x * 5));
  User->add_spell_point(-90-(random(50)) + (PO->query_guild_exp() / 400000));
  if(nmy && nmy->query_attack() != User)
    nmy->attack_object(User);
  if(nmy && User->query_attack() != nmy)
    User->attack_object(nmy);
  comp->use_liquid();
  PO->set_rage(1);
  PO->add_endurance(-3);
  PO->energy_check();
  return 1;
}