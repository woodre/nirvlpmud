/*
 *      File:                   /players/earwax/area/fields/mon/groshnarg
 *      Function:               
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2004 Earwax/David Halek
 *                                      All Rights Reserved.
 *      Source:                 06/27/06
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

inherit "/obj/monster.c";

/* Global Variables */
int Current;     /* Used for tracking damage taken     */
int TotalGiven;  /* Used for tracking damage delivered */
int TotalRounds; /* Track total number of rounds       */
int ExtraAc;     /* Track extra ac granted             */

status id(string arg)
{
  return (arg == "groshnarg" || arg == "general" || arg == "daddy"
       || arg == "general groshnarg");
}

string query_name() { return BOLD+"General Groshnarg"+NORM; }

/* Disallow calming and retreating */
void stop_fight()
{
  if (!this_player() && (int)this_player()->query_level() < 20)
    write(name+" can't be distracted!\n");
  else
    ::stop_fight();
}

string *query_message_hit(int dam)
{
  int t;
  
  switch(dam)
  {
    case  1..10: t = 14; break;
    case 11..17: t = 12; break;
    case 18..23: t = 10; break;
    case 24..30: t =  8; break;
    case 31..40: t =  6; break;
    case 41..50: t =  4; break; 
    case 51..60: t =  2; break; 
    default:     t =  0; break; 
  }
  
  return ({ message_hit[t+1], message_hit[t] });
}
    
void reset(status arg)
{
  ::reset(arg);
  set_name(BOLD+"General Groshnarg"+NORM);
  set_race("qtip");
  set_level(50);
  set_al(0);
  set_hp(5000); /* Randomize this later */
  set_wc(70);
  set_ac(50);
  set_short(BOLD+"General Groshnarg"+NORM+", of the "+HIR+"Swabbian Army"+NORM);
  set_long(name+"is intimidating to say the least.  The former General\n\
of the Swabbian Armies (known as the QTips) stands about nine feet tall\n\
and all four of his arms look fully capable of wielding a weapon with a\n\
great deal of skill.  He's covered in greyish scales that appear to act\n\
as natural armor.  Around his massive neck there is a gorget forged from\n\
some unknown metal.  A blood-red crystal is the only ornament on him, and\n\
hangs just below his neckguard.\n");
  message_hit = ({
    HIK+"reduces"+NORM, " to a "+HIR+"bloody"+NORM+" pulp",
    HIR+"hits"+NORM,    " so hard it hurts just to see it",
    RED+"beats"+NORM,   " like a "+RED+"red"+NORM+"-headed stepchild",
    RED+"smashes"+NORM, HIK+" with great might and power"+NORM,
    "generously gives", " a boot to the teeth",
    "hits",             " with a solid blow",
    "hits",             " with a glancing blow",
    "backhands",        " contemptuously",    
  });
  set_armor_special("defensive_special");
}

/* This mob decides what to do each round based on number of attackers, how 
 * much damage he's taking, and his current hit-points.  He'll automatically
 * block a certain number of attacks, but the more damage he takes the more
 * likely he is to inflict a major special.  If he's taking more moderate
 * damage he'll tend to area-effect and use his second weapon more.  His
 * extra weapon and shield will be used for defense if he's taking a lot of
 * damage, in other words, and he'll counter-attack heavily if the damage is
 * excessive, otherwise he'll be more offensive, and tend to go after back-row
 * players more often.
 */
 
void heart_beat()
{
tell_room(environment(this_object()), "DAMAGE TAKEN: "+(Current - hit_point)+"\nWC_BONUS: "+wc_bonus+"\nAC_BONUS: "+ac_bonus+"\n");
  ::heart_beat();
  Current = hit_point;
  if (!attacker_ob || environment(attacker_ob) != environment(this_object())) 
    return;
  TotalRounds++;
  wc_bonus = TotalGiven / TotalRounds;
  ac_bonus = ExtraAc / TotalRounds;
  call_out("check_fury", 0, attacker_ob);
}

void check_fury(object ob)
{
  int chance, dam, i, siz;
  string *msg;
  object *attackers, *peeps;
  object here;

  here = environment(this_object());
  
  if (!ob || environment(ob) != here)
    return;
    
  /* Chance of the big counterattack is 1% per dam over 75 they took prev round */
  chance = Current - hit_point - 75;
  if (random(100) > chance)
    return;
    
  tell_room(here, "\nAfter staggering back for a second, "+name+" shakes his head\n\
a few times angrily, jerks his weapons up and charges forward in a rage!\n\n"+NORM);

  /* Specific attack on the tank */
  tell_object(here, "\
You apparently hurt "+name+" somewhat, but now he's got a maniacal look in his \n\
eyes and he's swinging his axe right at your head!\n\n");
  chance -= 25;
  dam = 25 + random(26);
  if (chance > 100) dam += random(26); /* Punishment for dealing damage heh */
  if (chance > 150) dam += random(26);
  if (chance > 200) dam += random(26);
  if (chance > 250) dam += random(26);
  TotalGiven += dam;
  msg = query_message_hit(dam);
  tell_object(ob, name+msg[1]+" you"+msg[0]+".\n");
  tell_room(here, HIR+name+" strikes viciously at "+(string)ob->query_name()+HIR+" with his axe!\n"+NORM, ({ ob }));
  tell_room(here, name+msg[1]+" "+(string)ob->query_name()+msg[0]+".\n", ({ ob }));
  ob->hit_player(dam);
    
  tell_room(here, HIR+name+" swings his weapons at everything that moves!\n");
        
  i = siz = sizeof(peeps = all_inventory(here));
  while(i--)
  {
    int r;
    object victim;
      
    r = random(siz);
    victim = peeps[r];
    if (living(victim) && (status)victim->query_ghost() < 1 
    && (object)victim->query_attack() == this_object())
    {
      tell_object(victim, RED+"You get whacked by a "+(random(2) ? "shield" : "spear")+"!\n"+NORM);
      r = 10+random(16); /* 10-25 damage avg 17-18 */
      victim->hit_player(r);
      TotalGiven += r;
    }   
  }
}      

/* As his hps get lower, he'll be less likely to counterattack with his defense,
 * in order to focus more on staying alive.
 */
int defensive_special(object me)
{
  object them, here;
  string attname;    
  int dam;
  int chance;           /* % chance of a counterattack         */
  int totaldam;         /* Total damage to counter-attack with */
  status flag_counter;  /* 1 means counter-attack, 0 means no  */
  
  if (!this_player()) return 0;
  them = this_player();
  if (them == me) return 0;
  attname = (string)this_player()->query_name();
  chance = 25 + ((hit_point * 100)/max_hp); /* What % of hps is he at */
  flag_counter = (random(100) < chance);
  here = environment(me);
  totaldam = 0;
  
  if (!random(3)) /* Show a defensive armor emote - woot spammage! */
  {
    string temp;
    
    switch(random(5))
    {
      case 0: temp = name+"'s"+CYN+" scales are impenetrable!\n"; break;
      case 1: temp = "Laughter rings out from "+name+CYN+" as his scales stop a strike.\n";break;
      case 2: temp = "A powerful strike is stopped short by the scales covering "+name+".\n"; break;
      case 3: temp = name+CYN+" ignores the pitiful attempts to breach his defenses.\n";break;
      case 4: temp = "The scales stop a blow.\n"; break;
    }
    
    say(CYN+temp+NORM);
  }
  
  /* 1/2 of the time he'll counter-strike with his spear if other check hits */
  if (!random(3) && flag_counter && them != attacker_ob) /* back-row only */
  {
    dam = 25+random(25); /* This may need to be upped, since it's physical */
    switch(dam)
    {
      case 25..30: write(name+RED+" counter-attacks you with his spear.\n"+NORM);
                   tell_room(here, name+ "counter-attacks "+attname+" with his spear.\n", ({ them }));
                   break;
      case 31..40: write(name+RED+" counter-attacks you brutally with his spear!\n"+NORM);
                   tell_room(here, name+CYN+" counter-attacks "+attname+NORM+CYN+" brutally with his spear!\n"+NORM, ({ them }));
                   break;
      case 41..50: write(name+HIR+" viciously impales you with a counter-strike from his spear!\n"+NORM);
                   tell_room(here, name+CYN+" vicioiusly impales "+attname+NORM+CYN+" brutally with his spear!\n"+NORM, ({ them }));
    }
    
    totaldam += dam;
    TotalGiven += dam;
  }
  
  /* 1/2 the time he'll counter-strike with his shield if other check hits */
  if (!random(3) && flag_counter)
  {
    dam = 10+random(16);
    
    switch(dam)
    {
      case 10..15: write(name+RED+" bashes you with his shield.\n"+NORM);
                   tell_room(here, attname+ " is shield-bashed.\n", ({ them }));
                   break;
      case 16..20: write(name+RED+" bashes you hard with his shield.\n"+NORM);
                   tell_room(here, attname+ "gets shield-bashed hard.\n", ({ them }));
                   break;
      case 21..25: write(name+RED+" bashes you HARD with his shield.\n"+NORM);
                   tell_room(here, attname+ " gets shield-bashed HARD.\n", ({ them }));
                   break;
    }
    
    totaldam += dam;
    TotalGiven += dam;
  }

  if (totaldam)
    them->hit_player(totaldam);
    
  if (chance > 74)   return 0;     /* No resistance until he's under 75% */
  if (chance > 50) { ExtraAc +=  6; return 0105; } /* 01% res, +05 ac if 50-75% hps */
  if (chance > 40) { ExtraAc += 10; return 0406; } /* 04% res, +06 ac if 40-50% hps */
  if (chance > 30) { ExtraAc += 15; return 0807; } /* 08% res, +07 ac if 30-40% hps */
  if (chance > 20) { ExtraAc += 21; return 1208; } /* 12% res, +08 ac if 20-30% hps */
  if (chance > 10) { ExtraAc += 26; return 1609; } /* 16% res, +09 ac if 10-20% hps */
  else             { ExtraAc += 30; return 2010; } /* 20% res, +10 ac if  0-10% hps */
}

#ifdef 0
  set_dead_ob(this_object()); /* On death, ink the room (stun) and dest corpse */
  
  set_armor_params("other|water", 100, 100, 0); /* Immune to water damage  */
  set_armor_params("other|poison", 0, 50, 0);   /* 50% resistant to poison */
  set_armor_params("other|light", 0, -25, 0);   /* Extra damage from light */
  set_armor_params("other|fire", 0, -50, 0);    /* Extra damage from heat  */
  
  /* I arrived at the following bonuses by the following average stats
   * with the poison damage granting 3/2 bonus over physical:
   * 5 tentacle attacks, averaging 4 damage physical, 2 damage poison = 23 wc bonus
   * I'm cutting the bonus in half since it's low physical damage and does less damage.
   * avg 5 additional tentacle attacks at same average = 23 wc bonus altogether
   * avg 5 tentacle defenses, at 4 hp avg regen each per hb at 2 bonus per = 40 ac bonus
   */
  set_wc_bonus(23);
  set_ac_bonus(40);
  
  /* Three spells in place, each have a 15% chance of going off each will do up to 
   * 100 physical damage, one will hit just the non-players, and the other will hit just
   * the players.
   */
  add_spell("area_effect", 
            "#MN#"+HIR+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            "#MN#"+HIR+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            15, "10d10", 0, 1);
  add_spell("pet_killer",
            0,
            "#MN#"+HIC+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            15, 100, 0, 4, 0);
  add_spell("just_the_players",
            "#MN#"+HIG+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            "#MN#"+HIG+" goes into a frenzy and flails wildly with its tentacles!\n"+NORM,
            15, 100, 0, 3, 0);
} 

status corpse_check(object ob)
{
  object corpse;
  
  corpse = present("corpse", ob);
  
  if (!corpse)
    return 0;
    
  tell_room(ob, HIK+"\n\n\nThe squid glories in its kill!\n\
It grabs a corpse with a few tentacles and starts to turn around...\n\
The squid releases a cloud of ink and you can't see a thing.\n"+NORM);
  move_object(clone_object(INKCLOUD), ob);
      
  while (corpse)
  {
    move_object(corpse, HIDEOUT);
    corpse = present("corpse", ob);
  }
      
  move_object(this_object(), HIDEOUT);
  call_out("return_to_room", 10);
  return 1;
}

void heart_beat()
{
  int i, rnum, tdam, tpdam;
  object here, att, corpse;
  string attname;
  
  ::heart_beat();
  here = environment(this_object());
  
  if (find_object(MYHOME) != here) return;
  
  if (corpse_check(here)) return;
  
  /* Make sure everyone in the room is attacked */
  if (!attacker_ob)
  {
    object ob;
    
    ob = first_inventory(here);
  
    while(ob)
    {
      if (ob != this_object() && living(ob) 
      && (int)ob->is_wizard() < 1 && (status)ob->query_ghost() < 1)
      {
        att = ob;
        attacked_by(ob);
        ob->attacked_by(this_object());
      }
      
      ob = next_inventory(ob);
    }
  }
  else
  {
    att = attacker_ob;
  }
  
  if (!att) /* Turn off heartbeat if no victims are around */
  {
    set_heart_beat(0);
    return;
  }
  
  attname = (string)att->query_name();
  tdam = tpdam = 0;
  rnum = 11 + random(11);
  
  if (random(100) < 5) /* 1/20 chance of an extra attack() */
    attack(); 
  
  for (i = 0; i < rnum; i++)
  {
    if (i < 5 || !random(2)) /* Tentacle attacks */
    {
      int dmg, pdmg;
      string c;

      tdam += random(3) + random(3);  /* 0-8 damage, avg 4 */
      dmg   = random(3) + random(3);
      pdmg  = random(3) + random(3);  /* 0-4 poison damage, avg 2 */
      c = (pdmg ? GRN : "");
      
      switch(dmg)
      {
        case 0:    say(name+" misses with a swinging tentacle.\n");
                   break;
        case 1:    tell_room(here, name+c+" hits "+attname+" weakly with a tentacle.\n"+NORM, ({ att }));
                   tell_object(att, name+c+" hits you weakly with a tentacle.\n"+NORM);
                   break;
        case 2..3: tell_room(here, name+c+" hits "+attname+" with a tentacle.\n"+NORM, ({ att }));
                   tell_object(att, name+c+" hits you with a tentacle.\n"+NORM);
                   break;
        case 4:    tell_room(here, name+c+" hits "+attname+" hard with a tentacle.\n"+NORM, ({ att }));
                   tell_object(att, name+c+" hits you hard with a tentacle.\n"+NORM);
                   break;
      }
      
      if (dmg)
        att->hit_player(dmg);
        
      tpdam += pdmg;
      
      if ((int)att->query_hp() <= 0 && corpse_check(here))
        return; /* To make sure the hit_player() didn't kill them */
    }
    else
    {
      say(name+" uses its tentacles to defend itself.\n");
      heal_self(random(5)+random(5));
    }
    
  }
  
  if (tdam)
    att->hit_player(tdam);
    
  if (att && (int)att->query_hp() <= 0)
    corpse_check(here);
  else if (tpdam) 
    att->hit_player(tpdam, "other|poison");
}

void return_to_room()
{
  object myroom, ob;
  
  myroom = find_object(MYHOME);
  tell_room(myroom, "The "+name+" suddenly jumps out from the darkness!\n");
  move_object(this_object(), myroom);
  ob = present(PLAYER_ID, myroom);
  
  while(ob)
  {
    if ((int)ob->query_level() < 20 && (status)ob->query_ghost() < 1)
      ob->attacked_by(this_object());
      
    ob = next_inventory(ob);
  }
}

void init()
{
  ::init();
  set_heart_beat(1);
}

void ink_cloud()
{
  object here;
  
  here = environment(this_object());
  tell_room(here, HIK+"\nThe squid releases a massive cloud of some type of black substance!\n"+NORM);
  move_object(clone_object(INKCLOUD), here);
}

/* 
 * Ugh, I died.  Cause an overall stun, then disintigrate the corpse.  
 * Purely thematic, no other reason for this, just need a justification for 
 * leaving no corpse heh :)
 */
int monster_died()
{
  object corpse;
  
  environment()->add_exit(RPATH+"moat_cave", "enter");
  corpse = present("corpse", environment());
  destruct(corpse);
  tell_room(environment(), "The squid disintigrates as it dies.\n");
  ink_cloud();
  return 1;
}
#endif