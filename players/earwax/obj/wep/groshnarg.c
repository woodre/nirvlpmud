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

#define WEPDIR "/players/earwax/obj/wep/"

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
  object wep;
  
  ::reset(arg);
  set_name(BOLD+"General Groshnarg"+NORM);
  set_race("qtip");
  set_level(50);
  set_al(0);
  set_hp(5000); /* Randomize this later */
  set_wc(90);
  set_ac(50);
  set_short(BOLD+"General Groshnarg"+NORM+", of the "+HIR+"Swabbian Army"+NORM);
  set_long(name+" is intimidating to say the least.  The former General\n\
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
  wep = clone_object(WEPDIR+"axe");
  move_object(wep, this_object());
  init_command("wield axe");
  add_spell("charge tank", 
    "$R$#MN#$N$R$ charges at you swinging his axe, spear and shield!$N$\n",
    "$C$#MN#$HC$ charges at #TN# swinging his axe, spear and shield!$N$\n",
    15, "3d25+25", 0, 0, 0, 0);
  add_spell("charge pets",
    0, /* for pets, so no msg necessary */
    "$C$#MN#$C$ charges forward wildly laying about him with all four arms!$N$\n", 
    25, "5d5+5", 0, 4);
  add_spell("charge everyone",
    "$R$#MN#$R$ charges forward wildly laying about him with all four arms!$N$\n", 
    "$R$#MN#$R$ charges forward wildly laying about him with all four arms!$N$\n", 
    25, "5d5+5", 0, 1);
  add_spell("charge at random",
    "$R$#MN#$HR$ gets a strange gleam in his eyes and launches himself right at you!$N$\n",
    "$C$#MN#$N$C$ eyes #TN# strangely then charges forward!\n$N$",
    35, ({ "2d5", "2d5", "2d5", "2d5", "2d5", "2d5", "2d5", "2d5"}), 0, 5);
    
  TotalRounds = 1;  
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
  
  wc_bonus = TotalGiven / TotalRounds;
  ac_bonus = ExtraAc / TotalRounds;
  TotalRounds++;
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
    
  chance = (Current - hit_point); /* How much damage they took */
  
  if (chance > 50 && random(100) < chance) /* Counter based on damage taken */
  {
    tell_room(here, "\nAfter staggering back for a second, "+name+" shakes his head\n\
a few times angrily, jerks his weapons up and charges forward in a rage!\n"+NORM);

    /* Specific attack on the tank */
    tell_object(ob, "\
You apparently hurt "+name+" somewhat, but now he's got a maniacal look in his \n\
eyes and he's swinging his axe right at your head!\n\n");
    dam = 25 + random(26);
    if (chance >  75) dam += random(26);
    if (chance > 100) dam += random(26); /* Punishment for dealing damage heh */
    if (chance > 150) dam += random(26);
    if (chance > 200) dam += random(26);
    if (chance > 250) dam += random(26);
    TotalGiven += dam;
    msg = query_message_hit(dam);
    tell_object(ob, name+" "+msg[1]+" you"+msg[0]+".\n\n\n");
    tell_room(here, HIR+name+" strikes viciously at "+(string)ob->query_name()+HIR+" with his axe!\n\n"+NORM, ({ ob }));
    tell_room(here, name+" "+msg[1]+" "+(string)ob->query_name()+msg[0]+".\n\n", ({ ob }));
    ob->hit_player(dam);
  }
    
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
  
  if (!random(5)) /* Show a defensive armor emote - woot spammage! */
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
                   tell_room(here, name+ " counter-attacks "+attname+" with his spear.\n", ({ them }));
                   break;
      case 31..40: write(name+RED+" counter-attacks you brutally with his spear!\n"+NORM);
                   tell_room(here, name+CYN+" counter-attacks "+attname+NORM+CYN+" brutally with his spear!\n"+NORM, ({ them }));
                   break;
      case 41..50: write(name+HIR+" viciously impales you with a counter-strike from his spear!\n"+NORM);
                   tell_room(here, name+CYN+" impales "+attname+NORM+CYN+" brutally with his spear!\n"+NORM, ({ them }));
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
                   tell_room(here, attname+ " get shield-bashed by the General.\n", ({ them }));
                   break;
      case 16..20: write(name+RED+" bashes you hard with his shield.\n"+NORM);
                   tell_room(here, attname+ " gets shield-bashed hard by the General.\n", ({ them }));
                   break;
      case 21..25: write(name+RED+" bashes you HARD with his shield.\n"+NORM);
                   tell_room(here, attname+ " gets shield-bashed HARD by the General.\n", ({ them }));
                   break;
    }
    
    totaldam += dam;
    TotalGiven += dam;
  }

  if (totaldam)
    them->hit_player(totaldam);
    
  if (chance > 74) { ExtraAc +=  2; return random(5); } /*  */
  if (chance > 50) { ExtraAc +=  6; return 0105; } /* 01% res, +05 ac if 50-75% hps */
  if (chance > 40) { ExtraAc += 10; return 0406; } /* 04% res, +06 ac if 40-50% hps */
  if (chance > 30) { ExtraAc += 15; return 0807; } /* 08% res, +07 ac if 30-40% hps */
  if (chance > 20) { ExtraAc += 21; return 1208; } /* 12% res, +08 ac if 20-30% hps */
  if (chance > 10) { ExtraAc += 26; return 1609; } /* 16% res, +09 ac if 10-20% hps */
  else             { ExtraAc += 30; return 2010; } /* 20% res, +10 ac if  0-10% hps */
}

