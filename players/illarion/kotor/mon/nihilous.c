/* nihilous.c
   a nasty critter-
   his primary attack is laser, he resists most laser and
   mental attacks, and has a variety of spells, many of which
   heal him

   Also, players whose willpower are too low have a 5% chance
   each round of being instantly killed.
*/

#include "/players/illarion/dfns.h"
inherit IMM_MON;

int lightsaber_on;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  if(!present("mask"))
    move_object(clone_object(KOTOROBJ+"nihilous_mask"));
  set_name(HIK+"Darth "+HIW+"N"+HIR+"ih"+HIW+"il"+HIR+"ou"+HIW+"s"+NORM);
  set_alias("nihilous");
  set_alt_name("lord");
  set_gender("male");
  set_short("The Sith Lord, "+name);
  set_long(
      "Though at first glance Nihilous appears to be a human in black robes\n"+
      "with a red and white mask, it is instantly clear he is not human.  It's\n"+
      "more like he's a human-shaped hole in the universe- waves of hunger\n"+
      "roll away from his figure.\n");
  set_al(-1000);
  set_hp(2000);
  set_hp_bonus(1000); /* for the healing effect of the drain spell */
  set_weapon_params("other|laser",50,0);
  set_ac(20);
  set_armor_params("other|mental",0,50,0);
  set_armor_params("other|evil",0,50,0);
  set_armor_params("other|good",0,-50,0);  
 
  set_x_attack_chance(100);
  set_multi_attack(2);
  set_attacks(4);

  set_dodge_chance(25);
  add_emote("dodge",
      "$MN$ steps out of the way of your attack almost before you start to make it.\n",
      "$MN$ steps out of the way of $TN$'s attack with prescient ease.\n");
  add_emote("dodge",
      "$MN$ waves his hand, and your attack slams into an invisible wall.\n",
      "$MN$ waves his hand, and $TN$'s attack slams into an invisible wall.\n");

  set_armor_params("other|laser",20,0,"lightsaber_deflect");
  add_spell("force lightning",
      "You are struck by the $M$Force lightning$N$!\n",
      "#MN# raises #MP# hand an unleashes a storm of $M$Force lightning$N$!\n",
      10,"30-50","other|electric",1); /* hits all attackers */
  add_spell("force debris",
      "#MN# waves a gloved hand, and a piece of equipment shakes loose from\n"+
      "a nearby bulkhead and slams into you!\n",
      "#MN# waves a gloved hand, and a piece of equipment shakes loose from\n"+
      "a nearby bulkhead and slams into #TN#!\n",
      10,"20-40","physical",5);
  add_spell("force push",
      "#MN# waves a gloved hand at you, and an invisible force throws you\n"+
      "across the room and into a bulkhead!\n",
      "#MN# waves a gloved hand, and #TN# flies across the room and crashes\n"+
      "into a bulkhead!\n",
      15,"20-40","physical",5); /* hits a single attacker at random */
  add_spell("force drain",
      "One of the ropes of sickly red light attaches to your chest.\n"+
      "Your life force is drained away!\n",
      "#MN# spreads his arms, and ropes of sickly red light jump from his\n"+
      "chest, attaching themselves to his attackers!\n",
      10,"20-30","other|mental",1,"drain_heal");
  add_spell("instablick drain",
      "#MN# turns the full force of his terrible hunger on you.\n"+
      "You feel it tugging at your very soul!\n",
      0,
      10,0,0,6,"hunger_check"); /* hits a single player attacker */      
  set_death_emote("Darth Nihilous falls to the ground, his hunger finally ended, his lightsaber destroyed.\n");   
}

attacked_by(ob) {
  ::attacked_by(ob);
  if(!lightsaber_on) {
    lightsaber_on=1;
    tell_room(ETO,
        "With a loud snap-hiss, "+NAME(TO)+" ignites his red-bladed lightsaber.\n");
  }
}

drain_heal(object victim,object room,int damage) {
  if(damage > 0) {
    heal_self(2*damage);
    say(NAME(TO)+" looks stronger!\n");
  }
}

hunger_check(object victim,object room) {
  int wil;
  int life;
  wil=(int)victim->query_attrib("wil");
  if(random(27) > wil) { /* willpower of 26 or higher means this won't happen */
    tell_object(victim,
        "Your mind collapses under the force of "+NAME(TO)+"'s hunger!\n"+
        "Your life force drains away into the void.\n");
    life=4*((int)victim->query_mhp());
    heal_self(2*victim->do_damage(({life}),({"other|mental"})));
  } else {
    tell_object(victim,
        "Somehow you manage to resist "+NAME(TO)+"'s rapacious assault.\n");
  }
}

int lightsaber_deflect(object me,int dam) {
  if(random(3) && TO !=TP) { /* 2/3rds chance of laser type deflect */
    if(!random(4)) { /* 1/4 chance of deflecting the damage straight back */
      tell_room(ETO,NAME(TO)+"'s lightsaber deflects "+NAME(TP)+"'s attack straight back at "+OBJ(TP)+"!\n",({TO,TP}));
      tell_object(TP,NAME(TO)+"'s lightsaber deflects your attack straight back at you!\n");
      TP->do_damage(({dam}),({"other|laser"}));
    } else {
      tell_room(ETO,NAME(TO)+"'s lightsaber deflects "+NAME(TP)+"'s attack!\n",({TO,TP}));
      tell_object(TP,NAME(TO)+"'s lightsaber deflects your attack!\n");
    }
    return 10000;
  }
}                    
