/* 18 Nov 04
   Updated weapon so it's only two-handed if the players dex is under 25
   Updated weapon_hit so chance to hit is based on extra level
   79% success rate at +100  58% at +50 0% at +0
   Updated weapon_hit so return is not random but still based on wil
   max return is 6 wt wil30+.  it's randomized automatically in living.c

   Finally, the number of successful deathblows affects the chance
   of a non-physical hit if
   1) the weapon_hit fires
   2) count_hit_made is called
   chance is 9% at 10 deathblows (minimum required)
   27% at 50 deathblows
   46% at 500 deathblows
   the chance will never exceed 50%
   That damage is based on level and maxes at 17 for +100 
   The number of deathblows is saved when the weapon is saved
   
 */
 
 /* 6/18/2011
   One final attempt to make this weapon worth using at high levels.
   Added multiple hits based on willpower
*/

inherit "obj/weapon.c";
#include "/players/illarion/dfns.h"

int accum_dam;
status deathblow_attempt;
status align_hit;
string att_name;
object att_ob;

int deathblows;

#define WIELDER environment()

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("katana");
  set_type("sword");
  set_short("A "+BOLD+"dragon-head"+NORM+" katana");
  set_long(
"A truly awesome weapon forged by a japanese weaponsmith over two centuries\n"+
"ago.  The blade is long, double-edged, and slightly curved, with a wicked\n"+
"point.  The long white hilt is carved into a fanciful representation of\n"+
"a dragon that has made this sword famous, though it is the superior\n"+
"craftsmanship that really makes it special.\n");
  set_class(20);
  set_weight(5);
  set_value(3000);
  set_hit_func(this_object());
  /* Checks for a shield being worn */
  wield_func=HOBJ+"shieldcheck";
  accum_dam=0;
}
/*   Two handed weapon code
 */
status two_handed() { if((int)TP->query_attrib("dex") < 25) return 1; }

status id(string str) {
  if(str == "notarmor" && (string)previous_object()->query_type() == "shield" && wielded && (int)WIELDER->query_attrib("dex") < 25)
    return 1;
  if(deathblow_attempt && WIELDER && str == "kill_check_object")
    return 1;
  return (int)::id(str);
}

init() {
  ::init();
  if(this_player() == environment()) {
    write("This weapon has been updated (6/18/2011):\n"+
          " - The more heads it takes the more powerful it becomes\n"+
          " - The more powerful the heads it takes, the faster its power grows.\n"+
          " - It now confers Duncan's ability to attack more than once.\n");
  }
}

void make_head(string name) {
  object head;
  head=clone_object("/obj/treasure");
  head->set_id("head");
  head->set_short("The severed head of "+name+", taken by "+
     WIELDER->query_name());
  head->set_long(format(name+"'s head was obviously removed in "+
     "a single stroke by something razor-sharp.\n"));
  head->set_weight(1);
  head->set_value(0);
  move_object(head,environment(WIELDER));
  return;
}

alignment_hit() {
  int aln,dam;
  string dtype;
  object victim;
  victim=WIELDER->query_attack();
  if(!victim || !present(victim,environment(WIELDER)))
    return;
  aln=WIELDER->query_alignment();
  dam=1+WIELDER->query_level()+WIELDER->query_extra_level()/2;
  dam/=4;  /* Dam is 17 for xlvl 100 */
  if(dam > 17) dam=17;
  if(dam < 4) dam=4;
  if(!dam)
    return;
  if(aln > 750) {
    dtype="other|holy";
    tell_room(environment(WIELDER),
      "A "+HIW+"holy"+NORM+" aura glows around the wound left by the katana!\n");
  } else if (aln < -750) {
    tell_room(environment(WIELDER),
      "An "+HIB+"evil"+NORM+" aura glows around the wound left by the katana!\n");
    dtype="other|evil";
  } else {
    tell_room(environment(WIELDER),
      "A "+HIG+"magical"+NORM+" aura glows around the wound left by the katana!\n");
    dtype="magical";
  }
  accum_dam+=victim->hit_player(dam,dtype);
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
    tell_object(att_ob,format(WIELDER->query_name()+" misses the deathblow. "+
        "You feel renewed by the second chance!\n"));
    tell_object(WIELDER,format("Your swing goes wide, leaving "+att_name+
        " very much alive.  The katana quivers in disappointment.\n"));
    say(WIELDER->query_name()+"'s deathblow goes wide!\n",({att_ob,WIELDER}));
    att_ob->heal_self(50);
}
    deathblow_attempt=0;
    accum_dam=0;
  }
  return 1;
}
status count_hit_made(int w) {
  if(deathblow_attempt && att_ob)
  {
    att_ob->death();
  }
  else if(align_hit && deathblows>10 && random(deathblows) > random(50+3*deathblows/4))
    alignment_hit();
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
    case -100..0:      return ({"","missed"});
  }
}

int times;
status recursing;

int weapon_hit(object att) {
  /* attempt at an instant kill for a monster under 20hp
   * if it misses, the target is healed +50 to balance the 
   * 25 (or more if the second part of the function fires)
   * weapon return
   */
  int wil,times;
  if(!att) return 0;
  wil=((int)WIELDER->query_attrib("wil"))/5;
  if(wil>6)
    wil=6;
  if(!att) return 0;
  align_hit=0;
  if((string)WIELDER->query_guild_name() != "samurai" && att->query_hp() < ((int)att->query_mhp())/12) {
    write(format("You look at your beaten enemy, and tell "+
        att->query_objective()+", \"There can be only one!\"\n"+
        "You bring the katana down, at "+att->query_possessive()+" neck.\n"));
    say(format(WIELDER->query_name()+" yells, \"There can be only one!\"\n"+
        "With a mighty sweep, "+WIELDER->query_pronoun()+" swings at "+
        att->query_name()+"'s neck.\n"),({WIELDER,att}));
    tell_object(att,format(WIELDER->query_name()+" looks you right in "+
        "the eye, and cries, \"There can be only one!\"\n"+
        WIELDER->query_possessive()+" sword descends toward your neck!\n"));
    att_name=(string)att->query_name();
    att_ob=att;
    deathblow_attempt=1;
    return wil*5; /* Gives the user a high chance to hit.  If they hit, the monster dies */
  }
  if(WIELDER->is_npc()) return 0;
  if(!recursing && wil && !WIELDER->is_npc()) {
    if(random((int)WIELDER->query_extra_level()/2 + wil ) > random(33)) {    
      write(CYN+"You focus your mind on your sword.\n"+
            "You feel a ghostly presence flow from the sword and into your\n"+
            "arms, guiding your strike with the skill of whole lifetimes.\n"+NORM);
      say(format("A flickering, ghostly figure appears, overlaying "+
        WIELDER->query_name()+"'s form, and guiding "+
        WIELDER->query_possessive()+" sword."));
        
      recursing=1;
      times = 0;
      while(att && random(deathblows) > random((times+1)*333)) {
        int dam;
        string *dmess;
        dam = (int)att->hit_player(random(class_of_weapon+weapon_hit(att)));
        if(att)
        {
          dmess = query_message_hit(dam);
          write("You "+dmess[1]+" "+att->query_name()+dmess[0]+".\n");
          say(WIELDER->query_name()+" "+dmess[1]+" "+att->query_name()+dmess[0]+".\n");
        }
        if(dam > 0) {
          align_hit=1;
          count_hit_made(0);
          align_hit=0;
        }
        else count_misses();
        times++;
        if(times >= (int)WIELDER->query_extra_level()/20  || times >= 3) break;
      }
      recursing=0;
      align_hit=1;
    }  
  }
  return random(wil);
}

void add_deathblow(object what) {
  int worth;
  if(WIELDER) tell_object(WIELDER,"Your katana grows stronger!\n");
  deathblows++;
  if(!what) return;
  worth=(int)what->calculate_worth();
  if(worth>10000) deathblows++;
  if(worth>50000) deathblows++;
  if(worth>200000) deathblows++;
  if(worth>1000000) deathblows++;
}

/* should be cancelled if the wielder misses, by the count_misses
 * function, but it also won't happen if the attacker is still alive.
 * also heals sps in the amount of 1/5 of the damage done by the weapon
 * since the last deathblow attempt.  A missed deathblow also resets the
 * amount, so it can be quite low.  It's also limited to 50sps total.
 */
void kill_check(object what) {
  if(att_ob == what) {
    tell_room(environment(WIELDER),att_name+"'s head drops to the ground.\n");
    if(accum_dam>1000)
      accum_dam=1000;
    WIELDER->add_spell_point(accum_dam/10);
    if(accum_dam>=10)
      write("Energy flows into you from your sword's hilt!\n");
    accum_dam=0;
    make_head(att_name);
    if((int)what->query_level() > 5)
      add_deathblow(what);
  }
  deathblow_attempt=0;
}

locker_arg() {
  return ""+deathblows;
}

locker_init(str) {
  if(str)
    sscanf(str,"%d",deathblows);
}

