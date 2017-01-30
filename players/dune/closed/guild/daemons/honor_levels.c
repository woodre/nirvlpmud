#include "../DEFS.h"
#include DEFS_HLEVELS

#define  HONOR_CHANCE 30


string honorTitle(int lev)
{
  /* Returns honor title for honor points specified */
  string title;
  if(lev >= HONOR_LEVEL_MD1) { title = HONOR_TITLE_MD1; }
  if(lev >= HONOR_LEVEL_MD2) { title = HONOR_TITLE_MD2; }
  if(lev >= HONOR_LEVEL_MD3) { title = HONOR_TITLE_MD3; } 
  if(lev >= HONOR_LEVEL_MD4) { title = HONOR_TITLE_MD4; }
  if(lev >= HONOR_LEVEL_MD5) { title = HONOR_TITLE_MD5; }
  if(lev >= HONOR_LEVEL_MD6) { title = HONOR_TITLE_MD6; }
  if(lev >= HONOR_LEVEL_MD7) { title = HONOR_TITLE_MD7; }
  if(lev >= HONOR_LEVEL_MD8) { title = HONOR_TITLE_MD8; }
  if(lev >= HONOR_LEVEL_MD9) { title = HONOR_TITLE_MD9; }
  if(lev >= HONOR_LEVEL_MAX) { title = HONOR_TITLE_MAX; }
  if(!title) return HONOR_TITLE_MIN;
  return title;
}


string findRangeNames(object ob)
{
  string stone, name;
  if (!IPOB) return 0;
  if (!IPOB->query_stone())
  {
    if ((int)IPOB->query_honor() < HONOR_LEVEL_MD6) return 0;
    name = HONOR_AWARDNAME_MIN;
    return name;
  }
  stone = (string)IPOB->query_stone();
  name = HONOR_AWARDNAME_MIN+", "+HONOR_AWARDNAME_MD1;

  if (
    stone == "ruby" ||
    stone == "jade" ||
    stone == "opal")
    name += ", " + HONOR_AWARDNAME_MD2;
  else if (
    stone == "sapphire" ||
    stone == "pearl"    ||
    stone == "emerald"  ||
    stone == "onyx")
    name += ", " + HONOR_AWARDNAME_MD2 + ", " + HONOR_AWARDNAME_MD3;
  else if (ORN == OWNER1 || ORN == OWNER2) 
    name += ", " + HONOR_AWARDNAME_MD2 + ", " + HONOR_AWARDNAME_MD3 +
            ", " + HONOR_AWARDNAME_MD4 + ", " + HONOR_AWARDNAME_MAX;
  else if (
    stone == "adamantium" ||
    stone == "diamond")
    name += ", " + HONOR_AWARDNAME_MD2 + ", " + HONOR_AWARDNAME_MD3 +
            ", " + HONOR_AWARDNAME_MD4;
  return name;
}


int get_points(string test)
{
    int points;
    points = 0;
    switch(test) {
      case HONOR_AWARDNAME_MIN: points = HONOR_AWARDNUM_MIN; break;
      case HONOR_AWARDNAME_MD1: points = HONOR_AWARDNUM_MD1; break;
      case HONOR_AWARDNAME_MD2: points = HONOR_AWARDNUM_MD2; break;
      case HONOR_AWARDNAME_MD3: points = HONOR_AWARDNUM_MD3; break;
      case HONOR_AWARDNAME_MD4: points = HONOR_AWARDNUM_MD4; break;
      case HONOR_AWARDNAME_MAX: points = HONOR_AWARDNUM_MAX; break;
      }
    return points;
}


int honor_checkup(object ob)
{
  object wep, att;
  int hon;
  string me;

  if (!ob) return 1;
  if (!find_player((string)ob->query_real_name())) return 1;
  if (!ob->query_interactive()) return 1;
  if (ob->query_level() >= 20) return 1;

  me  = (string)ob->query_real_name();
  hon = (int)IPOB->query_honor();
  wep = (object)ob->query_weapon();
  att = (object)ob->query_attack();

  if (att && !ob->query_ghost())
  {
    if(att->is_player()                           && 
       (string)att->query_guild() != "cyberninja" &&
       random(HONOR_CHANCE) == 1)
    {
      if ((att->query_level() > ob->query_level() ||
          att->query_level() > 15)                &&
          !environment(ob)->query_spar_area()     &&
          hon < HONOR_LEVEL_MD4)
      {
        tell_object(ob, BOLD+"You gain honor in combat!"+OFF+"\n");
        IPOB->add_honor(HONOR_AWARDNUM_MIN);
        IPOB->save_me();
      }
      else if (att->query_level() > 15             &&
               !environment(ob)->query_spar_area() &&
               random(2) == 1)
      {
        tell_object(ob, BOLD+"You gain honor in combat."+OFF+"\n");
        if ((object)att->query_attack() == ob)
          IPOB->add_honor(HONOR_AWARDNUM_MIN);
        else
          IPOB->add_honor(HONOR_AWARDNUM_MIN);
        IPOB->save_me();
      }
    }
  }

  /* added by wocket 11/1/03 */
  if(wep && !wep->id(WEAPON_ID)){
    tell_object(ob,BOLD+"You lose honor for not using your choosen weapon.\n"+OFF);
    IPOB->add_honor(-HONOR_AWARDNUM_MIN);
    IPOB->save_me();
  }
  if (!ob->query_pl_k()) return 1;

  /* Due to the impossibility of players working with a system,
   * these have been made pretty unlikely. -Snow 9/99 */

  if (hon >= HONOR_LEVEL_MD9)
  {
    if (random(5) == 1)
    {
      tell_object(ob,BOLD+CYAN+"\tYour honor grants you energy.\n"+OFF);
      ob->heal_self(random(6)+2);
    }
    return 1;
  }

  if (hon >= HONOR_LEVEL_MD8)
  {
    if (random(10) == 1)
    {
      tell_object(ob,WHITE+"\tYour honor grants you energy.\n"+OFF);
      ob->heal_self(random(6)+2);
    }
    return 1;
  }

  if (hon >= HONOR_LEVEL_MD7)
  {
    if (random(15) == 1)
    {
      tell_object(ob,BOLD+YELLOW+"\tYour honor grants you energy.\n"+OFF);
      ob->heal_self(random(5)+2);
    }
    return 1;
  }

  if (hon >= HONOR_LEVEL_MD6)
  {
    if (random(20) == 1)
    {
      tell_object(ob,BOLD+GREEN+"\tYour honor grants you energy.\n"+OFF);
      ob->heal_self(random(4)+1);
    }
    return 1;
  }

  if (hon >= HONOR_LEVEL_MD5)
  {
    if (random(25) == 1)
    {
      tell_object(ob,BOLD+MAGENTA+"\tYour honor grants you energy.\n"+OFF);
      ob->heal_self(random(3)+1);
    }
    return 1;
  }

  if (hon >= HONOR_LEVEL_MD4)
  {
    if (random(30) == 1)
    {
      tell_object(ob,BOLD+MAGENTA+"\tYour honor grants you energy.\n"+OFF);
      ob->heal_self(random(3)+1);
    }
    return 1;
  }

  if (hon < HONOR_LEVEL_MD2)
  {
    if (random(6) == 1)
    {
      tell_object(ob,BOLD+RED+"\tYour lack of honor pains you.\n"+OFF);
      ob->heal_self(-random(4)-1);
    }
    return 1;
  }

  return 1;
}
