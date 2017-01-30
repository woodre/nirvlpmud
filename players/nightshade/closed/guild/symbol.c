

inherit "players/nightshade/closed/guild/object";

static int no_mon;
static int no_tell;
static int worn_by;
static int is_off;
static int Time;
static int Time2;
static int Time3;
static my_hp, old_hp, heart_check;
static object servant;
static object vest, hamm;
static object fire, blade, thorn;
static object esquire, knight, squire;
int donated;
int is_quiet;
int guild_exp;
int guild_level;
int mana;
int max_mana;
int faith;
int faith_quest;
int faith_donate;
int heal_count;
int blade_count;
int evade_hp;
string evade_dir;
#include     "/players/nightshade/closed/guild/cleric/def.h"
#include     "/players/nightshade/closed/guild/cleric/magic.h"
#include     "/players/nightshade/closed/guild/cleric/ref.h"
#include     "/players/nightshade/closed/guild/cleric/comm.h"
#include     "/players/nightshade/closed/guild/cleric/misc.h"
#include     "/players/nightshade/closed/guild/cleric/attack.h"
#include     "/players/nightshade/closed/guild/cleric/heal.h"
#include     "/players/nightshade/closed/guild/cleric/summon.h"
#include     "/players/nightshade/closed/guild/cleric/title.h"

get()           { return 1; }
drop()          { return 1; }
give()          { return 1; }

reset(arg) {
  heal_count = 0;
  blade_count = 0;
if(arg) return;
  set_name("symbol of faith");
  set_alias("symbol");
  set_alt_name("cleric_guild");
  set_short("Symbol of Faith");
  set_value(0);
  set_weight(0);
  set_arm_light(0);
  set_guild_level(1);
  set_max_mana(50);
  set_mana(50);
  set_faith(1);
  no_mon = True;
  no_tell = False;
  is_off = True;
  guildload();
  Time = time();
  Time2 = time();
  Time3 = time();
  guild_title();
}

long() {
int am;
  am = Glevel * 2 + 10;
  write("This is a beautiful symbol of faith. With this symbol of Matry,\n"
+"the faithful ones are granted the healing powers. Type <cleric> for help.\n");
  return 1;
}

query_auto_load() { return "players/nightshade/closed/guild/symbol:";}

guildsave() {
  if(this_player()->query_guild_name() != "clerics") {
    write("You do not belong to this guild.\n");
    destruct(this_object());
    return 1;
  }
    save_object("players/nightshade/closed/guild/clericsave/" +NAME);
}
guildload() {
   restore_object("players/nightshade/closed/guild/clericsave/" +NAME);
}
saving() {
  write("Saving guild status.\n");
  guildsave();
  return 1;
}

reclone() {
  if(Level < 21) { write("What ?\n"); return 1; }
  write("Fixing up the symbol.\n");
  saving();
move_object(clone_object("players/nightshade/closed/guild/symbol"), this_player());
  destruct(this_object());
  return 1;
}

guild_score() {
int need;
  Me->score();
  write("\n");
  need = Needed - Gexp;
  if(need <= 0) write("If it is possible, you may now advance.\n");
  else write("Guild exp needed: " +need+ "\n");
  write("Guild lev: " +Glevel+ "\t\tFaith: " +Faith+
  "\tGuild exp: " +Gexp+ "\n");
  write("Mana: " +Mana+ " / " +MANA+ 
        "\t\tDonated: " +Donated+ "\n");
  return 1;
}

gscore() {
int need;
  need = Needed - Gexp;
  if(need <= 0) write("If it is possible, you may now advance.\n");
  else write("Guild exp needed: " +need+ "\n");
  write("Guild lev: " +Glevel+ "\t\tFaith: " +Faith+
  "\tGuild exp: " +Gexp+ "\n");
  write("Mana: " +Mana+" / " +MANA+
        "\t\tDonated: " +Donated+ "\n");
  guildsave();
  return 1;
}

brief_hp() {
int hp, HP, max;
  hp = Me->query_hp();
  HP = Me->query_mhp();
  max = Me->query_msp();
  write("HP: "+hp+"/"+HP+" | SP: "+SP+"/"+max+" | MANA: " +
    Mana+"/"+MANA+"\n");
  return 1;
}

init() {

  add_action("recycle",         "recycle");
add_action("fairy_fire", "ffire");
add_action("hammer", "hammer");
  add_action("evading",		"evade");
  add_action("hp_duh",		"hpwatch");
  add_action("new_members",     "clerics2");
  add_action("guild_mem",       "members");
  add_action("guild_emote",     "chante");
  add_action("cross_chat",      "cross");
  add_action("chat",            "chant");
  add_action("members",         "clerics");
  add_action("mind_block",      "block");
  add_action("gscore",          "gscore");
  add_action("gscore",          "gs");
  add_action("brief_hp",        "hp");
  add_action("guild_score",     "score");
  add_action("saving",          "gsave");
  add_action("offer",           "offer");
  add_action("locate",          "locate");
  add_action("locate_object",   "locate2");
  add_action("peace",           "peace");
  add_action("turn_undead",     "turn");
  add_action("reclone",         "anew");
  add_action("shine",           "shine");
  add_action("nospell",         "fireball");
  add_action("nospell",         "missile");
  add_action("nospell",         "shock");
  add_action("donate",          "donate");
  add_action("help_file",       "cleric");
  add_action("quit",            "quit");
  add_action("detect_align",    "detect");
  add_action("entangle",        "entangle");
  add_action("silence",         "silence");
  add_action("dispell",         "dispell");
  add_action("pass_trace",      "pass");
  add_action("call_lightning",  "call");
  add_action("call_servant",    "servant");
  add_action("beckon_servant",  "callservant");
  add_action("new_shield",      "fixsymbol");
  add_action("guild_title",     "gtitle");
  add_action("cure_light",      "cl");
  add_action("mend",            "mend");
  add_action("create",          "create");
  add_action("cure_serious",    "cs");
  add_action("cure_critical",   "cc");
  add_action("complete_heal",   "cheal");
  add_action("regenerate",      "regen");
  add_action("know_alignment",  "know");
  add_action("holy_word",       "word");
  add_action("magic_stone",     "mstone");
  add_action("earthquake",      "equake");
  add_action("vestment",        "vestment");
  add_action("wall_of_fire",    "wfire");
  add_action("wall_of_thorns",  "wthorn");
  add_action("blade_barrier",   "blade");
  add_action("entrall",         "entrall");

}

new_shield() {
  move_object(Badge, Me);
  return 1;
}

quit() {
  saving();
  return 0;
}


shine(str) {
  if(str == "symbol") {
    is_off = !is_off;
    if(is_off) {
      write("Your symbol no longer shines brightly.\n");
      say(Name+"'s symbol no longer shines brightly.\n");
      set_arm_light(0);
      return 1;
    }
    if(!is_off) {
      write("Your symbol shines brightly.\n");
      say(Name+"'s symbol shines brightly.\n");
      set_arm_light(1);
      return 1;
    }
  }
}

nospell() {
  write("Being in the Cleric's guild, you no longer possess the magical ability\n"
     + "to cast magic spells of that nature.\n");
  return 1;
}
hp_duh(str) {
  if(Glevel < 5) return;
  if(!str) {
    write("Hpwatch on or off.\n");
    return 1;
  }
  if(str == "on") {
    if(!no_mon) {
      write("You are already watching your hit points.\n");
      return 1;
    }
    write("You will now watch your hit points.\n");
    no_mon = 0;
    old_hp = environment(Badge)->query_hp();
    return 1;
  }
  if(str == "off") {
    if(no_mon) {
      write("You are not using the hit point watch.\n");
      return 1;
    }
    write("You stop your hit point watch.\n");
    no_mon = 1;
    return 1;
  }
}


