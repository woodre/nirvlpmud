/* The purpose of this code is to hopefully stop Dervish guild
 * members from using their auto-lead drawback to attack a very
 * weak monster, become the tank, and steal any exp.
 * If they attempt to attack a monster below 15% of max hp
 * and the monster is already fighting someone else, the
 * attack will fail
 *  Illarion  10/30/02
 */
check_dervish_attack(object meat) {
  object room,meat_attacker;
  int meat_hp,meat_mhp;
  if(!meat)
    return 0;
/* This check doesn't apply to PK.  It won't allow PK either, it just
 * doesn't forbid it.
 */
  if(meat->is_player())
    return 1;
  room=environment(meat);
  if(!room)
    return 0;
  meat_attacker=meat->query_attack();
/* If the monster isn't fighting anyone else, is fighting the dervish,
 * or the person they're fighting is gone then we can allow the fight.
 */
  if(!meat_attacker || !present(meat_attacker,room) || meat_attacker == this_player())
    return 1;

  meat_hp=meat->query_hp();
  meat_mhp=meat->query_mhp();
/* If the monster has no max_hp set we can't calculate */
  if(meat_mhp==0) return 1;
/* The Dervish is attacking a weakened monster someone else is already
 * fighting.  Don't allow it. */
  if(100*meat_hp/meat_mhp <= 15) {
    return 0;
  }
/* Otherwise, it should now be okay. */
  return 1;
}

static sand_missle(str){
  object meat;
  int dmg;
  if(this_player()->query_level() < 5) return 0;
  if(this_player()->query_spell_dam()) {
    write("The Sands are already lending strength to your attack.\n");
  spell_attacks ++;
    return 1; }
  if(str) meat = present(str, environment(TP));
/* If the spell is being used to start combat, see if the monster
 * is already low on hps and being attacked by someone else.
 */
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }
  if(!meat) meat = TP->query_attack();
  if(!meat) { write("Attack what?\n"); return 1; }
  dmg = 5+random(10);
  TP->spell_object(meat,"",dmg,10,
      get_at_msg(meat,dmg),"",get_rm_msg(meat,dmg));
  TP->set_spell_dtype("other|earth");
  return 1; }

static sand_shock(str) {
  object meat;
  int dmg;
  if(this_player()->query_level() < 10) return 0;
  if(this_player()->query_spell_dam()) {
    write("The Sands are already lending strength to your attack.\n");
  spell_attacks ++;
    return 1; }
  if(str) meat = present(str, environment(TP));

/* If the spell is being used to start combat, see if the monster
 * is already low on hps and being attacked by someone else.
 */
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }

  if(!meat) meat = TP->query_attack();
  if(!meat) { write("Attack what?\n"); return 1; }
  dmg = 8+random(14);
  TP->spell_object(meat,"NAME",dmg,15,
      get_at_msg(meat,dmg),"",get_rm_msg(meat,dmg));
  TP->set_spell_dtype("other|earth");
  return 1; }

static sand_fireball(str) {
  object meat;
  int dmg;
  if(this_player()->query_level() < 15) return 0;
  if(this_player()->query_spell_dam()) {
    write("The Sands are already lending strength to your attack.\n");
  spell_attacks ++;
    return 1; }
  if(str) meat = present(str, environment(TP));

/* If the spell is being used to start combat, see if the monster
 * is already low on hps and being attacked by someone else.
 */
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }

  if(!meat) meat = TP->query_attack();
  if(!meat) { write("Attack what?\n"); return 1; }
  dmg = 12+random(16);
  TP->spell_object(meat,"NAME",dmg,20,
      get_at_msg(meat,dmg),"",get_rm_msg(meat,dmg));
  TP->set_spell_dtype("other|earth");
  return 1; }

static sand_sonic(str) {
  object meat;
  int dmg;
  if(this_player()->query_extra_level() < 5) return 0;
  if(this_player()->query_spell_dam()) {
    write("The Sands are already lending strength to your attack.\n");
  spell_attacks ++;
    return 1; }
  if(str) meat = present(str, environment(TP));

/* If the spell is being used to start combat, see if the monster
 * is already low on hps and being attacked by someone else.
 */
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }

  if(!meat) meat = TP->query_attack();
  if(!meat) { write("Attack what?\n"); return 1; }
  dmg = 15+random(18);
  TP->spell_object(meat,"NAME",dmg,25,
      get_at_msg(meat,dmg),"",get_rm_msg(meat,dmg));
  TP->set_spell_dtype("other|earth");
  return 1; }

/* override the basic kill function too */
kill(str) {
  object meat;
  if(!str) return 0;
  meat=present(str,environment(TP));
  if(meat) if(!check_dervish_attack(meat)) {
    write("The sands stay your arm, and bid you find a worthy opponent.\n");
    return 1;
  }
  return 0;
}

get_at_msg(object meat, int num) {
  string meatn, msg;
  if(!meat) return;
  meatn = meat->query_real_name();
  if(!meatn) meatn = meat->query_name();
  if(!meatn) meatn = "something";
  meatn = capitalize(meatn);
  switch(num) {
  case 0..9:     msg = "A zephyr gives speed to your arm."; break;
  case 10..15:   msg = "The Sands lend power to your blow."; break;
  case 16..18:   msg = BOLD+"Particles of sand whip into "+meatn+"."; break;
  case 19..22:   msg = BOLD+"You attack with ungodly speed!"; break;
  case 23..25:   msg = RED+"The Scirocco whips into "+meatn+"!"; break;
  case 26..28:   msg = RED+"Winds flay the skin from "+meatn+"'s bones!"; break;
  case 29..31:   msg = RED+"Flecks of fire burn into "+meatn+"!"; break;
  case 32..34:   msg = BOLD+RED+meatn+" is hammered by the Sands!"; break;
  case 35..37:   msg = BOLD+RED+"Your motions blur as you rip into "+meatn+"!";
                 break;
  case 38..45:   msg = BOLD+RED+"The SandStorm blasts into "+meatn+"!"; break;
  }
  return msg+OFF+"\n";
}

get_rm_msg(meat, num) {
  string meatn, msg;
  if(!meat) return;
  meatn = meat->query_real_name();
  if(!meatn) meatn = meat->query_name();
  if(!meatn) meatn = "something";
  meatn = capitalize(meatn);
  switch(num) {
  case 0..9:     msg = "A zephyr gives speed to "+TP->query_name()+"'s arm."; break;
  case 10..15:   msg = "The Sands lend power to "+TP->query_name()+"'s blow."; break;
  case 16..18:   msg = BOLD+"Particles of sand whip into "+meatn; break;
  case 19..22:   msg = BOLD+TP->query_name()+" attacks with ungodly speed!"; break;
  case 23..25:   msg = RED+"The Scirocco whips into "+meatn+"!"; break;
  case 26..28:   msg = RED+"Winds flay the skin from "+meatn+"'s bones!"; break;
  case 29..31:   msg = RED+"Flecks of fire burn into "+meatn+"!"; break;
  case 32..34:   msg = BOLD+RED+meatn+" is hammered by the Sands!"; break;
  case 35..37:   msg = BOLD+RED+TP->query_name()+"'s motions blur as "+
                 TP->query_gender()+" rips into "+meatn+"!"; break;
  case 38..45:   msg = BOLD+RED+"The SandStorm blasts into "+meatn+"!"; break;
  }
  return msg+OFF+"\n";
}

