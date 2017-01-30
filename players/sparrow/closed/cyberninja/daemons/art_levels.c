#include "../DEFS.h"
#include DEFS_ALEVELS
#include DEFS_HLEVELS
#include DEFS_OFFICES


int art_exp(int level)
{
  int xp;
  switch(level)
  {
    case 1:    xp = XP_BELT1; break;
    case 2:    xp = XP_BELT2; break;
    case 3:    xp = XP_BELT3; break;
    case 4:    xp = XP_BELT4; break;
    case 5:    xp = XP_BELT5; break;
    case 6:    xp = XP_BELT6; break;
    case 7:    xp = XP_MAX;   break;
  }
  return xp;
}


string findBeltColor(int level)
{
  string belt;
  if (level >= BLACK_BELT) return COLOR_MAX;
  switch(level)
  {
     case 0:   belt = COLOR_MIN;    break;
     case 1:   belt = COLOR_BELT1;  break;
     case 2:   belt = COLOR_BELT2;  break;
     case 3:   belt = COLOR_BELT3;  break;  
     case 4:   belt = COLOR_BELT4;  break; 
     case 5:   belt = COLOR_BELT5;  break; 
     case 6:   belt = COLOR_BELT6;  break;   
     case 7:   belt = COLOR_MAX;    break; 
  }
  return belt;
}


status train(object ob, string art)
{
  int artlevel, newArtlevel, level, xp, honor, 
      lowxp, reqxp, freexp, temp, degree;
  string color, counselPair;

  if (!IPOB) return 0;

  art = "Ninjitsu";
  honor =    (int)IPOB->query_honor();
  artlevel = (int)IPOB->query_art_level();
  newArtlevel = artlevel + 1;
  degree = newArtlevel - BLACK_BELT;
  xp =    (int)(IPOB->guild_exp());
  level = (int)(IPOB->guild_lev());
  lowxp = (int)call_other(GLEVELD, "low_exp", level);
  if(newArtlevel <= 7) reqxp = art_exp(newArtlevel);
  else reqxp = XP_DEGREES;
  freexp = xp - lowxp;

  if(newArtlevel > MAX_ART_LEVEL)
  {
    write(OPN+" cannot advance further in "+art+".\n");
    tell_object(ob, "You are already Grandmaster of "+art+".\n");
    return 0; 
  }

  if(freexp < reqxp)
  {
    temp = reqxp - freexp;
    write(OPN+" does not have enough free guild experience.\n");
    tell_object(ob, "You do not have enough free guild experience.\n");
    tell_object(ob, "You need "+temp+" more xp to learn "+art+".\n");
    return 0;
  }

  if( ((newArtlevel ==  BLACK_BELT) && 
       (honor < HONOR_LEVEL_MD2)) ||
      ((newArtlevel == GRANDMASTERY) && 
       (honor < HONOR_LEVEL_MD3)) )
  {
      write(OPN+" is not honorable enough for such a level.\n");
      tell_object(ob, "You try to train but fail.\n");
      return 0; 
  }

  color = findBeltColor(newArtlevel);
  if(newArtlevel == 1)
  {
    IPOB->set_art(art);
    tell_object(ob, "You are introduced to the discipline of "+art+".\n");
    tell_object(ob, "A "+color+" belt is given to you.\n");
    write("You introduce "+OPN+" to the discipline of "+art+".\n");
    write(OPN+" begins as a "+color+" belt.\n");
  }

  if((newArtlevel <= BLACK_BELT) && (newArtlevel > 1))
  {
    tell_object(ob, "You advance in the discipline of "+art+"!\n");
    write(OPN+" advances in the discipline of "+art+".\n");
    write("You hand "+OPN+" a crisp new "+color+" belt.\n");
    tell_object(ob, "You don a crisp new "+color+" belt.\n");
  }

  if(newArtlevel > BLACK_BELT)
  {
    tell_object(ob, "You advance to a black belt of degree "+degree+".\n");
    write("You place a shiny red mark on "+OPN+"'s black belt.\n");
    tell_object(ob, "Shiny red markings are added to your black belt.\n");
  }

  if(newArtlevel == MASTERY)
  {
    tell_object(ob, "You have mastered the discipline of "+art+"!\n");
    IPOB->add_honor(HONOR_AWARDNUM_MD3);
    tell_object(ob, "You gain much honor.\n");
    if (IPOB->query_counselor())
    {
      counselPair = (string)IPOB->query_counselor() + " " + (string)ob->query_real_name();
      call_other(RECRUITD, "clearCouncelee", counselPair);
      IPOB->set_counselor(0);
    }
    call_other(CHANNELD, "overchannel", 
      ORN+" has mastered the discipline of "+art+"!\n");
    write(OPN+" has mastered the discipline of "+art+".\n");
  }

  if(newArtlevel == GRANDMASTERY)
  {
    tell_object(ob, "You have achieved Grandmaster status in the \n"+
           "discipline of "+art+"!\n");
    call_other(CHANNELD, "overchannel", 
      ORN+" has become Grandmaster of "+art+"!\n");
    IPOB->add_honor(HONOR_AWARDNUM_MD4 + HONOR_AWARDNUM_MAX);
    tell_object(ob, "You gain very much honor.\n");
    write(OPN+" has become a Grandmaster of "+art+".\n");
  }

  IPOB->set_art_level(newArtlevel);
  ob->add_guild_rank(1);
  IPOB->add_honor(HONOR_AWARDNUM_MD2);
  IPOB->add_xp(-reqxp);
  write_file(LOGDIR + "/TRAIN", 
    TPN+" trained "+ORN+" to level "+newArtlevel+
    " in "+capitalize(art)+". ("+ctime()+")\n");
  IPOB->save_me();
  ob->save_me();
  move_object(IPOB, ob);

  return 1;
}


void list(object ob)
{
  int i;
  int totxp;
  totxp = 0;
  tell_object(ob, LINE+BOLD+YELLOW+"Belt         Xp (total)\n"+OFF+LINE);
  for(i = 1; i <= BLACK_BELT; i++)
  {
    tell_object(ob, 
      pad(findBeltColor(i), 12) + " " + 
      (totxp + art_exp(i)) + "\n");
    totxp += art_exp(i);
  }
  for(i = 1; i <= MAX_ART_LEVEL - BLACK_BELT; i++)
  {
    tell_object(ob, 
      pad("degree " + i, 12) + " " + 
      (totxp + XP_DEGREES) + "\n");
    totxp += XP_DEGREES;
  }
  tell_object(ob, "... (degrees are 100k per level)\n" + LINE);
}
