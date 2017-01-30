/* THE BASE NECROMANCER OBJECT */

#include "/players/daranath/guild/defs.h"
#define CHAT "/players/daranath/guild/chatter.c"
#define SPELL "/players/daranath/guild/daemon"
#define SAVE "players/daranath/guild/member/"
#define spellfailed write("You lose your concentration.\n"); return 1;

int blood, eye, heart, skin, soul, spine;
int cdust;
int free_skill, perc, val;
int g_level;

query_auto_load() {return "/players/daranath/guild/guildob.c"; }
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
/*
extra_look() {
object ex_look;
  ex_look = environment(this_object())->query_name();
  write(ex_look+" has a small skull tattoo upon "+tp()->query_possessive()+" forehead.\n");
}
*/
init() {
if(environment(this_object()) == this_player()) {
  if(!restore_object(SAVE+tpn)) {
    free_skill = 15;
    blood = 0;
    eye = 0;
    heart = 0;
    skin = 0;
    soul = 0;
    spine = 0;
    cdust = 0;
	g_level = 1;
    perc = allocate(32);
    save_object(SAVE+tpn);
  }
  if(tp->query_level() < 20) {
    tp->set_guild_name("necromancer");
	if(tp->query_guild_rank() != g_level) tp->add_guild_rank(g_level - tp->query_guild_rank());
  }
  CHAT->add_membr(tp);
  /* basic guild abilities */
add_action("necro_chat","nc");
add_action("necro_emote","ne");
add_action("quit","quit");
add_action("world_emote","emote");
add_action("world_emote",":");
add_action("necro_who","nwho");
add_action("necro_score","nsc");
add_action("necro_score","nscore");
add_action("necro_quit","leave_guild");
add_action("necro_save","nsave");
add_action("necro_update","nupdate");
add_action("necro_notes","nhelp");
add_action("necro_block","missile",2);
add_action("necro_block","shock",2);
add_action("necro_block","fireball",2);
add_action("necro_block","sonic",2);
add_action("necro_block","invisible",5);
/*
add_action("necro_wear","wear");
add_action("necro_ready","ready");
*/

  /* level 1 spells */
add_action("wraithform","wform");
add_action("gravepact","gravepact");
add_action("corpse_light","clight");
add_action("necro_call","ncall");
add_action("dembrace","embrace_death");
add_action("touch_chill","chill");
add_action("autopsy","autopsy");
add_action("summon_tool","toolme");

  /* level 2 spells */
add_action("assasination","backstab");
add_action("bad_moon","badmoon");
add_action("dis_burial","disturb");
add_action("con_corpse","consume");
add_action("death_door","ddoor");

  /* level 3 spells */
add_action("un_divine","divine");
add_action("drain_life","lifedrain");
add_action("buried_alive","bury_me");
add_action("con_grave","congrave");

  /* level 4 spells */
add_action("aban_hope","abandon");
add_action("conf_cloak","cloak");

  /* level 5 spells */
add_action("ghast_stench","stench");
add_action("haunt_wind","haunt");

  /* level 6 spells */
add_action("drain_spirit","spiritdrain");
add_action("un_grasp","ungrasp");

  /* level 7 spells */
add_action("grafting","graft");
add_action("jester_cos","caress");

  /* level 8 spells */
add_action("drain_energy","energydrain");

  /* level 9 spells */
add_action("blind_agony","agony");
add_action("deathfog","deathfog");

  /* level 10 spells */
add_action("raise_dead","raise");
add_action("death_spell","death");
add_action("dark_intr","intrude");

  /* avatar spells */
add_action("banshee","banshee");
add_action("ceremony","ceremony");
add_action("darkpact","darkpact");
}
  }

add_perc(int mem,int val) {
  set_perc(mem,query_perc(mem) + val);
}

set_perc(int mem,int val) { /* present("necro_obj",tp)->set_perc(0,30); */
 perc[mem] = val;
 save_me();
return 1; }

query_perc(int mem) { return perc[mem]; }
query_blood() {return blood; }
query_skin() {return skin; }
query_eye() {return eye; }
query_spine() {return spine; }
query_heart() {return heart; }
query_soul() {return soul; }
query_cdust() {return cdust; }

save_me() { g_level = ep->query_guild_rank(); save_object(SAVE+epn); return 1; }

necro_save() { save_me(); tell_object(ep,"Guild status saved.\n"); return 1; }

necro_update() {
  move_object(clone_object("/players/daranath/guild/guildob.c"),tp);
  write("Guild status updated.\n");
  destruct(this_object());
return 1; }

necro_chat(str) {
  if(!str) { write("Type something dumbass.\n"); return 1; }
  CHAT->chat_line(str,tp->query_name());
return 1; }

necro_emote(str) {
  if(!str) { write("Type something dumbass.\n"); return 1; }
  CHAT->chat_line(str,tp->query_name(),1);
return 1; }

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
}

world_emote(str) {
  if(!str) return 0;
  tell_room(environment(tp),tp->query_name()+" "+str+"\n");
return 1; }

add_blood(int num){ blood += num; }
add_skin(int num){ skin += num; }
add_eye(int num){ eye += num; }
add_spine(int num){ spine += num; }
add_heart(int num){ heart += num; }
add_soul(int num){ soul += num; }
add_cdust(int num){ cdust += num; }

necro_block() {
 if(tp->query_level() < 20) {
  write("That action is not allowed within the Necromancer guild.\n");
 return 1; }
}

guild_notes() {
write("---------------  NECROMANCERS  ----------------\n\n");
return 1;
}
examine() {SPELL->examine(); return 1; }
preserve() {SPELL->preserve(); return 1; }
consume() {SPELL->consume(); return 1; }
dembrace() {SPELL->dembrace(); return 1; }

touch_chill(str) { 
  if(!spell_failure(perc[0])) { spellfailed }
    SPELL->touch_chill(str); return 1; }

spell_failure(int j) {
  j = 100;
  if(random(100) > j) return 0;
  else return 1; }
  
