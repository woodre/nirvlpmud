/*
//  Created:      Forbin@Nirvana
//  Copyright:    Copyright (c) 2005 Forbin
//                  All Rights Reserved.
//  Realm:        Sir Faris Perham Miniquest
//  Function:     Weapon
//  Create Date:  2005.07.16
//  Last Edit:    2005.07.16 -Forbin
//  Notes:        modeled after: 
//                /players/daranath/qualtor/newstuff/weps/dmace_maj.c
//                  Copyright (c) Daranath
//                with a little added flavor based on: 
//                /players/fred/closed/bloodfist/EQ/es.c
//                  Copyright (c) Zeus/Fred
//  -21 WC, weight 5 weapon (WC not static, tied to wear)
//  -weapon cannot be repaired if broken
//  -38% chance (w/ maxed piety) of special attack, 1-2 other|light and
//     1-2 other|good damage to evil aligned, or 2-8 other|light and
//     2-8 other|good damage to undead creatures, 
//  -has a 1% chance 38% of time instantly kill undead.
//  -smaller returns of 3 (13%), 2 (13%), 1 (6%) if the piety special isn't called
//  DISCLAIMER:
//    Before you get bent out of shape about the weapon, realize it has to 
//    be gained from a miniquest of sorts requiring the following:
//      1.  Either Llew's Crystal Longsword or Snow's Glowing Sword
//      2.  Zeus' Ancient Talisman (from Fallen Lands quest)
//      3.  Snow's Black Diamond (from Cleoprites) 
/     This will require the player to kill AT LEAST 8 lvl 15 mobs, 3 lvl 19 mobs, 
//    10 lvl 21 mobs, and 2 lvl 25 mobs, all in fairly dangerous 
//    situations while figuring out where to find the needed items to trade 
//    for the weapon.
*/

#include "/players/forbin/realms/cave/cavedefine.h"

#define MOD +(!random(2) ? HIW+"Mace of Disruption"+NORM : HIW+"Disruption Mace"+NORM)+
#define WHO capitalize((string)environment()->query_name())
#define WHOP (string)environment()->query_possessive()
#define WHOO (string)environment()->query_objective()

inherit "obj/weapon.c";

int funcd;
string *hits1, *hits2;

/* Prototype Declaration */
void undead_check(object ob);

void reset(status arg) {
  ::reset(arg);
  if(arg)return;

  funcd = 0;
  
  message_hit = ({
    "PULVERIZED"," with a blow from "+BOLD+"HELL"+NORM,    
    "BLUDGEONED"," into "+BOLD+"unrecognizable pulp"+NORM,
    "SMASHED"," with demonic force",
    "bashed ",", with a sickening CRUNCH",
    "bonked "," leaving a sizeable welt",
    "clunked"," just missing a solid blow",
    "tapped"," with hardly any result"
  });  
  
  set_name("distruption mace");
  set_alias("mace");
  set_alt_name("mace of disruption");
  set_short(HIW+"Mace of Disruption"+NORM);
  set_long(
    "An ancient weapon from the long forgotten city of Qualtor, the\n"+
    "Mace of Disruption was a holy instrument used to rid the realm of\n"+
    "undead fiends.  Eight long blades wreathe the diamond-shaped head,\n"+
    "and its handle of black wood cut from the forests of the Underdark\n"+
    "is banded in several places with metal strips.  The end of the\n"+
    "handle is wrapped in leather to form a wide grip.  Legends are\n"+
    "told of the god Tarkos' intervention and blessing of a handful of\n"+
    "these maces.  Being imbued with such heavenly power, a Mace of\n"+
    "Disruption can be highly sought in the war against the ever\n"+
    "burgeoning rise of evil.\n");
  set_class(21);
  set_type("club");
  set_weight(5);
  set_light(2);
  set_value(10750);
  set_hit_func(this_object());
}

status query_save_flag() { 
  if(broke) return 1;  
  else return 0; 
}

int fix_weapon() { 
  if(!broke) return 0;
  if(broke)
    write("This weapon is beyond repair, it cannot be fixed.\n");
  return 1;
}

int weapon_breaks() {
  if(broke) return 1;
  save_flag = 0;
  tell_object(environment(),
    "\nThere is a loud pop as your "MOD" breaks!\n\n");
  tell_room(environment(environment()),
    "\nThere is a loud pop as "+WHO+"'s "MOD" breaks!\n", ({ environment() }));
  class_of_weapon = 3;
  broke = 1;
  this_object()->set_silentwield(1);
  command("unwield "+name_of_weapon, environment());
  command("wield "+name_of_weapon, environment());
  this_object()->set_silentwield(0);
  long_desc =
    "An ancient weapon from the long forgotten city of Qualtor, the\n"+
    "Mace of Disruption was a holy instrument used to rid the realm of\n"+
    "undead fiends.  Eight long blades wreathe the diamond-shaped head,\n"+
    "and its handle of black wood cut from the forests of the Underdark\n"+
    "is banded in several places with metal strips.  The end of the\n"+
    "handle is wrapped in leather to form a wide grip.  Legends are\n"+
    "told of the god Tarkos' intervention and blessing of a handful of\n"+
    "these maces.  Being imbued with such heavenly power, a Mace of\n"+
    "Disruption can be highly sought in the war against the ever\n"+
    "burgeoning rise of evil.  The handle seems to have snapped in two,\n"+
    "making the weapon fairly useless now.\n";
  return 1;
}

int weapon_class() {             /* actual wc based on wear */
	int wear;
  wear = (int)::query_wear();
  if(broke)
    return 3;                    /* is the weapon broken? */
  if(wear > 399)                 /* well worn */
    return 16;
  if(wear > 199 && wear < 400)   /* worn */
    return 18;
  if(wear > 99 && wear < 200)    /* somewhat worn */
    return 19;
  if(wear > 39 && wear < 100)    /* a little worn */
    return 20;
  if(wear < 40)                  /* like new */
    return 21;
}

void define_arrays() {
  funcd = 1;
  hits1 =({
    "You swing the "MOD" in front of you.\n",
    "You bring the "MOD" downward across your body.\n",
    "You bring the "MOD" upward across your body.\n",
    "Spinning the "MOD" underhanded, you swing it up through the air.\n",
    "Spinning the "MOD" overhanded, you swing it down through the air.\n",
    "You leap ahead, driving the "MOD" forward.\n",
    "You lean left, swinging the "MOD" defensively.\n",
    "You lean left, swinging the "MOD" into a parry.\n", 
    "Stepping left, you parry with the "MOD".\n",   
    "You lean right, swinging the "MOD" defensively.\n",
    "You lean right, swinging the "MOD" into a parry.\n",
    "Stepping right, you parry with the "MOD".\n",
    "You lean back, bringing the "MOD" up to block.\n",
    "You swing the "MOD" over your head before striking out.\n",
    "You bring down the "MOD" quickly from overhead\n",
    "You sling the "MOD" violently in front of you.\n",
    "You rip the "MOD" quickly back and forth before you.\n",
    "You gracefully swing the "MOD" in a wide arc.\n",
  });

  hits2 =({
    WHO+" swings the "MOD" in front of "+WHOO+".\n",
    WHO+" brings the "MOD" downward across "+WHOP+" body.\n",
    WHO+" brings the "MOD" upward across "+WHOP+" body.\n",
    "Spinning the "MOD" underhanded, "+WHO+" swings it up through the air.\n",
    "Spinning the "MOD" overhanded, "+WHO+" swings it down through the air.\n",
    WHO+" leaps ahead, driving the "MOD" forward.\n",
    WHO+" leans left, swinging the "MOD" defensively.\n",
    WHO+" leans left, swinging the "MOD" into a parry.\n", 
    "Stepping left, "+WHO+" parries with the "MOD".\n",   
    WHO+" leans right, swinging the "MOD" defensively.\n",
    WHO+" leans right, swinging the "MOD" into a parry.\n",
    "Stepping right, "+WHO+" parries with the "MOD".\n",
    WHO+" leans back, bringing the "MOD" up to block.\n",
    WHO+" swings the "MOD" over "+WHOP+" head before striking out.\n",
    WHO+" brings down the "MOD" quickly from overhead\n",
    WHO+" slings the "MOD" violently in front of "+WHOO+".\n",
    WHO+" rips the "MOD" quickly back and forth before "+WHOO+".\n",
    WHO+" gracefully swings the "MOD" in a wide arc.\n",
  });
}

int weapon_hit(object att) {
  int a, b, p, k;
  
  if(broke) return 0; /* no specials if the weapon is broken */
  
  a = random(100);
  b = random(100);
  
  if(!funcd) define_arrays();
  p = random(sizeof(hits1));
  k = random(15);
  
  tell_object(environment(), hits1[p]);  
  tell_room(environment(environment()), hits2[p], ({ environment() }));
  
  if(this_player()->query_attrib("pie") > random(80)) {
    tell_object(environment(),
      "\nThe "MOD" glows with a "+WHT+"soft light"+NORM+".\n");    
    tell_room(environment(environment()),
      "The "MOD" glows with a holy light.\n", ({ environment() }));

    if(undead_check(att)) {
      if(a > 2) { /* 98% of time this attack is called on undead */
        tell_object(environment(),
          "The light from the "MOD" flares brightly.\n"+
          (string)att->query_name()+" screams loudly as the "+HIY+"Holy Light"+NORM+
          " tears into its undead form.\n");
        tell_room(environment(environment()),
          "\nThe light from the mace "+HIW+"BURNS"+NORM+" into "+
          (string)att->query_name()+"'s form.\n\n", ({ environment() }));
        att->hit_player(2+random(7), "other|light");
        att->hit_player(2+random(7), "other|good");
        return 1; 
      }
      if(b < 75) {       /* 75% of 2% of 38% this attack is called */
        object targ;     /* 6/1000ths chance of massive attack on undead */
        targ = present(att, environment(this_player()));
        tell_object(environment(),
          "The "MOD" fills the area with a brilliant\n\n"+
          "           "+HIW+"     |       "+NORM+"\n"+
          "       "+ HIW+"<<-- "+HIY+"HOLY LIGHT"+HIW+" -->>"+NORM+"\n"+
          "           "+HIW+"     |       "+NORM+"\n\n");
        if((int)targ->query_hp() > 600)
          tell_object(environment(),
            (string)targ->query_name()+" is blasted by the light.\n");
        else
          tell_object(environment(),
            (string)targ->query_name()+" turns to dust from the light.\n");
        tell_room(environment(environment()),
          "\nLight streams from the "+HIW+"Holy Mace"+NORM+" and "+HIY+"BLASTS"+NORM+
          "the "+(string)targ->query_name()+"!\n\n", ({ environment() }));
        if((int)targ->query_hp() > 600) 
          targ->hit_player(((int)targ->query_mhp() / 2), "other|forbin");
        else 
          targ->death(); 
      }
      return 0;
    }
    if(att->query_alignment() < 0) {
      att->hit_player(1+random(2), "other|light");
      att->hit_player(1+random(2), "other|good");
    }
    return 1;
  }
  
  switch(k) {
    case 0..1:
      tell_object(environment(),
        "With a great heave you bring the "MOD" crashing\n"+
        "down on "+(string)att->query_name()+"...\n\n"+
        RED+"Blood spurts from "+(string)att->query_objective()+
        RED+", showering the ground.\n"+NORM);
      tell_room(environment(environment()),
        "With a great heave, "+WHO+" brings the "MOD" crashing\n"+
        "down on "+(string)att->query_name()+"...\n\n"+
        RED+"Blood spurts from "+(string)att->query_objective()+
        RED+", showering the ground.\n"+NORM, ({ environment() }));
      return 3;
      break;
    case 2..3:
      tell_object(environment(),
        "Fiercely grunting, you swing the "MOD" across\n"+
        "your body, striking out at your opponent...\n\n"+
        "The razor edges of the mace tear into "+(string)att->query_name()+
        "\n\t"+HIR+". :. :: : "+NORM+RED+
        "A cloud of blood streaks the air "+HIR+": :: .: .\n"+NORM);
      tell_room(environment(environment()),
        "Fiercely grunting, "+WHO+" swings the "MOD" across\n"+
        WHOP+" body, striking out at "+WHOP+" opponent...\n\n"+
        "The razor edges of the mace tear into "+(string)att->query_name()+
        "\n\t"+HIR+". :. :: : "+NORM+RED+
        "A cloud of blood streaks the air "+HIR+": :: .: .\n"+NORM, ({ environment() }));
      return 2;
      break;
    case 4:
      tell_object(environment(),
        "Yanking the "MOD" back across your torso, you\n"+
        "smash into "+(string)att->query_name()+" with a sickening force...\n\n"+
        RED+"\tBlood immediately sprays from the wound!\n"+NORM);
      tell_room(environment(environment()),
        "Yanking the "MOD" back across "+WHOP+" torso, "+WHO+"\n"+
        "smashes into "+(string)att->query_name()+" with a sickening force...\n\n"+
        RED+"\tBlood immediately sprays from the wound!\n"+NORM, ({ environment()}));
     return 1;
     break;
    case 5:
      tell_object(environment(),
        "\nAs you swing the "MOD" through the air... \n\t\t"+
        RED+"- Blood splatters everywhere! -\n\n"+NORM);
      tell_room(environment(environment()), 
        "\nAs "+WHO+" swings the "MOD" through the air... \n\t\t"+
        RED+"Blood splatters everywhere!\n\n"+NORM, ({ environment() }));
      break;
    case 6:
      tell_room(environment(environment()), 
        RED+"Blood"+NORM+" drips from the "MOD" onto the ground.\n", ({ environment() }));
      tell_object(environment(), 
        RED+"Blood"+NORM+" drips from the "MOD" onto the ground.\n");
      break;    
    case 7..15:
      break;
  } 
  return 0;
}

status undead_check(object ob) {
  if(call_other(ob,"id", "undead") || call_other(ob, "id", "skeleton") ||
     call_other(ob, "id", "spirit") || call_other(ob, "id", "wraith") ||
     call_other(ob, "id", "dracula") || call_other(ob, "id", "vampire") ||
     call_other(ob, "id", "zombie") || call_other(ob, "id", "banshee") ||
     call_other(ob, "id", "ghost") || call_other(ob, "id", "revenant") ||
     call_other(ob, "id", "mummy") || call_other(ob, "id", "dracolich") ||
     call_other(ob, "id", "lich") || call_other(ob, "id", "ghoul") ||
     call_other(ob, "id", "frankenstein") || call_other(ob, "id", "corpse"))
    return 1;
  else 
    return 0;
} 

int query_wear() {
  int wear;
  wear = 3*misses/5 + 2*hits/11;
  return wear;
}
