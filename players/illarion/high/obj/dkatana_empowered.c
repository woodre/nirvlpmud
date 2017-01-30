inherit "obj/weapon.c";
#include "/players/illarion/dfns.h"

int accum_dam;
string element;
status deathblow_attempt;
string att_name;
object att_ob;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("katana");
  set_short("A "+BOLD+"dragon-head"+NORM+" katana");
  set_long(
"A truly awesome weapon forged by a japanese weaponsmith over two centuries\n"+
"ago.  The blade is long, double-edged, and slightly curved, with a wicked\n"+
"point.  The long white hilt is carved into a fanciful representation of\n"+
"a dragon that has made this sword famous, though it is the superior\n"+
"craftsmanship that really makes it special.\n");
  set_class(18);
  set_weight(5);
  set_value(3000);
  set_hit_func(this_object());
  /* Checks for a shield being worn */
  wield_func=HOBJ+"shieldcheck";
  accum_dam=0;
}
/*   Two handed weapon code
 */
status two_handed() { return 1; }

status id(string str) {
  if(str == "notarmor" && (string)previous_object()->query_type() == "shield" && wielded)
    return 1;
  if(deathblow_attempt && wielded_by && str == "kill_check_object")
    return 1;
  return (status)::id(str);
}

void make_head(string name) {
  object head;
  head=clone_object("/obj/treasure");
  head->set_id("head");
  head->set_short("The severed head of "+name+", taken by "+
     wielded_by->query_name());
  head->set_long(format(name+"'s head was obviously removed in "+
     "a single stroke by something razor-sharp.\n"));
  head->set_weight(1);
  head->set_value(0);
  move_object(head,environment(wielded_by));
  return;
}


/*   Weapon doesn't get dull or break
 */
status query_wear() {
  return 0;
}
status count_misses() {
  if(deathblow_attempt) {
/* Somehow this got called with no att_ob, so this should fix that while still
clearing out the deathblow */
    if(att_ob) {
      tell_object(att_ob,format(wielded_by->query_name()+" misses the deathblow. "+
          "You feel renewed by the second chance!\n"));
      tell_object(wielded_by,format("Your swing goes wide, leaving "+att_name+
          " very much alive.  The katana quivers in disappointment.\n"));
      say(wielded_by->query_name()+"'s deathblow goes wide!\n",({att_ob,wielded_by}));
      att_ob->heal_self(50);
    }
    deathblow_attempt=0;
    accum_dam=0;
  }
  element=0;
  return 1;
}
elemental_attack() {
  object victim;
  int dam;
  victim=wielded_by->query_attack();
  if(!victim || !present(victim,environment(wielded_by))) return;
  dam=1+wielded_by->query_level()+wielded_by->query_extra_level()/2;
  dam/=4;  /* Dam is 17 for xlvl 100 */
  if(dam) {
    victim->do_damage(({dam}),({"other|"+element}));
  }
}
status count_hit_made() {
/* currently when a monster dies this isn't called, so if this function
 * is called with an active deathblow attempt it means the deathblow failed and
 * the monster should be healed, etc.
 */
  if(deathblow_attempt) count_misses();
  else if(element) elemental_attack();
  element=0;
  return 1;
}
status add_wear(int x) {
  return 0;
}
status weapon_breaks() { return 0; }
status re_break() { return 0; }
/*   damage messages
 */
string *query_message_hit(int dam) {
  accum_dam+=dam;
  switch(dam) {
    default:     return ({" with a blinding slash","eradicated"});
    case 21..30: return ({" with quick stabs","perforated"});
    case 16..20: return ({" opening a minor wound","slashed"});
    case 11..15: return ({" tearing some flesh","stabbed"});
    case 6..10:  return ({" opening a small cut","slashed"});
    case 4..5:   return ({" barely piercing the skin","stabbed"});
    case 2..3:   return ({" with a weak slash","nicked"});
    case 1:      return ({" with a slow stab","tapped"});
  }
}


int weapon_hit(object att) {
  /* attempt at an instant kill for a monster under 20hp
   * if it misses, the target is healed +50 to balance the 
   * 25 (or more if the second part of the function fires)
   * weapon return
   */
  if(att->query_hp()<20) {
    write(format("You look at your beaten enemy, and tell "+
        att->query_objective()+", \"There can be only one!\"\n"+
        "You bring the katana down, at "+att->query_possessive()+" neck.\n"));
    say(format(wielded_by->query_name()+" yells, \"There can be only one!\"\n"+
        "With a mighty sweep, "+wielded_by->query_pronoun()+" swings at "+
        att->query_name()+"'s neck.\n"),({wielded_by,att}));
    tell_object(att,format(wielded_by->query_name()+" looks you right in "+
        "the eye, and cries, \"There can be only one!\"\n"+
        wielded_by->query_possessive()+" sword descends toward your neck!\n"));
    att_name=(string)att->query_name();
    att_ob=att;
    deathblow_attempt=1;
    att->do_damage(({(int)att->query_hp()-1}),({"magical"}));
  }
  if(random((int)wielded_by->query_extra_level()/2)> random(20)) {
    int wil;
    int e;
    if(wielded_by->is_npc()) return 0;
    wil=((int)wielded_by->query_attrib("wil"))/5;
    if(wil>6)
      wil=6;
    if(wil) {
      write("You feel a ghostly presence flow from the sword and into your\n"+
            "arms, guiding your strike with the skill of whole lifetimes.\n");
      say(format("A flickering, ghostly figure appears, overlaying "+
        wielded_by->query_name()+"'s form, and guiding "+
        wielded_by->query_possessive()+" sword."));
      e=random(4);
      element=({"electric","ice","fire","dark"})[e];
      tell_room(environment(wielded_by),"\n"+
        ({HIY+"Lightning"+NORM+" crackles along the katana's blade!",
          "A sheen of the coldest "+HIC+"frost"+NORM+" coats the katana's edge!",
          "A wave of searing "+HIR+"fire"+NORM+" follows the katana's strike!",
          "An aura of "+HIK+"darkness"+NORM+" surrounds the katana's blade!",
        })[e]+"\n\n");
      return wil;
    }
  }
}

/* should be cancelled if the wielder misses, by the count_misses
 * function, but it also won't happen if the attacker is still alive.
 * also heals sps in the amount of 1/5 of the damage done by the weapon
 * since the last deathblow attempt.  A missed deathblow also resets the
 * amount, so it can be quite low.  It's also limited to 50sps total.
 */
void kill_check(object what) {
  if(att_ob == what) {
    tell_room(environment(wielded_by),att_name+"'s head drops to the ground.\n");
    if(accum_dam>500) /* limit to 500/10 = 50 sp heal */
      accum_dam=500;
    wielded_by->add_spell_point(accum_dam/10);
    if(accum_dam>=10)
      write("Mental energy flows into you from your sword's hilt!\n");
    accum_dam=0;
    make_head(att_name);
  }
  element=0;
  deathblow_attempt=0;
}
