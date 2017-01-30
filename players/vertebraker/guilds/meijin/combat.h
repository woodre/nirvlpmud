#define SINGLE_COST 6		/******************************************/
#define DOUBLE_COST 9		/* Combat cost defines - these can be     */
#define RAGE_COST   105		/* easily tweaked to make sure the combat */
#define CRIT1_COST  5		/* costs stay balanced with the game.     */
#define CRIT2_COST  15		/******************************************/
#define CRIT3_COST  25
#define CRIT4_COST  40

int
combat_beat() {
  object attacker, weapon, offwield;
  int bonus, amount, endur, wep;
  string crit_msg;

  if(!(weapon = ENV->query_weapon())) return 0;		/* must have weapon */
  if(!weapon->query_type()) return 0;			/* weapon must have type */
  if(!(attacker = ENV->query_attack())) return 0;	/* attacker present */

  endur = query_endurance();
  wep = query_guild_skill(weapon->query_type());

  /****************************************************/
  /* This section applies if we are _not_ offwielding */
  /****************************************************/
  if(!(offwield = query_off_wield())) {

	/*** suffer penalties if we are too tired ***/
	if(endur <= 0) {
		return -random(4);
	}

	/*** no bonus if using the tumble skill ***/
	if(query_skill_variable("tumble")) {
		add_endurance(-SINGLE_COST);
		return 0;
	}

	/************************************/
	/* calculate the damage bonus here. */
	/************************************/
	bonus =
	   (wep/2) +
	   random(query_guild_stat("strength")/4) +
	   random(query_guild_stat("agility")/4);
	bonus = bonus / 10;

	/*****************************************************/
	/* critical hits multiply the bonus and increase the */
        /* damage signifigantly.  criticals also have a high */
        /* endurance cost to the player.                     */
	/*****************************************************/
	if((query_guild_skill("critical") > random(999) || query_skill_variable("focus"))) {

	   /*****************************************************************/
	   /* If we are using the focus skill then critical amount is based */
	   /* on the focus stat.					    */
	   /*****************************************************************/
	   if(query_skill_variable("focus")) {
		amount = query_guild_skill("focus") * 2;
		set_skill_variable("focus", 0);
	   }
	   else amount = random(query_guild_stat("prowess") + query_guild_skill("critical"));

	   switch (amount) {
		  case 0 .. 110 :
			if(endur < CRIT1_COST) break;
			bonus += (bonus * 1);
			add_endurance(-CRIT1_COST);
			crit_msg = "[Critical! (x1)]";
			break;
		  case 111 .. 177 :
			if(endur < CRIT2_COST) break;
			bonus += (bonus * 2);
			add_endurance(-CRIT2_COST);
			crit_msg = "[Critical! (x2)]";
			break;
		  case 178 .. 190 :
			if(endur < CRIT3_COST) break;
			bonus += (bonus * 3);
			add_endurance(-CRIT3_COST);
			crit_msg = "[Critical!! (x3)]";
			break;
		  default :
			if(endur < CRIT4_COST) break;
			bonus += (bonus * 4);
			add_endurance(-CRIT4_COST);
			crit_msg = " [Critical!!! (x4)]";
			break;
		}
	}

	/*** display critical message, if any ***/
	if(crit_msg) tell_object(ENV, HIB+">>> "+HIW+crit_msg+HIB+" <<<\n"+NORM);

	/*** wizard debug message ***/
	if(ENV->query_level() > 20 && query_skill_variable("debug")) {
		tell_object(ENV, CYN+"[Damage Bonus: "+bonus+"]\n"+NORM);
	}

	/*** standard guild endurance cost ***/
	add_endurance(-SINGLE_COST);
	return bonus;
  }

  /**********************************************/
  /* this section applies if we are offwielding */
  /**********************************************/
  else {
	string *off_mess;

	/*** make sure we aren't too tired to offwield ***/
	if(query_endurance() <= 0) {
		tell_object(ENV, PRED+"You are too tired to wield two weapons.\n");
		tell_object(ENV, "You stop wielding "+offwield->query_name()+" in your "+
		query_handed(1)+" hand.\n");
		set_off_wield(0);
		return 0;
	}

	/*** weapon break stuff ***/
	weapon->count_hit_made();
	if(weapon->query_wear() > 1 && random(4000000/weapon->query_wear()) < 10) {
		weapon->weapon_breaks();
	}

	/*** no offwield damage when parrying ***/
	if(query_skill_variable("parry")) {
		add_endurance(-DOUBLE_COST);
		return 0;
	}

	/*** get the offwield damage, use normal living.c damage checks ***/
	wep = offwield->weapon_class();
        if(ENV->query_level() < 20 && wep > 30) wep = 10 + random(12);
	if(ENV->query_level() < 20 && wep > 24) wep = 24;

	/*** calculate the offwield damage ***/
	bonus =
	   query_guild_skill("offwield")/2 +
	   random(query_guild_skill(offwield->query_type())/4) +
	   random(query_guild_stat("dexterity")/4);
	bonus = (wep * bonus) / 100;

	/*** report the hit_message ***/
	off_mess = offwield->query_message_hit(bonus);
	if(!off_mess) off_mess = ENV->query_message_hit(bonus);
	tell_object(ENV, "You "+off_mess[1]+" "+capitalize(attacker->query_name())+off_mess[0]+".\n");
	tell_object(attacker, capitalize(ENV->query_name())+" "+off_mess[1]+" you"+off_mess[0]+".\n");
	room_say(ENV, capitalize(ENV->query_name())+" "+off_mess[1]+" "+capitalize(attacker->query_name())+
		off_mess[0]+".\n");

	/*** wizard debug message ***/
	if(ENV->query_level() > 20 && query_skill_variable("debug"))
		tell_object(ENV, CYN+"[Offwield Dmg: "+bonus+"]\n"+NORM);

	/*** endurance cost is double when offwielding ***/
	add_endurance(-DOUBLE_COST);
	return bonus;
  }
}

/**************************************************/
/* rage_beat is called in place of combat_beat    */
/* when the player is using the xrage skill.      */
/* xrage allows the player to have twice as many  */
/* attacks during a combat round.                 */
/**************************************************/
int
rage_beat() {
  int dam, total;
  string *messages;
  object attacker, wep, off;
  int i;

  if(!(wep = ENV->query_weapon())) return 0;
  if(!(attacker = ENV->query_attack())) return 0;
  off = query_off_wield();
  messages = ({});

  if(!off) {
	/****************************************/
	/* Two extra attacks with single weapon */
	/****************************************/
	for(i=0; i<2; i++) {
		dam = random(wep->weapon_class());
		messages += wep->query_message_hit(dam);
		total += dam;
	}
  }
  else {
	/*************************************************/
	/* One attack with primary and one with offwield */
	/*************************************************/
	dam = random(off->weapon_class());
	messages += off->query_message_hit(dam);
	total += dam;

	dam = random(wep->weapon_class());
	messages += wep->query_message_hit(dam);
	total += dam;
  }

  for(i=0; i<sizeof(messages); i+=2) {
	tell_object(ENV, "You "+messages[i+1]+" "+capitalize(attacker->query_name())+messages[i]+".\n");
	tell_object(attacker, capitalize(ENV->query_name())+" "+messages[i+1]+" you"+messages[i]+".\n");
	room_say(ENV, capitalize(ENV->query_name())+" "+messages[i+1]+" "+
		capitalize(attacker->query_name())+messages[i]+".\n");
  }

  add_endurance(-RAGE_COST);
  return total;
}

/***************************************************/
/* shield_bonus is the paladin's shield function.  */
/* this function is used for the guild tumble and  */
/* parry skills to improve the players armor class */
/***************************************************/
int
shield_bonus() {
  if(query_skill_variable("tumble"))
	return tumble_bonus();
  else if(query_skill_variable("parry"))
	return parry_bonus();
  else
	return 0;
}

/*
 * tumble is a weaker version of parry
 */
int
tumble_bonus() {
  int bonus;
  string name;

  if(query_off_wield()) {
	tell_object(ENV, PRED+"You are no longer tumbling.\n");
	remove_skill_variable("tumble");
	return 0;
  }

  name = capitalize(ENV->query_attack()->query_name());
  bonus = query_guild_stat("tumble") + query_guild_stat("dexterity");
  bonus = random(bonus) / 39;		/* max possible = 5 */

  if(bonus > 2) {
	tell_object(ENV, PRED+HIW+"You tubmle away from "+name+"'s attack.\n");
	room_say(ENV, MYNAME+" tubmles away from "+name+"'s attack.\n");
  }
  return bonus;
}

int
parry_bonus() {
  object offwield, attacker;
  string name;
  int ac_bonus;

  if(!(offwield = query_off_wield())) {
	tell_object(ENV, PRED+"You are no longer attempting to parry your enemy's attacks.\n");
	remove_skill_variable("parry");
	return 0;
  }

  attacker = ENV->query_attack();
  name = capitalize(attacker->query_name());
  ac_bonus = offwield->weapon_class() / 2;
  if(ac_bonus > 10) ac_bonus = 10;

  switch (random(query_guild_skill("parry") + query_guild_stat("dexterity"))) {
     case 0 .. 80 :
	tell_object(ENV, PRED+HIW+"You deflect some of "+name+"'s attack.\n"+NORM);
	tell_object(attacker, MYNAME+" deflects some of your attack.\n");
	room_say(ENV, MYNAME+" deflects some of "+name+"'s attack.\n");
	return (ac_bonus / 4);		/* mx: 2 */
	break;
     case 81 .. 140 :
	tell_object(ENV, PRED+HIW+"You parry some of "+name+"'s attack.\n"+NORM);
	tell_object(attacker, MYNAME+" parries some of your attack.\n");
	room_say(ENV, MYNAME+" skillfully parries some of "+name+"'s attack.\n");
	return 2 * (ac_bonus / 4);	/* mx: 4 */
	break;
     case 141 .. 170 :
	tell_object(ENV, PRED+HIW+"You deflect most of "+name+"'s attack!\n"+NORM);
	tell_object(attacker, MYNAME+" deflect most of your attack!\n");
	room_say(ENV, MYNAME+" deflect most of "+name+"'s attack!\n");
	return 2 * (ac_bonus / 3);	/* mx:  6 */
	break;
     case 171 .. 190 :
	tell_object(ENV, PRED+HIW+"You quickly parry most of "+name+"'s attack!\n"+NORM);
	tell_object(attacker, MYNAME+" quickly parries most of your attack!\n");
	room_say(ENV, MYNAME+" quickly parries most of "+name+"'s attack!\n");
	return 4 * (ac_bonus / 5);	/* mx: 8 */
	break;
     default :
	tell_object(ENV, PRED+HIW+"You masterfully parry "+name+"'s attack!\n"+NORM);
	tell_object(attacker, MYNAME+" masterfully parries your attack!\n");
	room_say(ENV, MYNAME+" masterfully parries "+name+"'s attack!\n");
	return ac_bonus;		/* mx: 10 */
	break;
  }
  return 0;
}

void
room_say(myself, str) {
  object ob, attk;
  int i;

  ob = all_inventory(environment(myself));
  attk = myself->query_attack();
  for(i=0; i<sizeof(ob); i++) {
	if(ob[i] == myself || ob[i] == attk) continue;
	tell_object(ob[i], str);
  }
  return;
}

