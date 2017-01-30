/* 03/07/06 Copyright (c) Earwax/David Halek
 *
 * The actual 'adrenaline' object...it's an invisible, no-ac weapon
 * and armor object that allows an extra attack() call.
 * Description of injection:
 *
 * An injection specifically intended for CyberNinja use only.  This
 * is sort of a stop-gap measure to beef ninja offense somewhat so
 * they can contend with other guilds, until we nerf the attack()
 * code in the dominant weapons, as well as address overall game
 * balance and equipment.
 *
 * Formula:  chance of a 2nd attack() call in a given round is:
 * ste/3 + dex/3 + chip level + belt level + xlevel/10
 * with each having a max of 10, for a total chance of 50%.
 *
 * This will not recurse further, for a max of 2 attacks per round,
 * on average, 3 attacks per 2 rounds, for a +100 with max stats
 * and max guild.
 *
 * Defense:  it has an additional chance of returning a value for
 * a very minor defensive bonus.  This chance per hb is 1/3 of the
 * chance for the extra attack, for a return of 1+random(10).
 *
 * 03/15/06 Earwax:
 * Switched from using RegisterArmor() and maledicta's ghetto-style
 * method for extra attack to RegisterWeapon() as I'm told that this
 * code now works properly, due to the inimitable and enigmatic 
 * Illarion's efforts.  Woot!  What this means is that this object
 * will special off of weapon hits, rather than armor - so ninja with
 * the adrenaline will also special when hitting behind, rather than
 * just the tank.
 */

#include "../../defs.h"

#define DEFENSE_BONUS 1+random(10)
#define BUGLOG "/players/earwax/obj/adrenaline.log"

/* Global Variables */
object Owner;  /* Who owns this thing */
int    Chance; /* Calculated chance of attack() call */
status Flag;   /* Recursion flag */

/* Prototype Declarations */
void defense_message(int i);
void attack_message(int i);

/* For testing purposes */
void twax(string arg) {
  object ob; ob = find_player("earwax"); tell_object(ob, HIG+arg+NORM+"\n");
}

status drop() { return 1; }
status id(string arg) { return arg == "CRYSTALIZED_ADRENALINE_ID"; }
int query_value() { return -10; }

status activate_adrenaline(object who) {
  if (!who) return 0;
  Owner = who;
  Owner->RegisterWeapon(this_object(), ({"physical", 0, "do_attack_special"}) );
  Owner->RegisterArmor(this_object(), ({"physical", 0, 0, "do_defense_special"}) );
  Flag = 0;
  return 1;
}

/* 
 * Calculate chance
 */
int calc_chance() {
  int t;
  object gob;

  gob = present("guild_implants", Owner);
  if (!Owner) Owner = environment(this_object());

  if (!gob) { /* They aren't a ninja? cheater! */
    Chance = -10;
    return -10;
  }

  t = (int)Owner->query_attrib("ste") / 3;
  Chance = (t > 10 ? 10 : t);
  t = (int)Owner->query_attrib("dex") / 3;
  Chance += (t > 10 ? 10 : t);
  Chance += (int)gob->guild_lev();
  t = (int)gob->query_art_level();
  Chance += (t > 7 ? t - 7 : 0);
  Chance += ((int)Owner->query_extra_level()/10);
  return Chance;
}

int do_attack_special(object ob) {
  string t;
  object att;

  if (Flag) return 0;
  if (!ob || !((object)ob->query_attack())) return 0;
  Owner = environment(this_object());
  att = (object)Owner->query_attack();
  if (!Owner) return 0;
  if (!Chance || random(200) == 66) calc_chance();
  if (!att || (int)att->query_hp() < 50) return 0;
  
  if (random(100) > Chance)
    return 0;

  attack_message(random(8));
  Flag = 1;
  call_out("no_recurse", 1);
  if (t = catch(Owner->attack()))
    write_file(BUGLOG, HIK+ctime()+": "+(string)Owner->query_real_name()+" vs "+ file_name(att)+"\n"+NORM+t+"\n");
  return 0;
}    

status query_silent_damage() { return 1; }

void no_recurse() {
  while(remove_call_out("no_recurse") != -1);
  Flag = 0;
}

/* 
 * See if there's a defensive (return value) special 
 */
int do_defense_special(object ob) {    
  int ret;
  
  ret = 0;
  Owner = environment(this_object());
  if (!Owner) return 0;
  if (!((object)Owner->query_attack())) return 0;
  if (!Chance || random(200) == 66) calc_chance();
  
  if (random(100) < (Chance /3)) {
    ret = DEFENSE_BONUS;
    defense_message(random(4));
  }
  return ret;
}

status destruct_me(string arg) {
  write("Destructing...\n");
  move_object(this_object(), "/room/void");
  destruct(this_object());
  return 1;
}

void init() {
  add_action("extra_attack_fun", "Maledicta_ghetto_fix");
  /* For testing */
  add_action("destruct_me", "calmdown");
  /* Byyy Menan.  I mean Fred. */
  add_action("quit", "quit");
}

string extra_look() {
  return (string)environment(this_object())->query_name()
    + " is tweaking on "+HIC+"crystalized adrenaline"+NORM;
}

void defense_message(int i) {
  string name;

  name = (string)Owner->query_name();
  tell_object(Owner, HIC + ({
    "Your enhanced speed allows you to dodge attacks.", 
    "You narrowly avoid some damage.",
    "You laugh as your incredible speed makes your opponent miss.",
    "You dodge with ungodly speed." })[i] + NORM+"\n");
  tell_room(environment(Owner), CYN + name + ({
    " moves faster than your eyes can follow.\n",
    " dodges attacks with ease.\n",
    " spins under an attack.\n",
    " dodges an attack with ungodly speed.\n",
    })[i] + NORM, ({ Owner }));
}

void attack_message(int i) {
  string name;

  name = (string)Owner->query_name();
  tell_object(Owner, HIC + ({
    "Your incredible speed allows you to strike again!\n",
    "You strike again!\n",
    "You attack in a flurry of speed!\n",
    "You attack in a blur of motion!\n",
    "Your movements blur as you strike again.\n",
    "Your body blurs with speed.\n",
    "Your muscles twitch and spasm, and you strike again!\n",
    "You swing again.\n",
    })[i] + NORM);
  tell_room(environment(Owner), CYN + name + ({
    " attacks with blinding speed!\n",
    " strikes again.\n",
    " attacks in a flurry of speed.\n",
    " blurs as they strike again.\n",
    " swings again.\n",
    " is a whirlwind of motion.\n",
    " laughs and hits again.\n",
    " gets another attack in.\n",
    })[i] + NORM, ({ Owner }));
}

/* The piece de resistance  which will hopefully
   fix the little coin issue - Frep.
*/

quit(){
  destruct(this_object());
}
