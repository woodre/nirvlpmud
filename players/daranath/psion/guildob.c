/* Base Psion guild object, taken heavily from my Necromancer Object, which 
   may or may not look like the current one, I have no idea */

#include "/players/daranath/psion/defs.h"
#define CHAT "/players/daranath/guild/chatter.c"
#define SPELL "/players/daranath/guild/daemon"
#define SAVE "players/daranath/guild/member/"

int blood, eye, heart, skin, soul, spine;
int cdust;
int val;
int g_level;
string enter_msg, leave_msg;

query_auto_load() {return "/players/daranath/guild/guildob.c:"; }
id(str) {return str == "necro_ob" || str == "skull" || str == "notarmor";; }
short() { return "A small, brightly polished skull"; }
long() {
write("A skull taken from a treasured victory of long ago.\n"+
      "The skull has been meticulously cleaned and taken\n"+
      "care of. The symbol of a true Necromancer.\n"+
      "<"+BOLD+"nhelp"+NORM+"> for necromantic notes.\n");
  }

drop() { return 1;}
get() { return 0;}

extra_look() {
write(environment()->query_name()+" has a small skull tattoo upon "+
  environment()->query_possessive()+" forehead.\n");
}

init() {
if(environment(this_object()) == this_player()) {
  if(!restore_object(SAVE+tpn)) {
    blood = 25;
    eye = 0;
    heart = 0;
    skin = 0;
    soul = 0;
    spine = 0;
    cdust = 0;
	g_level = 1;
   enter_msg = "enters the game.";
   leave_msg = "leaves the game.";
   save_object(SAVE+tpn);
  }
  if(tp->query_level() < 20) {
    tp->set_guild_name("necromancer");
	if(tp->query_guild_rank() != g_level) tp->add_guild_rank(g_level - tp->query_guild_rank());
  tp->save_character();
  }
  CHAT->add_membr(tp);
  if(!tp->query_invis()) {
  call_other(CHAT,"chat_line",enter_msg,this_player()->query_name(),1);
}
  /* basic guild abilities */
add_action("necro_chat","nc");
add_action("necro_emote","nce");
}
  }

query_guild_title() {
  if(g_level == 1) {return "the Apprentice Necromancer";}
  if(g_level == 2) {return "the Acolyte of Suffering"; }
  if(g_level == 3) {return "the Initiate of Shadows"; }
  if(g_level == 4) {return "the Servant of Shadows"; }
  if(g_level == 5) {return "the Harvester of Bone"; }
  if(g_level == 6) {return "the Grifter"; }
  if(g_level == 7) {return "the Initiate of Darkness"; }
  if(g_level == 8) {return "the Servant of Darkness"; }
  if(g_level == 9) {return "the Minister of Souls"; }
  if(g_level == 10){return "the Master Necromancer"; }
  if(tp->query_name() == "Daranath"){return "The Creator"; }
}

query_g_level() {return g_level; }

save_me() { g_level = ep->query_guild_rank(); save_object(SAVE+epn); return 1; }

necro_save() { save_me(); tell_object(ep,"Guild status saved.\n"); return 1; }

necro_update() {
  move_object(clone_object("/players/daranath/guild/guildob.c"),tp);
  write("<"+HIW+"NECRO"+NORM+"> Guild Status Updated.\n");
  destruct(this_object());
return 1; }

necro_chat(str) {
  if(!str) { write("What do you want to say over the Necro line.\n"); return 1; }
  CHAT->chat_line(str,tp->query_name());
return 1; }

necro_emote(str) {
  if(!str) { write("What do you want to emote over the Necro line.\n"); return 1; }
  CHAT->chat_line(str,tp->query_name(),1);
return 1; }

necro_title() {
 string title;
  if(g_level == 1) {title = "the Apprentice Necromancer"; }
  if(g_level == 2) {title = "the Acolyte of Suffering"; }
  if(g_level == 3) {title = "the Initiate of Shadows"; }
  if(g_level == 4) {title = "the Servant of Shadows"; }
  if(g_level == 5) {title = "the Harvester of Bone"; }
  if(g_level == 6) {title = "the Grifter"; }
  if(g_level == 7) {title = "the Initiate of Darkness"; }
  if(g_level == 8) {title = "the Servant of Darkness"; }
  if(g_level == 9) {title = "the Minister of Souls"; }
  if(g_level == 10){title = "the Master Necromancer"; }
  tp->set_title(title);
  write("<"+HIW+"NECRO"+NORM+"> Necromancer Title Set.\n");
return 1; }

necro_login(str) {
  if(!str){write("Where do you want to login? (church/guild)\n"); return 1;}
  if(str == "church") {tp->set_home("/room/church.c"); }
  if(str == "guild") {tp->set_home("/players/daranath/guild/room/necro2.c"); }
  write("<"+HIW+"NECRO"+NORM+"> Your login position has been changed.\n");
  return 1;
}

necro_quit() {
      tp->set_guild_name(0);
      tp->add_exp(tp->query_guild_exp());
      tp->add_guild_exp(-tp->query_guild_exp());
      tp->add_guild_rank(-tp->query_guild_rank());
	  tp->add_exp(-(tp->query_exp()/2));
      tp->set_attrib("sta",1);
	  tp->reset(1);
	  command("save",tp);
	  write("FOOL!\n");
	  CHAT->sub_membr(tp);
	  CHAT->chat_line("has left the guild",tp->query_real_name(),1);
      rm("/"+SAVE+tpn+".o");
	  destruct(this_object());
return 1; }

quit() {
  necro_save();
  CHAT->sub_membr(ep);
  if(!tp->query_invis()) {
  call_other(CHAT,"chat_line",leave_msg,this_player()->query_name(),1);
}
}

world_emote(str) {
  if(!str) return 0;
  tell_room(environment(tp),tp->query_name()+" "+str+"\n");
return 1; }

set_necro_enter(str) {
  enter_msg = str;
  necro_save();
  write("<"+HIW+"NECRO"+NORM+"> Necromancer enter message set.\n");
return 1; }

set_necro_leave(str) {
  leave_msg = str;
  necro_save();
  write("<"+HIW+"NECRO"+NORM+"> Necromancer leave message set.\n");
return 1; }

add_blood(int num){ blood += num; }
add_skin(int num){ skin += num; }
add_eye(int num){ eye += num; }
add_spine(int num){ spine += num; }
add_heart(int num){ heart += num; }
add_soul(int num){ soul += num; }
add_cdust(int num){ cdust += num; }
add_val(int num) { val += num; }
set_val(arg) { val = arg; necro_save(); return 1; }

necro_block() {
 if(tp->query_level() < 20) {
  write("<"+HIW+"RoD"+NORM+"> The Realm of Death distains the use of that spell.\n");
 return 1; }
}

necro_notes() {
return 1;
}

comp_cost() {
return 1; 
}

no_harvester() {
  if(present("necro_tool",this_player())) {
  return 0; } else {
  write("You must have a harvesting tool to harvest.\n");
  return 1; }
}

corpse_light() {
  set_light(1);
  write("You cast a dim light.\n");
  call_out("fade_light",100);
return 1; }

fade_light() {
  set_light(-1);
  write("The dim light fades from view.\n");
return 1; }

check(int chk) {
   if(chk > ep->query_guild_rank()) { tell_object(ep,"You are not advanced enough for that spell....  yet.\n"); return 0; }
    return 1; 
}

necro_score() {SPELL->necro_score(); return 1; }
necro_who() {SPELL->necro_who(); return 1; }
necro_gwho() {SPELL->necro_gwho(); return 1; }
autopsy(str) {SPELL->autopsy(str); return 1; }
preserve() {SPELL->preserve(); return 1; }
dembrace() {SPELL->dembrace(); return 1; }
touch_chill(str) { SPELL->touch_chill(str); return 1; }
summon_tool() { SPELL->summon_tool(); return 1; }
assasination(str) { if(check(2)) SPELL->backstab(str); return 1; }
wraithform() { SPELL->wraithform(); return 1; }
gravepact(str) { SPELL->gravepact(); return 1; }
touch_spect(str) { if(check(2)) SPELL->touch_spect(str); return 1; }
death_door() { if(check(2)) SPELL->death_door(); return 1; }
cons_corp(str) { if(check(2)) SPELL->cons_corp(str); return 1; }
dis_burial() { if(check(2)) SPELL->dis_burial(); return 1; }
badmoon() { if(check(2)) SPELL->badmoon(); return 1; }
drain_life() { if(check(3)) SPELL->drain_life(); return 1; }
buried_alive() { if(check(3)) SPELL->buried_alive(); return 1; }
con_grave() { if(check(3)) SPELL->con_grave(); return 1;}
aban_hope(str) { if(check(4)) SPELL->aban_hope(str); return 1; }
conf_cloak(str) { if(check(4)) SPELL->conf_cloak(str); return 1; }
sphere(str) { if(check(4)) SPELL->sphere(str); return 1; }
ghast_stench() { if(check(5)) SPELL->ghast_stench(); return 1; }
raise_portal() { if(check(5)) SPELL->raise_portal(); return 1; }
syphon(str) { if(check(6)) SPELL->syphon(str); return 1; }
sad_glee(str) { if(check(6)) SPELL->sad_glee(str); return 1; }
grafting(str) { if(check(7)) SPELL->grafting(str); return 1; }
shadow(str) { if(check(8)) SPELL->shadow(str); return 1; }
blind_agony(str) { if(check(9)) SPELL->blind_agony(str); return 1; }
deathfog() { if(check(10)) SPELL->deathfog(); return 1; }
raise_dead(str) { if(check(10)) SPELL->raise_dead(str); return 1; }
banshee(str) { if(check(11)) SPELL->banshee(str); return 1; }

