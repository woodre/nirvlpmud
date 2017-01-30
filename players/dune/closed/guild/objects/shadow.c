/*
 * CyberNinja Defensive Skills
 * Reduces damage from 0-51% depending on mode
 */

#include "../DEFS.h"
#include DEFS_ENHANCEMENTS
#define NO_SHORT 17

object player;
int damage;


query_defense()
{
  return 1;
}


start_defense(who)
{
   player = who;
   shadow(player, 1);
   return 1;
}


stop_defense()
{
   shadow(player, 0);
   destruct(this_object());
   return 1;
}


quit()
{
   shadow(player, 0);
   player->quit();
   return 1;
}


/* Attempt to make CyberEyes more thematically effective */
test_dark()
{
  object gob;
  gob = present(GUILD_ID, player);
  if (gob && gob->item_eyes()) return 0;
  else return player->test_dark();
}


look(str)
{
  object gob;
  gob = present(GUILD_ID, player);
  if (gob && gob->item_eyes())
  {
    gob->do_light(2);
    player->look(str);
    gob->do_light(-2);
  }
  else
  {
    player->look(str);
  }
  return 1;
}


move_player(str)
{
  object gob;
  if (!str) return;
  gob = present(GUILD_ID, player);
  if (!gob) player->move_player(str);
  if (player->query_level() > 19 || !gob->item_eyes())
  {
    player->move_player(str);
  }
  else
  {
    gob->do_light(2);
   /*
    if (player->query_real_name() == "snowtest" ||
        player->query_real_name() == "dunetest" )
    */
   if(gob->query_shadows()) 
    {
      shadow_move(str);
    }
    else
    {
      player->move_player(str);
    }
    gob->do_light(-2);
  }
}


/* HIDE IN SHADOWS CODE */
check_shadows()
{
  object gob;
  gob = present(GUILD_ID, player);
  if (!gob) return 0;
  return gob->query_shadows();
}


short()
{
  int clvl,cste,cint,mylvl,myste,myint;
  if (check_shadows())
  {
    if(TP){
      clvl = TP->query_total_level(); mylvl=player->query_total_level();
      cste = TP->query_attrib("ste"); myste=player->query_attrib("ste");
      cint = TP->query_attrib("int"); myint=player->query_attrib("int");
    if (TP && TP->query_level() > 21)
       return player->short()+" (hiding in shadows)";
    else 
    if (clvl > mylvl && random(myste+myint)*3/2 < random(cste+cint)) 
       return player->short()+" (hiding in shadows)"; 
    else
      return;
    }
  /* must be visiable to more powerful players! -Bp */
  }
  return player->short();
}


long()
{
  if (!TP ||
      (TP && !IPTP && check_shadows())) shadows_spotted();
  player->long();
}


shadows_spotted()
{
  object gob;
  tell_object(player,"You are no longer hidden.\n");
  if (TP) tell_object(TP, "You spot "+player->query_name()+" in the shadows.\n");
  gob = present(GUILD_ID, player);
  if (gob)
  {
    gob->set_shadows(0);
    gob->save_me();
  }
  return 1;
}


void room_tell(string rmsg)
{
  object *allroom;
  int i;
  allroom = all_inventory(environment(player));
  for (i=0; i < sizeof(allroom); i++)
  {
    if (allroom[i] != player) tell_object(allroom[i], rmsg);
  }
}


void show_move(int num, object player, object room)
{
  string pmsg, rmsg, me;
  me = player->query_name()+" ";

  switch(num)
  {
    case 0:
      pmsg = "You cringe.";
      rmsg = me+"cringes.";
      break;

    case 1:
      pmsg = "You duck and pray.";
      rmsg = me+"ducks and prays.";
      break;

    case 2:
      pmsg = "You exhale at the moment of impact!";
      rmsg = me+"exhales at the moment of impact!";
      break;

    case 3:
      pmsg = "You step back slightly.";
      rmsg = me+"steps back slightly.";
      break;

    case 4:
      pmsg = "You lean back.";
      rmsg = me+"leans back.";
      break;

    case 5:
      pmsg = "You twist slightly to the left.";
      rmsg = me+"twists slightly to the left.";
      break;

    case 6:
      pmsg = "You twist slightly to the right.";
      rmsg = me+"twists slightly to the right.";
      break;

    case 7:
      pmsg = "You step to the right.";
      rmsg = me+"steps to the right.";
      break;

    case 8:
      pmsg = "You step to the left.";
      rmsg = me+"steps to the left.";
      break;

    case 9:
      pmsg = "You perform a left forearm cross-parry.";
      rmsg = me+"performs a left forearm cross-parry.";
      break;

    case 10:
      pmsg = "You perform a right forearm cross-parry.";
      rmsg = me+"performs a right forearm cross-parry.";
      break;

    case 11:
      pmsg = "You shoulder-roll to your left.";
      rmsg = me+"shoulder-rolls to the left.";
      break;

    case 12:
      pmsg = "You shoulder-roll to your right.";
      rmsg = me+"shoulder-rolls to the right.";
      break;

    case 13:
      pmsg = "You flash-roll to your left!";
      rmsg = me+"flash-rolls to the left!";
      break;

    case 14:
      pmsg = "You flash-roll to your right!";
      rmsg = me+"flash-rolls to the right!";
      break;

    case 15:
      pmsg = "You flash-roll back!";
      rmsg = me+"flash-rolls back!";
      break;

    case 16:
      pmsg = "You perform a back handspring!";
      rmsg = me+"performs a back handspring!";
      break;

    case 17:
      pmsg = "You flip to your left!";
      rmsg = me+"flips to the left!";
      break;

    case 18:
      pmsg = "You flip to your right!";
      rmsg = me+"flips to the right!";
      break;

    case 19:
      pmsg = "You flip-turn left!";
      rmsg = me+"flip-turns left!";
      break;

    case 20:
      pmsg = "You flip-turn right!";
      rmsg = me+"flip-turns right!";
      break;

    case 21:
      pmsg = "You flip-turn back!";
      rmsg = me+"flip-turns back!";
      break;

    case 22:
      pmsg = "You DODGE and completely avoid the blow!";
      rmsg = me+" performs a DODGE, and completely avoids the blow!";
      break;
  }

  tell_object(player, BOLD+pmsg+OFF+"\n");
  room_tell(rmsg+"\n");
}


/* DAMAGE REDUCTION CODE */
hit_player(dam1, type1, dam2, type2)
{
   return do_damage(({dam1,dam2}),({type1,type2}));
}
do_damage(int *damage, string *method)
{
  object gob;
  string type, cat, subcat;
  int i, dam, total, modenum;

  gob = present(GUILD_ID, player);
  if (!gob) destruct(this_object());

  /***********************************/
  /*  Handle Beck's Defense Types    */
  /***********************************/
  if (!damage) return 0;
  for(i=0; i < sizeof(damage); i++)
  {
    /* Get damage type information. */
    subcat = 0;
    if (!damage[i]) continue;
    dam = damage[i];
    if (!method) type = "physical";
    else if (!method[i]) type = "physical";
    else
    {
      type = method[i];
      if (type != "physical" && type != "magical")
      {
        if (sscanf(type, "%s|%s", cat, subcat) !=2)
        {
          type = "physical";
        }
        else if (cat != "other") type = "physical";
        else                     type = "other";
      }
    }

    dam = calcDamage(dam, type, subcat, gob);

    total += dam;
  }

/* players don't get caps on the damage done to them! */
/*  -Bp
  if (total > 50) total = 40+random(10);
*/
  if (total <= 0) total = 0;

  return total;
}


/* DAMAGE REDUCTION GUIDE
   defnum:    the % resistance to the damage
   basered:   the ac against the damage, random(basered) is deducted
   MAX_REDUX: the max damage points that can be deducted
              this may rise for certain damage types
*/
int calcDamage(int dam, string type, string subcat, object gob)
{
  int alev, modenum, defnum, basered, tmp_dam, 
      MAX_REDUX, mode2Max, mode1Max, mode0Max, maxDef, maxBase;
  string myname;
  status dodge, leaderBonus;
  object attacker;
  int glev;

  myname = capitalize((string)player->query_name());
  modenum = (int)gob->query_attack_mode();
  glev = (int)gob->query_guild_rank();
  alev = (int)gob->query_art_level();
  defnum   = 0;
  basered  = 0;
  MAX_REDUX = 50;    /* MAX HP REDUCTION */
  mode2Max  = 25;    /* STEALTH MODE MAX DMG REDUCTION % */
  mode1Max  = 15;    /* ATTACK  MODE MAX DMG REDUCTION % */
  mode0Max  = 20;    /* NORMAL  MODE MAX DMG REDUCTION % */

/* GUILD LEADER BONUS */
  /* nanoblood enhancement only available to guild leaders */
  leaderBonus = (status)gob->item_nanoblood();
  if (leaderBonus)
  {
    /* guild leaders get an award for their work */
    defnum    += 2;
    basered   += 1;
    MAX_REDUX += 2;
    mode2Max  += 3;
    mode1Max  += 3;
    mode0Max  += 3;
  }

  /*
    DODGE IS EXPERIMENTAL, NOT APPROVED, AND NOT SCHEDULED FOR APPROVAL.
    I HAVE LEFT IN SOME CODE PIECES HERE IN CASE I WISH TO USE IT.
    FOR NOW, DODGE IS SET TO 0 (NO DODGING)
    A ninja may have dodge capability (complete dmg avoidance),
    but this comes at a sacrifice of less combat dmg. The ninja's
    choice of enhancements and martial art determine dodge ability.
    Calculate dodge % here and determine if dodge is set to 1 
    (successful dodge) or 0 (no dodge).
  */
  dodge = 0; /* never dodge */

/* STEALTH MODE */
  if (modenum == 2)
  {
    defnum += alev;
    defnum += random(alev);
    /* ac max of 22 */
    basered += (alev + glev) / 2;
    if (defnum > mode2Max) defnum = mode2Max;
    maxDef = mode2Max;
  }

/* HYPER MODE */
  if (modenum == 1)
  {
    defnum += random(alev);
    /* ac max of 11 */
    basered += (alev + glev) / 4;
    if (defnum > mode1Max) defnum = mode1Max;
    maxDef = mode1Max;
  }

/* NORMAL MODE */
  if (!modenum)
  {
    defnum += alev/2;
    defnum += random(alev);
    /* ac max of 14 */
    basered += (alev + glev) / 3;
    if (defnum > mode0Max) defnum = mode0Max;
    maxDef = mode0Max;
  }

/* SUB-DERMAL ARMORING, DAMAGE REDUCTION OF RANDOM(10)+1% */
  if (gob->query_armor())
  {
    defnum  += random(7)+1;
    basered += 1;
    maxDef  += 7;
  }

/* DAMAGE TYPE MODIFIERS */
  if (type == "magical")
  {
    /* complete vulnerability to magical attacks */
    defnum  = 0;
    basered = 0;
    tell_room(environment(player), BOLD+MAGENTA+myname+
      " suffers FULL damage from the magical attack!"+OFF+"\n");
  }
  if (type == "physical" && gob->item_inertia())
  {
    /* slightly enhanced defense vs. physical attacks */
    defnum  +=  0 + random(5);
    basered +=  2;
    maxDef  +=  4;
  }
  if (type == "other")
  {
    subcat = lower_case(subcat);
    if (subcat == "good"  || subcat == "evil")
    {
      /* enhanced vulnerability to these types */
      defnum -= 15;
      maxDef -= 15;
      basered = 0;
      if (subcat == "good") subcat = "holy";
      else                  subcat = "unholy";
      tell_room(environment(player), MAGENTA+
        "The "+subcat+" attack rips through "+myname+"'s defenses!"+OFF+"\n");
    }
    if ( gob->item_blood() &&
        (subcat == "ice"    || subcat == "electric" ||
         subcat == "mental" || subcat == "poison"))
    {
      /* enhanced defense vs. these types */
      defnum += 7;
      maxDef += 7;
      basered += 3;
      tell_room(environment(player), BOLD+YELLOW+myname+
        "'s polymer blood resists the "+subcat+" attack!"+OFF+"\n");
      MAX_REDUX += 7;
    }
    if (subcat == "water")
    {
      /* extreme vulnerability versus water damage */
      defnum -= 25;
      maxDef -= 25;
      basered = 0;
      tell_room(environment(player), BOLD+CYAN+myname+
        "'s circuits fry in the water!"+OFF+"\n");
    }
    if (subcat == "laser")
    {
      /* extreme defense versus futuristic damage */
      defnum   = 90;
      maxDef   = 90;
      basered += 15;
      tell_room(environment(player), BOLD+BLUE+myname+
        " seems utterly unaffected by the technological attack!"+OFF+"\n");
      MAX_REDUX += 20;
    }
  }

  if (defnum < 0)   defnum = 0;
  if (maxDef < 0)   maxDef = 0;
  if (defnum > 100) defnum = 100;
  if (maxDef > 100) maxDef = 100;
  if (basered < 0)  basered = 0;
/*
  if (dodge) defnum = 100;
*/

  maxBase = basered;
  basered = random(basered)+1;

/*
  attacker = (object)player->query_attack();
*/
attacker = this_player();
/* was creating bugs w/ the older line - Jaraxle [9/6/03] */
/* Um.  this prev. line creates bugs too.  How about
    an if check ? */
/* verte 9.15.03 */
  if(attacker)
  if(attacker->is_player()) defnum = 7*defnum / 12;
  tmp_dam = ((100-defnum)*dam)/100;
  tmp_dam -= basered;
  if (tmp_dam < 0) tmp_dam = 0;
  if (dam - tmp_dam > MAX_REDUX) tmp_dam = dam - MAX_REDUX;

  /* Make sure we don't interfere with objects or spells that damage ourself. */
  if (this_player() && this_player() == player)
  {
    dodge   = 0;
    defnum  = 0;
    maxDef  = 0;
    basered = 0;
    tmp_dam = dam;
  }

/* DO DAMAGE */
  if (!dodge)
  {
    if (gob->guild_manager()         ||
        player->query_level() >= 100 ||
        myname == "Dunetest")
    {
      tell_object(player, 
        BOLD+GREEN+"DAMAGE ["+tmp_dam+"/"+dam+" redux "+(dam-tmp_dam)+"/"+MAX_REDUX+"], "+
        "DEFENSE ["+defnum+"/"+maxDef+"%-"+basered+"/"+maxBase+"]"+OFF+"\n");
    }
    player->hit_player(tmp_dam);
  }

/* SHOW DEFENSIVE MESSAGE */
  if (defnum > 0 && defnum <= 15)
    show_move(random(5), player, environment(this_object()));
  if (defnum > 15 && defnum <= 40)
    show_move((random(10)+4), player, environment(this_object()));
  if (defnum > 40 && defnum < 100)
    show_move(random(18)+4, player, environment(this_object()));
  if (defnum == 100)
    show_move(22, player, environment(this_object()));


/* BLADES ENHANCEMENT DAMAGE */
  if (gob->query_blad_on() && gob->guild_lev() > random(40))
  {
    attacker = (object)player->query_attack();
    if (attacker && modenum != 2 && gotsp(player, ENERGY_BLADES))
    {
      int bladedam;
      string victim;
      player->add_spell_point(-ENERGY_BLADES);
      victim = capitalize((string)attacker->query_name());
      tell_room(environment(player),
        RED+victim+" is impaled on "+myname+"'s blades!\n"+OFF);
      bladedam = random((int)gob->guild_lev()) + 1;
      if (bladedam < (int)attacker->query_hit_point())
      {
/* There is no reason why this should be non-defendable damage
 - illarion jan 05
        attacker->heal_self(-bladedam);
        attacker->add_spell_point(bladedam);
*/
        attacker->hit_player(bladedam);
      }
    }
  }
  return tmp_dam;
}


#include "shadow_move.h"
