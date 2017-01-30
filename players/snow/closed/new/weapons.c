#include "../DEFS.h"
#include DEFS_WEAPONS


int findWeaponCost(int level, string wep) {
  /* requires art level */
  int cost;
  level = level * 1000;
  switch(wep) {
    case NUNCU: cost = level + COST_NUNCU; break;
    case NINJO: cost = level + COST_NINJO; break;
    case TONFA: cost = level + COST_TONFA; break;
    case NAGIA: cost = level + COST_NAGIA; break;
    case KUSAA: cost = level + COST_KUSAA; break;
    case UNARM: cost = COST_UNARM; break;
    default:    return -1;
  }
  return cost;
}


object findWeaponObject(string wep) {
  object wepob;
  switch(wep) {
  case NUNCU:
       wepob = clone_object(WEAPONDIR +"/"+  NUNCU + ".c");
       break;
  case NINJO:
       wepob = clone_object(WEAPONDIR +"/"+  NINJO + ".c");
       break;
  case TONFA:
       wepob = clone_object(WEAPONDIR +"/"+  TONFA + ".c");
       break;
  case KUSAA:
       wepob = clone_object(WEAPONDIR +"/"+  KUSAA + ".c");
       break;
  case NAGIA:
       wepob = clone_object(WEAPONDIR +"/"+  NAGIA + ".c");
       break;
  case UNARM:
       wepob = clone_object(WEAPONDIR +"/"+  UNARM + ".c");
       break;
  default:
       return 0;
  }
  return wepob;
}


status change_weapon(object ob, string str) {
  string currentwep;
  int level, xp, lowxp, freexp, temp;
  int old_cost, new_cost, diffcost, credits;
  if(findWeaponCost((int)IPOB->query_art_level(), str) < 0) {
    tell_object(ob, "No weapon called '"+str+"'.\n");
    return 0;
  }
  currentwep = (string)IPOB->query_weapon();
  if(currentwep == str) {
    tell_object(ob, "Weapon already set.\n");
    return 0;
  }
  if(!currentwep) {
    tell_object(ob, "No weapon to change from.\n");
    return 0;
  }
  old_cost = findWeaponCost((int)IPOB->query_art_level(), currentwep);
  new_cost = findWeaponCost((int)IPOB->query_art_level(), str);
  diffcost = new_cost - old_cost;
  diffcost += WEPCHANGE_CREDITS; /* extra handling fee */
  credits = (int)IPOB->balance();
  level   = (int)IPOB->guild_lev();
  xp      = (int)IPOB->guild_exp();
  lowxp   = (int)IPOB->low_exp(level);
  freexp  = xp - lowxp;
  if(freexp < WEPCHANGE_XP) {
    temp = WEPCHANGE_XP - freexp;
    tell_object(ob, "Insufficient free guild xp: "+temp+" short.\n");
    return 0;
  }
  if(diffcost > credits) {
    temp = diffcost - credits;
    tell_object(ob, "Insufficient credits: @"+temp+" short.\n");
    return 0;
  }
  if(diffcost < 0) {
    tell_object(ob, "@"+(-diffcost)+" refund associated "+
      "with weapon switch.\n");
  }
  write_file(LOGDIR + "/WEAPONRY", 
    ORN+" changed from "+currentwep+" to "+str+". ("+ctime()+")\n");
  tell_object(ob, "Weapon switched from '"+
                  currentwep+"' to '"+str+"'.\n");
  say(OPN+" changes weapons.\n");
  IPOB->set_weapon(str);
  IPOB->addToBalance(-diffcost);
  IPOB->add_xp(-WEPCHANGE_XP);
  IPOB->save_me();
  move_object(IPOB, ob); /* force init */
  return 1;
}


status select_weapon(object ob, string str) {
  int credits, cost, temp;
  string currentwep;
  if(findWeaponCost((int)IPOB->query_art_level(), str) < 0) {
    tell_object(ob, "No weapon called '"+str+"'.\n");
    return 0;
  }
  currentwep = (string)IPOB->query_weapon();
  credits    = (int)IPOB->balance();
  cost       = findWeaponCost((int)IPOB->query_art_level(), str);
  if(currentwep == str) {
    tell_object(ob, "Weapon already set.\n");
    return 0;
  }
  if(currentwep) {
    /* attempt to change weapons */
    if(!change_weapon(ob, str)) {
      tell_object(ob, "Unable to select/change weapon.\n");
      return 0;
    }
    /* weapon changed */
    return 1;
  }
  if(credits < cost) {
    temp = cost - credits;
    tell_object(ob, "Insufficient credits: @"+temp+" short.\n");
    return 0;
  }
  IPOB->set_weapon(str);
  IPOB->addToBalance(-cost);
  IPOB->save_me();
  write_file(LOGDIR + "/WEAPONRY", 
    ORN+" selected the "+str+" weapon. ("+ctime()+")\n");
  tell_object(ob, "Weapon '"+str+"' selected.\n");
  say(OPN+" has chosen to train in the "+str+".\n");
  return 1;
}


void list(object ob) {
  int level;
  level = (int)IPOB->query_art_level();
  tell_object(ob, 
  pad("WEAPONS",20) + "COST\n" +
  "_______________________________\n"+
  pad(NUNCU,20) + findWeaponCost(level, NUNCU) + "\n" +
  pad(NINJO,20) + findWeaponCost(level, NINJO) + "\n" +
  pad(TONFA,20) + findWeaponCost(level, TONFA) + "\n" +
  pad(NAGIA,20) + findWeaponCost(level, NAGIA) + "\n" +
  pad(KUSAA,20) + findWeaponCost(level, KUSAA) + "\n" +
  pad(UNARM,20) + findWeaponCost(level, UNARM) + "\n" +
  "_______________________________\n");
}


void list_links(object ob) {
  tell_object(ob, 
  "<><><><><><><><><><><><><><><><><><><><><><>\n"+
  "<>Smartweapon Link current prices:\n"+
  "<>\n"+
  "<>First Link...............@"+WEPLINK_STARTUP+"\n"+
  "<>Subsequent Links ........@"+WEPLINK        +"\n"+
  "<>(Maximum of "+MAXLINKS+" Smartweapon Links)\n"+
  "<><><><><><><><><><><><><><><><><><><><><><>\n");
}


int buy_link(object ob) {
  int cost;
  if((int)IPOB->item_weplink() > 0)  cost = WEPLINK;
  if((int)IPOB->item_weplink() == 0) cost = WEPLINK_STARTUP;
  if(cost == 0) return 0;
  if((int)IPOB->item_weplink() >= MAXLINKS) {
    tell_object(ob, "Already at maximum weapon linkage.\n");
    return 0;
  }
  if((int)IPOB->balance() < cost) {
    tell_object(ob, "Insufficient credits.\n");
    return 0;
  }
  if(cost == WEPLINK_STARTUP) {
    tell_object(ob, "Weapon link granted\n");
    tell_object(ob, "The WeaponMaster inserts SmartWeapon mnemonic fibers up through\n"+
          "your hands and arms into your implants. It is slightly painful.\n");
    IPOB->addToBalance(-cost);
    IPOB->set_weplink(1);
    IPOB->save_me();
    move_object(IPOB, ob); /* force init */
    return 1;
  }
  if(cost == WEPLINK) {
    tell_object(ob, "Weapon link granted\n");
    tell_object(ob, "The WeaponMaster installs a booster link and fibers through your\n"+
          "muscles and skeletal structure.\n");
    IPOB->addToBalance(-cost);
    IPOB->add_weplink(1);
    IPOB->save_me();
    move_object(IPOB, ob); /* force init */
    return 2;
  }
  return 0;
}
