

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
#include        "/players/nightshade/guild/cleric/def.h"
#include        "/players/nightshade/guild/cleric/ref.h"
#include        "/players/nightshade/guild/cleric/comm.h"
#include        "/players/nightshade/guild/cleric/misc.h"
#include        "/players/nightshade/guild/cleric/attack.h"
#include        "/players/nightshade/guild/cleric/magic.h"
#include        "/players/nightshade/guild/cleric/heal.h"
#include        "/players/nightshade/guild/cleric/summon.h"
#include        "/players/nightshade/guild/cleric/title.h"

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

query_auto_load() { return "players/nightshade/guild/symbol:"; }

guildsave() {
  if(this_player()->query_guild_name() != "clerics") {
    write("You do not belong to this guild.\n");
    destruct(this_object());
    return 1;
  }
   save_object("players/nightshade/guild/clericsave/" +NAME);
}
guildload() {
  restore_object("players/nightshade/guild/clericsave/" +NAME);
}
saving() {
  write("Saving guild status.\n");
  guildsave();
  return 1;
}

reclone() {
  if(Level < 51) { write("What ?\n"); return 1; }
  write("Fixing up the symbol.\n");
  saving();
  move_object(clone_object("players/nightshade/guild/symbol"),
        this_player());
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
/******************Not in game yet******************
heart_beat() {
object ob;
  ob = environment(this_object());
  heart_check = 0;
  if(ob->query_attack() && !heart_check) {
    if(ob->query_hp() < evade_hp) {
        tell_object(ob, "You attempt to EVADE " +evade_dir+"!!!\n");
      command(evade_dir, ob);
    }
    if(!no_mon) {
      my_hp = old_hp - ob->query_hp();
      tell_object(ob,
        "You have been hit for : "+my_hp+" hps.\n");
    }
  }
  old_hp = ob->query_hp();
}
heart() {
  set_heart_beat(0);
  set_heart_beat(1);
  write("Done.\n");
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
send_esquire() {
  if(!esquire) {
    write("You do not have one out.\n");
    return 1;
  }
  write("You call to your esquire and relieve him of his duty.\n");
  destruct(esquire);
  return 1;
}
call_esquire() {
  if(esquire) {
    write("You already have an esquire.\n");
    return 1;
  }
  if(SP < 20) {
    write("You do not possess enough magical energy to call for an esquire.\n");
    return 1;
  }
  if(Glevel < 5) {
    write("You are not worthy enough to ask Matry.\n");
    return 1;
  }
  if(environment(Me)->query_property("NT")) {
    write("The room will not allow you to call for an esquire.\n");
    return 1;
  }
  write("You call for an esquire.\n");
  say("An esquire arrives.\n");
  esquire = clone_object("players/nightshade/guild/obj/esquire");
  esquire->set_short(Name+"'s Esquire");
  esquire->set_name(NAME+"'s esquire");
  esquire->set_max_weight((Glevel * 2) + (Honor * 2));
  move_object(esquire, environment(Me));
  Gain(EXP20);
  Ssp(20);
  return 1;
}

evading(str) {
int amt;
string direct;
  if(!str) {
    write("Evade <hp> [amt], Evade <dir> <direction>, Evade <check>\n"
        +" Evade <test>\n");
    return 1;
  }
  if(str == "check") {
    write("Evading hp set at: "+evade_hp+"\n");
    write("Evade direction set at: "+evade_dir+"\n");
    return 1;
  }
  if(str == "test") {
    write("You test out your evading technic.\n");
    command(evade_dir, Me);
    return 1;
  }
  if(sscanf(str, "hp %d", amt)) {
    if(!amt) {
      write("Evade hp [amount]\n");
      return 1;
    }
    if(amt < 1) {
      write("You can't evade at negative hit points.\n");
      return 1;
    }
    write("You set your evading hit points at "+amt+"\n");
    set_evade_hp(amt);
    return 1;
  }
  if(sscanf(str, "dir %s", direct)) {
    if(!direct) {
      write("Evade dir <direction>\n");
      return 1;
    }
    write("You set you evade direction at: "+direct+"\n");
    set_evade_dir(direct);
    return 1;
  }
}
watch_call() {
object enemy;
  if(Glevel < 5) {
    write("You are just a squire, you can not call for knights.\n");
    return 1;
  }
  if(watch_point > (Glevel * 2)) {
    write("You must wait until next reset to call for help.\n");
    return 1;
  }
  if(Strayed) {
    write("You have strayed from your path!!!\n");
    return 1;
  }
  if(Glevel < 10) {
    if(SP < 40) {
      write("You do not have enough magical energy to call for a squire.\n");
      return 1;
    }
    if(squire) {
      write("You already have a squire. Send the first one away.\n");
      return 1;
    }
    if(!Me->query_attack()) {
      write("You are not fighting anyone.\n");
      return 1;
    }
    write("You summon a squire to help you with your battle.\n");
    say(Name+ " call for a squire to help "+Obj+ " fight.\n");
    squire = clone_object("players/nightshade/guild/obj/squire");
    squire->set_name(NAME+"'s squire");
    squire->set_level(Glevel);
    squire->set_hp(20);
    squire->set_wc((Glevel + 1) + (Honor));
    squire->set_ac(0);
    squire->set_short(Name+ "'s squire");
    squire->set_who(Name);
    move_object(squire, environment(Me));
    enemy = Me->query_attack();
    squire->attack_object(enemy);
    move_object(Me, environment(squire));
    enemy->attack_object(Me);
    watch_point++;
    Ssp(40);
    if(Path == "None")
    Gain(EXP40);
    else
    Gain(EXP40A);
    new_shield();
    return 1;
  }
  if(SP < 40) {
    write("You do not have enough magical energy to call for a knight.\n");
    return 1;
  }
  if(knight) {
    write("You already have a knight.\n");
    return 1;
  }
  if(!Me->query_attack()) {
    write("You are not fighting at the moment.\n");
    return 1;
  }
  write("You call for a knight to help you with your battle.\n");
  say(Name+" calls for a knight to help "+Obj+" fight.\n");
    knight = clone_object("players/nightshade/guild/obj/knight");
    knight->set_name(NAME+"'s knight");
    knight->set_level(Glevel + 1);
    knight->set_hp(50);
    knight->set_wc((Glevel + 1) + Honor);
    knight->set_ac(0);
    knight->set_short(Name+ "'s knight");
    knight->set_who(Name);
    move_object(knight, environment(Me));
    enemy = Me->query_attack();
    knight->attack_object(enemy);
    move_object(Me, environment(knight));
    enemy->attack_object(Me);
    watch_point ++;
    Ssp(40);
    if(Path == "None")
    Gain((Glevel * 3) + (Honor * 10));
    else
    Gain((Glevel * 3) + (Honor * 20));
    new_shield();
    return 1;
}

********* Above not in game yet ******/

