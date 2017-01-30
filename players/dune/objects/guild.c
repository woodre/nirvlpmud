#include "/players/pathfinder/closed/shadow/esc.h"
#define TOOL "/players/pathfinder/closed/shadow/shadow-master.c"
#define TP this_player()
#define ENV environment
#define TO this_object()
#define CAP capitalize
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define SAVE "players/pathfinder/closed/shadow/shadows/"
#define RN this_player()->query_real_name()
#define BOLD ESC+"[1m"
#define NOSTYLE ESC+"[0m"
 
static monitor_count;
static string logo;
 
int sh_xp, sh_pts, sh_lev, muffled, drain_damage, am_following, monitor;
int summon, points;
 
static object servant, follow, pearl;
 
 
query_auto_load() {
  return "/players/pathfinder/closed/shadow/shadow.c:";
  }
  
id(str) { return str == "mark" || str == "guild_object" || str == "shadow-mark" || str == "notarmor"; }
 
short() {
  string short;
  short = ESC+"[1m"+"Mark of the Shadows"+ESC+"[0m";
  return short;
  }
  
long() {
  tell_object(ENVTO,"This is the Mark of the Shadow Guild.\n"+
                    "To recieve information just type 'info help'.\n");
  }
                    
extra_look() {
  return""+capitalize(TP->query_name())+" has a shadowy aura surrounding them";
  }
  
get() { return 1; }
drop() { return 1; }
 
init_arg(str) {
  TOOL->guild_echo("\n"+"<"+BOLD+capitalize(this_player()->query_real_name())+NOSTYLE+"> has entered the game.\n");
  tell_object(TP,"\nWelcome to the "+BOLD+"NEW"+NOSTYLE+" Shadow Guild.\n");
  tell_object(TP,"To get the latest news type 'shadownews'.\n");
  tell_object(TP,"\n\nOh, by the way, the Shadows are under new management.\n");
  tell_object(TP,"If you have any questions, comments, bitches, gripes mail Quicksilver\n");
  tell_object(TP,"or Pathfinder.\n");
  TP->set_al_title(BOLD+"<SHADOW>"+NOSTYLE);
  /* commented out as it is taken care of in init()
  restore_me();
  */
  return 1;
}
 
update_arg(str) {
  sscanf(str,"%d#%d#%d#%d#%d",muffled,sh_xp,sh_lev,sh_pts,drain_damage);
  save_object(SAVE+RN);
  return 1;
}
 
reset(arg) {
 if(!arg) {
   muffled = 0;
   drain_damage = 6;
   sh_xp = 0;
   sh_lev = 1;
   sh_pts = 0;
   points = 0;
   am_following = 0;
   follow = 0;
   monitor = 0;
   summon = 0;
   monitor_count = 0;
 set_light(1);
 call_out("heal_shadow_pts",1);
 logo = read_file("/players/pathfinder/closed/shadow/logo");
 }
 }

heart_beat() {
  tell_object(TP,"here, trying to follow\n");
  if(!monitor && !follow) set_heart_beat(0);
  if(monitor > 0) {
    if(!(monitor_count % monitor)) {
      TOOL->do_shadow_monitor();
      monitor = 0;
      }
    monitor_count++;
    }
  if(monitor < 0 && (ENVTO->query_attack() || (servant && servant->query_attack()))) TOOL->do_shadow_monitor();
  if(follow && (!present(follow, ENV(TP)))) TOOL->update_follow(follow->query_real_name());
}

 
heart_me() {
  set_heart_beat(1);
  return 1;
  }
  
unheart_me() {
  set_heart_beat(0);
  return 1;
  }
 
heal_shadow_pts() {
  sh_pts += 1;
  if(sh_pts > TP->query_shlevel() * 5) sh_pts = TP->query_shlevel() * 5;
  call_out("heal_shadow_pts", 5);
  TP->set_guild_name("shadow");
  return 1;
}  
 
save_me() {
  string file;
  file = SAVE + RN;
  if(!save_object(file)) {
    tell_object(ENVTO,"Error in saving stats...\n");
    return 0;
    }
  tell_object(ENVTO,"Saving guild stats...\n");
  return 1;
}
 
restore_me() {
  string file;
  file = SAVE + RN;
  if(!restore_object(file)) {
    tell_object(TP,"Error in restoring stats...\n");
    return 0;
    }
  tell_object(TP,"Restoring guild stats...\n");
  return 1;
}
 
init() {
  restore_me();
  /* Sets shadows armor class to 4 + their shadow rank */
  TP->set_ac(TP->query_shlevel()+4);
  TP->set_al_title(BOLD+"<SHADOW>"+NOSTYLE);
/*  Commander functions as of about 10-1-94 */
  if(sh_lev > 8) {
    add_action("commander_talk", "ct");
    add_action("commander_emote", "ce");
    add_action("commander_who", "cw");
    add_action("promote_shadow","promote");
    add_action("add_shadow_xp","ashxp");
    add_action("add_shadow_pts", "ashp");
    add_action("hand_mark", "mark");
    add_action("force_update", "upd");
    add_action("show_logo", "logo");
    }
    
/*  Normal shadow functions.  as of about 10-1-94 */
 
  add_action("guild_who", "shw");
  add_action("guild_emote", "she");
  add_action("guild_tell","sh");
  add_action("update_me","update_me");
  add_action("save_me", "save_me");
  add_action("restore_me", "restore_me");
  add_action("which_points", "points");
  add_action("set_shadow_monitor", "mon");
  add_action("information", "info");
  add_action("drain_damage", "dd");
  add_action("check_time", "time");
  add_action("end_game","quit");
  add_action("muffle_shadow","muffsh");
  add_action("get_shadez","shades");
  
/*  Spells for shadows ..  as of about 10-1-94 */

  add_action("empty_corpse","empty");
  add_action("call_darkness","darkness");
  add_action("drain_monster", "drain");
  add_action("peace_room", "shadow");
  add_action("transfer_hp_to_sp", "pheal");
  add_action("transfer_sp_to_hp", "mheal");
  add_action("transfer_sp_shp", "transfer");
  add_action("follow_who", "follow");
  add_action("fade_to_player","fadeto");
  add_action("heal_da_shadow", "sheal");
  add_action("forge_weapon", "forge");
  add_action("recruit_shadow", "recruit");
  add_action("goto_guild","guild");
  
  call_out("heal_shadow_pts",1);
}  
 
query_shxp() { return sh_xp; }
add_shxp(amt) { sh_xp += amt; }
query_shlevel() { return sh_lev; }
query_shpts() { return sh_pts; }
set_shxp(amt) { sh_xp = amt; }
add_shpts(amt) { sh_pts += amt; }
set_points(pts) { points = pts; }
query_points() { return points; }
set_shpts(amt) { 
  int max;
  max = TP->query_shlevel() * 5;
  if(amt > max) {
    sh_pts = max;
  } else {
    sh_pts = amt;
  }
}
set_summon(sum) { summon = sum; }
query_summon() { return summon; }
query_follow() { return follow; }
query_muffled() { return muffled; }
set_muffled(muf) { muffled = muf; }
query_drain_damage() { return drain_damage; }
set_drain_damage(dam) { drain_damage = dam; }
 
set_shlevel(lev) { 
  sh_lev = lev;
  ENVTO->set_ac(4+sh_lev);
  tell_object(ENVTO,"You have been promoted to rank "+sh_lev+".\n");
  save_me();
  return 1; 
}
 
check_time() {
  call_other("/room/church.c","long","clock");
  return 1;
}
 
revoke_me() {
  int gxp, grank;
  gxp = ENVTO->query_shxp();
  grank = ENVTO->query_shlevel();
  tell_object(ENVTO,"Your mark has been revoked.\n");
  ENVTO->set_shxp(-gxp);
  ENVTO->set_shlevel(-grank);
  destruct(TO);
}
 
update_me() {
  object this;
  this = clone_object("/players/pathfinder/closed/shadow/shadow.c");
  save_me();
  move_object(this,ENVTO);
  tell_object(ENVTO,"Shadow mark updated.\n");
  destruct(TO);
  return 1;
}
  
 
follow_who(str) {
  object who;
  if(!str) {
    tell_object(ENVTO,"Usage: follow <player/off>.\n");
    return 1;
    }
  who = find_player(str);
  if(!who) {
    tell_object(ENVTO,"Can't find "+CAP(str)+" on the game.\n");
    return 1;
    }
  if(!present(who,ENV(ENVTO))) {
    tell_object(ENVTO,CAP(str)+" isn't present.\n");
    return 1;
    }
  if(who->query_level() > 20) {
    tell_object(ENVTO,"You can't follow wizards.\n");
    return 1;
    }
  if(who->query_ghost()) {
    tell_object(ENVTO,"You can't follow a ghost.\n");
    return 1;
    }
  if(!TOOL->less_pts(20)) {
   tell_object(ENVTO,"You don't have enough energy.\n");
   return 1;
   }
  tell_object(who,"You are being followed by "+CAP(RN)+".\n");
  tell_object(ENVTO,"You now follow "+CAP(str)+".\n");
  set_heart_beat(1);
  return 1;
}
 
show_logo() {
  if(logo) TOOL->guild_echo(BOLD+"\n"+logo+NOSTYLE+"\n");
  return 1;
}
 
set_shadow_monitor(str) {
  if(str == "attack") {
    monitor = -1;
    tell_object(ENVTO,"Monitor set to attack.\n");
    set_heart_beat(1);
    return 1;
    }
  if(!str) {
    monitor = 0;
    TOOL->shadow_monitor();
    set_heart_beat(0);
    return 1;
    }
  if(!str || !sscanf(str,"%d",monitor)) {
    tell_object(ENVTO,"Usage: mon <number/attack>.\n");
    return 1;
    }
  if(!monitor || monitor == 0) {
    monitor = 0;
    tell_object(ENVTO,"Monitor is off.\n");
    return 1;
    }
  tell_object(ENVTO,"Monitor time set to "+monitor+"\n");
  monitor_count = 0;
  set_heart_beat(1);
  return 1;
}
 
end_game() {
  if(present("pearl-object",ENVTO)) pearl->end_game();
  TOOL->guild_echo("<>"+BOLD+CAP(RN)+NOSTYLE+"<> has left the game.\n");
  save_me();
}
 
leave_shadows() {
  int gxp, grank, exp;
  gxp = ENVTO->query_shxp();
  grank = ENVTO->query_shlevel();
  exp = ENVTO->query_experience();
  ENVTO->set_shxp(-gxp);
  ENVTO->set_shlevel(-grank);
  ENVTO->set_guild_name(0);
  ENVTO->add_experience(-exp/6);
  tell_object(ENVTO, "You lose 1/6th of your experience for leaving a guild.\n");
  tell_object(ENVTO, "You have left the Shadow guild.\n");
}
 
information(str) { TOOL->information(str); return 1; }
guild_tell(str) { TOOL->guild_tell(str); return 1; }
guild_emote(str) { TOOL->guild_emote(str); return 1; }
guild_who() { TOOL->guild_who(); return 1; }
commander_talk(str) { TOOL->commander_talk(str); return 1; }
commander_emote(str) { TOOL->commander_emote(str); return 1; }
commander_who() { TOOL->commander_who(); return 1; }
promote_shadow(str) { TOOL->promote_shadow(str); return 1; }
add_shadow_xp(str) { TOOL->add_shadow_xp(str); return 1; }
add_shadow_pts(str) { TOOL->add_shadow_pts(str); return 1; }
hand_mark(str) { TOOL->hand_mark(str); return 1; }
force_update(str) { TOOL->force_update(str); return 1; }
shadow() { TOOL->shadow(); return 1; }
transfer_hp_to_sp(str) { TOOL->transfer_hp_to_sp(str); return 1; }
transfer_sp_to_hp(str) { TOOL->transfer_sp_to_hp(str); return 1; }
transfer_sp_shp(str) { TOOL->transfer_sp_shp(str); return 1; }
which_points() { TOOL->which_points(); return 1; }
heal_da_shadow() { TOOL->heal_da_shadow(); return 1; }
forge_weapon(str) { TOOL->forge_weapon(str); return 1; }
drain_damage(str) { TOOL->drain_damage(str); return 1; }
drain_monster(str) { TOOL->drain_monster(str); return 1; }
recruit_shadow(str) { TOOL->recruit_shadow(str); return 1; }
peace_room() { TOOL->peace_room(); return 1; }
muffle_shadow(str) { TOOL->muffle_shadow(str); return 1; }
call_darkness() { TOOL->call_darkness(); return 1; }
goto_guild() { TOOL->goto_guild(); return 1; }
fade_to_player(str) { TOOL->fade_to_player(str); return 1; }
get_shadez() { TOOL->get_shadez(); return 1; }
empty_corpse(str) { TOOL->empty_corpse(str); return 1; }

