#include "/players/pathfinder/closed/shadow/esc.h"
#define TOOL "/players/pathfinder/closed/shadow/shadow-master.c"
#define NEWTOOL "/players/pathfinder/closed/shadow/new/shadow-master.c"
#define TP this_player()
#define ENV environment
#define TO this_object()
#define QRN query_real_name()
#define CAP capitalize
#define ENVTP environment(this_player())
#define ENVTO environment(this_object())
#define SAVE "players/pathfinder/closed/shadow/shadows/"
#define RN this_player()->query_real_name()
#define BOLD ESC+"[1m"
#define NOSTYLE ESC+"[0m"
 
static monitor_count;
static string logo;
static int spell_time;
 
int sh_xp, sh_pts, sh_lev, muffled, drain_damage, monitor, summon, points, mshpts;
string in, out;
 
static object servant, follow, pearl;
 
 
query_auto_load() {
  return "/players/pathfinder/closed/shadow/shadow.c:";
  }
  
id(str) { return str == "mark" || str == "guild_object" || str == "shadow-mark"; }
 
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
  return ""+CAP(ENVTO->query_name())+" has a shadowy aura surrounding them";
  }
  
get() { return 1; }
drop() { return 1; }
 
init_arg(str) {
  restore_me();
  if(TP->query_invis() < 19)
  TOOL->guild_echo("\n"+"<"+BOLD+CAP(TP->QRN)+NOSTYLE+"> "+in);
  tell_object(TP,"\nWelcome to the "+BOLD+"NEW"+NOSTYLE+" Shadow Guild.\n");
  tell_object(TP,"To get the latest news type 'shadownews'.\n");
  tell_object(TP,"\n\nOh, by the way, the Shadows are under new management.\n");
  tell_object(TP,"If you have any questions, comments, bitches, gripes mail Quicksilver\n");
  tell_object(TP,"or Pathfinder.\n");
  write("\n\nIf you have any suggestions for the guild, mail Pathfinder at:\n");
  write("mkonopka@umich.edu\n");
  if(TP->query_level() > 19) {}
  else {
  TP->set_al_title(BOLD+"<SHADOW>"+NOSTYLE);
  }
  /* commented out as it is taken care of in init()
  restore_me();
  */
  return 1;
}
 
update_arg(str) {
sscanf(str,"%d#%d#%d#%d#%d#%d#%s:%s", monitor, points, sh_lev, sh_xp, sh_pts, drain_damage, in, out);
  save_object(SAVE+RN);
  return 1;
}
 
reset(arg) {
 if(!arg) {
  in = "has entered the game.\n";
  out = "has left the game.\n";
   muffled = 0;
   drain_damage = 6;
   sh_xp = 0;
   sh_lev = 1;
   sh_pts = 0;
   points = 0;
   follow = 0;
   monitor = 0;
   summon = 0;
   monitor_count = 0;
    spell_time = 0;
 set_light(1);
 logo = read_file("/players/pathfinder/closed/shadow/logo");
 }
 }

heart_beat() {
  if((monitor == 0) && !follow) set_heart_beat(0);
  if(monitor > 0) {
    if(!(monitor_count % monitor)) {
      shadow_monitor();
    set_heart_beat(1);
      }
    monitor_count++;
    }
  if(monitor < 0 && (ENVTO->query_attack() || (servant && servant->query_attack()))) shadow_monitor();
  if(follow && !present(follow,ENV(ENVTO))) update_follow();
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
    tell_object(TP,"Error in restoring stats...\n");
    return 0;
    }
  tell_object(TP,"Restoring guild stats...\n");
  return 1;
}
 
init() {
  object tp, mark;
  int gxp, grank;

  restore_me();
  
 /*
  tp = this_player();
  mark = present("shadow-mark", tp);

  tp->add_guild_exp((-1 * sh_xp));
  
  write("The Shadows are being disbanded, if you would like to see\n");
  write("them come back again sometime, please mail pathfinder\n");
  
  if(sh_lev > 8) sh_xp = 2000000;
  
  tp->add_guild_rank((-1 * sh_lev));
  tp->set_guild_name(0);
  tp->set_home("/room/church");
  tp->add_exp(sh_xp);
  
  command("save", tp);
 */
  
  mshpts = sh_lev * 5;
/*  Commander functions as of about 10-1-94 */
  if((sh_lev > 8) || (TP->query_real_name() == "pathfinder")) {
    add_action("commander_talk", "ct");
    add_action("commander_emote", "ce");
    add_action("commander_who", "cw");
    add_action("promote_shadow","promote");
    add_action("stat_shadow", "gstat");
    add_action("add_shadow_xp","ashxp");
    add_action("set_gc_title","settitle");
    add_action("add_shadow_pts", "ashp");
    add_action("hand_mark", "mark");
    add_action("force_update", "upd");
    add_action("show_logo", "logo");
    add_action("banish_shadow","bansh");
    add_action("get_flyer", "flyer");
    }
    
/*  Normal shadow functions.  as of about 10-1-94 */

  add_action("speed_move", "shadmove");
  add_action("change_over", "new_guild");
  add_action("review_title", "rev");
  add_action("set_login_string", "setin");
  add_action("set_logout_string", "setout");
  add_action("guild_stat", "sc");
  add_action("other_who", "ow");
  add_action("plague_monster", "plague");
  add_action("opp_shad_attack_opp", "oppshadatk");
  add_action("pk_who", "pkw");
  add_action("pk_who", "pkwho");
  add_action("compare_foe", "cmpfoe");
  add_action("recruit_shadow", "recruit");
  add_action("guild_who", "shw");
  add_action("guild_emote", "she");
  add_action("guild_tell","sh");
  add_action("shadow_speak", "shay");
  add_action("update_me","update_me");
  add_action("save_me", "save_me");
  add_action("restore_me", "restore_me");
  add_action("which_points", "points");
  add_action("set_shadow_monitor", "shp");
  add_action("shadow_monitor", "mon");
  add_action("information", "info");
  add_action("drain_damage", "dd");
  add_action("check_time", "time");
  add_action("end_game","quit");
  add_action("muffle_shadow","muffsh");
  add_action("shadow_news", "shadownews");
  add_action("get_shadez","shades");
  add_action("goto_guild","guild");
  add_action("toggle_summon","sum");
  add_action("change_startup", "startme");
  add_action("leave_shadows", "leave_shadows");
  
/*  Spells for shadows ..  as of about 10-1-94 */

  add_action("check_alignment", "check");
  add_action("empty_corpse","empty");
  add_action("call_darkness","darkness");
  add_action("drain_monster", "drain");
  add_action("shadow_spell", "sspell");
  add_action("attack_shadow", "atkshad");
  add_action("peace_room", "shadow");
  add_action("transfer_hp_to_sp", "pheal");
  add_action("transfer_sp_to_hp", "mheal");
  add_action("transfer_sp_shp", "transfer");
  add_action("follow_who", "follow");
  add_action("fade_to_player","fadeto");
  add_action("forge_weapon", "forge");
  dest_to();

}  

dest_to()
{
  destruct(this_object());
  return 1;
}

change_over() {
  object mark;
  int oldgxp, oldgrank;
  oldgxp = TP->query_guild_exp();
  oldgrank = TP->query_guild_rank();
  TP->add_guild_exp(-oldgxp);
  TP->add_guild_rank(-oldgrank);
  TP->add_guild_exp(sh_xp);
  TP->add_guild_rank(sh_lev);
  mark = clone_object("/players/pathfinder/closed/shadow/new/shadow.c");
  move_object(mark, TP);
  mark->save_me();
  destruct(this_object());
  return 1;
}
 
query_spell_time() { return spell_time; }
set_spell_time(amt) { spell_time = amt; }
query_shxp() { return sh_xp; }
query_light() { return set_light(0); }
add_shxp(amt) { sh_xp += amt; }
query_shlev() { return sh_lev; }
add_shlev(amt) {
  sh_lev += amt;
  write("You have just been advanced to rank " + sh_lev + ".\n");
}

query_shlevel() { return sh_lev; }
query_shpts() { return sh_pts; }
set_shxp(amt) { sh_xp = amt; }
add_shpts(amt) { sh_pts += amt; }
set_points(pts) { points = pts; }
query_points() { return points; }
query_pt_select() { return points; }
set_shpts(amt) { 
  if(amt > mshpts) {
    sh_pts = mshpts;
  } else {
    sh_pts = amt;
  }
  return 1;
}
set_summon(sum) { summon = sum; }
query_summon() { return summon; }
query_follow() { return follow; }
query_muffled() { return muffled; }
set_muffled(muf) { muffled = muf; }
query_drain_damage() { return drain_damage; }
set_drain_damage(dam) { drain_damage = dam; }
query_in() { return in; }
query_out() { return out; }
 
query_mshpts() { return mshpts; }
set_shlevel(lev) { 
  TP->add_guild_exp(-sh_xp);
  sh_lev = lev;
  mshpts = sh_lev * 5;
  tell_object(TP,"You have been promoted to rank "+sh_lev+".\n");
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
  ENVTO->set_guild_name("shadow");
  command("save", this_player());
  destruct(TO);
  return 1;
}
  
/* Status Line for the Shadow Monitor */
 
shadow_monitor() {
  object att, me, mark;
  int msp, mhp, sp, hp, intox, oppsh, ohp, omhp, shp, mshp;
  string mesg;
  int stuff, soak;
  me = find_living(ENVTO->query_real_name());
  mark = present("shadow-mark",me);
  msp = ENVTO->query_msp();
  mhp = ENVTO->query_mhp();
  sp = ENVTO->query_sp();
  stuff = ENVTO->query_stuffed();
  soak = ENVTO->query_soaked();
  hp = ENVTO->query_hp();
  shp = sh_pts;
  mshp = mshpts;
  intox = ENVTO->query_intoxination();
  mesg = " ";
  if(ENVTO->query_attack()) {
   if(((ENVTO->query_attack())->query_attack())->query_real_name() == ENVTO->query_real_name()) {
    mesg += BOLD;
   }
  }
  mesg += "<hp> [" + hp + "/" + mhp + "] ";
  if(ENVTO->query_attack()) {
   if(((ENVTO->query_attack())->query_attack())->query_real_name() == ENVTO->query_real_name()) {
  mesg += NOSTYLE;
   }
  }
  mesg += "<sp> ["+sp+"/"+msp+"] ";
  mesg += "<shp> ["+shp+"/"+mshp+"] ";
  if(intox > 0) mesg += "<intox> ["+intox+"] ";
  if(stuff > 0) mesg += "<stuffed> ["+stuff+"] ";
  if(soak > 0) mesg += "<soaked> ["+soak+"] ";
  if(ENVTO->query_attack()) {
    att = ENVTO->query_attack();
    if(att) {
      mesg += " <opp> [";
      ohp = att->query_hp();
      omhp = att->query_mhp();
      if(ohp && omhp) {
        if(ohp < (omhp/10)) {
          mesg += "VBS]";
          }
        else if(ohp < (omhp/5)) {
          mesg += "BS]";
          }
        else if(ohp < (omhp/2)) {
          mesg += "SWH]";
          }
        else if(ohp < (omhp - 20)) {
          mesg += "SLH]";
          }
        else {
          mesg += "GS]";
          }
        }
      }
    }
  mesg += "\n";
  tell_object(ENVTO,mesg);
  return 1;
}
 
/* setable login and logout strings for shadows. */

set_login_string(str)
{
  if(!str) {
  tell_object(TP,"Login Message: has entered the game.\n");
  in = "has entered the game.\n";
  return 1;
  }
  in = str + "\n";
  tell_object(TP,"Login Message: "+in);
  return 1;
}

set_logout_string(str)
{
  if(!str)
  {
  tell_object(TP,"Logout Message: has left the game.\n");
  out = "has left the game.\n";
  return 1;
  }
  out = str + "\n";
  tell_object(TP,"Logout Message: "+out);
  return 1;
}
/* Update the follow */
 
update_follow() {
  tell_object(ENVTO,"You follow "+CAP(follow->query_real_name())+"\n");
  move_object(ENVTO,ENV(follow));
command("glance", environment(this_object()));
  tell_room(ENV(ENVTO),CAP(ENVTO->QRN)+" arrives following in the shadows of "+CAP(follow->QRN)+"\n");
  return 1;
}
 

 
follow_who(str) {
  object who;
  if(!str) {
    tell_object(ENVTO,"Usage: follow <player/off>.\n");
    return 1;
    }
  if(str == "off") {
    tell_object(TP,"You are now following no one.\n");
    follow = 0;
    return 1;
    }
  who = find_living(str);
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
  follow = who;
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
  if(TP->query_invis() < 19)
  TOOL->guild_echo("<>"+BOLD+CAP(RN)+NOSTYLE+"<> "+out);
  save_me();
}
 
leave_shadows() {
  int gxp, grank, exp;
  object tp, mark;
  tp = this_player();
  mark = present("shadow-mark", tp);
  gxp = mark->query_shxp();
  grank = mark->query_shlevel();
  exp = tp->query_exp();
  mark->set_shxp(0);
  ENVTO->set_shlevel(-grank);
  ENVTO->set_guild_name(0);
  ENVTO->add_experience(-exp/6);
  tell_object(ENVTO, "You lose 1/6th of your experience for leaving a guild.\n");
  tell_object(ENVTO, "You have left the Shadow guild.\n");
  ENVTO->set_guild_name(0);
  ENVTO->add_guild_exp(-(ENVTO->query_guild_exp()));
  ENVTO->add_guild_rank(-(ENVTO->query_guild_rank()));
  ENVTO->set_home("/room/church");
  command("save", tp);
  destruct(this_object());
}
 
information(str) { TOOL->information(str); return 1; }
shadow_news() { TOOL->information("news"); return 1; }
guild_tell(str) { TOOL->guild_tell(str); return 1; }
guild_emote(str) { TOOL->guild_emote(str); return 1; }
guild_echo(str) { TOOL->guild_echo(str); return 1; }
guild_who() { TOOL->guild_who(); return 1; }
commander_talk(str) { TOOL->commander_talk(str); return 1; }
commander_emote(str) { TOOL->commander_emote(str); return 1; }
commander_who() { TOOL->commander_who(); return 1; }
promote_shadow(str) { TOOL->promote_shadow(str); return 1; }
shadow_spell(str) { TOOL->shadow_spell(str); return 1; }
attack_shadow(str) { TOOL->attack_shadow(str); return 1; }
add_shadow_xp(str) { TOOL->add_shadow_xp(str); return 1; }
add_shadow_pts(str) { TOOL->add_shadow_pts(str); return 1; }
hand_mark(str) { TOOL->hand_mark(str); return 1; }
force_update(str) { TOOL->force_update(str); return 1; }
compare_foe(str) { TOOL->compare_enemy(str); return 1; }
shadow() { TOOL->shadow(); return 1; }
plague_monster(str) { TOOL->plague_monster(str); return 1; }
opp_shad_attack_opp(str) { TOOL->opp_shad_attack_opp(str); return 1; }
transfer_hp_to_sp(str) { TOOL->transfer_hp_to_sp(str); return 1; }
transfer_sp_to_hp(str) { TOOL->transfer_sp_to_hp(str); return 1; }
transfer_sp_shp(str) { TOOL->transfer_sp_shp(str); return 1; }
which_points(str) { TOOL->which_points(str); return 1; }
forge_weapon(str) { TOOL->forge_weapon(str); return 1; }
drain_damage(str) { TOOL->drain_damage(str); return 1; }
drain_monster(str) { TOOL->drain_monster(str); return 1; }
recruit_shadow(str) { TOOL->recruit_shadow(str); return 1; }
peace_room() { TOOL->peace_room(); return 1; }
muffle_shadow(str) { TOOL->muffle_shadow(str); return 1; }
call_darkness() { TOOL->call_darkness(); return 1; }
goto_guild() { TOOL->goto_guild(); return 1; }
fade_to_player(str) { TOOL->fade_to_player(str); return 1; }
add_to_pool(amt) { TOOL->add_to_pool(amt); return 1; }
take_from_pool(amt) { TOOL->take_from_pool(amt); return 1; }
query_usage() { TOOL->query_usage(); return 1; }
query_pool() { TOOL->query_pool(); return 1; }
get_shadez() { TOOL->get_shadez(); return 1; }
empty_corpse(str) { TOOL->empty_corpse(str); return 1; }
less_pts(str) { TOOL->less_pts(str); return 1; }
toggle_summon(str) { TOOL->toggle_summon(str); return 1; }
guild_stat() { TOOL->guild_stat(); return 1; }
stat_shadow(str) { TOOL->stat_shadow(str); return 1; }
check_alignment(str) { TOOL->check_alignment(str); return 1; }
shadow_speak(str) { TOOL->shadow_speak(str); return 1; }
other_who() { TOOL->other_who(); return 1; }
pk_who() { TOOL->pk_who(); return 1; }
set_gc_title() { TOOL->set_gc_title(); return 1; }
change_startup(str) { TOOL->change_startup(str); return 1; }
anish_shadow(str) { TOOL->banish_shadow(str); return 1; }
review_title() { TOOL->review_title(); return 1; }
speed_move(str) { TOOL->speed_move(str); return 1; }
get_flyer() { TOOL->get_flyer(); return 1; }
