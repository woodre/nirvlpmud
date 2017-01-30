#include "/players/pathfinder/closed/shadow/esc.h"
#define TOOL "/players/pathfinder/closed/shadow/new/new_shadow-master.c"
#define THIS_FILE "/players/pathfinder/closed/shadow/new/new_shadow.c"
/*
#define TOOL "/players/pathfinder/closed/shadow/shadow-master.c"
#define THIS_FILE "/players/pathfinder/closed/shadow/shadow.c"
*/
#define SERVANT "/players/pathfinder/closed/shadow/servant.c"
#define TP this_player()
#define MARK present("shadow-mark", TP)
#define ENV environment
#define TO this_object()
#define QRN query_real_name()
#define QN query_name()
#define CAP capitalize
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define SAVE "players/pathfinder/closed/shadow/new/shadows/"
#define SAVE "players/pathfinder/closed/shadow/shadows/"
*/
#define RN this_player()->query_real_name()
#define BOLD ESC+"[1m"
#define NOSTYLE ESC+"[0m"
#define BNAME BOLD + CAP(TP->QN) + NOSTYLE

static string logo;
static int spell_time, monitor_count, shadow_healing;
static int heal_count, bonus;

int muffled, drain_damage, monitor, summon, points, mshpts;
string in, out;

static object servant, follow;

query_auto_load() {
  return THIS_FILE + ":";
}

id(str) { return str == "mark" ||
                 str == "shroud" ||
                 str == "guild_object" ||
                 str == "shadow-mark" ||
                 str == "notarmor";
        }

short() {
  string short;
  short = ESC+"[1m"+"Shroud of Darkness"+ESC+"[0m";
  return short;
}

long() {
  write("You possess the Shroud of Darkness, the Mark of The Shadow Guild\n"+
        "To recieve information just type 'info guild'.\n");
}

extra_look() { 
  return ""+CAP(ENVTO->query_name())+" is only faintly visible among the shadow$
}

get() { return 1; }

drop() { return 1; }

init_arg(str) {
  TOOL->init_argument(str);
  return 1;
}

update_arg(str) {
  sscanf(str,"%d#%d#%d",monitor, points, drain_damage);
  save_object(SAVE+RN);
  return 1;
}
  
reset(arg) {
 if(!arg) {
  in = "has entered the game.\n";
  out = "has left the game.\n";
  muffled = 0;
  drain_damage = 6;
  points = 0;
  follow = 0;  
  monitor = 0;
  summon = 0;
  monitor_count = 0;
  spell_time = 0;  
  numcalled = 0;
  shadow_healing = 0;
  set_light(1);
  logo = read_file("/players/pathfinder/closed/shadow/logo");
  }
}
 
heart_beat() {   
  if(ENVTO->query_attack() && ENV(ENVTO)->query_light() == 0) {
    TOOL->do_combat_stuff(ENVTO);
    }
  if(shadow_healing == 1) {
    if(!(heal_count % 10)) {
      TOOL->heal_da_shadow(ENVTO);
      set_heart_beat(1);
    }
    heal_count++;
  }
  if((monitor == 0) && !follow && (shadow_healing == 0)) set_heart_beat(0);
  if(monitor > 0) {
    if(!(monitor_count % monitor)) {
      TOOL->shadow_monitor(ENVTO);
      set_heart_beat(1);
      }
    monitor_count++;
    }
  if(monitor < 0 && (ENVTO->query_attack() ||
    (servant && servant->query_attack()))) TOOL->shadow_monitor(ENVTO);
  if(follow && !present(follow,ENV(ENVTO))) TOOL->update_follow(ENVTO);
  set_heart_beat(1);
}  
 
heart_me() {
  set_heart_beat(1);
  return 1;
  }
     
unheart_me() {
  set_heart_beat(0);
  return 1;
  }
     
save_me() {
  string file;
  file = SAVE + RN;
  if(!save_object(file)) {
    write("Error in saving stats...\n");
    return 0;
    }
  write("Saving guild stats...\n");
  return 1;
}
  
restore_me() {
  string file;
  file = SAVE + RN; 
  if(!restore_object(file)) {
    write("Error in restoring stats...\n");
    return 0;
    }
  write("Restoring guild stats...\n");
  setup_armor_class();
  return 1;
}
  
init() {   
  restore_me();
  setup_armor_class();

  add_action("old_hand_mark", "oldmark");
  add_action("old_promote_shadow", "oldpromote");
  add_action("old_force_update", "oldupd");
  add_action("commander_talk", "gct");  
  add_action("commander_emote", "gce");
  add_action("promote_shadow","promote");
  add_action("stat_shadow", "shadstat");
  add_action("add_shadow_xp","agxp");
  add_action("set_gc_title","settitle");
  add_action("add_shadow_pts", "ashp");
  add_action("hand_mark", "mark");
  add_action("force_update", "upd");
  add_action("show_logo", "logo");
  add_action("banish_shadow","banish");
  add_action("check_pool", "check_pool");  
    

  add_action("set_login_string", "setin");  
  add_action("set_logout_string", "setout");   
  add_action("review_strings", "revstr");
  add_action("guild_stat", "scs");
  add_action("guild_stat", "sc");
  add_action("other_who", "ow");   
  add_action("guild_who", "shw");
  add_action("guild_emote", "she");
  add_action("guild_tell","sh");
  add_action("shadow_speak", "shay"); 
  add_action("update_me","update_me");   
  add_action("refresh_me", "refresh_me");
  add_action("save_me", "save_me");  
  add_action("restore_me", "restore_me");  
  add_action("use_hit_points", "points");  
  add_action("set_shadow_monitor", "shp");
  add_action("shadow_monitor", "mon"); 
  add_action("information", "info");
  add_action("drain_damage", "dd");
  add_action("check_time", "time");   
  add_action("end_game","quit");
  add_action("muffle_shadow","muffsh");
  add_action("toggle_summon","sum");
  add_action("change_startup", "startme");
  add_action("shadow_news", "shadownews");
  add_action("add_to_sp_pool", "donate");
  add_action("take_from_sp_pool", "retrieve");

  add_action("count_sp_in_pool", "check");     
  add_action("leave_shadows", "leave_shadows");
  
  
  add_action("goto_guild","guild");
  add_action("add_shadow_ac_p1", "protect");
  add_action("add_shadow_ac_p3", "aura");
  add_action("check_alignment", "check");
  add_action("empty_corpse","empty");    
  add_action("call_darkness","darkness");
  add_action("drain_monster", "drain");
  add_action("peace_room", "shadow");
  add_action("transfer_hp_to_sp", "pheal");
  add_action("transfer_sp_to_hp", "mheal");
  add_action("start_shadow_healing", "sheal");
  add_action("follow_who", "follow");
  add_action("fade_to_player","fadeto");
  add_action("stop_heal", "stop_heal");
  add_action("forge_weapon", "forge");
  add_action("shadow_scream", "scream");
  add_action("shadow_spell", "shadkl");
  add_action("attack_shadow", "atkshad"); 
  add_action("send_to_shadow", "sendto"); 
  add_action("opp_shad_attack_opp", "oppshad");
  
  /* Shadow Only Emotes */
  
  add_action("shadow_smile", "ssmile");
  add_action("shadow_grin", "sgrin");
  add_action("shadow_say", "SAY");

}
  
setup_armor_class() {
  int sh_lev;
  sh_lev = TP->query_guild_rank();
  if(((sh_lev + 4) > 10) && (sh_lev < 15)) { TP->set_ac(10); }
  else TP->set_ac((sh_lev + 4));
  call_out("setup_armor_class", 60);
  return 1;
}
  
set_shadow_healing(amt) { shadow_healing = amt; }
query_shadow_healing() { return shadow_healing; }
query_heal_called() { return heal_called; }
reset_heal_called() { heal_called = 0; }
set_spell_time(amt) { spell_time = amt; }
query_spell_time() { return spell_time; } 
set_monitor(mon) { monitor = mon; monitor_count = 0; }
query_monitor() { return monitor; }
set_points(pts) { points = pts; }
query_points() { return points; }
set_summon(sum) { summon = sum; }
query_summon() { return summon; }
set_follow(amt) { follow = amt; }
query_follow() { return follow; } 
query_light() { return set_light(0); }
query_muffled() { return muffled; }
set_muffled(muf) { muffled = muf; }
query_drain_damage() { return drain_damage; }
set_drain_damage(dam) { drain_damage = dam; }
set_in_string(instr) { in = instr; }
set_out_string(outstr) { out = outstr; }
query_in_string() { return in; }
query_out_string() { return out; }  
add_bonus(amt) { bonus += amt; }
query_bonus() { return bonus; }
  

refresh_me() {
  TOOL->refresh_mark(ENVTO);
  return 1;
}


update_me() {
  object new;
  write("Updating your Shadowy Essence...\n");
  new = clone_object(THIS_FILE); 
  move_object(new, TP);
  write("Done!\n");
  destruct(TO);
  return 1;
}

show_logo() {
  if(logo) TOOL->guild_echo(BOLD+"\n"+logo+NOSTYLE+"\n");
  return 1;
}

end_game() {
  TOOL->end_the_game();
}

dest_guild_obj() {
  destroy(this_object());   
  return 1;
  }


check_time() { TOOL->check_time(); return 1; }
information(str) { TOOL->information(str); return 1; }  
guild_tell(str) { TOOL->guild_tell(str); return 1; }
guild_emote(str) { TOOL->guild_emote(str); return 1; }
guild_who() { TOOL->guild_who(); return 1; }  
commander_talk(str) { TOOL->commander_talk(str); return 1; }
commander_emote(str) { TOOL->commander_emote(str); return 1; }
commander_who() { TOOL->commander_who(); return 1; }
promote_shadow(str) { TOOL->promote_shadow(str); return 1 TOOL->add_shadow_pts(str); return 1; }
hand_mark(str) { TOOL->hand_mark(str); return 1; }
force_update(str) { TOOL->force_update(str); return 1; }
shadow() { TOOL->shadow(); return 1; }
transfer_hp_to_sp(str) { TOOL->transfer_hp_to_sp(str); return 1; }
transfer_sp_to_hp(str) { TOOL->transfer_sp_to_hp(str); return 1; }
transfer_sp_shp(str) { TOOL->transfer_sp_shp(str); return 1; }
use_hit_points(str) { TOOL->use_hit_points(str); return 1; }
start_shadow_healing() { TOOL->start_shadow_healing(); return 1; }
forge_weapon(str) { TOOL->forge_weapon(str); return 1; }   
drain_damage(str) { TOOL->drain_damage(str); return 1; }  
drain_monster(str) { TOOL->drain_monster(str); return 1; }
recruit_shadow(str) { TOOL->recruit_shadow(str); return 1; }
peace_room() { TOOL->peace_room(); return 1; }
muffle_shadow(str) { TOOL->muffle_shadow(str); return 1; }
call_darkness() { TOOL->call_darkness(); return 1; }
goto_guild() { TOOL->goto_guild(); return 1; }
fade_to_player(str) { TOOL->fade_to_player(str); return 1; }
empty_corpse(str) { TOOL->empty_corpse(str); return 1; }
less_pts(str) { TOOL->less_pts(str); return 1; }
toggle_summon(str) { TOOL->toggle_summon(str); return 1; }
guild_stat() { TOOL->guild_stat(); return 1; }
stat_shadow(str) { TOOL->stat_shadow(str); return 1; }
check_alignment(str) { TOOL->check_alignment(str); return 1; }
shadow_speak(str) { TOOL->shadow_speak(str); return 1; }
other_who() { TOOL->other_who(); return 1; }
set_gc_title() { TOOL->set_gc_title(); return 1; }
change_startup(str) { TOOL->change_startup(str); return 1; }
banish_shadow(str) { TOOL->banish_shadow(str); return 1; }
leave_shadows() { TOOL->leave_shadows(); return 1; }
follow_who(str) { TOOL->follow_who(str); return 1; }
shadow_scream(str) { TOOL->shadow_scream(str); return 1; }
goto_master() { SERVANT->goto_master(); return 1; }
shadow_smile(str) { TOOL->shadow_smile(str); return 1; }
shadow_grin(str) { TOOL->shaow(str); return 1; }
shadow_monitor() { TOOL->shadow_monitor(ENVTO); return 1; }
attack_shadow(str) { TOOL->attack_shadow(str); return 1; }
shadow_spell(str) { TOOL->shadow_spell(str); return 1; }
old_force_update(str) { TOOL->old_force_update(str); return 1; }
old_hand_mark(str) { TOOL->old_hand_mark(str); return 1; }
old_promote_shadow(str) { TOOL->old_promote_shadow(str); return 1; }
set_shadow_monitor(str) { TOOL->set_shadow_monitor(str); return 1; }
set_logout_string(str) { TOOL->set_logout_string(str); return 1; }
set_login_string(str) { TOOL->set_login_string(str); return 1; }
review_strings() { TOOL->review_strings(); return 1; }
stop_heal() { TOOL->stop_heal(); return 1; }
shadow_news() { TOOL->shadow_news(); return 1; }
opp_shad_attack_opp(str) { TOOL->opp_shad_attack_opp(str); return 1; }
shadow_say(str) { TOOL->shadow_say(str); return 1; }
add_to_sp_pool(amt) { TOOL->add_to_sp_pool(amt); return 1; }
take_from_sp_pool(amt) { TOOL->take_from_sp_pool(amt); return 1; }
count_sp_in_pool() { TOOL->count_sp_in_pool(); return 1; }
check_pool() { TOOL->check_pool(); return 1; }
add_shadow_ac_p1() { TOOL->add_shadow_ac_p1(); return 1; }
add_shadow_ac_p3() { TOOL->add_shadow_ac_p3(); return 1; }

