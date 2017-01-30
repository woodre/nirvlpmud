#include "/players/illarion/dfns.h"
inherit IMM_MON;

int lives;
int extra_exp;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  lives=5;
  set_name(HIK+"Darth "+HIR+"Sion"+NORM);
  set_alias("sion");
  set_alt_name("lord");
  set_gender("male");
  set_short("The Sith Lord, "+name);
  set_hp(250);
  set_weapon_params("other|laser",10,0);
  set_multi_attack(2);
  set_attacks(2);
  set_x_attack_chance(100);
  
  set_ac(10);
  set_dodge_chance(20);

  add_emote("dodge","$MN$ shrugs off your attack.  It hit him, but it just didn't affect him.\n",
      "$MN$ seems completely unaffected by $TN$'s attack.\n");
  set_armor_params("other|laser",10,0,"lightsaber_deflect");
  set_armor_params("other|evil",0,50,0);
  set_armor_params("other|good",0,-50,0);
  set_al(-1000);
  
  add_spell("force lightning",
      "You are struck by the $M$Force lightning$N$!\n",
      "#MN# raises #MP# hand an unleashes a storm of $M$Force lightning$N$!\n",
      10,"30-50","other|electric",1); /* hits all attackers */
  add_spell("force push",
      "#MN# waves a shattered hand at you, and an invisible force throws you\n"+
      "across the room and into a bulkhead!\n",
      "#MN# waves a shattered hand, and #TN# flies across the room and crashes\n"+
      "into a bulkhead!\n",
      15,"20-40","physical",5); /* hits a single attacker at random */
  add_spell("force drain",
      "One of the ropes of sickly red light attaches to your chest.\n"+
      "Your life force is drained away!\n",
      "#MN# spreads his arms, and ropes of sickly red light jump from his\n"+
      "chest, attaching themselves to his attackers!\n",
      10,"20-30","other|mental",1,"drain_heal");

}

drain_heal(object victim,object room,int damage) {
  if(damage > 0) {
    heal_self(damage);
    say(NAME(TO)+" looks stronger!\n");
  }
}

lightsaber_deflect(object me, int dam) {
  if(random(3) && TO != TP) {
    if(!random(4)) {
      tell_room(ETO,
          NAME(TO)+"'s lightsaber deflects "+NAME(TP)+"'s attack straight back at "+OBJ(TP)+"!\n",
          ({TP,TO}));
      tell_object(TP,NAME(TO)+"'s lightsaber deflects your attack straight back at you!\n");
    } else {
      tell_room(ETO,
          NAME(TO)+"'s lightsaber deflects "+NAME(TP)+"'s attack!\n",
          ({TP,TO}));
      tell_object(TP,NAME(TO)+"'s lightsaber deflects your attack!\n");
    }
    return 10000;
  }
}

second_life() {
  int mult;
  object corpse;
  corpse=present("corpse",ETO);
  if(corpse) destruct(corpse);
  if(lives>0) {
    lives--;
    tell_room(ETO,
        NAME(TO)+" laughs harshly, and climbs to his feet.  \""+HIK+"The Force sustains\n"+
        "me.  No matter how many times I fall, I will rise again, even stronger!\""+NORM+"\n");
    extra_exp+=::calculate_worth();
    mult=5-lives;
    set_hp(250+mult*250);
    set_weapon_params("other|laser",15+mult*4,0);
    set_ac(10+mult*4);
    set_dodge_chance(20+5*mult);
    set_attacks(2+mult);
    return 1;
  } else {
    tell_room(ETO,
        NAME(TO)+" tries to get up, but falls back to the ground with a sickly crunching\n"+
        "sound.  His body falls into pieces, which fall into dust, even as his disembodied\n"+
        "voice protests, \""+HIK+"NO!  I cannot die!\""+NORM+"\n");
    return 0;
  }
}

calculate_worth() {
  if(lives > 0) return 0;
  else return ::calculate_worth()+extra_exp;
}

