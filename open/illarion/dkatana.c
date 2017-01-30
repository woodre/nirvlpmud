inherit "obj/weapon.c";
#include "/players/illarion/dfns.h"

int accum_dam;
status deathblow_attempt;
string att_name;
object att_ob;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("katana");
  set_short("A "+BOLD+"dragon-head"+NORM+" katana.");
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
  accum_dam=0;
}
/*   Two handed weapon code
 */
status id(string str) {
  if(str == "notarmor" && (string)previous_object()->query_type() == "shield")
    return 1;
  return (status)::id(str);
}

status wield(string str) {
  object *inv;
  int x,s;
  if(!id(str))
    return 0;
  if(environment()!=TP)
    return 0;
  if(present("notweapon",this_player())) {
    write("For some reason you are unable to wield this weapon.\n");
    return 1;
  }
  if (wielded) {
    write("You already wield it!\n");
    return 1;
  }
  inv=all_inventory(TP);
  s=sizeof(inv);
  for(x=0;x<s;x++) {
    if((string)inv[x]->query_type() == "shield" && inv[x]->query_worn()) {
      write("You need both hands free for this weapon.\n");
      return 1;
    }
  }
  wielded_by = this_player();
  call_other(this_player(), "wield", this_object(), silentwield);
  wielded = 1;
  accum_dam=0;  /* reset spellpoint heal if the weapon is passed around */
  return 1;
}


void make_head(string name) {
  object head;
  head=clone_object("/obj/treasure");
  head->set_id("head");
  head->set_short("The severed head of "+name+", taken by "+
     wielded_by->query_name());
  head->set_long(format(name+"'s head was obviously removed in"+
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
    tell_object(att_ob,format(wielded_by->query_name()+" misses the deathblow. "+
        "You feel renewed by the second chance!\n"));
    tell_object(wielded_by,format("Your swing goes wide, leaving "+att_name+
        " very much alive.  The katana quivers in disappointment.\n"));
    say(wielded_by->query_name()+"'s deathblow goes wide!\n",({att_ob,wielded_by}));
    att_ob->heal_self(50);
    remove_call_out("deathblow_call");
    deathblow_attempt=0;
    accum_dam=0;
  }
  return 1;
}
status count_hit_made() {
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
   * -25 heal_self here- any hit should instantly kill the target,
   * as it will be at negative hps
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
    att->heal_self(-25);
    call_out("deathblow_call",0);
  }
  /* weapon return:  willpower 1  return=4    (avg 4)
   *                 willpower 8  return=4-6  (avg 5)
   *                 willpower 20 return=4-9  (avg 6.5)
   */
  if(random(10)<3) {
    int wil;
    if(wielded_by->is_npc()) return 0;
    write("You feel a ghostly presence flow from the sword and into your\n"+
          "arms, guiding your strike with the skill of whole lifetimes.\n");
          
    say(format("A flickering, ghostly figure appears, overlaying "+
      wielded_by->query_name()+"'s form, and guiding "+
      wielded_by->query_possessive()+" sword."));
    tell_room(environment(wielded_by),"\n"+
      ({HIY+"Lightning"+NORM+" crackles along the katana's blade!",
        "A sheen of the coldest "+HIC+"frost"+NORM+" coats the katana's edge!",
        "A wave of searing "+HIR+"fire"+NORM+" follows the katana's strike!",
        "An aura of "+HIK+"darkness"+NORM+" surrounds the katana's blade!",
      })[random(4)]+"\n\n");
    wil=(int)wielded_by->query_attrib("wil");
    wil/=4; 
    return 4+random(wil+1);
  }
}

/* should be cancelled if the wielder misses, by the count_misses
 * function, but it also won't happen if the attacker is still alive.
 * also heals sps in the amount of 1/5 of the damage done by the weapon
 * since the last deathblow attempt.  A missed deathblow also resets the
 * amount, so it can be quite low.  It's also limited to 50sps total.
 */
void deathblow_call() {
  if(!att_ob) {
    tell_room(environment(wielded_by),att_name+"'s head drops to the ground.\n");
    if(accum_dam>250) /* limit to 250/5=50 sp heal */
      accum_dam=250;
    wielded_by->add_spell_point(accum_dam/5);
    if(accum_dam>=5)
      write("Energy flows into you from your sword's hilt!\n");
    accum_dam=0;
    make_head(att_name);
  }
  deathblow_attempt=0;
}
