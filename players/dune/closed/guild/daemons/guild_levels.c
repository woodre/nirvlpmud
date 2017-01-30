#include "../DEFS.h"
#include DEFS_GLEVELS


string guild_title(int level) {
/* Returns guild title for guild level specified */
  string title;
  switch(level) {
    case     27:  return TITLE_MAX;
    case 24..26:  return TITLE_MD4;
    case 21..23:  return TITLE_MD4;
    case 18..20:  return TITLE_MD3;
    case 15..17:  return TITLE_MD3;
    case 12..14:  return TITLE_MD2;
    case 9..11:   return TITLE_MD2;
    case 6..8:    return TITLE_MD1;
    case 3..5:    return TITLE_MD1;
    case 0..2:    return TITLE_MIN;
  }
  return TITLE_BAD;
}


int xp_list(int xp) {
  /* Returns guild level for xp specified */
  if(xp <  XP_LEVEL1)  { return 0;  }
  if(xp <  XP_LEVEL2)  { return 1;  }
  if(xp <  XP_LEVEL3)  { return 2;  }
  if(xp <  XP_LEVEL4)  { return 3;  } 
  if(xp <  XP_LEVEL5)  { return 4;  }
  if(xp <  XP_LEVEL6)  { return 5;  }
  if(xp <  XP_LEVEL7)  { return 6;  }
  if(xp <  XP_LEVEL8)  { return 7;  } 
  if(xp <  XP_LEVEL9)  { return 8;  } 
  if(xp <  XP_LEVEL10) { return 9;  } 
  if(xp >= XP_LEVEL10) { return 10; } 
  return 0;
}


int low_exp(int level) {
  /* Returns the base xp for the level specified */
  int xp;
  switch(level) {
    case 0:     xp = 0;          break;
    case 1:     xp = XP_LEVEL1;  break;
    case 2:     xp = XP_LEVEL2;  break;
    case 3:     xp = XP_LEVEL3;  break;
    case 4:     xp = XP_LEVEL4;  break;
    case 5:     xp = XP_LEVEL5;  break;
    case 6:     xp = XP_LEVEL6;  break;
    case 7:     xp = XP_LEVEL7;  break;
    case 8:     xp = XP_LEVEL8;  break;
    case 9:     xp = XP_LEVEL9;  break;
    case 10:    xp = XP_LEVEL10; break;
    }
  if(level > 10) xp = XP_LEVEL10;
  return xp;
}


int cost_to_advance(int level) {
  switch(level) {
    case 1:  return COST_LEVEL1;
    case 2:  return COST_LEVEL2;
    case 3:  return COST_LEVEL3;
    case 4:  return COST_LEVEL4;
    case 5:  return COST_LEVEL5;
    case 6:  return COST_LEVEL6;
    case 7:  return COST_LEVEL7;
    case 8:  return COST_LEVEL8;
    case 9:  return COST_LEVEL9;
    case 10: return COST_LEVEL10;
    }
  return 0;
}


status checkBrand(object ob, int lv, string brand) {
  int i;
  string * brands;
  string desc;
  switch(lv) {
    case 1:  brands = BRAND1;  desc = BRAND1_DESC;  break;
    case 2:  brands = BRAND2;  desc = BRAND2_DESC;  break;
    case 3:  brands = BRAND3;  desc = BRAND3_DESC;  break;
    case 4:  brands = BRAND4;  desc = BRAND4_DESC;  break;
    case 5:  brands = BRAND5;  desc = BRAND5_DESC;  break;
    case 6:  brands = BRAND6;  desc = BRAND6_DESC;  break;
    case 7:  brands = BRAND7;  desc = BRAND7_DESC;  break;
    case 8:  brands = BRAND8;  desc = BRAND8_DESC;  break;
    case 9:  brands = BRAND9;  desc = BRAND9_DESC;  break;
    case 10: brands = BRAND10; desc = BRAND10_DESC; break;
  }
  if(!brand) tell_object(ob, "(" + desc + ")\n");
  for(i = 0; i < sizeof(brands); i++) {
    if(brand && (brand == brands[i])) return 1;
    if(!brand) tell_object(ob, brands[i] + "\n");
  }
  return 0;
}


void chipList(object ob) {
  int i;
  tell_object(ob, LINE+BOLD+YELLOW+
    "Level           Xp (total)    Cost\n"+OFF+LINE);
  for(i = 0; i <= MAX_QUALITY_LEVEL; i++)
  {
    tell_object(ob, 
      pad("Level " + i, 16) +
      pad(low_exp(i), 14) +
      cost_to_advance(i) +
      "\n");
  }
  tell_object(ob, LINE);
}


void list(object ob) {
  int i;
  string prev_title, new_title;
  tell_object(ob, 
  "List of levels for the "+FUNKYNAME+" guild\n"+
  "________________________ ____________ ______ ____ ___ __\n"+
  "  TITLE\n"+
  "________________________ ____________ ______ ____ ___ __\n");
  for(i = MAX_COMBO_LEVEL; i >= 0; i--) {
    new_title = guild_title(i);
    if(prev_title != new_title) {
      tell_object(ob, "   "+pad(guild_title(i), 40)+"\n");
      prev_title = new_title;
    }
  }
  tell_object(ob, 
  "________________________ ____________ ______ ____ ___ __\n");
}
  

status new_chip(object ob, string brand) {
  int level;
  string currentBrand;
  level = (int)IPOB->guild_lev();
  if(level <= 0) {
    tell_object(ob, 
      "You already have the generic chip when you started the guild.\n");
    return 0; 
  }
  currentBrand = (string)IPOB->query_brand();
  if(currentBrand && (currentBrand != "acme")) {
    tell_object(ob, 
      "You have already chosen a chip.\n");
    return 0;
  }
  if(!checkBrand(ob, level, brand)) {
    tell_object(ob, 
      "There is no such neural chip, consult your manufacturer.\n");
    return 0;
  }
  IPOB->set_brand(brand);
  IPOB->save_me();
  tell_object(ob, 
    "You use up your free chip quota and install a brand new\n"+
    capitalize(brand)+" Neural Microprocessor.\n");
  return 1;
}


status advance_member(object ob, string brand) {
  /* So guild members can advance level in the guild. */
  /* The value of object ob is member to be advanced. */
  /* Return 1 only if advancement was successful.     */
  int current_xp, current_lev, new_lev, new_lev_xp, 
      temp, cost, credits, next_lev, honor;
  credits     = (int)IPOB->balance();
  current_lev = (int)IPOB->guild_lev();
  current_xp  = (int)IPOB->guild_exp();
  honor       = (int)IPOB->query_honor();
  next_lev    = current_lev + 1;

  new_lev_xp = low_exp(next_lev);
  temp = new_lev_xp - current_xp;
  if(temp > 0) {
    write(OPN+" needs "+temp+" more guild xp for a better chip.\n");
    tell_object(ob, temp+
      " more guild xp is required for tolerance of a better chip.\n");
    return 0;
  }
  cost = cost_to_advance(next_lev);
  if(credits < cost) {
    temp = cost - credits;
    write(OPN+" needs "+temp+" more credits for a better chip.\n");
    tell_object(ob, "Insufficient credits: @"+temp+" short.\n");
    return 0;
  }
  if(next_lev == 11) {
    write(OPN+" already has one of the best chips available.\n");
    tell_object(ob, 
      "There is no better processor than what you already have.\n");
    return 0; 
  }
  if(!checkBrand(ob, next_lev, brand)) {
    write("There is no such neural chip.\n");
    return 0;
  }
  IPOB->set_rank(next_lev);
  ob->add_guild_rank(1);
  IPOB->addToBalance(-cost);
  IPOB->set_brand(brand);
  tell_object(ob, 
    "A brand new neural microprocessor is inserted in your head.\n");
  tell_object(ob, 
    "Go out and tell your friends you're a "+capitalize(brand)+
    " junkie.\n");
  write_file(LOGDIR + "/ADVANCE", 
    TRN+" advanced to brand["+brand+"] level "+next_lev+" ("+
    ctime()+")\n");
  IPOB->set_title();
  IPOB->save_me();
  ob->save_me();
  move_object(IPOB, ob); /* force init */
  return 1;
}


status exchange_exp(object ob, int amount) {
  /* Way to exhchange normal xp to guild xp */
  int current_real_xp, new_guild_xp, min_xp, extra_xp;
  int bxp;

  if (amount <= 0) return 0;

  bxp = (int)IPOB->query_basexp();

/* Removed the requirement that extra xp cannot be used
   that is earned while the member was not a ninja.
   This is just way too harsh. - Dune 8/2002
 */
/*
  if (bxp)
  {
    if (bxp > (int)ob->query_exp())
    {
      tell_object(ob, "Insufficient experience to exchange!\n");
      IPOB->set_basexp(ob->query_exp());
      IPOB->save_me();
      return 0;
    }
  }
*/

  current_real_xp = ((int)ob->query_exp());

  if (ob->query_level() > 19)
  {
    min_xp = (int)call_other("/room/adv_guild.c", "get_next_exp", 0);
  }
  else if ((int)ob->query_level() == 19 && (int)ob->query_extra_level() > 0)
  {
    min_xp = (int)call_other("/room/exlv_guild.c",
             "get_next_exp", (int)ob->query_extra_level() - 1);
  }
  else
  {
    min_xp = (int)call_other("/room/adv_guild.c",
             "get_next_exp", (int)ob->query_level() - 1);
  }

  if (!bxp)
  {
    bxp = min_xp;
    IPOB->set_basexp(bxp);
    IPOB->save_me();
  }

/* Removed the requirement that extra xp cannot be used
   that is earned while the member was not a ninja.
   This is just way too harsh. - Dune 8/2002
 */
/*
  if (bxp > min_xp)
  {
    min_xp = bxp;
  }
*/

  extra_xp = current_real_xp - min_xp;

  if (amount > current_real_xp || extra_xp <= 0)
  {
    tell_object(ob,"Insufficient experience to exchange.\n");
    return 0;
  }

/*
  if(amount+IPOB->guild_exp() > MAXEXP){
    amount = MAXEXP-(int)IPOB->guild_exp();
  }
*/
  if(amount > extra_xp) {
    /* just exchange all extra experience */
    tell_object(ob, extra_xp+" experience exchanged.\n");
    IPOB->add_xp(extra_xp);
    amount = extra_xp;
  }
  else {
    /* exchange the specified amount of experience */
    tell_object(ob, amount+" experience exchanged.\n");
    IPOB->add_xp(amount);
  }
  call_other(ob, "add_exp", -amount);
  IPOB->save_me();
  ob->save_me();
  return 1; 
}
