/*
 * New Doppleganger guild object
 * Dopplegangers originally coded by Grimm, and original code is still
 * in his directory.
 * New code by Rumplemintz - deamonized and removed from his dir
 */

#include <ansi.h>
#include "def.h"

int cloaked;                          /* Badge hidden? */
string g_title;                       /* Guild title */
int res_time;                         /* Time for rescue */
int last_read;                        /* Last read news */
int bztime;                           /* Berserk delay */
int fang_hit;                         /* Fang damage */
string morph_name;                    /* Morph name */
int morphed;                          /* Are we morphed? */
int allowem;                          /* Allow summons/steps */
int shaddup;                          /* Allow guild channel */
int monitor;                          /* Pet monitor toggle */
int bfact, mfact;                     /* Faction flags */
int corpse_heal;                      /* Amount of healing drain does */
int which_drain;                      /* Toggle hp/sp for drain */
int fang_casting;                     /* Delay on casting fang */
int berserk_delay;                    /* Delay on going berserk */
int shift_flag;                       /* Shifted ? (Bonus AC) */
int sleep_time, sleep_amount;         /* Sleeping vars/delay */
int sp_stored, hp_stored;             /* Stored hps and sps for factions */
int veiled;                           /* Casting veil on something or not */
int plagued;                          /* Whether we're casting a plauge */
int cursed;                           /* Whether we're casting a curse */
object hiding_return;                 /* Room object from which we hid */
object pet_object;                    /* Object clone for pet */


/* Gate stuff... */
static int gate1, gate2, gate3, gate4, gate5;
static object g1, g2, g3, g4, g5;

static object owner;

/* Prototypes */
string query_guild_title(int rank);
int clear_gates();

id(str) {
  return str == "badge" || str == "badge of dopplegangers guild" ||
         str == "GUILD" || str == "V-GUILD" || str == "GI" || str == "scar";
}

short() {
  string result;

  if (cloaked) return;
  result = "Badge of the Doppleganger's Guild (" + g_title + ")";
  if (bfact) {
    result += "\nScar of the Barbarian Faction";
    if (hp_stored)
      result += " (" + hp_stored + " hp stored)";
  }
  if (mfact) {
    result += "\nScar of the Mystic Faction";
    if (sp_stored)
      result += " (" + sp_stored + " sp stored)";
  }
  return result;
}

long(str) {
  if (str == "scar") {
    if (bfact && mfact) {
      write("These are the scars of the Doppleganger factions.\n" +
            "Only those who have proven themselves may wear them.\n" +
            "Type \"bh\" or \"barbarian_help\" for barbarian help.\n" +
            "Type \"mh\" or \"mystic_help\" for mystic help.\n");
      if (hp_stored) write("(" + hp_stored + " hit points stored)\n");
      if (sp_stored) write("(" + sp_stored + " spell points stored)\n");
    } else
    if (mfact || bfact) {
        write("This is the scar of the " +
              (bfact ? "barbarian's" : "mystics'") +
              " faction.\n");
        write("Only those who have proven themselves " +
              (bfact ? "in battle" : "worthy") +
              " may wear it.\n");
        write("Type \"" + (bfact ? "b" : "m") + "h\" or \"" +
              (bfact ? "barbarian" : "mystic") +
              "_help\" for more help.\n");
        if (hp_stored) write("(" + hp_stored + " hit points stored)\n");
        if (sp_stored) write("(" + sp_stored + " spell points stored)\n");
    }
  } else
  write ("This is a badge of darkness.  Only the most evil may posses it!\n"+
         "     Type \"help_badge\" or \"hb\" for a list of commands.\n");
}

save_me(silently) {
  if (!owner) return;
  if (!silently)
    tell_object(owner, "Saving Doppleganger status...\n");
  save_object(GUILD_DIR + "member/" + (string)owner->query_real_name());
}

restore_me() {
  if (!owner) return;
  tell_object(owner, "Restoring Doppleganger status...\n");
  restore_object(GUILD_DIR + "member/" + (string)owner->query_real_name());
}

reset(arg) {
  if (!environment()) return; /* Illarion 01/22/2014 */
  if (arg)
    save_me();
  set_light(1);
  g_title = query_guild_title(environment()->query_guild_rank());
  gate1 = 0;
  gate2 = 0;
  gate3 = 0;
  gate4 = 0;
  gate5 = 0;
  berserk_delay = time();
  res_time = time();
  shaddup = 0;
/*
  set_heart_beat(1);
*/
}

quit_hook() {
  write("Destroying your gates.\n");
  say(owner->query_name() + " seals a rip behind " +
      owner->query_possessive() + " shadow.\n");
  clear_gates();
  this_player()->unshadow();
  morphed = 0;
  save_me();
}

heart_beat() {
  object pet;

  if (present("dopple_pet", environment(this_player())))
    pet = present("dopple_pet", environment(this_player()));
  if (this_player()->query_level() < 20)
    this_player()->set_al_title("[" + g_title + "]");
  if (monitor)
    if (pet)
      if (pet->query_owner() == this_player()->query_real_name())
        tell_object(this_player(), "  PET HP-> " +
           pet->query_hp() + "/" + pet->query_mhp() + "\n");
  if (gate1 && !g1) gate1 = 0;
  if (gate2 && !g2) gate2 = 0;
  if (gate3 && !g3) gate3 = 0;
  if (gate4 && !g4) gate4 = 0;
  if (gate5 && !g5) gate5 = 0;
}

drop() { return 1; }
get() { return 1; }

init() {
  if (this_player() && environment() && !owner && this_player()==environment())
    owner = this_player();
  else
    return;

  restore_me();
  add_action("quit_hook", "quit");

  /* Guild Level 1 spells */
  add_action("spells1", "bite");
  add_action("spells1", "renew");
  add_action("spells1", "note");
  add_action("spells1", "fang_set");
  add_action("spells1", "fs");
  add_action("spells1", "check_al");
  add_action("spells1", "set_morph");
  add_action("spells1", "change");
  add_action("spells1", "allow_toggle");
  add_action("spells1", "at");
  add_action("spells1", "guild_tell_shaddup");
  add_action("spells1", "gts");
  add_action("spells1", "gw");
  add_action("spells1", "gz");
  add_action("spells1", "ga");
  add_action("spells1", "php");
#ifndef __LDMUD__
  add_action("spells1"), add_xverb("hb");
  add_action("spells1"), add_xverb("help_badge");
#else
  add_action("spells1", "help_badge", 3);
  add_action("spells1", "hb", 3);
#endif
  add_action("spells1", "new_commands");
  add_action("spells1", "guild_news");
  add_action("spells1", "score");
  add_action("spells1", "sc");
  add_action("spells1", "guild_tell");
  add_action("spells1", "gt");
  CHAND->add_channel("dopplegangers", this_player());

  /* Guild Level 2 spells */
  add_action("spells2", "drain");
  add_action("spells2", "drain_toggle");
  add_action("spells2", "dt");
  add_action("spells2", "fang");
  add_action("spells2", "tonic");
  add_action("spells2", "rescue");

  /* Guild Level 3 spells */
  add_action("spells3", "smelt");
  add_action("spells3", "new_title");
  add_action("spells3", "gput");
  add_action("spells3", "gget");
  add_action("spells3", "gate");

  /* Guild Level 4 spells */
  add_action("spells4", "ginv");
  add_action("spells4", "appraise");
  add_action("spells4", "app");
  add_action("spells4", "other_who");
  add_action("spells4", "ow");

  /* Guild Level 5 spells */
  add_action("spells5", "melt");
  add_action("spells5", "direct");
  add_action("spells5", "scan");
  add_action("spells5", "berserk");
  add_action("spells5", "step");
  add_action("spells5", "cloak");

  /* Guild Level 6 spells */
  add_action("spells6", "horde");
  add_action("spells6", "jerky");
  add_action("spells6", "guard");
  add_action("spells6", "pet");
  add_action("spells6", "coat");

  /* Guild LEvel 7 spells */
  add_action("spells7", "blast");
  add_action("spells7", "summon");
  add_action("spells7", "hide");
  add_action("spells7", "return");
  add_action("spells7", "spice");

  /* Guild Level 8 spells */
  add_action("spells8", "blade");
  add_action("spells8", "shift");
  add_action("spells8", "sleep");

  /* Guild Level 9 spells */
  add_action("spells9", "strike");
  add_action("spells9", "calm");
  add_action("spells9", "vandalize");

  /* Guild Commander Commands */
  if (this_player()->query_guild_rank() >= 20) {
    add_action("spells1", "commander_tell");
    add_action("spells1", "ct");
    add_action("commander", "commander_help_badge");
    add_action("commander", "chb");
    add_action("commander", "add_faction");
    add_action("commander", "remove_faction");
    add_action("commander", "query_faction");
    add_action("commander", "dopp_promote");
    add_action("commander", "dopp_demote");
    add_action("commander", "dopp_status");
    add_action("commander", "dopp_recruit");
    add_action("commander", "dopp_remove");
  }

  /* Faction Specific Spells */
  if (mfact) {
    /* Mystic Faction Level 1 Spells */
    add_action("spells1", "mystic_tell");
    add_action("spells1", "mt");
    CHAND->add_channel("dopplegangersM", this_player());
    add_action("spells10", "mystic_help");
    add_action("spells10", "mh");
    add_action("spells10", "mystic_who");
    add_action("spells10", "mw");
    add_action("spells10", "cheal");
    add_action("spells10", "shadizar");
    add_action("spells10", "mbag");

    /* Mystic Faction Level 2 Spells */
    add_action("spells11", "veil");
    add_action("spells11", "store");
    add_action("spells11", "retrieve");
    add_action("spells11", "crypt");

    /* Mystic Faction Level 3 Spells */
    add_action("spells12", "weaken");
    add_action("spells12", "enchant");
    add_action("spells12", "imp");

    /* Mystic Faction Level 4 Spells */
    add_action("spells13", "spirits");
    add_action("spells13", "plague");
    add_action("spells13", "dull");

    /* Mystic Faction LEvel 5 Spells */
    add_action("spells14", "cure");
    add_action("spells14", "curse");

    /* Mystic Factio LEvel 6 Spells */
    add_action("spells15", "death");
    add_action("spells15", "resurrect");
    add_action("spells15", "scare");
  }

  if (bfact) {
    /* Barbarian Faction Level 1 Spells */
    add_action("spells1", "barbarian_tell");
    add_action("spells1", "bt");
    CHAND->add_channel("dopplegangersB", this_player());
    add_action("spells10", "barbarian_help");
    add_action("spells10", "bh");
    add_action("spells10", "barbarian_who");
    add_action("spells10", "bw");
    add_action("spells10", "cheal");
    add_action("spells10", "hack");

    /* Barbarian Faction Level 2 Spells */
    add_action("spells11", "store");
    add_action("spells11", "retrieve");
    add_action("spells11", "tame");
    add_action("spells11", "scare");

    /* Barbarian Faction Level 3 Spells */
    add_action("spells12", "wolf");
    add_action("spells12", "reforge");
    add_action("spells12", "firstaid");

    /* Barbarian Faction Level 4 Spells */
    add_action("spells13", "squeeze");
    add_action("spells13", "terminate");
    add_action("spells13", "polish");

    /* Barbarian Faction Level 5 Spells */
    add_action("spells14", "forge");
    add_action("spells14", "aggress");

    /* Barbarian Faction Level 6 Spells */
    add_action("spells15", "forgearmor");
    add_action("spells15", "absorb");
    add_action("spells15", "quake");
  }
}

spells1(string str) {
  return call_other(SPELLS + "01_" + query_verb(), "main", str);
}

spells2(string str) {
  return call_other(SPELLS + "02_" + query_verb(), "main", str);
}

spells3(string str) {
  return call_other(SPELLS + "03_" + query_verb(), "main", str);
}

spells4(string str) {
  return call_other(SPELLS + "04_" + query_verb(), "main", str);
}

spells5(string str) {
  return call_other(SPELLS + "05_" + query_verb(), "main", str);
}

spells6(string str) {
  return call_other(SPELLS + "06_" + query_verb(), "main", str);
}

spells7(string str) {
  return call_other(SPELLS + "07_" + query_verb(), "main", str);
}

spells8(string str) {
  return call_other(SPELLS + "08_" + query_verb(), "main", str);
}

spells9(string str) {
  return call_other(SPELLS + "09_" + query_verb(), "main", str);
}

spells10(string str) {
  return call_other(SPELLS + "10_" + query_verb(), "main", str);
}

spells11(string str) {
  return call_other(SPELLS + "11_" + query_verb(), "main", str);
}

spells12(string str) {
  return call_other(SPELLS + "12_" + query_verb(), "main", str);
}

spells13(string str) {
  return call_other(SPELLS + "13_" + query_verb(), "main", str);
}

spells14(string str) {
  return call_other(SPELLS + "14_" + query_verb(), "main", str);
}

spells15(string str) {
  return call_other(SPELLS + "15_" + query_verb(), "main", str);
}

commander(string str) {
  return call_other(SPELLS + "20_" + query_verb(), "main", str);
}

/* Calls from above */
string query_guild_title(int rank) {
  string result;

  switch(rank) {
  case 1: result = HIW + "Fledgeling" + NORM; break;
  case 2: result = HIW + "Zombie" + NORM; break;
  case 3: result = HIW + "Doppleganger" + NORM; break;
  case 4: result = HIW + "Master Doppleganger" + NORM; break;
  case 5: result = HIW + "Senior Doppleganger" + NORM; break;
  case 6: result = HIW + "Disciple of Darkness" + NORM; break;
  case 7: result = HIW + "Master of Darkness" + NORM; break;
  case 8: result = HIW + "Lord of Darkness" + NORM; break;
  case 9: result = HIW + "Overlord" + NORM; break;
  case 10..19: result = HIW + "Faction Doppleganger" + NORM; break;
  case 20..29: result = RED + "Guild Commander" + NORM; break;
  case 30..49: result = RED + "Guild Senior" + NORM; break;
  case 50..99: result = HIB + "Guild Wiz" + NORM; break;
  case 100..199: result = HIB + "Commanding Guild Wiz" + NORM; break;
  case 200..999: result = HIB + "Senior Commanding Guild Wiz" + NORM; break;
  case 1000: result = HIR + "Guild Master" + NORM; break;
  default: result = "";
  }
  return result;
}

/* Queries, Sets and Toggles! */
query_fang_casting() { return fang_casting; }
set_fang_casting() {
  fang_casting = 1;
  call_out("remove_fang_casting", 2);
  return 1;
}
remove_fang_casting() {
  fang_casting = 0;
  return 1;
}
query_sp_stored() { return sp_stored; }
add_sp_stored(x) { sp_stored += x; }
query_hp_stored() { return hp_stored; }
add_hp_stored(x) { hp_stored += x; }
query_res_time() { return res_time; }
set_res_time(str) { res_time = str; }
query_sleep_time() { return sleep_time; }
set_sleep_time(str) { sleep_time = str; }
query_sleep_amount() { return sleep_amount; }
set_sleep_amount(str) { sleep_amount = str; }
query_hiding_return() { return hiding_return; }
set_hiding_return(obj) { hiding_return = obj; }
query_berserk_delay() { return berserk_delay; }
set_berserk_delay(str){ berserk_delay = str; }
query_allowem() { return allowem; }
toggle_allowem() { allowem = !allowem; }
query_shift_flag() { return shift_flag; }
toggle_shift_flag() { shift_flag = !shift_flag; }
query_pet_object() { return pet_object; }
set_pet_object(obj) { pet_object = obj; }
query_cloaked() { return cloaked; }
toggle_cloaked() { cloaked = !cloaked; }
query_monitor() { return monitor; }
toggle_monitor() { monitor = !monitor; }
query_last_read() { return last_read; }
set_last_read(str) { last_read = str; }
query_veiled() { return veiled; }
set_veiled(str) { veiled = str; }
query_bz_time() { return bztime; }
set_bz_time(str) { bztime = str; }
query_plagued() { return plagued; }
set_plagued(str) { plagued = str; }
query_cursed() { return cursed; }
set_cursed(str) { cursed = str; }

query_shaddup() { return shaddup; }

set_shaddup(int s) {
  if (s == shaddup) return;
  write("Doppleganger channels are now " + (s ? "off" : "on") + "\n");
  shaddup = s;
}

query_corpse_heal() { return this_player()->query_guild_rank() * 5; }
query_which_drain() { return which_drain; }
toggle_which_drain() { which_drain = !which_drain; }
query_morph() { return morph_name; }
set_morph(str) { morph_name = str; }
query_morphed() { return morphed; }
set_morphed(str) { morphed = str; }
query_fang_hit() { return fang_hit; }
set_fang_hit(str) { fang_hit = str; }
query_gate(int gatenum) {
  switch (gatenum) {
  case 1: return gate1; break;
  case 2: return gate2; break;
  case 3: return gate3; break;
  case 4: return gate4; break;
  case 5: return gate5; break;
  default: return 0;
  }
  return 0;
}

set_gate(gate, onoff) {
  switch(gate){
  case 1: gate1 = onoff; break;
  case 2: gate2 = onoff; break;
  case 3: gate3 = onoff; break;
  case 4: gate4 = onoff; break;
  case 5: gate5 = onoff; break;
  default: return 0;
  }
  return 1;
}

clear_gates() {
  gate1 = 0; gate2 = 0; gate3 = 0; gate4 = 0; gate5 = 0;
  g1 = 0; g2 = 0; g3 = 0; g4 = 0; g5 = 0;
  return 1;
}

query_g(int gnum) {
  switch(gnum) {
  case 1: return g1; break;
  case 2: return g2; break;
  case 3: return g3; break;
  case 4: return g4; break;
  case 5: return g5; break;
  default: return 0;
  }
  return 0;
}

set_g(g, room) {
  switch(g) {
  case 1: g1 = room; break;
  case 2: g2 = room; break;
  case 3: g3 = room; break;
  case 4: g4 = room; break;
  case 5: g5 = room; break;
  default: return 0;
  }
  return 1;
}

query_factions() {
  write("Barb: " + bfact + " Myst: " + mfact + "\n");
  return 1;
}

query_faction(str) {
  if (str == "barbarian") return bfact;
  else if (str == "mystic") return mfact;
  else return 0;
}

set_faction(str) {
  if (str == "barbarian") bfact = 1;
  else if (str == "mystic") mfact = 1;
  else return 0;
  return 1;
}

remove_faction(str) {
  if (str == "barbarian") {
    bfact = 0;
    remove_action("bt");
    remove_action("barbarian_tell");
    CHAND->remove_channel("dopplegangersB", this_player());
    save_me(1);
  }
  else if (str == "mystic") {
    mfact = 0;
    remove_action("mt");
    remove_action("mystic_tell");
    CHAND->remove_channel("dopplegangersM", this_player());
    save_me(1);
  }
  else return 0;
  return 1;
}
